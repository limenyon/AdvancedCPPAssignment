#pragma once
#include "CSquare.h"

class GO :
    public CSquare
{
public:
    //constructor for the GO class
    GO(istream& file);
    //a friend function that allows child classes to access this, allow me to create them using this
    friend istream& operator >> (istream& input, GO& go);
};