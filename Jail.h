#pragma once
#include "CSquare.h"
class Jail :
    public CSquare
{

public:
    //constructor for jail
    Jail(istream& file);
    //a friend function that allows child classes to access this, allow me to create them using this
    friend istream& operator >> (istream& input, Jail& jail);
};

