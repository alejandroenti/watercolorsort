#pragma once

#include "Functionalities.h"
#include "Liquids.h"

struct Bottle
{

	Liquids liquids[TOTAL_LIQUIDS_IN_BOTTLE];
	int total_liquids;

	void StartFilling(int position);
	bool CheckIfCanFillBottle();
	bool CheckIfCanClearBottle();
	char GetIconToClear();
	void SetIconToFill(char icon);
	bool IsBottleFilled();
};