#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/Utility/TimeService.h"

using namespace sf;
using namespace Utility;

namespace Gameplay {
	class Paddle {
	private:
		RectangleShape paddle_sprite;

		const float paddle_width = 20.0f;
		const float paddle_height = 140.0f;

		float paddle_speed = 0.1f;
		float topBoundary = 20.0f;
		float bottomBoundary = 700.0f;
		int speedMultiplier = 10;

		void createPaddle(float position_x, float position_y);
		void movePaddle(bool move_up_key_pressed, bool move_down_key_pressed, TimeService* time_service);

	public:

		Paddle(float position_x, float position_y);

		RectangleShape getPaddleSprite();
		void reset(float position_x, float position_y);

		void update(bool move_up_key_pressed, bool move_down_key_pressed, TimeService* time_service);
		void render(RenderWindow* game_window);
	};
}