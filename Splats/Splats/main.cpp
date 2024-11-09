#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
using namespace sf;


int main() {

	Texture textureRojo, textureAzul;
	vector<Sprite> sprites;

	string rutaRojo = "assets/rcircle.png";
	string rutaAzul = "assets/rcircleb.png";

	textureRojo.loadFromFile(rutaRojo);
	textureAzul.loadFromFile(rutaAzul);

	RenderWindow App(sf::VideoMode(800, 600, 32), "Splats");

	while (App.isOpen())
	{
		Event evt;

		while (App.pollEvent(evt)) {

			switch (evt.type) {
			case sf::Event::Closed:
				App.close();
				break;

			case sf::Event::MouseButtonPressed:

				Vector2f mousePos = App.mapPixelToCoords(Mouse::getPosition(App));

				if (evt.mouseButton.button == Mouse::Left) {
					Sprite circuloRojo;
					circuloRojo.setTexture(textureRojo);
					circuloRojo.setOrigin(textureRojo.getSize().x / 2, textureRojo.getSize().y / 2);
					circuloRojo.setPosition(mousePos);
					sprites.push_back(circuloRojo);
				}
				else if (evt.mouseButton.button == Mouse::Right) {
					Sprite circuloAzul;
					circuloAzul.setTexture(textureAzul);
					circuloAzul.setOrigin(textureRojo.getSize().x / 2, textureRojo.getSize().y / 2);
					circuloAzul.setPosition(mousePos);
					sprites.push_back(circuloAzul);
				}
				break;
			}
		}

		App.clear();

		for (auto& sprite : sprites) {
			App.draw(sprite);
		}

		App.display();

	}

	return 0;

}