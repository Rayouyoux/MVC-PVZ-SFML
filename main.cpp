#include <SFML/Graphics.hpp>

#include "GameWindow.h"

using namespace sf;

int main()
{
    GameWindow	window;
	Event		event;

	// Pour l'instant ici parce que nique et qu'en attendant la version stylée on aura ca

	bool		loop = true;

	while (loop) {
		while (window.w_window->pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.Close();
			if (Mouse::isButtonPressed(Mouse::Button::Left) and window.w_window->hasFocus()) {
				// truc
			}
		}
	}
    return 0;
}
