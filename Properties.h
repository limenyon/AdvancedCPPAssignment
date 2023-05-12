#pragma once
#include "CSquare.h"
class Properties :
    public CSquare
{
protected:
    int cost = 0;
    int rent = 0;
    int colourGroup = 0;
    string secondStreetWord;
public:
    //properties constructor
    Properties(istream& file);
    //a friend function that allows child classes to access this, allow me to create them using this
    friend istream& operator >> (istream& input, Properties& house);
    //a getter for cost
    int GetCost();
    //a getter for rent
    int GetRent();
    //a getter for colour group
    int GetColourGroup();
    //properties have two word names so I need a setter to store the value from the file
    string getSecondStreetWord();
};