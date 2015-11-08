#include "stdafx.h"
#include <string>
#include "Player.h"
#include "Country.h"

Player::Player() // Constructor
{
	this->name = "NO NAME";
	this->playerNumber = 0;
}

Player::Player(string name, int playerNumber) // Constructor with parameters
{
	this->name = name;
	this->playerNumber = playerNumber;
}

Player::~Player() // Deconstructor
{
}

void Player::removeCountryFromList(string name)
{
	//TODO STEVEN
}

void Player::addCountryToList(Country* country)
{
	country->addArmies(2);
	listCountriesOwned.push_back(country);
}

vector<Country*> Player::getCountriesThatCanAttack()
{
	vector<Country*> canAttack;

	for (Country* c : listCountriesOwned)
	{
		if (c->getArmySize() > 2)
			canAttack.push_back(c);
	}

	return canAttack;
}

string Player::getPlayerName() // Accessor function to get the player name
{
	return this->name;
}

void Player::setPlayerName(string name) // Mutator function to set the player name
{
	this->name = name;
}

int Player::getPlayerNumber() // Accessor function to get the player number
{
	return this->playerNumber;
}

void Player::setPlayerNumber(int number) // Mutator function to set the player number
{
	this->playerNumber = number;
}

void Player::updateListCountriesOwned()
{
	notify();
}

void Player::updateContinentOwned()
{
	notify();
}

void Player::updateReinforcementNumber(int armies)
{
	this->currentNumberReinforcement = armies;
	updateArmiesNumber(armies);
	notify();
}

void Player::updateArmiesNumber(int armies)
{
	this->totalNumberOfArmies += armies;
	notify();
}

void Player::updateBattlesWonNumber()
{
	notify();
}
