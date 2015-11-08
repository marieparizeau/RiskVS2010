#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>

#include "Country.h"
#include "Continent.h"
#include "Subject.h"

using namespace std;

// Player object
class Player : public Subject
{
public:
	Player(); // Constructor
	Player(string name, int playerNumber); // Constructor with parameters
	~Player(); // Deconstructor
	string getPlayerName(); // Accessor function to get the player name
	void setPlayerName(string name); // Mutator function to set the player name
	int getPlayerNumber(); // Accessor function to get the player number
	void setPlayerNumber(int number); // Mutator function to set the player number

	void removeCountryFromList(string name);
	void addCountryToList(Country* country);

	void updateListCountriesOwned();
	void updateContinentOwned();
	void updateReinforcementNumber(int armies);
	void updateArmiesNumber(int armies);
	void updateBattlesWonNumber();
	
	vector<Country*> getCountriesThatCanAttack();

	vector<Country*> getListCountriesOwned() { return listCountriesOwned; };
	vector<Continent*> getListContinentOwned() { return listContinentsOwned; };
	int getReinforcementNumber() { return currentNumberReinforcement; };
	int getArmiesNumber() { return totalNumberOfArmies; };
	int getBattlesWonNumber() { return numberOfBattlesWon; };

private:
	string name; // Player name
	int playerNumber; // Player number

	vector<Country*> listCountriesOwned; // list containing the countries owned by the player
	vector<Continent*> listContinentsOwned; // list containing the continent owned by the player
	int currentNumberReinforcement; // Current number of reinforcement given
	int totalNumberOfArmies;  // Total number of armies of the player
	int numberOfBattlesWon;	// Total number of battles won
};
#endif