#include "Bottle.h"

void Bottle::StartFilling(int position) {
	char icon;
	
	do {
		icon = liquids->liquids[GenerateRandom(0, TOTAL_LIQUIDS - 1)];
	} while (icon == ' ');
		
	liquids[position].icon = icon;
}

bool Bottle::CheckIfCanFillBottle() {
	return liquids[0].icon == ' ';
}

bool Bottle::CheckIfCanClearBottle() {
	return liquids[2].icon != ' ';
}

char Bottle::GetIconToClear() {

	char icon = ' ';

	for (int i = 0; i < TOTAL_LIQUIDS_IN_BOTTLE; i++) {
		if (liquids[i].icon != ' ') {
			icon = liquids[i].icon;
			liquids[i].icon = ' ';
			return icon;
		}
	}
}

void Bottle::SetIconToFill(char icon) {

	for (int i = TOTAL_LIQUIDS_IN_BOTTLE - 1; i >= 0; i--) {
		if (liquids[i].icon == ' ') {
			liquids[i].icon = icon;
			break;
		}
	}

}

bool Bottle::IsBottleFilled() {

	char icon = liquids[2].icon;

	for (int i = 0; i < TOTAL_LIQUIDS_IN_BOTTLE; i++) {
		if (liquids[i].icon != icon && liquids[i].icon != ' ') {
			return false;
		}
	}

	return true;
}