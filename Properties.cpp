#include "Properties.h"
//definition of the constructor used in SquareFactory to create a new object and a pointer towards it
Properties::Properties(istream& file) : CSquare(file)
{
	file >> *this;
}
//used to read from the file and to add the appropriate parts to the object, because it has a lot more variables to it than the parent class they need to be read from the file and put into the object here
istream& operator >> (istream& input, Properties& properties)
{
	input >> properties.secondStreetWord;
	input >> properties.cost;
	input >> properties.rent;
	input >> properties.colourGroup;
	return input;
}

//a getter for the cost of properties
int Properties::GetCost()
{
	return this->cost;
}

//a getter for the properties rent
int Properties::GetRent()
{
	return this->rent;
}

//properties have 2 words in their names so I return this to combine the two words into one string
string Properties::getSecondStreetWord()
{
	return this->secondStreetWord;
}

//a getter to get the colour group which does not do anything right now
int Properties::GetColourGroup()
{
	return this->colourGroup;
}