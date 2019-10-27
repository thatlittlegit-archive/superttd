/* (c) 2019 thatlittlegit and PinguPenguin.
 * This file is from the SuperTTD project.
 *
 * SuperTTD, and by extension this file, is free software under
 * the GNU General Public License, 2.0.
 *
 * SuperTTD is distributed in the hope that it will be useful,
 * but comes with NO WARRANTY WHATSOEVER. Please se the official
 * GNU GPL 2.0 for more information.
 *
 * You should have recieved a copy of the GPL with this project.
 * If not, see https://gnu.org/licenses/.
 */
#pragma once
#include <optional>
#include <string>
#include <vector>

namespace SuperTTD {
class ResourceCode {
public:
    static std::optional<ResourceCode> lookupResource(std::string);
    static std::optional<std::string> lookupResource(ResourceCode);

    /** Creates a new resource type. Returns the existing one if a type has the
      same name. */
    static ResourceCode addResource(std::string);

    static ResourceCode invalid();
    static bool invalid(ResourceCode);

private:
    static std::vector<std::string> resourceTypes;
    int code;
    explicit ResourceCode(int);
};

ResourceCode sprite();

class NamespacedIdentifier {
public:
    ResourceCode type = ResourceCode::invalid();
    std::string provider;
    std::optional<std::string> world;
    std::optional<std::string> identifier;
    NamespacedIdentifier(std::string text);
    std::string to_string();
};
} // namespace SuperTTD
