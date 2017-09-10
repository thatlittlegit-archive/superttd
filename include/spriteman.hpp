#include <SFML/Graphics.hpp>
#include <yaml-cpp/yaml.h>
#include <string>
#include <vector>

using std::string;

namespace SuperTTD {
	class Sprite {
	private:
		string filename;
	  int world;
	  string id;
		sf::Sprite associated;

		void construct(string argFilename, unsigned int argWorld, string argId);
	public:
		string getFilename();
		int getWorld();
		string getId();

		sf::Sprite reloadSprite();

		Sprite(string argFilename, int argWorld, string argId);

		Sprite(YAML::Node yaml);
	};
}

std::vector<SuperTTD::Sprite> fetchSprites(string spriteFolder);
