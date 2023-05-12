#pragma once
#include "CSquare.h"
class Bonus :
    public CSquare
{

public:
    //constructor for the Bonus Square defined here
    Bonus(istream& file);
    //used for reading in from the file when creating the child square
    friend istream& operator >> (istream& input, Bonus& bonus);
};

