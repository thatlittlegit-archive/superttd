/* (c) 2017-2019 thatlittlegit & PinguPenguin. This file's from the SuperTTD
 * project.
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
#include "sprite.hpp"
#include <algorithm>
#include <iterator>

using std::string;

namespace SuperTTD {
Sprite::Sprite(std::filesystem::path argFolder, NamespacedIdentifier argIdentifier)
    : id(argIdentifier)
    , folder(argFolder)
{
}

Sprite Sprite::fromYaml(std::filesystem::path folder, std::string provider, YAML::Node yaml)
{
    return Sprite(folder, NamespacedIdentifier(sprite(), provider, yaml["world"].as<string>(), yaml["id"].as<string>()));
}

sf::Texture Sprite::getSfmlTexture()
{
    Texture sprite = getPixelData();
    sf::Image image;
    image.create(512, 512, (uint8_t*)sprite.data());

    sf::Texture texture;
    if (!texture.loadFromImage(image, sf::IntRect(0, 0, 512, 512)))
        throw std::runtime_error("failed to load texture");

    return texture;
}

Texture& Sprite::getPixelData() { return texture; }

void Sprite::setPixelData(const Texture& newTexture)
{
    std::copy(std::begin(newTexture), std::end(newTexture), std::begin(texture));
}

std::vector<SuperTTD::Sprite> Sprite::loadedSprites;

void Sprite::loadSprites(std::filesystem::path spriteFolder)
{
    YAML::Node providers = YAML::LoadFile((spriteFolder / "sprites.yml").string())["sprites"];

    for (YAML::Node providerNode : providers) {
        YAML::Node sprites = providerNode["contents"];
        std::string provider = providerNode["provider"].as<string>();

        for (YAML::Node sprite : sprites) {
            loadedSprites.push_back(Sprite::fromYaml(spriteFolder, provider, sprite));
        }
    }
}

std::filesystem::path Sprite::filename()
{
    return folder / id.provider / id.world.value() / id.identifier.value();
}
} // namespace SuperTTD
