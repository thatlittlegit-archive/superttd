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
#pragma once
#include "namespaced_id.hpp"
#include <SFML/Graphics.hpp>
#include <filesystem>
#include <string>
#include <vector>
#include <yaml-cpp/yaml.h>

namespace SuperTTD {
struct Pixel {
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a = 0xFF;
};
constexpr short TEXTURE_SIZE = 512;
typedef std::array<std::array<Pixel, TEXTURE_SIZE>, TEXTURE_SIZE> Texture;

class Sprite {
public:
    NamespacedIdentifier id;

    sf::Texture getSfmlTexture();
    Texture& getPixelData();
    void setPixelData(const Texture&);

    Sprite(std::filesystem::path folder, NamespacedIdentifier id);

    static void loadSprites(std::filesystem::path spriteFolder);

private:
    static std::vector<Sprite> loadedSprites;
    std::filesystem::path folder;
    Texture texture;

    static Sprite fromYaml(std::filesystem::path folder, std::string provider, YAML::Node yaml);
    std::filesystem::path filename();
};
} // namespace SuperTTD
