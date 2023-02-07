#pragma once

#include <iostream>

#include "Functionalities.h"
#include "Bottle.h"

struct Board
{

	Bottle bottles[TOTAL_BOTTLES];

	void InitBoard();
	void PrintBoard();
};