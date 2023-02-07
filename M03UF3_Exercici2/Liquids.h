#pragma once

#include "Functionalities.h"

struct Liquids
{
	enum Liquid {BUIT, VERD, LILA, BLAU, VERMELL};
	char liquids[TOTAL_LIQUIDS] = { ' ', 'X', '#', 'O', 'S' };

	char icon;

};