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
#include "namespaced_id.hpp"
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <yaml-cpp/yaml.h>

namespace SuperTTD {
struct Pixel {
    uint8_t r;
    uint8_t g;
    uint8_t b;
};
constexpr short TEXTURE_SIZE = 512;
typedef std::array<std::array<Pixel, TEXTURE_SIZE>, TEXTURE_SIZE> Texture;

class Sprite {
public:
    std::string filename;
    int world;
    NamespacedIdentifier id;

    sf::Texture getSfmlTexture();
    Texture& getPixelData();
    void setPixelData(const Texture&);

    Sprite(std::string argFilename, unsigned int argWorld, std::string argId);

    static void loadSprites(std::string spriteFolder);

private:
    static std::vector<Sprite> loadedSprites;
    Texture texture;

    static Sprite fromYaml(YAML::Node yaml);
};
} // namespace SuperTTD
