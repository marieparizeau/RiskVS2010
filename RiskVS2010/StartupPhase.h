#ifndef STARTUPPHASE_H
#define STARTUPPHASE_H

#include "Player.h"
#include "MapIni.h"

// Startup phase object
class StartupPhase
{
public:
	StartupPhase(); // Constructor
	vector<Player> asksPlayersNames(); // Function that asks for the players name
	void assignCountryRandomly(vector<Player> vectorPlayers); // Function that assigns randomly countries to players
	void giveOutInitialArmies(vector<Player> vectorPlayers); // Function that give out the initial armies to every players
	void loadMap(int mapChosen); // Function that loads the chosen map

private:
	MapIni* currentMap;
};
#endif
