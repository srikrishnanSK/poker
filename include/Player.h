#pragma once
#include "Deck.h"

using namespace std;

class Player {
private:
	card* hand[5];
	int chips = 100;
	int cardsheldHand = 0;
	bool isPlaying = 0;
	int playerID = 0;
public:
	bool isFirst = 0;
	void setchips(int);
	void setPlayerID(int);
	int getPlayerID();
	void setIsPlayerPlaying(int);
	bool getIsPLayerPlaying();
	int getchips();
	void win(int);
	void receiveCard(card*);
	void swaptheCard(card*, int);
	void Bet(int);
	void displaycardsAtHand();
	void displayschips();
	int getCardValue(int);
	int getCardfaceValue(int);
};
