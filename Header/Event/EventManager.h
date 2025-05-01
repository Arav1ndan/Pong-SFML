#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

namespace CoustomEvent {
	class EventManager {
	public:
		void pollEvents(RenderWindow* game_window);
		bool isKeyPressed(Keyboard::Key key);
	};
}