#include "GoToJail.h"
//definition of the constructor used in SquareFactory to create a new object and a pointer towards it
GoToJail::GoToJail(istream& file) : CSquare(file)
{
	file >> *this;
}
//used to read from the file and to add the appropriate parts to the object
istream& operator >> (istream& input, GoToJail& goToJail)
{
	input >> goToJail.secondJailWord;
	input >> goToJail.thirdJailWord;
	return input;
}

// go to jail has 3 words in it's name so I need to return the second and third go to jail words to combine them for a full name in squarefactory
string GoToJail::GetGoToJailSecondWord()
{
	return this->secondJailWord;
}
string GoToJail::GetGoToJailThirdWord()
{
	return this->thirdJailWord;
}