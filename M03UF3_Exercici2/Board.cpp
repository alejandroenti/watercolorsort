#include "Board.h"


void Board::InitBoard() {

	bool areEqual = false;
	int fullBottles[FULL_BOTTLES];

	do {

		fullBottles[0] = GenerateRandom(0, TOTAL_BOTTLES - 1);
		fullBottles[1] = GenerateRandom(0, TOTAL_BOTTLES - 1);

		(fullBottles[0] == fullBottles[1]) ? areEqual = true : 0;
		
	} while (areEqual);

	for (int i = 0; i < TOTAL_BOTTLES; i++) {
		for (int j = TOTAL_LIQUIDS_IN_BOTTLE - 1; j > 0; j--) {
			bottles[i].StartFilling(j);
		}
	}

	for (int i = 0; i < TOTAL_BOTTLES; i++) {

		if (i == fullBottles[0] || i == fullBottles[1]) {
			bottles[i].StartFilling(0);
			continue;
		}
		
		bottles[i].liquids->icon = ' ';
	}
}

void Board::PrintBoard() {

	for (int i = 0; i < TOTAL_BOTTLES; i++) {
		std::cout << " \\ / ";
	}
	std::cout << std::endl;

	for (int i = 0; i < TOTAL_LIQUIDS_IN_BOTTLE; i++) {
		for (int j = 0; j < TOTAL_BOTTLES; j++) {
			std::cout << " |" << bottles[j].liquids[i].icon << "| ";
		}
		std::cout << std::endl;
	}

	for (int i = 0; i < TOTAL_BOTTLES; i++) {
		std::cout << " ''' ";
	}
	std::cout << std::endl;

	for (int i = 0; i < TOTAL_BOTTLES; i++) {
		std::cout << "  " << i + 1 << "  ";
	}
	std::cout << std::endl;

}