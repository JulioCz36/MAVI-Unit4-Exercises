#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
using namespace sf;
class Enemigo {
    Sprite sprite;
    bool estaVivo;
    float lifetime;
    float elapsedTime;

public:
    Enemigo(Texture& texture, Vector2u windowSize);

    void respawn(Vector2u windowSize);

    void actualizar(float deltaTime, sf::Vector2u windowSize);

    bool isClicked(Vector2f clickPosition);

    void dibujar(RenderWindow& window);
};

