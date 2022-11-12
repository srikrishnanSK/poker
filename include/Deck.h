#pragma once
#include <iostream>
#include <time.h>
#include <string>

using namespace std;

struct card {
	int face;
	int value;
};

class Deck {
private:
	card* deck[52];
	int totalCardsInseck = 52;
public:
	void initDeck();
	void randominitDeck();
	void showDeck();
	card* pop();
};

