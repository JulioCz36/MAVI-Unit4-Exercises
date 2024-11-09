#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
using namespace sf;

class Crosshair {
    Sprite sprite;

public:
    Crosshair(Texture& texture);

    void actualizar(RenderWindow& window);

    void dibujar(RenderWindow& window);

    Vector2f verPos() const;
};

