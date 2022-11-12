#pragma once
#include "Deck.h"
#include "Player.h"


class Poker {
private:
	int playersBet(Player*);
	void appendtoPot(Player*, int);
	void playercurrentBet(Player*, int);
	void PlayeStays(Player*, int);
	void firstPlayer();
	void newCards(Player*);
	void swapCrds(Player*, int);
	int getWinningValue(Player*);
	int getHighestValue(Player*);

public:
	Deck deck;
	Player first;
	Player second;
	int pot = 0;

	void init();
	void numberOrder(int*, int*, int*, int*, int*);
	void initgame();
	void deal();
	void roundbets();
	int fold();
	void secondroundofdeals();
	void compare();
	void rewards();
	int theEnd();
};
