#pragma once
#include <string>
using namespace std;

class player
{
protected: 
	int money = 0;
	string name = "";
	int position = 0;
	bool jailed = false;
public:
	//a constrcutor for player
	player();
	//a setter to change money values
	void SetMoney(int moneyChange);
	//a getter to get money values
	int GetMoney();
	//a setter for the name
	void SetName(string changeName);
	//a getter for the name
	string GetName();
	//a setter for the position
	void SetPosition(int changePosition);
	//a getter for the position
	int GetPosition();
	//a bool setter for a jailed variable
	void ChangeJailStatus();
	//a destructor to clean up memory
	virtual ~player();
};