#pragma once
#include "CSquare.h"
class FreeParking :
    public CSquare
{
protected:
    string secondParkingWord;

public:
    //a constructor for Free Parking
    FreeParking(istream& file);
    //a friend function that allows child classes to access this, allow me to create them using this
    friend istream& operator >> (istream& input, FreeParking& freeParking);
    //free parking has two words in it's name so I need a second free parking specific function to read the second word from the file
    string GetSecondParkingWord();
};