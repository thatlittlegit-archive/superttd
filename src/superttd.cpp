#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SuperTTD");

	while (window.isOpen())
		{
			sf::Event event;

			while (window.pollEvent(event))
				{
					if (event.type == sf::Event::Closed) window.close();
				}
			window.clear(sf::Color::Black);

			// draw everything here...
			// window.draw(...);

			// end the current frame
			window.display();
		}
}
