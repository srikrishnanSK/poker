
#include <iostream>
#include <time.h>
#include "Deck.h"
#include "Player.h"
#include "poker.h"

using namespace std;


int main() {
	int choice = -1, retv = 0;
	Poker poker;
	poker.init();
	while (choice == -1) {
		cout << "\nWelcome to simple Pocker!\n\nPlease choose accordingly from the provided menu support\n=====================================================================\n0 - To proceed to the table.\n"
			"1 - To read the rules.\n2 - quit\n";
		cin >> choice;
		cin.clear();
		cin.ignore('\n', 10);
		switch (choice) {
		case(0):
			choice = -1;
			while (choice == -1) {
				cout << "\nWelcome to the Table!\n\n";
				poker.first.displayschips();
				poker.second.displayschips();
				cout << "\n0 - to leave the table.\n"
					"1 - Enter the table\n";
				cin.clear();
				cin.ignore('\n', 10);
				switch (choice) {
				case(0):
					break;
				case(1):
					if (!poker.theEnd()) {
						poker.initgame();
						poker.deal();
						poker.roundbets();
						if (!poker.fold()) {
							poker.secondroundofdeals();
							poker.roundbets();
							if (!poker.fold()) {
								cout << "\nComparing hands right now!\n";
								poker.compare();
							}
						}
						poker.rewards();
					}
					else {
						cout << "ERROR : BOTH NOT HAVE ENOUGH MONEY TO PLAY\n\n";
					}
					break;
				default:
					cout << "\nERROR : INVALID ENTRY\n\n";
					break;
				}
				if (choice != 0)
					choice = -1;
			}
			break;
		case(1):
			cout << "\nThe game is called 5 card draw. 2 Players will start with a $10."
				"\nPlayers will then be dealt 5 cards each player are allowed to stay, or fold\n"
				"when offered by dealer the players are allowed to discard up to 3 cards and receive new cards from the dealer.\n"
				"With second another round of betting, and if either of the player has not folded, the player with the best hand will win\n";
			break;
		case(2):
			cout << "\nGOOD BYE\n\n";
			break;
		default:
			cout << "\nERROR : INVALID INPUT\n\n";
			break;
		}
		if (choice != 2)
			choice = -1;
	}
	return 0;
}
