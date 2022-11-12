#include <iostream>
#include "Player.h"
#include "Deck.h"



void Player::setchips(int value) {
	chips = value;
}


void Player::receiveCard(card* newCard) {
	if (cardsheldHand < 5) {
		//Populating accordingly
		hand[cardsheldHand] = newCard;
		cardsheldHand++;
	}
}


void Player::swaptheCard(card* newCard, int discardedCardIndex) {
	delete hand[discardedCardIndex - 1];
	hand[discardedCardIndex - 1] = newCard;
}

void Player::displaycardsAtHand() {
	if (isPlaying) {
		cout<<"Player " << playerID <<"is playing:\n";
		for (int i = 0; i < cardsheldHand; i++) {
			cout << "Card " << i + 1 << ": ";
			//Spade
			if (hand[i]->face == 0) {
				if (hand[i]->value == 0)
					cout<<"This card is an Ace of Spade"<<endl;
				else if (hand[i]->value == 10)
					cout<<"This card is a Jack of Spade"<<endl;
				else if (hand[i]->value == 11)
					cout<<"This card is a Queen of Spade"<<endl;
				else if (hand[i]->value == 12)
					cout <<"This card is a King of Spade"<<endl;
				else
					cout<<"This card is a " << hand[i]->value + 1 << " of Spade"<<endl;
			}
			//Clubs
			if (hand[i]->face == 1) {
				if (hand[i]->value == 0)
					cout << "This card is an Ace of Clubs"<<endl;
				else if (hand[i]->value == 10)
					cout << "This card is a Jack of Clubs"<<endl;
				else if (hand[i]->value == 11)
					cout << "This card is a Queen of Clubs"<<endl;
				else if (hand[i]->value == 12)
					cout << "This card is a King of Clubs"<<endl;
				else
					cout << "This card is a " << hand[i]->value + 1 << " of Clubs" << endl;
			}
			//Diamond
			if (hand[i]->face == 2) {
				if (hand[i]->value == 0)
					cout<<"This card is an Ace of Diamond"<<endl;
				else if (hand[i]->value == 10)
					cout<<"This card is a Jack of Diamond"<<endl;
				else if (hand[i]->value == 11)
					cout<<"This card is a Queen of Diamond"<<endl;
				else if (hand[i]->value == 12)
					cout<<"This card is a King of Diamond"<<endl;
				else
					cout<<"This card is a " << hand[i]->value + 1 << " of Diamond" << endl;
			}
			//Club
			if (hand[i]->face == 3) {
				if (hand[i]->value == 0)
					cout<<"This card is an Ace of Club"<<endl;
				else if (hand[i]->value == 10)
					cout<<"This card is a Jack of Club"<<endl;
				else if (hand[i]->value == 11)
					cout<<"This card is a Queen of Club"<<endl;
				else if (hand[i]->value == 12)
					cout<<"This card is a King of Club"<<endl;
				else
					cout<<"This card is a " << hand[i]->value + 1 << " of Club" <<endl;
			}
		}
		cout << endl;
	}
}

void Player::Bet(int bet) {
	chips -= bet;
}

int Player::getchips() {
	return chips;
}

void Player::displayschips() {
	cout<< "Player " << playerID << " has $" << chips <<endl;
}

void Player::setPlayerID(int id) {
	playerID = id;
}

int Player::getPlayerID() {
	return playerID;
}

void Player::setIsPlayerPlaying(int val) {
	isPlaying = val;
}

bool Player::getIsPLayerPlaying() {
	return isPlaying;
}

void Player::win(int money) {
	chips += money;
}

int Player::getCardValue(int carValue) {
	return hand[carValue-1]->value;
}

int Player::getCardfaceValue(int cardfaceValue) {
	return hand[cardfaceValue-1]->face;
}
