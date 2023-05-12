#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//the very main class that is a parent to all other 8 children
class CSquare
{
protected:
	int squareType = 0;
	string name = "";
	//both bus station and properties have owners so I'm creating a variable for those here
	string owner;

public:
	//constructor for the CSquare object
	CSquare(istream& file);

	friend istream& operator >> (istream& input, CSquare& square);

	//a setter for squares that have two words in their name
	void setMultiWordSquareName(string secondWord);
	//a setter for squares with 3 words in their name, using an overloaded function for ease
	void setMultiWordSqaureName(string secondWord, string thirdWord);
	//a setter to read in from the file and to change the square type from its initial state
	void setSquareType(int type);
	//a setter to change the owner when the players purchase the properties
	void SetOwner(string playerName);
	
	//a getter to access the owner variable
	string GetOwner();
	//a getter to access the name of the square
	string GetName();
	//a getter to access the squaretype
	int GetSquareType();
	//a virtual getter is used because this allows me to access the child class getters/setters through the parent class allowing me to change the children from my vector that is filled with pointers of CSquare
	virtual int GetBusCost();
	virtual int GetBusRent();
	virtual int GetCost();
	virtual int GetRent();
	virtual int GetColourGroup();
	virtual string getSecondStreetWord();
	virtual string GetSecondParkingWord();
	virtual string GetGoToJailSecondWord();
	virtual string GetGoToJailThirdWord();
	virtual string GetBusStationSecondWord();

	//defining a destructor because objects cause leaks and we don't want that
	virtual ~CSquare();
};