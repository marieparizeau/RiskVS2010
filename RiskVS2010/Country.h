#pragma once
#include <string>
using namespace std;

class Country
{
public:
	Country();
	Country(string Name);
	~Country();

	string getName();
	void setName(string value);

	string getContinent();
	void setContinent(string value);

	int getArmySize();
	void addArmies(int numberToAdd);
	void removeArmies(int numberToRemove);

	string getOwner();
	void setOwner(string value);


private:
	string name;
	string continent;
	int armySize;
	string ownerName;
};

