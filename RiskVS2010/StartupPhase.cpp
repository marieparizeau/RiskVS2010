#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <ctime>

#include "StartupPhase.h"
#include "Player.h"

using namespace std;

StartupPhase::StartupPhase() // Constructor
{
}

vector<Player> StartupPhase::asksPlayersNames() // Asks the players name
{
	// Asks how many players are going to play
	cout << "Enter the number of players (2 - 5 players): ";

	int totalNumberPlayer;
	cin >> totalNumberPlayer;
	cout << endl;

	vector<Player> vectorPlayers;
	string name;

	// Pushes in the vectors the Player objects
	for (int i = 1; i <= totalNumberPlayer; i++)
	{
		cout << "Player " << i << " - Enter your name: ";
		cin >> name;

		Player* newPlayer = new Player(name, i);

		vectorPlayers.push_back(*newPlayer);

	}
	
	return vectorPlayers;
}

void StartupPhase::assignCountryRandomly(vector<Player> vectorPlayers) // Assigns randomly countries to the players
{
}

void StartupPhase::giveOutInitialArmies(vector<Player> vectorPlayers) // Gives out the initial armies to the players
{
	int numberOfPlayers = vectorPlayers.size();
	int numberOfArmies = 0;

	switch (numberOfPlayers)
	{
	case 2:
		numberOfArmies = 40;
		break;
	case 3:
		numberOfArmies = 35;
		break;
	case 4:
		numberOfArmies = 30;
		break;
	case 5:
		numberOfArmies = 25;
		break;
	}

	for (int i = 0; i < numberOfPlayers; i++)
		vectorPlayers[i].updateReinforcementNumber(numberOfArmies);
}

void StartupPhase::loadMap(int mapChosen) // Loads the chosen map
{
	//currentMap = new MapIni(mapChosen);  //TODO STEVEN
}
