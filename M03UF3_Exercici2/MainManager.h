#pragma once

#include <iostream>
#include <string>

#include "Functionalities.h"
#include "Board.h"

struct MainManager
{

	enum Scenes { MENU, GAME, SCOREBOARD, EXIT };

	Scenes currentScene = GAME;

	Board b;

	int moves = MAX_MOVES;
	int bottleToFill;
	int bottleToClear;

	int score;
	std::string name;

	void Game();
	void DemandBottleToFill();
	void DemandBottleToClear();

};