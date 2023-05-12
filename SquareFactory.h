#pragma once

#include <istream>
#include "CSquare.h"
//enumerator used to compare against the square types read from file to create appropriate objects
enum class ESquareType : int
{
	Properties = 1,
	GO = 2,
	BusStation = 3,
	Bonus = 4,
	Penalty = 5,
	Jail = 6,
	GoToJail = 7,
	FreeParking = 8
};

//a function to create new square objctes
CSquare* NewSquare(istream& file, ESquareType square, int type);