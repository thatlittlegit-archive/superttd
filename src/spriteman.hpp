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
#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <yaml-cpp/yaml.h>

namespace SuperTTD {
class Sprite {
private:
    void construct(std::string argFilename, unsigned int argWorld, std::string argId);

public:
    std::string filename;
    int world;
    std::string id;
    sf::Sprite associated;
    sf::Texture associatedTexture;
    static std::vector<Sprite>* loadedSprites;

    sf::Sprite reloadSprite();

    Sprite(std::string argFilename, int argWorld, std::string argId);
    Sprite(YAML::Node yaml);

    Sprite(const Sprite& spriteobj);
};
}

std::vector<SuperTTD::Sprite> fetchSprites(std::string spriteFolder);
