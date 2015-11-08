#include "stdafx.h"
#include "Country.h"
#include <string>

Country::Country() {}

Country::Country(string Name)
{
	armySize = 0;
	setName(name);
}


Country::~Country()
{
}

string Country::getName()
{
	return name;
}

void Country::setName(string value)
{
	name = value;
}

string Country::getContinent()
{
	return continent;
}

void Country::setContinent(string value)
{
	continent = value;
}

int Country::getArmySize()
{
	return armySize;
}

void Country::addArmies(int numberToAdd)
{
	armySize += numberToAdd;
}

void Country::removeArmies(int numberToRemove)
{
	if (armySize > 0)
		armySize -= numberToRemove;
}

string Country::getOwner()
{
	return ownerName;
}

void Country::setOwner(string value)
{
	ownerName = value;
}
