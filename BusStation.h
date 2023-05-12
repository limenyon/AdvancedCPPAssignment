#pragma once
#include "CSquare.h"
//A CSquare child class
class BusStation :
    public CSquare
{
protected:
    string secondWord;
    int busCost = 200;
    int busRent = 10;

public:
    //constructor for the bus station objects
    BusStation(istream& file);
    //used for reading in from the file when creating the child square
    friend istream& operator >> (istream& input, BusStation& busStation);
    //Bus has to read in multiple words from the file so I'm creating a return function to get that work
    string GetBusStationSecondWord();
    //A bus has a cost and rent, they never change so I only create these two getters for them
    int GetBusCost();
    int GetBusRent();
};