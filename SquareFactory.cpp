#include "SquareFactory.h"
#include "Properties.h"
#include "GO.h"
#include "BusStation.h"
#include "Bonus.h"
#include "Penalty.h"
#include "Jail.h"
#include "GoToJail.h"
#include "FreeParking.h"

//using a switch case statement I am creating squares by reading in data from the file
//I create a new pointer and while I have it here I combine words to get a full name where applicable and set a squaretype, square type does not follow fully through the creation process of the squares and is gotten rid of after this
//So I create a this to assign the square type before it gets put into the vector of pointers
//All of these do the same, create a pointer by reading from the file, set the type and return a pointer, some also create a full name out of variables inside of the child objects that were read from the file
CSquare* NewSquare(istream& file, ESquareType square, int type)
{
	switch (square)
	{
	case ESquareType::Properties:
	{
		CSquare* newPtr = new Properties(file);
		newPtr->setSquareType(type);
		newPtr->setMultiWordSquareName(newPtr->getSecondStreetWord());
		return newPtr;
		break;
	}
	case ESquareType::GO:
	{
		CSquare* newPtr = new GO(file);
		newPtr->setSquareType(type);
		return newPtr;
		break;
	}
	case ESquareType::BusStation:
	{
		CSquare* newPtr = new BusStation(file);
		newPtr->setSquareType(type);
		newPtr->setMultiWordSquareName(newPtr->GetBusStationSecondWord());
		return newPtr;
		break;
	}
	case ESquareType::Bonus:
	{
		CSquare* newPtr = new Bonus(file);
		newPtr->setSquareType(type);
		return newPtr;
		break;
	}
	case ESquareType::Penalty:
	{
		CSquare* newPtr = new Penalty(file);
		newPtr->setSquareType(type);
		return newPtr;
		break;
	}
	case ESquareType::Jail:
	{
		CSquare* newPtr = new Jail(file);
		newPtr->setSquareType(type);
		return newPtr;
		break;
	}
	case ESquareType::GoToJail:
	{
		CSquare* newPtr = new GoToJail(file);
		newPtr->setSquareType(type);
		newPtr->setMultiWordSqaureName(newPtr->GetGoToJailSecondWord(), newPtr->GetGoToJailThirdWord());
		return newPtr;
		break;
	}
	case ESquareType::FreeParking:
	{
		CSquare* newPtr = new FreeParking(file);
		newPtr->setSquareType(type);
		newPtr->setMultiWordSquareName(newPtr->GetSecondParkingWord());
		return newPtr;
		break;
	}
	}
}