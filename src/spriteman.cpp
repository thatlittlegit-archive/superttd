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
#include "spriteman.hpp"
#include <string>

using std::string;

namespace SuperTTD {
void Sprite::construct(string argFilename, unsigned int argWorld, string argId)
{
    filename = argFilename;
    world = argWorld;
    id = argId;

    try {
        associated = reloadSprite();
        associated.setScale(0.125 * 0.65, 0.125 * 0.65);
        associated.setRotation(135);
    } catch (const std::invalid_argument& e) {
    }
}
sf::Sprite Sprite::reloadSprite()
{
    if (!associatedTexture.loadFromFile("sprites/" + filename)) {
        throw std::invalid_argument("Unable to load sprite");
    } else {
        associated.setTexture(associatedTexture);
        return associated;
    }
}

Sprite::Sprite(string argFullFilename, int argWorld, string argId)
{
    construct(argFullFilename, argWorld, argId);
}

Sprite::Sprite(YAML::Node yaml)
{
    construct(yaml["world"].as<string>() + "/" + yaml["filename"].as<string>(),
        yaml["worldid"].as<unsigned int>(), yaml["id"].as<string>());
}

Sprite::Sprite(const Sprite& spriteobj)
    : associated(spriteobj.associated)
    , associatedTexture(spriteobj.associatedTexture)
{
    associated.setTexture(associatedTexture);
}
}

std::vector<SuperTTD::Sprite>* SuperTTD::Sprite::loadedSprites;

std::vector<SuperTTD::Sprite> fetchSprites(string spriteFolder)
{
    YAML::Node sprites = YAML::LoadFile(spriteFolder + "/sprites.yml")["sprites"];
    std::vector<SuperTTD::Sprite> toReturn;

    for (unsigned int index = 0; index < sprites.size(); index++) {
        toReturn.push_back(SuperTTD::Sprite(sprites[index]));
    }

    return toReturn;
}
