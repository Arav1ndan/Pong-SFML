#include "../../Header/Gameplay/GameplayManager.h"

namespace Gameplay {
	//GameplayManager::GameplayManager()
	//{
	//	
	//}
	GameplayManager::GameplayManager(EventManager* manager)
	{
		time_service = new TimeService();
		time_service->initialize();
		initialize();
		boundary = new Boundary();
		event_manager = manager;
		ui_service = new UIService();
		ui_service->loadFontTexture();
		ui_service->createLeftScoreText();
		ui_service->createRightScoreText();
		
	}
	void GameplayManager::initialize() {
		ball = new Ball();

		

		player1 = new Paddle(player1_position_x, player1_position_y);
		player2 = new Paddle(player2_position_x, player2_position_y);
	}
	void GameplayManager::render(RenderWindow* game_window)
	{
		boundary->render(game_window);
		ball->render(game_window);
		player1->render(game_window);
		player2->render(game_window);
		ui_service->render(game_window);
	}
	void GameplayManager::update()
	{
		UpdateScore();
		ui_service->update();
		time_service->update();
		ball->update(player1,player2,time_service);
		player1->update(event_manager->isKeyPressed(Keyboard::W),
			event_manager->isKeyPressed(Keyboard::S), time_service);
		player2->update(event_manager->isKeyPressed(Keyboard::Up),
			event_manager->isKeyPressed(Keyboard::Down), time_service);
	}	
	void GameplayManager::UpdateScore()
	{
		if (ball->isLeftCollisionOccurred()) {
			ui_service->incrementPlayer2Score();
			ball->updateLeftCollisionState(false);
			//resetPlayer();
		}
		if (ball->isRightCollisionOccurred()) {
			ui_service->incrementPlayer1Score();
			ball->updateRightCollisionState(false);
			//resetPlayer();
		}
	}
	void GameplayManager::resetPlayer()
	{
		player1->reset(player1_position_x, player1_position_y);
		player2->reset(player2_position_x, player2_position_y);
	}
	
}

