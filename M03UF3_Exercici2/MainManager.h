#pragma once

#include <iostream>
#include <string>
#include <fstream>

#include "Functionalities.h"
#include "Board.h"

struct MainManager
{

	enum Scenes { MENU, GAME, SCOREBOARD, GAMEOVER, EXIT };

	Scenes currentScene;

	Board b;

	int moves = MAX_MOVES;
	int bottleToFill;
	int bottleToClear;

	bool hasWin;
	int score;
	int total_scores;
	std::string name;

	void Start();
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
	void LoadScores();
};