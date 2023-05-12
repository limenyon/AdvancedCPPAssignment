#pragma once
#include "CSquare.h"
class GoToJail :
    public CSquare
{
protected:
    string secondJailWord;
    string thirdJailWord;

public:
    //A constructor for Go To Jail
    GoToJail(istream& file);
    //a friend function that allows child classes to access this, allow me to create them using this
    friend istream& operator >> (istream& input, GoToJail& goToJail);
    //go to jail has multiple words so I need multiple functions to read words coming from the file stream
    string GetGoToJailSecondWord();
    string GetGoToJailThirdWord();
};

