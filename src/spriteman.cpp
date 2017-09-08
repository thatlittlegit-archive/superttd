#include <yaml-cpp/yaml.h>
#include <SFML/Graphics.hpp>
#include <string>
#include <array>
#include <iostream>

using std::string;
using std::array;

sf::Sprite fetchSprites(string spriteFolder) {
	YAML::Node sprites = YAML::LoadFile(spriteFolder + "/sprites.yaml")["sprites"];

  for(unsigned int index; index < sprites.size(); index++) {
		std::cout << index << '\n';
	}
}
