#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include "Crosshair.h"
#include "Enemigo.h"
#include <iostream>
using namespace std;
using namespace sf;


int main() {

    Clock clock;

    srand(static_cast<unsigned int>(std::time(nullptr)));

	Texture crosshairTexture, enemigoTexture;
	crosshairTexture.loadFromFile("assets/crosshair.png");
	enemigoTexture.loadFromFile("assets/et.png");

	Crosshair crosshair(crosshairTexture);
	vector<Enemigo> enemigos;

    int enemigosMatados = 0;
    int maxEnemigosMatados = 5;

    RenderWindow App(sf::VideoMode(800, 600, 32), "Clickale");
    App.setMouseCursorVisible(false);
    while (App.isOpen()) {
        Event evt;
        while (App.pollEvent(evt)) {
            switch (evt.type) {
            case sf::Event::Closed:
                App.close();
                break;

            case sf::Event::MouseButtonPressed:
                if (evt.mouseButton.button == Mouse::Left) {
                    Vector2f clickPosition = App.mapPixelToCoords(Mouse::getPosition(App));
                    for (auto& enemy : enemigos) {
                        if (enemy.isClicked(clickPosition)) {
                            enemigosMatados++;
                            if (enemigosMatados < maxEnemigosMatados) {
                                enemy.respawn(App.getSize());
                            }
                            break;
                        }
                    }
                }
                break;
            }
        }
        float Time = clock.restart().asSeconds();

        crosshair.actualizar(App);
        for (auto& enemy : enemigos) {
            enemy.actualizar(Time, App.getSize());
        }

        if (enemigos.size() < 3) {
            enemigos.emplace_back(enemigoTexture, App.getSize());
        }

        App.clear();
        crosshair.dibujar(App);

        for (auto& enemy : enemigos) {
            enemy.dibujar(App);
        }

        App.display();

        if (enemigosMatados >= maxEnemigosMatados) {
            App.close();
        }
    }

	return 0;

}