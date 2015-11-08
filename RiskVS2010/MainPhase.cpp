#include "stdafx.h"
#include <iostream>

#include "MainPhase.h"
#include "Player.h"
#include "Country.h"

MainPhase::MainPhase() // Constructor
{
}

void MainPhase::reinforce(Player player) // Stub function - Reinforcement phase
{
	cout << "Player " << player.getPlayerNumber() << ": " << player.getPlayerName() << " -> Reinforcing countries !" << endl;
}

void MainPhase::attack(Player attacker) // Stub function - Attack phase
{
	bool moreAttacks = true;
	char attackConfirmation;

	cout << "Would you like to issue an attack? 'Y/y' for yes or 'N/n' for no: ";
	cin >> attackConfirmation;

	if (attackConfirmation == 'Y' || attackConfirmation == 'y')
		moreAttacks = true;
	else
		moreAttacks = false;

		// While loop, if the player wants to issue more attacks
		while (moreAttacks)
		{
			int attackerCountryNumber;
			cout << "Enter the number of the country you want to use to attack: ";
			cin >> attackerCountryNumber;

			int defenderPlayerNumber;
			cout << "Who do you want to attack? enter the player number: ";
			cin >> defenderPlayerNumber;

			int defenderCountryNumber;
			cout << "What country you want to attack? Enter the country number: ";
			cin >> defenderCountryNumber;

			char moreAttacksConfirmation;
			bool isWrongAnswer = true;

			// While loop, confirmation for more attacks
			while (isWrongAnswer)
			{
				cout << "\nWould you like to attack another country?\nEnter 'Y/y' for yes or 'N/n' for no: ";
				cin >> moreAttacksConfirmation;
				if (moreAttacksConfirmation == 'N' || moreAttacksConfirmation == 'n')
				{
					moreAttacks = false;
					isWrongAnswer = false;
				}
				else
					if (moreAttacksConfirmation == 'Y' || moreAttacksConfirmation == 'y')
					{
						moreAttacks = true;
						isWrongAnswer = false;
					}
					else
					{
						cout << "Wrong answer" << endl;
						isWrongAnswer = true;
					}
			}
		}
}

void MainPhase::fortification(Player player) // Stub function - Fortification phase
{
	cout << "Player " << player.getPlayerNumber() << ": " << player.getPlayerName() << " -> Fortifying countries !" << endl;
}