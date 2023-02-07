#include "MainManager.h"

void MainManager::Game() {

	bool isPlaying = true;
	b.InitBoard();

	while (isPlaying) {

		switch (currentScene) {
		case MENU:
			break;
		case GAME:
			b.PrintBoard();
			DemandBottleToFill();
			DemandBottleToClear();
			b.bottles[bottleToFill - 1].SetIconToFill(b.bottles[bottleToClear - 1].GetIconToClear());
			break;
		case SCOREBOARD:
			break;
		case EXIT:
			break;
		default:
			break;
		}

		system("pause");
		system("cls");

	}

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

		canFill = b.bottles[bottleToFill - 1].CheckIfCanFillBottle();
		
		if (!canFill) {
			std::cout << " [!] Bottle selected can not be filled." << std::endl;
			std::cout << " [!] Select another one.\n" << std::endl;
			continue;
		}

		std::cout << " [*] Bottle number " << bottleToFill << " selected.\n" << std::endl;

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

		if (bottleToClear == bottleToFill) {
			std::cout << " [!] Bottle already selected to fill." << std::endl;
			std::cout << " [!] Select a another one.\n" << std::endl;
			canClear = false;
			continue;
		}

		canClear = b.bottles[bottleToClear - 1].CheckIfCanClearBottle();

		if (!canClear) {
			std::cout << " [!] Bottle selected can not be cleared to fill another bottle." << std::endl;
			std::cout << " [!] Select another one.\n" << std::endl;
			continue;
		}

		std::cout << " [*] Bottle number " << bottleToClear << " selected.\n" << std::endl;

	} while (!canClear);

}