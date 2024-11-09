#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
using namespace sf;


int main() {

	Texture texture;
	Sprite sprite;

	string ruta = "assets/crosshair.png";

	texture.loadFromFile(ruta);

	float width = texture.getSize().x;
	float height = texture.getSize().y;

	sprite.setTexture(texture);

	sprite.setPosition((800 / 2) - (width / 2), (600 / 2) - (height / 2));


	RenderWindow App(sf::VideoMode(800, 600, 32), "Crosshair");

	while (App.isOpen())
	{

		App.clear();

		App.draw(sprite);

		App.display();
	}

	return 0;

}