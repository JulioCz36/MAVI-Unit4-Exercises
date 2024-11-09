#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
using namespace sf;


int main() {

	Texture texture;
	Sprite s1, s2, s3, s4;

	string ruta = "assets/rcircle.png";

	texture.loadFromFile(ruta);

	s1.setTexture(texture); 
	s2.setTexture(texture);
	s3.setTexture(texture); 
	s4.setTexture(texture);

	float width = texture.getSize().x;
	float height = texture.getSize().y;

	s2.setPosition(800 - width, 0);
	s3.setPosition(0, 600 - height);
	s4.setPosition(800 - width, 600 - height);

	RenderWindow App(sf::VideoMode(800, 600, 32), "Drag");

	
	bool dragging = false;
	Sprite* selectedSprite = nullptr;  
	Vector2f offset;

	while (App.isOpen())
	{
		Event evt;

		while (App.pollEvent(evt)) {

			switch (evt.type) {
				case sf::Event::Closed:
					App.close();
				break;

				case sf::Event::MouseButtonPressed:
					if (evt.mouseButton.button == Mouse::Left) {
						Vector2f mousePos = App.mapPixelToCoords(Mouse::getPosition(App));

						if (s1.getGlobalBounds().contains(mousePos)) {
							selectedSprite = &s1;
						}
						else if (s2.getGlobalBounds().contains(mousePos)) {
							selectedSprite = &s2;
						}
						else if (s3.getGlobalBounds().contains(mousePos)) {
							selectedSprite = &s3;
						}
						else if (s4.getGlobalBounds().contains(mousePos)) {
							selectedSprite = &s4;
						}

						if (selectedSprite) {
							// Calcula el offset para arrastrar sin que el sprite "salte"
							offset = mousePos - selectedSprite->getPosition();
							dragging = true;
						}
					}
					break;

				case sf::Event::MouseButtonReleased:
					if (evt.mouseButton.button == Mouse::Left) {
						dragging = false;
						selectedSprite = nullptr;
					}
				break;
			}
		}

		if (dragging && selectedSprite) {
			Vector2f mousePos = App.mapPixelToCoords(Mouse::getPosition(App));
			selectedSprite->setPosition(mousePos - offset);
		}

		App.clear();
		App.draw(s1);
		App.draw(s2);
		App.draw(s3);
		App.draw(s4);
		App.display();

	}

	return 0;

}