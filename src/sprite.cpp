/* (c) 2017-2019 thatlittlegit and PinguPenguin.
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
#include "sprite.hpp"
#include <algorithm>
#include <iterator>

using std::string;

namespace SuperTTD {
Sprite::Sprite(string argFilename, unsigned int argWorld, string argId)
{
    filename = argFilename;
    world = argWorld;
    id = argId;
}

Sprite Sprite::fromYaml(YAML::Node yaml)
{
    return Sprite(yaml["world"].as<string>() + "/" + yaml["filename"].as<string>(),
        yaml["worldid"].as<unsigned int>(), yaml["id"].as<string>());
}

sf::Texture Sprite::getSfmlTexture()
{
    Texture image = getPixelData();
    sf::Texture texture;
    if (!texture.loadFromMemory(&image, TEXTURE_SIZE * TEXTURE_SIZE))
        throw std::runtime_error("failed to load texture");

    return texture;
}

Texture& Sprite::getPixelData()
{
    return texture;
}

void Sprite::setPixelData(const Texture& newTexture)
{
    std::copy(std::begin(newTexture), std::end(newTexture), std::begin(texture));
}

std::vector<SuperTTD::Sprite> Sprite::loadedSprites;

void Sprite::loadSprites(string spriteFolder)
{
    YAML::Node sprites = YAML::LoadFile(spriteFolder + "/sprites.yml")["sprites"];

    for (unsigned int index = 0; index < sprites.size(); index++) {
        loadedSprites.push_back(Sprite::fromYaml(sprites[index]));
    }
}
}
