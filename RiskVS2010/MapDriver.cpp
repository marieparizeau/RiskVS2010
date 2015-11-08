#include <iostream>
#include <map>
#include "Continent.h"
#include "TerritoryNode.h"
#include "World.h"
#include "MapIni.h"

using namespace std;

void createWorldFromMap(World& myWorld, MapIni* myMap);
void showWorldDetails(World& myWorld);

int main(int argc, char* argv[])
{
	cout << "RiskGame Map parser" << endl << endl;
	MapIni *myMap;
	myMap = new MapIni("..\\resources\\World.map");
	
	// create world
	World myWorld("Earth");
	createWorldFromMap(myWorld, myMap);
	delete myMap;

	// print world details
	showWorldDetails(myWorld);

	// get North America
	Continent* na = myWorld.getContinent("North America");
	if (na == NULL)
	{
		cout << "Could not find North America in the world." << endl;
	}

	// delete a territory from a continent
	cout << endl << "Deleting Quebec from North America" << endl;
	TerritoryNode* qc = na->removeTerritory("Quebec");
	// delete from the whole world
	myWorld.removeTerritory(qc);
	delete qc;

	// write new world to file
	cout << "Write modified world to file" << endl;
	MapIni::writeWorldToFile(myWorld, "..\\resources\\newWorld.map");

	cin.get();
	return EXIT_SUCCESS;
}

void createWorldFromMap(World& myWorld, MapIni* myMap)
{
	// retrieve info
	myWorld.setInfo(myMap->getMapInfo());
	map<string, TerritoryNode*> territories = myMap->getTerritories();
	map<string, list<string>> adjacency = myMap->getAdjacency();
	map<string, Continent*> continents = myMap->getContinents();

	// list territories and fill the world
	for (map<string, TerritoryNode*>::iterator it = territories.begin();it != territories.end(); ++it)
	{
		// add territory to world
		myWorld.addTerritory(it->second);
	}

	// assign adjacancy
	myWorld.addAdjacency(adjacency);

	// list continents and fill the world
	for (map<string, Continent*>::iterator it = continents.begin(); it != continents.end(); ++it)
	{
		// add continent to world
		myWorld.addContinent(it->second);
	}
}

void showWorldDetails(World& myWorld)
{
	// print included continents
	myWorld.print();
	cout << endl;

	// display continents info
	map<string, Continent*> continents = myWorld.getContinents();
	for (map<string, Continent*>::iterator it = continents.begin(); it != continents.end(); ++it)
	{
		it->second->print();

		// print territories details
		vector<TerritoryNode*> territories = it->second->getTerritories();
		for (vector<TerritoryNode*>::size_type i=0; i<territories.size(); i++)
		{
			territories[i]->print();
		}
		cout << endl;
	}
}
