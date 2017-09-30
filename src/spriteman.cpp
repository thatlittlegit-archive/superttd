#include <yaml-cpp/yaml.h>
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <iostream>

using std::string;

namespace SuperTTD {
	class Sprite {
	private:
		void construct(string argFilename, unsigned int argWorld, string argId) {
			filename = argFilename;
			world = argWorld;
			id = argId;

			try {
				associated = reloadSprite();
			} catch (const std::invalid_argument& e) {}
		}
	public:
	  string filename;
	  unsigned int world;
	  string id;
	  sf::Sprite associated;
	  sf::Texture associatedTexture;

	  sf::Sprite reloadSprite() {

			if(!associatedTexture.loadFromFile("sprites/" + filename)) {
				throw std::invalid_argument("Unable to load sprite");
			} else {
				associated.setTexture(associatedTexture);
				return associated;
			}
		}

		Sprite(string argFilename, int argWorld, string argId) {
			construct(argFilename, argWorld, argId);
		}

		Sprite(YAML::Node yaml) {
			construct(yaml["filename"].as<string>(),
				  yaml["world"].as<unsigned int>(),
				  yaml["id"].as<string>());
		}

	  Sprite(const Sprite &spriteobj) : associatedTexture(spriteobj.associatedTexture), associated(spriteobj.associated) {
	    associated.setTexture(associatedTexture);
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
