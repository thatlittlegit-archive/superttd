#include <SFML/Graphics.hpp>
#include <yaml-cpp/yaml.h>
#include <string>
#include <vector>

using std::string;

namespace SuperTTD {
	class Sprite {
	private:
		void construct(string argFilename, unsigned int argWorld, string argId);
	public:
		string filename;
		int world;
		string id;
		sf::Sprite associated;
		sf::Texture associatedTexture;
		
		sf::Sprite reloadSprite();

		Sprite(string argFilename, int argWorld, string argId);
		Sprite(YAML::Node yaml);

		Sprite(const Sprite &spriteobj);
	};
}

std::vector<SuperTTD::Sprite> fetchSprites(string spriteFolder);
