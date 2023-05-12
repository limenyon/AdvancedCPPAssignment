#include "Penalty.h"
//definition of the constructor used in SquareFactory to create a new object and a pointer towards it
Penalty::Penalty(istream& file) : CSquare(file)
{
	file >> *this;
}
//used to read from the file and to add the appropriate parts to the object
istream& operator >> (istream& input, Penalty& penalty)
{
	return input;
}
