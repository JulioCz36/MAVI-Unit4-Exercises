#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

int main() {
    RenderWindow window(VideoMode(800, 600), "Adaptación");

    int minWidth = 100;
    int minHeight = 100;
    int maxWidth = 1000;
    int maxHeight = 1000;

    while (window.isOpen()) {
        Event evt;
        while (window.pollEvent(evt)) {
            if (evt.type == Event::Closed) {
                window.close();
            }

            if (evt.type == Event::Resized) {
                int newWidth = evt.size.width;
                int newHeight = evt.size.height;
                if (newWidth < minWidth) newWidth = minWidth;
                if (newWidth > maxWidth) newWidth = maxWidth;
                if (newHeight < minHeight) newHeight = minHeight;
                if (newHeight > maxHeight) newHeight = maxHeight;

                window.setSize(Vector2u(newWidth, newHeight));
            }
        }

        window.clear();
        window.display();
    }

    return 0;
}
