#include "MainManager.h"

void MainManager::Game() {

	bool isPlaying = true;
	b.InitBoard();

	while (isPlaying) {

		switch (currentScene) {
		case MENU:
			break;
		case GAME:
			
			if (moves == 0) {
				currentScene = GAMEOVER;
				continue;
			}

			b.PrintBoard();
			PrintMovesLeft();
			
			if (StillPlaying()) {
				currentScene = GAMEOVER;
				hasWin = false;
				continue;
			}

			DemandBottleToFill();
			DemandBottleToClear();
			b.bottles[bottleToFill].SetIconToFill(b.bottles[bottleToClear].GetIconToClear());
			
			if (CheckIfPlayerHasWin()){
				hasWin = true;
				currentScene = GAMEOVER;
			}
			
			moves--;
			break;
		case SCOREBOARD:
			break;
		case GAMEOVER:

			b.PrintBoard();
			PrintMovesLeft();
			GetScore();
			PrintScore();
			DemandUserName();
			SaveScore();
			currentScene = MENU;
			break;
		case EXIT:

			isPlaying = false;

			std::cout << "\n Goodbye! See you next time" << std::endl;

			break;
		default:
			break;
		}

		system("pause");
		system("cls");

	}

}

void MainManager::PrintMovesLeft() {

	std::cout << "\n Moves left: " << moves << std::endl;
	
}

void MainManager::DemandBottleToFill() {

	bool canFill;

	do {
		canFill = true;

		std::cout << "\n Which bottle do you want to fill? ";
		std::cin >> bottleToFill;

		if (bottleToFill <= 0 || bottleToFill > 6) {
			std::cout << " [!] Bottle selected does not exist." << std::endl;
			std::cout << " [!] Select a valid one.\n" << std::endl;
			canFill = false;
			continue;
		}

		bottleToFill -= 1;

		canFill = b.bottles[bottleToFill].CheckIfCanFillBottle();
		
		if (!canFill) {
			std::cout << " [!] Bottle selected can not be filled." << std::endl;
			std::cout << " [!] Select another one.\n" << std::endl;
			continue;
		}

		std::cout << " [*] Bottle number " << bottleToFill + 1 << " selected.\n" << std::endl;

	} while (!canFill);

}

void MainManager::DemandBottleToClear() {

	bool canClear;

	do {

		canClear = true;

		std::cout << "\n Which bottle do you want to clear first liquid? ";
		std::cin >> bottleToClear;

		if (bottleToClear <= 0 || bottleToClear > 6) {
			std::cout << " [!] Bottle selected does not exist." << std::endl;
			std::cout << " [!] Select a valid one.\n" << std::endl;
			canClear = false;
			continue;
		}
		
		bottleToClear -= 1;

		if (bottleToClear == bottleToFill) {
			std::cout << " [!] Bottle already selected to fill." << std::endl;
			std::cout << " [!] Select a another one.\n" << std::endl;
			canClear = false;
			continue;
		}

		canClear = b.bottles[bottleToClear].CheckIfCanClearBottle();

		if (!canClear) {
			std::cout << " [!] Bottle selected can not be cleared to fill another bottle." << std::endl;
			std::cout << " [!] Select another one.\n" << std::endl;
			continue;
		}

		std::cout << " [*] Bottle number " << bottleToClear + 1 << " selected.\n" << std::endl;

	} while (!canClear);

}

bool MainManager::CheckIfPlayerHasWin() {

	for (int i = 0; i < TOTAL_BOTTLES; i++) {
		if (!b.bottles[i].IsBottleFilled())
			return false;
	}

	return true;
}

void MainManager::GetScore() {

	for (int i = 0; i < TOTAL_BOTTLES; i++) {
		
		if (b.bottles[i].IsBottleFilled() && b.bottles[i].total_liquids == 0) {
			score += 50;
			continue;
		}

		if (b.bottles[i].IsBottleFilled()) {
			score += b.bottles[i].total_liquids * 10;
		}
	}

	score += moves * 3;

}

void MainManager::PrintScore() {


	if (hasWin) {
		std::cout << "\n You won!!! Your score is " << score << " ---> ";
	}
	else {
		std::cout << "\n You lost!!! Your score is " << score << " ---> ";
	}

}

void MainManager::DemandUserName() {

	std::cout << "Enter your name: ";
	std::cin >> name;

}

bool MainManager::StillPlaying() {

	char option;

	std::cout << "\n What do you want to do? [play / finish] ";
	std::cin >> option;

	if (option == 'f') {
		return false;
	}

	return true;
}

void MainManager::SaveScore() {

	size_t size = name.size();

	std::ofstream outFile;
	outFile.open("scores.wcs", std::ios::out | std::ios::binary | std::ios::app);

	outFile.write(reinterpret_cast<char*>(&name), sizeof(size_t));
	outFile.write(name.c_str(), sizeof(char) * size);
	outFile.write(reinterpret_cast<char*>(&score), sizeof(int));

	outFile.close();
}