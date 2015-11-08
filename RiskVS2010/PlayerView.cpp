#include "stdafx.h"
#include "PlayerView.h"
#include "Player.h"
#include <iostream>

using namespace std;

PlayerView::PlayerView()
{
};

PlayerView::PlayerView(Player* s)
{
	_subject = s;
	_subject->attach(this);
};

PlayerView::~PlayerView()
{
	_subject->detach(this);
};

void PlayerView::update()
{
	display();
};

void PlayerView::display()
{
	vector<Country*> listCountriesOwned = _subject->getListCountriesOwned();
	vector<Continent*> listContinentsOwned = _subject->getListContinentOwned();
	int currentNumberReinforcement = _subject->getReinforcementNumber();
	int totalNumberOfArmies = _subject->getArmiesNumber();
	int numberOfBattlesWon = _subject->getBattlesWonNumber();

	cout << "Player " << _subject->getPlayerNumber() << " - " << _subject->getPlayerName() << endl;

	cout << "Countries Owned:" << endl;
	for (int i = 0; i < listCountriesOwned.size(); i++)
		cout << listCountriesOwned[i]->getName() << ", ";
	cout << endl;

	cout << "Continent Owned: " << endl;
	for (int i = 0; i < listContinentsOwned.size(); i++)
		cout << listContinentsOwned[i]->getName() << ", ";
	cout << endl;

	cout << "Current Number of Reinforcement: " << currentNumberReinforcement << endl;
	cout << "Total Number of Armies: " << totalNumberOfArmies << endl;
	cout << "Number of Battles Won: " << numberOfBattlesWon << endl;
};
