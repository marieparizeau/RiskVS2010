#ifndef MAINPHASE_H
#define MAINPHASE_H

#include "Player.h"
#include "Country.h"

// Main phase object
class MainPhase
{
public:
	MainPhase(); // Constructor
	void reinforce(Player player); // Reinformence phase
	void attack(Player player); // Attack phase
	void fortification(Player player); // Fortificition phase

private:

};

#endif