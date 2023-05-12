#pragma once

//Here I am storing a bunch of variables that will not change in runtime such as text, const ints and function declarations

#include <string>
using namespace std;
//using a struct allows all of the strings to be deleted when Main ends which usually does not happen and causes memory leaks
struct TextConsts
{
	const string monopolyPartsFileName = "monopoly.txt";
	const string errorMessageWhileOpeningFile = "Unable to open file";
	const string welcomeMessage = "Welcome To Monopol-ish";
	const string playerNames[2] = { "Car", "Boot" };
	const string seedFileName = "seed.txt";
	const string playerLandsOnText = " lands on ";
	const string playerPassesGoText = "player passes GO and collects";
	const string turnText = "Turn: ";
	const string rollsText = " rolls ";
	const string purchasesText = " buys ";
	const string forText = " for ";
	const string leavingThemWithText = " leaving them with ";
	const string paysTheOtherPlayerText = " pays ";
	const string forRentText = " for rent";
	const string landsOnTheirOwnPropertyText = " lands on their own property.";
	const string playerDoesntHaveEnoughMoneyToBuyThisPropertyText = "  player doesn't have enough money to buy this square";
	const string hasText = " has ";
	const string isJustVisitingText = " is just visiting ";
	const string goesToJailText = " goes to Jail";
	const string paysText = " pays ";
	const string placePlayerOnJail = "Jail";
	const string visitsTheirOwnText = " visits their own ";
	const string forABusTicket = " for a bus ticket";
	const string andEndsUpOnSquareText = " and ends up on square ";
	const string onSquareText = " on square ";
	const string isRestingText = " is resting";
	const string youFindSomeMoneyText = " finds some money.";
	const string gainMoneyText = " Gain ";
	const string winACodingCompetitionText = " wins a coding competition.";
	const string rentText = " receives a rent rebate.";
	const string lotteryText = " wins the lottory.";
	const string bequestText = " receives a bequest.";
	const string itsBirthday = "It's ";
	const string birthdayText = "'s birthday.";
	const string forTheBonusText = " for the bonus";
	const string forThePenaltyText = " for the penalty";
	const string loseMoneyText = " Lose ";
	const string buyCoffeeText = " buys a coffee in Starbucks";
	const string payBroadbandText = " pays their broadband bill";
	const string visitShopText = " visits the SU shop for food";
	const string buySolutiontText = " buys an assignment solution";
	const string romanticMealText = " buys a romantic meal";
	const string payUniversityText = " pays university fees";
	const string winningText = " wins with ";
};

//declaring my functions that are defined in my main file here
int RollDice(float sidesOfDice);
void MakeNewPlayer(vector<player*>& playerList, int i, TextConsts Text);
void CheckSquareAction(int playerNumber, vector<CSquare*> squareList, vector<player*> playerList, ESquareType cases, TextConsts Text);
void TakeTurn(int playerNumber, vector<CSquare*> squareList, vector<player*> playerList, TextConsts Text);
void GameOver(vector<player*> playerList, TextConsts Text);
void MemoryCleanup(vector<player*> playerList, vector<CSquare*> squareList);

//these data types unlike string get deleted when main ends so they don't have to be in a struct
const float sidesOfDice = 6.0f;
const char pound = 156;
const int numberOfPlayers = 2;
const int numberOfRounds = 20;
const int startingMoney = 1500;
const int startingPosition = 1;
const int maxNumberOfSquares = 26;
const int moneyFromGo = 200;
const int numberOfBonuses = 6;
const int punishmentRewardTier2 = 50;
const int punishmentRewardTier1 = 20;
const int punishmentRewardTier3 = 100;
const int punishmentRewardTier4 = 150;
const int punishmentRewardTier5 = 200;
const int punishmentRewardTier6 = 300;
const int numberOfPenalties = 6;
const int jailPrice = 50;
