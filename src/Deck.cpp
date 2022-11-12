#include "Deck.h"




void Deck::initDeck() {
	for (int i = 0; i < totalCardsInseck; i++) {
		//Card is a spade
		if (i < 13) {
			card* newCard = new card;
			newCard->value = i;
			newCard->face = 0;
			deck[i] = newCard;
		}
		//Card is a Clubs
		else if (i < 26) {
			card* newCard = new card;
			newCard->value = i - 13;
			newCard->face = 1;
			deck[i] = newCard;
		}
		//Card is a Diamonds
		else if (i < 39) {
			card* newCard = new card;
			newCard->value = i - 26;
			newCard->face = 2;
			deck[i] = newCard;
		}
		//Card is a Heart
		else {
			card* newCard = new card;
			newCard->value = i - 39;
			newCard->face = 3;
			deck[i] = newCard;
		}
	}
}



void Deck::randominitDeck() {
	srand(time(NULL));
	for (int i = 0; i < rand(); ++i){
		int randomIdx1 = (rand() + i) % 26 + 26;
		int randomIdx2 = (rand() + i) % 26;
		card* tempCard = deck[randomIdx1];
		deck[randomIdx1] = deck[randomIdx2];
		deck[randomIdx2] = deck[51];

		//Swapping
		deck[51] = deck[25];
		deck[25] = deck[0];
		deck[0] = tempCard;
	}
}

void Deck::showDeck() {
	for (int i = 0; i < totalCardsInseck; i++) {
		//Deck is a Spade
		if (deck[i]->face == 0) {
			if (deck[i]->value == 0)
				cout << "This card is an Ace of Hearts" << endl;
			else if (deck[i]->value == 10)
				cout << "This card is a Jack of Hearts" << endl;
			else if (deck[i]->value == 11)
				cout << "This card is a Queen of Hearts" << endl;
			else if (deck[i]->value == 12)
				cout << "This card is a King of Hearts" << endl;
			else
				cout << "This card is a " << deck[i]->value + 1 << " of Hearts" << endl;
		}
		//Deck is a Club
		if (deck[i]->face == 1) {
			if (deck[i]->value == 0)
				cout << "This card is an Ace of Diamonds" << endl;
			else if (deck[i]->value == 10)
				cout << "This card is a Jack of Diamonds" << endl;
			else if (deck[i]->value == 11)
				cout << "This card is a Queen of Diamonds" << endl;
			else if (deck[i]->value == 12)
				cout << "This card is a King of Diamonds" << endl;
			else
				cout << "This card is a " << deck[i]->value + 1 << " of Diamonds" << endl;
		}
		//Deck is a Diamond
		if (deck[i]->face == 2) {
			if (deck[i]->value == 0)
				cout << "This card is an Ace of Clubs" << endl;
			else if (deck[i]->value == 10)
				cout << "This card is a Jack of Clubs" << endl;
			else if (deck[i]->value == 11)
				cout << "This card is a Queen of Clubs" << endl;
			else if (deck[i]->value == 12)
				cout << "This card is a King of Clubs" << endl;
			else
				cout << "This card is a " << deck[i]->value + 1 << " of Clubs" << endl;
		}
		//Deck is a Heart
		if (deck[i]->face == 3) {
			if (deck[i]->value == 0)
				cout << "This card is an Ace of Spades" << endl;
			else if (deck[i]->value == 10)
				cout << "This card is a Jack of Spades" << endl;
			else if (deck[i]->value == 11)
				cout << "This card is a Queen of Spades" << endl;
			else if (deck[i]->value == 12)
				cout << "This card is a King of Spades" << endl;
			else
				cout << "This card is a " << deck[i]->value + 1 << " of Spades" << endl;
		}
	}
}

card* Deck::pop() {
	if (totalCardsInseck > 0) {
		card* topCard = deck[totalCardsInseck - 1];
		totalCardsInseck--;
		return topCard;
	}
}
