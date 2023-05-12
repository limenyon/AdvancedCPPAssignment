//Vytenis Sakalinskas, pretty proud of how much I got used to this after the initial start
//All comments represent the code that's right underneath the comment

 //used for multiple input output function such as cout
#include <iostream>
//using this to access the files
#include <fstream> 
//using this for storing my pointers dinamically
#include <vector> 
//using this to get the functions from CSquare
#include "CSquare.h"
//using this to create my squares
#include "SquareFactory.h" 
//using this to create my players
#include "player.h" 
//placing a bunch of constants and class initialisations to de-clutter
#include "Consts.h"

//used for a bunch of stuff like string data types and such
using namespace std; 

int main ()
{
    {
        TextConsts Text;
        //storing the dynamically allocated result of the dice roll
        int rolledNumber = 0;
        //storing the dynamtically allocated seed here
        int seed = 0;
        //using a dynamic vector of pointers to store the poitners for my squares
        vector<CSquare*> squareList;
        //using my dynamic vector of pointers to store my players
        vector<player*> playerList;

        //giving visual studio the file to open
        ifstream file(Text.monopolyPartsFileName);
        //checking if file is open
        if (file.is_open())
        {
            //looping through all of the lines inside of the text file until it's closed
            while (file)
            {
                int type = 0;
                file >> type;

                if (type != 0)
                {
                    //creating my squarefiles and then placing them in my pointer vector
                    squareList.push_back(NewSquare(file, ESquareType(type), type));
                }
            }
        }
        else
        {
            cout << Text.errorMessageWhileOpeningFile;
        }
        //opening up the seed file
        ifstream seedFile(Text.seedFileName);
        if (seedFile.is_open())
        {
            //storing my the contents of the seed file in a variable to later use with srand for seeded rolls
            while (seedFile)
            {
                int type = 0;
                seedFile >> type;

                if (type != 0)
                {
                    seed = type;
                }
            }
        }
        else
        {
            cout << Text.errorMessageWhileOpeningFile;
        }

        //creating players and placing them inside a dynamic array
        for (int i = 0; i < numberOfPlayers; i++)
        {
            MakeNewPlayer(playerList, i, Text);
        }

        cout << Text.welcomeMessage << endl;

        //seeding my rolls using a seed from a file
        srand(seed);
        //looping 20 times for my game and calling the take turn function that rolls a die and resolves whichever square the players landed on
        for (int i = 0; i < numberOfRounds; i++)
        {
            for (int j = 0; j < playerList.size(); j++)
            {
                TakeTurn(j, squareList, playerList, Text);
                cout << endl;
            }
        }
        //calling a function to decide who won
        GameOver(playerList, Text);
        //doing a memory leak cleanup by deleting my pointers towards objects and objects by use of destructor
        MemoryCleanup(playerList, squareList);
    }
    _CrtDumpMemoryLeaks();
}

//used to generate a random number
int RollDice(float sidesOfDice)
{
    //using common random number generation code
    return static_cast<int>(static_cast<double> (rand()) / (RAND_MAX + 1) * sidesOfDice + 1);
}

//creating a new player object function
void MakeNewPlayer(vector<player*>& playerList, int i, TextConsts Text)
{
    //creating a new pointer towards the player object
    player* playerPtr = new player;
    //adding it to my vector
    playerList.push_back(playerPtr);
    //setting starting values of money, name and position
    playerList[i]->SetMoney(startingMoney);
    playerList[i]->SetName(Text.playerNames[i]);
    playerList[i]->SetPosition(startingPosition);
}

//a function to resolve actions for whichever square the players land on
void CheckSquareAction(int playerNumber, vector<CSquare*> squareList, vector<player*> playerList, ESquareType cases, TextConsts Text)
{
    //there are 8 possible cases and I'm reusing the cases from SquareFactory.h because they're identical
    switch (cases)
    {
     //what to do when a player is currently standing on a property tile
    case ESquareType::Properties:
    {
        //check if player is current owner of property they landed on, if so output message and move on
        if (playerList[playerNumber]->GetName() == squareList[playerList[playerNumber]->GetPosition() - 1]->GetOwner())
        {
            cout << playerList[playerNumber]->GetName() << Text.landsOnTheirOwnPropertyText << endl;
        }
        //check if there is an owner and if there is remove rent value from player on the square and add it to the other player's money pile
        else if (!empty(squareList[playerList[playerNumber]->GetPosition() - 1]->GetOwner()))
        {
            if (playerList[playerNumber]->GetName() != squareList[playerList[playerNumber]->GetPosition() - 1]->GetOwner())
            {
                cout << playerList[playerNumber]->GetName() + Text.paysTheOtherPlayerText + pound << squareList[playerList[playerNumber]->GetPosition() - 1]->GetRent() << endl;
                playerList[playerNumber]->SetMoney(playerList[playerNumber]->GetMoney() - squareList[playerList[playerNumber]->GetPosition() - 1]->GetRent());
                //loop through to compare names of players and the owner of the tile so the rent money goes to the appropriate player
                for (int k = 0; k < playerList.size(); k++)
                {
                    if (squareList[playerList[playerNumber]->GetPosition() - 1]->GetOwner() == playerList[k]->GetName())
                    {
                        playerList[k]->SetMoney(squareList[playerList[playerNumber]->GetPosition() - 1]->GetRent() + playerList[k]->GetMoney());
                        break;
                    }
                }
            }
        }
        //if a player lands on a property that has no owner, check if they can afford it, if they can purchase it, remove the cost from the total money the player has and change the owner to the player who just bought it
        else if (empty(squareList[playerList[playerNumber]->GetPosition() - 1]->GetOwner()))
        {
            if (playerList[playerNumber]->GetMoney() >= squareList[playerList[playerNumber]->GetPosition() - 1]->GetCost())
            {
                squareList[playerList[playerNumber]->GetPosition() - 1]->SetOwner(playerList[playerNumber]->GetName());
                playerList[playerNumber]->SetMoney(playerList[playerNumber]->GetMoney() - squareList[playerList[playerNumber]->GetPosition() - 1]->GetCost());
                cout << playerList[playerNumber]->GetName() << Text.purchasesText << squareList[playerList[playerNumber]->GetPosition() - 1]->GetName() << Text.forText + pound << squareList[playerList[playerNumber]->GetPosition() - 1]->GetCost() << endl;
            }
            else
            {
                //if a player can't afford the property put out a message and move on
                cout << playerList[playerNumber]->GetName() + Text.playerDoesntHaveEnoughMoneyToBuyThisPropertyText << endl;
            }
        }
        break;
    }
    //just creating a case for this to prevent errors, receive money from go gets resolved in taketurn
    case ESquareType::GO:
    {
        break;
    }
    //bus station is similar to property so the same comments apply here, in retrospect I could've used a function for this and I should've but that's how looking back on work goes
    case ESquareType::BusStation:
    {
        //check if player is current owner of bus station they landed on, if so output message and move on
        if (playerList[playerNumber]->GetName() == squareList[playerList[playerNumber]->GetPosition() - 1]->GetOwner())
        {
            cout << playerList[playerNumber]->GetName() + Text.visitsTheirOwnText + squareList[playerList[playerNumber]->GetPosition() -1]->GetName() << endl;
        }
        //check if there is an owner and if there is remove rent value from player on the square and add it to the other player's money pile
        else if (empty(squareList[playerList[playerNumber]->GetPosition() - 1]->GetOwner()))
        {
            if (empty(squareList[playerList[playerNumber]->GetPosition() -1]->GetOwner()))
            {
                if (playerList[playerNumber]->GetMoney() >= squareList[playerList[playerNumber]->GetPosition() - 1]->GetBusCost())
                {
                    squareList[playerList[playerNumber]->GetPosition() - 1]->SetOwner(playerList[playerNumber]->GetName());
                    playerList[playerNumber]->SetMoney(playerList[playerNumber]->GetMoney() - squareList[playerList[playerNumber]->GetPosition() - 1]->GetBusCost());
                    cout << playerList[playerNumber]->GetName() << Text.purchasesText << squareList[playerList[playerNumber]->GetPosition() - 1]->GetName() << Text.forText + pound << squareList[playerList[playerNumber]->GetPosition() - 1]->GetBusCost() << endl;
                }
                else
                {
                    cout << playerList[playerNumber]->GetName() + Text.playerDoesntHaveEnoughMoneyToBuyThisPropertyText << endl;
                }
            }
        }
        //if a player lands on a bus stop that has no owner, check if they can afford it, if they can purchase it, remove the cost from the total money the player has and change the owner to the player who just bought it
        else if (!empty(squareList[playerList[playerNumber]->GetPosition() - 1]->GetOwner()))
        {
            if (playerList[playerNumber]->GetName() != squareList[playerList[playerNumber]->GetPosition() - 1]->GetOwner())
            {
                cout << playerList[playerNumber]->GetName() + Text.paysTheOtherPlayerText + pound << squareList[playerList[playerNumber]->GetPosition() - 1]->GetBusRent() << Text.forABusTicket;
                playerList[playerNumber]->SetMoney(playerList[playerNumber]->GetMoney() - squareList[playerList[playerNumber]->GetPosition() - 1]->GetBusRent());
                cout << Text.leavingThemWithText + pound << playerList[playerNumber]->GetMoney() << endl;
                for (int k = 0; k < playerList.size(); k++)
                {
                    if (squareList[playerList[playerNumber]->GetPosition() - 1]->GetOwner() == playerList[k]->GetName())
                    {
                        playerList[k]->SetMoney(squareList[playerList[playerNumber]->GetPosition() - 1]->GetRent() + playerList[k]->GetMoney());
                        break;
                    }
                }
            }
        }
        break;
    }
    //a resolution for the six possible cases of bonus rolls
    case ESquareType::Bonus:
    {
        int rolledNumber = RollDice(numberOfBonuses);
        cout << playerList[playerNumber]->GetName() + Text.rollsText << rolledNumber << Text.forTheBonusText << endl;
        switch (rolledNumber)
        {
        //each case does the same thing with different amounts of money and a different message, other than that they all gain money for the player
        case 1:
        {
            cout << playerList[playerNumber]->GetName() + Text.youFindSomeMoneyText + Text.gainMoneyText + pound << punishmentRewardTier1 << endl;
            //add money
            playerList[playerNumber]->SetMoney(playerList[playerNumber]->GetMoney() + punishmentRewardTier1);
            break;
        }
        case 2:
        {
            cout << playerList[playerNumber]->GetName() + Text.winACodingCompetitionText + Text.gainMoneyText + pound << punishmentRewardTier2 << endl;
            playerList[playerNumber]->SetMoney(playerList[playerNumber]->GetMoney() + punishmentRewardTier2);
            break;
        }
        case 3:
        {
            cout << playerList[playerNumber]->GetName() + Text.rentText + Text.gainMoneyText + pound << punishmentRewardTier3 << endl;
            playerList[playerNumber]->SetMoney(playerList[playerNumber]->GetMoney() + punishmentRewardTier3);
            break;
        }
        case 4:
        {
            cout << playerList[playerNumber]->GetName() + Text.lotteryText + Text.gainMoneyText + pound << punishmentRewardTier4 << endl;
            playerList[playerNumber]->SetMoney(playerList[playerNumber]->GetMoney() + punishmentRewardTier4);
            break;
        }
        case 5:
        {
            cout << playerList[playerNumber]->GetName() + Text.bequestText + Text.gainMoneyText + pound << punishmentRewardTier5 << endl;
            playerList[playerNumber]->SetMoney(playerList[playerNumber]->GetMoney() + punishmentRewardTier5);
            break;
        }
        case 6:
        {
            cout << Text.itsBirthday + playerList[playerNumber]->GetName() + Text.birthdayText + Text.gainMoneyText + pound << punishmentRewardTier6 << endl;
            playerList[playerNumber]->SetMoney(playerList[playerNumber]->GetMoney() + punishmentRewardTier6);
            break;
        }
        }
        break;
    }
    //a resolution for the 6 penalty options
    case ESquareType::Penalty:
    {
        int rolledNumber = RollDice(numberOfPenalties);
        cout << playerList[playerNumber]->GetName() + Text.rollsText << rolledNumber << Text.forThePenaltyText << endl;
        switch (rolledNumber)
        {
        //just like bonus these are all the same except with different money amounts and a different message, except this removes money from players
        case 1:
        {
            cout << playerList[playerNumber]->GetName() + Text.buyCoffeeText + Text.loseMoneyText + pound << punishmentRewardTier1 << endl;
            //remove money
            playerList[playerNumber]->SetMoney(playerList[playerNumber]->GetMoney() - punishmentRewardTier1);
            break;
        }
        case 2:
        {
            cout << playerList[playerNumber]->GetName() + Text.payBroadbandText + Text.loseMoneyText + pound << punishmentRewardTier2 << endl;
            playerList[playerNumber]->SetMoney(playerList[playerNumber]->GetMoney() - punishmentRewardTier2);
            break;
        }
        case 3:
        {
            cout << playerList[playerNumber]->GetName() + Text.visitShopText + Text.loseMoneyText + pound << punishmentRewardTier3 << endl;
            playerList[playerNumber]->SetMoney(playerList[playerNumber]->GetMoney() - punishmentRewardTier3);
            break;
        }
        case 4:
        {
            cout << playerList[playerNumber]->GetName() + Text.buySolutiontText + Text.loseMoneyText + pound << punishmentRewardTier4 << endl;
            playerList[playerNumber]->SetMoney(playerList[playerNumber]->GetMoney() - punishmentRewardTier4);
            break;
        }
        case 5:
        {
            cout << playerList[playerNumber]->GetName() + Text.romanticMealText + Text.loseMoneyText + pound << punishmentRewardTier5 << endl;
            playerList[playerNumber]->SetMoney(playerList[playerNumber]->GetMoney() - punishmentRewardTier5);
            break;
        }
        case 6:
        {
            cout << playerList[playerNumber]->GetName() + Text.payUniversityText + Text.loseMoneyText + pound << punishmentRewardTier6 << endl;
            playerList[playerNumber]->SetMoney(playerList[playerNumber]->GetMoney() - punishmentRewardTier6);
            break;
        }
        }
        break;
    }
    //Jail is a regular square with an extra message so it just outputs a message
    case ESquareType::Jail:
    {
        cout << playerList[playerNumber]->GetName() + Text.isJustVisitingText << endl;
        break;
    }
    //This sets the player's location to the jail square by looping through the squarelist vector and finding jail, making it scalable, it also removes money from the player
    case ESquareType::GoToJail:
    {
        cout << playerList[playerNumber]->GetName() + Text.goesToJailText << endl;
        cout << playerList[playerNumber]->GetName() + Text.paysText + pound << jailPrice << endl;
        //removing money from the player
        playerList[playerNumber]->SetMoney(playerList[playerNumber]->GetMoney() - jailPrice);
        //loop for finding jail's location in the vector
        for (int i = 0; i < squareList.size(); i++)
        {
            if (squareList[i]->GetName() == Text.placePlayerOnJail)
            {
                playerList[playerNumber]->SetPosition(i);
                break;
            }
        }
     break;
    }
    //free parking is a regular square with an extra message so it just outputs a message
    case ESquareType::FreeParking:
    {
        cout << playerList[playerNumber]->GetName() + Text.isRestingText << endl;
        break;
    }
    }
}

//take turn is the function that resolves go and calls the other two previously mentioned functions
void TakeTurn(int playerNumber, vector<CSquare*> squareList, vector<player*> playerList, TextConsts Text)
{
    int rolledNumber = RollDice(sidesOfDice);
    cout << playerList[playerNumber]->GetName() << Text.rollsText << rolledNumber << endl;
    playerList[playerNumber]->SetPosition(playerList[playerNumber]->GetPosition() + rolledNumber);
    //if a player goes above 26 on their position they get 200 money and their position is set to position - 26, making it scalable
    if (playerList[playerNumber]->GetPosition() > maxNumberOfSquares)
    {
        playerList[playerNumber]->SetMoney(playerList[playerNumber]->GetMoney() + moneyFromGo);
        playerList[playerNumber]->SetPosition(playerList[playerNumber]->GetPosition() - maxNumberOfSquares);
        cout << playerList[playerNumber]->GetName() + " " + Text.playerPassesGoText + " " << pound << moneyFromGo << endl;
    }
    //here and throughout I use GetPosition() - 1 because player position can never be 0 while the array starts at 0, so it has to move one point back
    cout << playerList[playerNumber]->GetName() << Text.playerLandsOnText << squareList[playerList[playerNumber]->GetPosition() - 1]->GetName() << endl;
    CheckSquareAction(playerNumber, squareList, playerList, ESquareType(squareList[playerList[playerNumber]->GetPosition() - 1]->GetSquareType()), Text);
    cout << playerList[playerNumber]->GetName() + Text.hasText + pound << playerList[playerNumber]->GetMoney() << endl;
}

//a function that compares players and the player that has more money at the end is output as the winner
void GameOver(vector<player*> playerList, TextConsts Text)
{
    int numberOfWinningPlayer = 0;
    //loop a scalable amount of times and place the person with the highest amount of money inside of numberofwinningplayer
    for (int i = 1; i < playerList.size(); i++)
    {
        if (playerList[numberOfWinningPlayer]->GetMoney() < playerList[i]->GetMoney())
        {
            numberOfWinningPlayer = i;
        }
    }
    cout << playerList[numberOfWinningPlayer]->GetName() + Text.winningText + pound << playerList[numberOfWinningPlayer]->GetMoney() << endl;
}

//used to call the destructors for both of the vectors that store pointers to get rid of the pointers and objects associated with them to prevent memory leaks
void MemoryCleanup(vector<player*> playerList, vector<CSquare*> squareList)
{
    for (int i = 0; i < playerList.size(); i++)
    {
        delete playerList[i];
    }
    for (int j = 0; j < squareList.size(); j++)
    {
        delete squareList[j];
    }
}