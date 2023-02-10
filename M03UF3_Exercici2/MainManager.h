#pragma once

#include <iostream>
#include <string>
#include <fstream>

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
	int score = 0;
	std::string name;

	void Game();
	void PrintMovesLeft();
	void DemandBottleToFill();
	void DemandBottleToClear();
	bool CheckIfPlayerHasWin();
	void GetScore();
	void PrintScore();
	void DemandUserName();
	bool StillPlaying();
	void SaveScore();
};