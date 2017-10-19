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
#include <vector>
#include <iostream>

using std::vector;

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SuperTTD");
	
	vector<SuperTTD::Sprite> sprites = fetchSprites("sprites");
	while (window.isOpen())
		{
			sf::Event event;
			
			while (window.pollEvent(event))
				{
					if (event.type == sf::Event::Closed) window.close();
				}
			window.clear(sf::Color::Black);
			
			// draw everything here...
			window.draw(sprites.at(1).associated);
			// window.draw(...);
			
			// end the current frame
			window.display();
		}
}
