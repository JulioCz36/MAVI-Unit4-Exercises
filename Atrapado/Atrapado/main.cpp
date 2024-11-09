#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
using namespace sf;


int main() {

	Texture textureCuadrado, textureCirculo;
	Sprite s1, s2, s3, s4;

	string rutaCuadrado = "assets/cuad_yellow.png";
	string rutaCirculo = "assets/rcircleg.png";

	textureCuadrado.loadFromFile(rutaCuadrado);
	textureCirculo.loadFromFile(rutaCirculo);

	float w_cuadrado = textureCuadrado.getSize().x;
	float h_cuadrado = textureCuadrado.getSize().y;
	float w_circulo = textureCirculo.getSize().x; 
	float h_circulo = textureCirculo.getSize().y;

	float escaleX_cuadrado = w_circulo / w_cuadrado;
	float escaleY_cuadrado = h_circulo / h_cuadrado;

	RenderWindow App(sf::VideoMode(800, 600, 32), "Atrapado");

	Sprite shape;
	shape.setTexture(textureCuadrado);
	shape.setOrigin(w_cuadrado / 2, h_cuadrado / 2);
	shape.setPosition(App.getSize().x / 2, App.getSize().y / 2);
	shape.setScale(escaleX_cuadrado, escaleY_cuadrado);

	bool esCuadrado = true;
	float velocidad = 0.25f;

	while (App.isOpen())
	{
		Event evt;

		while (App.pollEvent(evt)) {

			switch (evt.type) {
			case sf::Event::Closed:
				App.close();
				break;

			case sf::Event::KeyPressed:

				if (evt.key.code == Keyboard::Space) {

					if (esCuadrado) {
						shape.setTexture(textureCirculo);
						shape.setScale(1, 1);
						shape.setOrigin(w_circulo / 2, h_circulo / 2);
					}
					else {
						shape.setTexture(textureCuadrado);
						shape.setScale(escaleX_cuadrado, escaleY_cuadrado);
						shape.setOrigin(w_cuadrado / 2, h_cuadrado / 2);
					}
					esCuadrado = !esCuadrado;
				}

				break;
			}
		}

		Vector2f position = shape.getPosition();

		if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A) && position.x > w_circulo / 2) {
			position.x -= velocidad;
		}
		if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D) && position.x < 800 - w_circulo / 2) {
			position.x += velocidad;
		}
		if (Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W) && position.y > w_circulo / 2) {
			position.y -= velocidad;
		}
		if (Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S) && position.y < 600 - w_circulo / 2) {
			position.y += velocidad;
		}

		shape.setPosition(position);

		App.clear();
		App.draw(shape);
		App.display();

	}

	return 0;

}