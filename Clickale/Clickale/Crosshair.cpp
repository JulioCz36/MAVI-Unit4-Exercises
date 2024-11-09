
#include "Crosshair.h"
Crosshair::Crosshair(Texture& texture) {
    sprite.setTexture(texture);
    sprite.setScale(0.5f, 0.5f);
    sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
}

void Crosshair::actualizar(RenderWindow& window) {
    Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
    sprite.setPosition(mousePos);
}

void Crosshair::dibujar(RenderWindow& window) {
    window.draw(sprite);
}

Vector2f Crosshair::verPos() const{
    return sprite.getPosition();
}