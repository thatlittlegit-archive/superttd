/* (c) 2019 thatlittlegit & PinguPenguin. This file's from the SuperTTD project.
 *
 * SuperTTD, and by extension this file, is free software under the GNU General
 * Public License, 2.0.
 *
 * SuperTTD is distributed in the hope that it will be useful, but comes with NO
 * WARRANTY WHATSOEVER. Please see the GNU GPL 2.0 license for more information.
 *
 * You should have recieved a copy of the GPL with this project. If not, see
 * https://gnu.org/licenses/.
 */
#include "namespaced_id.hpp"
#include <algorithm>
#include <array>

namespace SuperTTD {
std::optional<ResourceCode> ResourceCode::lookupResource(std::string wanted)
{
    std::array<std::string, 1> wantedArr = { wanted };

    auto foundCode = std::find_first_of(resourceTypes.begin(), resourceTypes.end(),
        wantedArr.begin(), wantedArr.end());

    if (foundCode == resourceTypes.end())
        return std::nullopt;
    else
        return std::optional { ResourceCode(foundCode - resourceTypes.begin()) };
}

std::optional<std::string> ResourceCode::lookupResource(ResourceCode code)
{
    try {
        return std::optional { resourceTypes.at(code.code) };
    } catch (std::out_of_range& e) {
        return std::nullopt;
    }
}

ResourceCode ResourceCode::addResource(std::string code)
{
    std::optional<ResourceCode> possiblyFound = lookupResource(code);
    if (possiblyFound.has_value())
        return possiblyFound.value();

    resourceTypes.push_back(code);
    return ResourceCode(resourceTypes.size() - 1);
}

ResourceCode ResourceCode::invalid() { return ResourceCode(-1); }

bool ResourceCode::invalid(ResourceCode code) { return code.code == -1; }

ResourceCode::ResourceCode(int index) { code = index; }

std::vector<std::string> ResourceCode::resourceTypes;

ResourceCode sprite() { return ResourceCode::addResource("sprite"); }

NamespacedIdentifier::NamespacedIdentifier(std::string text)
{
    enum class Mode {
        TYPE_MODE,
        PROVIDER_MODE,
        WORLD_MODE,
        IDENTIFIER_MODE,
    };
    Mode currentState = Mode::TYPE_MODE;
    std::string wipType;

    world = std::optional { "" };
    identifier = std::optional { "" };

    for (unsigned int i = 0; i < text.length(); i++) {
        char current = text.c_str()[i];

        switch (currentState) {
        case Mode::TYPE_MODE:
            switch (current) {
            case '[':
                if (i == 0)
                    break;
                else
                    throw std::invalid_argument("invalid id string");
            case ']':
                currentState = Mode::PROVIDER_MODE;
                break;
            default:
                wipType += current;
                break;
            }
            break;
        case Mode::PROVIDER_MODE:
            switch (current) {
            case ':':
                currentState = Mode::WORLD_MODE;
                break;
            default:
                provider += current;
                break;
            }
            break;
        case Mode::WORLD_MODE:
            switch (current) {
            case '#':
                world.value().clear();
            case ':':
                currentState = Mode::IDENTIFIER_MODE;
                break;
            default:
                world.value() += current;
                break;
            }
        case Mode::IDENTIFIER_MODE:
            identifier.value() += current;
        }
    }

    type = ResourceCode::lookupResource(wipType).value();
}

NamespacedIdentifier::NamespacedIdentifier(ResourceCode atype, std::string aprovider, std::optional<std::string> aworld, std::optional<std::string> aidentifier)
    : type(atype)
    , provider(aprovider)
    , world(aworld)
    , identifier(aidentifier)
{
}

std::string NamespacedIdentifier::to_string()
{
    return "[" + ResourceCode::lookupResource(type).value() + "]" + provider + ":" + (world.has_value() ? (world.value().empty() ? "#" : world.value()) : "#") + (identifier.has_value() ? ":" + identifier.value() : "");
}
} // namespace SuperTTD
