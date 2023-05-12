#include "CSquare.h"
#include <iostream>

//definition of the constructor used in SquareFactory to create a new object and a pointer towards it
CSquare::CSquare(istream& file)
{
	file >> *this;
}

//used to read from the file and to add the appropriate parts to the object
istream& operator >> (istream& input, CSquare& square)
{
	input >> square.name;
	return input;
}

//a getter to return the name of each object through a parent function
string CSquare::GetName()
{
	return this->name;
}

//a etter to get the square type of each object through a parent function
int CSquare::GetSquareType()
{
	return this->squareType;
}

//a getter to return the owner of each ojbect, only two classes end up using this
string CSquare::GetOwner()
{
	return owner;
}

//a setter to change the owner
void CSquare::SetOwner(string playerName)
{
	owner = playerName;
}

//a virtual getter to get the cost of properties, it's virtual because I'm accessing it through the parent class because I'm storing CSquare pointers in one vector rather than multiple arrays of child specific pointers
int CSquare::GetCost()
{
	return 0;
}

//a virtual getter to get the rent of properties, while they will not return these values if everything goes correctly returning something prevents errors
int CSquare::GetRent()
{
	return 0;
}

//a virtual getter to get the cost of busses
int CSquare::GetBusCost()
{
	return 0;
}

//a virtual getter to get the rent of buses
int CSquare::GetBusRent()
{
	return 0;
}

//a virtual getter to get the second word for property names
string CSquare::getSecondStreetWord()
{
	return "";
}

//a virtual getter to get the second word for the free parking name
string CSquare::GetSecondParkingWord()
{
	return "";
}

//two virtual getters to get the second and third word from go to jail which has 3 words in its name and the file reads in one word at a time
string CSquare::GetGoToJailSecondWord()
{
	return "";
}
string CSquare::GetGoToJailThirdWord()
{
	return "";
}

//a virtual getter to get the second word for bus station's name
string CSquare::GetBusStationSecondWord()
{
	return "";
}

//a virtual getter to get the colour group of properties
int CSquare::GetColourGroup()
{
	return 0;
}

//a setter to change the square type that I do in squarefactory
void CSquare::setSquareType(int type)
{
	squareType = type;
}

//a setter to set the full name of a square instead of just one word
void CSquare::setMultiWordSquareName(string secondWord)
{
	name = name + " " + secondWord;
}

//an overloaded setter that works the same way as the one above but with 3 words instead of 2
void CSquare::setMultiWordSqaureName(string secondWord, string thirdWord)
{
	name = name + " " + secondWord + " " + thirdWord;
}

//the destructor body
CSquare::~CSquare()
{

}