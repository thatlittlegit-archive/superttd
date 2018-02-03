/* (c) 2017 thatlittlegit and PinguPenguin.
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
#include <SFML/Graphics.hpp>
#include "spriteman.hpp"
#include "tileman.hpp"
#include <vector>
#include <iostream>

using std::vector;

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SuperTTD");

	vector<SuperTTD::Sprite> sprites = fetchSprites("sprites");
	SuperTTD::Sprite::loadedSprites = &sprites;

	// TEMP Create a 255x255 map for development
	for (unsigned char x = 0; x < 255; x++) {
		for (unsigned char y = 0; y < 255; y++) {
			SuperTTD::Tile::tiles.push_back(SuperTTD::Tile(0, x, y, 0));
		}
	}
	while (window.isOpen()) {
		sf::Event event;

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear(sf::Color::Black);

		// draw everything here...
		for (unsigned int index = 0; index < SuperTTD::Tile::tiles.size();
			 index++) {
			SuperTTD::Tile tile = SuperTTD::Tile::tiles.at(index);
			sprites.at(tile.spriteIndex)
					.associated.setPosition(
							sf::Vector2f(tile.x * 8, tile.y * 8));
			window.draw(sprites.at(tile.spriteIndex).associated);
		}
		// end the current frame
		window.display();
	}
}
