#pragma once
#include "CSquare.h"
class Penalty :
    public CSquare
{

public:
    //constructor for penalty
    Penalty(istream& file);
    //a friend function that allows child classes to access this, allow me to create them using this
    friend istream& operator >> (istream& input, Penalty& penalty);
};