#include "BusStation.h"

//definition of the constructor used in SquareFactory to create a new object and a pointer towards it
BusStation::BusStation(istream& file) : CSquare(file)
{
	file >> *this;
}
//used to read from the file and to add the appropriate parts to the object, because it has another word in it's name it needs to be read in here to place it inside of the bus station object specifically
istream& operator >> (istream& input, BusStation& busStation)
{
	input >> busStation.secondWord;
	return input;
}
//this object has multiple words in it's name so I need to read them from a file and set them as a variable inside
string BusStation::GetBusStationSecondWord()
{
	return this->secondWord;
}
//getters that return the cost and rent that are invoked through virtual from the parent object
int BusStation::GetBusCost()
{
	return this->busCost;
}
int BusStation::GetBusRent()
{
	return this->busRent;
}