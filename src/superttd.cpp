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
