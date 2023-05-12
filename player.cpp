#include "player.h"
#include <iostream>

//the body of the constructor
player::player()
{
}

//a setter to change money during player
void player::SetMoney(int moneyChange)
{
	money = moneyChange;
}

//a getter to get money during play
int player::GetMoney()
{
	return money;
}

//a setter to set the name of the player during player
void player::SetName(string changeName)
{
	name = changeName;
}

//a getter to get the name during play
string player::GetName()
{
	return name;
}

//a setter to change the position whenever the player moves/at the start of the game
void player::SetPosition(int changePosition)
{
	position = changePosition;
}

//a getter to get the the position during player
int player::GetPosition()
{
	return position;
}

//an unused status that would put the player in and out of the being able to move state
void player::ChangeJailStatus()
{
	jailed = !jailed;
}


//destructor body
player::~player()
{

}