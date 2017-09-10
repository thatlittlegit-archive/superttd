#include <yaml-cpp/yaml.h>
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <iostream>

using std::string;

namespace SuperTTD {
	class Sprite {
	private:
		string filename;
	  int world;
	  string id;
		sf::Sprite associated;

		void construct(string argFilename, unsigned int argWorld, string argId) {
			filename = argFilename;
			world = argWorld;
			id = argId;

			try {
				reloadSprite();
			} catch (const std::invalid_argument& e) {}
		}

	public:
		string getFilename() { return filename; }
		int getWorld() { return world; }
		string getId() { return id; }

		sf::Sprite reloadSprite() {
			sf::Texture texture;

			if(!texture.loadFromFile("sprites/" + filename)) {
				throw std::invalid_argument("Unable to load sprite");
			} else {
				associated.setTexture(texture);
				return associated;
			}
		}

		Sprite(string argFilename, int argWorld, string argId) {
			construct(argFilename, argWorld, argId);
		}

		Sprite(YAML::Node yaml) {
			construct(yaml["filename"].as<string>(), yaml["world"].as<unsigned int>(), yaml["id"].as<string>());
		}
	};
}

std::vector<SuperTTD::Sprite> fetchSprites(string spriteFolder) {
	YAML::Node sprites = YAML::LoadFile(spriteFolder + "/sprites.yml")["sprites"];
	std::vector<SuperTTD::Sprite> toReturn;

  for(unsigned int index = 0; index < sprites.size(); index++) {
		toReturn.push_back(SuperTTD::Sprite(sprites[index]));
	}

	return toReturn;
}
