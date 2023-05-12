#include "FreeParking.h"
//definition of the constructor used in SquareFactory to create a new object and a pointer towards it
FreeParking::FreeParking(istream& file) : CSquare(file)
{
	file >> *this;
}
//used to read from the file and to add the appropriate parts to the object
istream& operator >> (istream& input, FreeParking& freeParking)
{
	input >> freeParking.secondParkingWord;
	return input;
}

//free parking has 2 words in it's name so I need to return the second parking word to combine both for a full name in squarefactory
string FreeParking::GetSecondParkingWord()
{
	return this->secondParkingWord;
}