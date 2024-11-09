#include "Enemigo.h"

Enemigo::Enemigo(Texture& texture, Vector2u windowSize) {
    sprite.setTexture(texture);
    sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
    respawn(windowSize);
}

void Enemigo::respawn(Vector2u windowSize) {
    sprite.setScale(0.05f, 0.05f);

    float x = static_cast<float>(std::rand() % (windowSize.x - static_cast<int>(sprite.getGlobalBounds().width)));
    float y = static_cast<float>(std::rand() % (windowSize.y - static_cast<int>(sprite.getGlobalBounds().height)));
    
    sprite.setPosition(x, y);
    
    estaVivo = true;

    lifetime = 1.0f ;
    elapsedTime = 0.0f;
}

void Enemigo::actualizar(float deltaTime, sf::Vector2u windowSize) {
    elapsedTime += deltaTime;
    if (elapsedTime >= lifetime) {
        respawn(windowSize);
    }
}

bool Enemigo::isClicked(Vector2f clickPosition) {
    if (estaVivo && sprite.getGlobalBounds().contains(clickPosition)) {
        estaVivo = false;
        return true;
    }
    return false;
}

void Enemigo::dibujar(RenderWindow& window) {
    if (estaVivo) {
        window.draw(sprite);
    }
}

