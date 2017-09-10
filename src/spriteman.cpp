#include <yaml-cpp/yaml.h>
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <iostream>

std::vector<sf::Sprite> fetchSprites(std::string spriteFolder) {
	YAML::Node sprites = YAML::LoadFile(spriteFolder + "/sprites.yml")["sprites"];

  for(unsigned int index = 0; index < sprites.size(); index++) {
		std::cout << sprites[index] << '\n';
	}
	std::cout << std::endl;
}
