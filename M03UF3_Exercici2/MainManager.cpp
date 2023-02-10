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
			b.bottles[bottleToFill].SetIconToFill(b.bottles[bottleToClear].GetIconToClear());
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