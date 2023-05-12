#include "Bonus.h"

//definition of the constructor used in SquareFactory to create a new object and a pointer towards it
Bonus::Bonus(istream& file) : CSquare(file)
{
	file >> *this;
}
//used to read from the file and to add the appropriate parts to the object
istream& operator >> (istream& input, Bonus& bonus)
{
	return input;
}