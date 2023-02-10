#pragma once

#include <iostream>
#include <string>

#include "Functionalities.h"
#include "Board.h"

struct MainManager
{

	enum Scenes { MENU, GAME, SCOREBOARD, GAMEOVER, EXIT };

	Scenes currentScene = GAME;

	Board b;

	int moves = MAX_MOVES;
	int bottleToFill;
	int bottleToClear;

	bool hasWin = false;
	int score;
	std::string name;

	void Game();
	void PrintMovesLeft();
	void DemandBottleToFill();
	void DemandBottleToClear();
	bool CheckIfPlayerHasWin();

};