#include <yaml-cpp/yaml.h>
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <iostream>

std::vector<sf::Sprite> fetchSprites(std::string spriteFolder) {
	YAML::Node sprites = YAML::LoadFile(spriteFolder + "/sprites.yaml")["sprites"];

  for(unsigned int index; index < sprites.size(); index++) {
		std::cout << index << '\n';
	}
}
