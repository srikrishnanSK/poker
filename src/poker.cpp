#include <iostream>
#include <time.h>
#include "poker.h"
#include "Deck.h"
#include "Player.h"




void Poker::init() {
	first.setPlayerID(1);
	second.setPlayerID(2);
}

void Poker::initgame() {
	deck.initDeck();
	deck.randominitDeck();
	first.setIsPlayerPlaying(1);
	second.setIsPlayerPlaying(1);
	firstPlayer();
	appendtoPot(&first, 10);
	appendtoPot(&second, 10);
}

void Poker::firstPlayer() {
	if (first.isFirst == 0) {
		first.isFirst = 1;
		second.isFirst = 0;
	}
	else {
		first.isFirst = 0;
		second.isFirst = 1;
	}
}

void Poker::appendtoPot(Player* player, int amount) {
	player->Bet(amount);
	pot += amount;
}

void Poker::deal() {
	for (int i = 0; i < 5; i++) {
		if (first.isFirst){
			first.receiveCard(deck.pop());
			second.receiveCard(deck.pop());
		}
		else {
			second.receiveCard(deck.pop());
			first.receiveCard(deck.pop());
		}
	}
}


int Poker::playersBet(Player* player) {
	int selection = -1;
	if (first.getchips() == 0 || second.getchips() == 0) {
		cout << "\nCan not bet, insufficient chips.\n\n";
		return 0;
	}
	else {
		while (selection == -1) {
			cout << "\nPlayer " << player->getPlayerID() << ": do you want to fold or stay?\n\n"
				"Please enter '0' to bet, and '1' to fold, '2' for stay, or '3' to display cards at hand and chips.\n\n";
			cin >> selection;
			cin.clear();
			cin.ignore('\n', 10);
			//Player wants to bet
			if (selection == 0) {
				playercurrentBet(player, 0);
				return 0;
			}
			//Player wants to fold
			else if (selection == 1) {
				player->setIsPlayerPlaying(0);
				return 0;
			}
			//Player wants to stay
			else if (selection == 2) {
				return 1;
			}
			//Display hand
			else if (selection == 3) {
				player->displaycardsAtHand();
				player->displayschips();
				selection = -1;
			}
			else {
				cout << "\nERROR : INVALID ENTRY\n\n";
				selection = -1;
			}
		}
	}
}


void Poker::roundbets() {
	int betHasNotOccurred;
	if (first.isFirst) {
		betHasNotOccurred = playersBet(&first);
		if (betHasNotOccurred)
			playersBet(&second);
	}
	else {
		betHasNotOccurred = playersBet(&second);
		if (betHasNotOccurred)
			playersBet(&first);
	}
}

void Poker::PlayeStays(Player* player, int bet) {
	int selection = -1;
	while (selection == -1) {
		cout << "\nPlayer " << player->getPlayerID() << ": do you want to fold or stay?\n\n"
				"Please enter '0' to fole, and '1' to match the bet, '2' to raise, or '3' to display cards at hand and chips.\n\n";
		cin >> selection;
		cin.clear();
		cin.ignore('\n', 10);
		//Player folds
		if (selection == 0) {
			player->setIsPlayerPlaying(0);
		}
		//Player matches bet
		else if (selection == 1) {
			if (player->getchips() < bet) {
				cout << "\nERROR : INSUFFICIENT CHIPS\n\n";
				player->displayschips();
				selection = -1;
			}
			else {
				appendtoPot(player, bet);
			}
		}
		//Player raises bet
		else if (selection == 2) {
			if (player->getchips() <= bet) {
				cout << "\nERROR : INSUFFICIENT CHIPS\n\n";
				player->displayschips();
				selection = -1;
			}
			else {
				playercurrentBet(player, bet);
			}
		}
		else if (selection == 3) {
			player->displaycardsAtHand();
			player->displayschips();
			selection = -1;
		}
		//Invalid input
		else {
			cout << "\nERROR : INVALID ENTRY\n\n";
			selection = -1;
		}
	}
}

void Poker::playercurrentBet(Player* player, int previousBet) {
	int betAmount = 0;
	do {
		cout << "\nAmount to bet: ";
		cin >> betAmount;
		cin.clear();
		cin.ignore('\n', 10);
		//Not all players can afford the bet
		if ((betAmount - previousBet) > first.getchips() || (betAmount - previousBet) > second.getchips() || betAmount > player->getchips()) {
				cout << "\nERROR : bet not acceptable";
				second.displayschips();
				betAmount = 0;
		}
		else if (betAmount < 0)
			cout << "\nERROR : Bet must be more than 0.\n\n";
		else if (betAmount <= previousBet) {
			cout << "\nERROR : Bet must be more than previous bet. Previous bet was $" << previousBet << "\n\n";
			betAmount = 0;
		}
	} while (betAmount < 1);
	appendtoPot(player, betAmount);
	if (player->getPlayerID() == 1)
		PlayeStays(&second, betAmount - previousBet);
	else
		PlayeStays(&first, betAmount - previousBet);
}



int Poker::fold() {
	if (first.getIsPLayerPlaying() == 0 || second.getIsPLayerPlaying() == 0)
		return 1;
	return 0;
}

void Poker::secondroundofdeals() {
	if (first.isFirst) {
		newCards(&first);
		newCards(&second);
	}
	else {
		newCards(&second);
		newCards(&first);
	}
}
void Poker::swapCrds(Player* player, int numberOfCards) {
	int timesRan = 0;
	int card1 = 0;
	int card2 = 0;
	int card3 = 0;
	int selection = -1;
	while (timesRan < numberOfCards) {
		if (card1 == 0) {
			while (selection == -1) {
				player->displaycardsAtHand();
				cout << "\nEnter the card number to discard here, or  0 to display cards at hand and chips: ";
				cin >> selection;
				cin.clear();
				cin.ignore('\n', 10);
				if (selection >= 1 && selection <= 5)
					card1 = selection;
				else if (selection == 0) {
					player->displaycardsAtHand();
					player->displayschips();
					selection = -1;
				}
				else {
					cout << "\nERROR : INVALID ENTRY\n\n";
					selection = -1;
				}
			}
			++timesRan;
			selection = -1;
		}
		else {
			while (selection == -1) {
				player->displaycardsAtHand();
				cout << "Enter another card number to discard here: ";
				cin >> selection;
				cin.clear();
				cin.ignore('\n', 10);
				if (selection >= 1 && selection <= 5 && card1 != selection && card2 != selection) {
					if (card2 == 0)
						card2 = selection;
					else
						card3 = selection;
				}
				else {
					cout << "\nERROR : INVALID ENTRY\n\n";
					selection = -1;
				}
			}
			++timesRan;
			selection = -1;
		}
	}
	player->swaptheCard(deck.pop(), card1);
	if (card2 != 0)
		player->swaptheCard(deck.pop(), card2);
	if (card3 != 0)
		player->swaptheCard(deck.pop(), card3);
}

void Poker::newCards(Player* player) {
	int selection = -1;
	while (selection == -1) {
		cout << "\nPlayer " << player->getPlayerID() << ": Enter '0' to swap 0 cards, '1' to swap 1 card, "
			"'2' to swap 2 cards,\n'3' to swap 3 cards, or '4' to display hand and wallet\n\nPlease enter your selection here: ";
		cin >> selection;
		cin.clear();
		cin.ignore('\n', 10);
		if (selection == 1)
			swapCrds(player, 1);
		else if (selection == 2)
			swapCrds(player, 2);
		else if (selection == 3)
			swapCrds(player, 3);
		else if (selection == 4) {
			player->displaycardsAtHand();
			player->displayschips();
			selection = -1;
		}
		else if (selection != 0) {
			cout << "\nERROR : INVALID ENTRY\n\n";
			selection = -1;
		}
	}
}
void Poker::numberOrder(int* val1, int* val2, int* val3, int* val4, int* val5) {
	//While numbers are not sorted
	int temp;
	while (!(val1[0] <= val2[0]) || !(val2[0] <= val3[0]) || !(val3[0] <= val4[0]) || !(val4[0] <= val5[0])) {
		if (!(val1[0] <= val2[0])) {
			temp = val1[0];
			val1[0] = val2[0];
			val2[0] = temp;
		}
		if (!(val2[0] <= val3[0])) {
			temp = val2[0];
			val2[0] = val3[0];
			val3[0] = temp;
		}
		if (!(val3[0] <= val4[0])) {
			temp = val3[0];
			val3[0] = val4[0];
			val4[0] = temp;
		}
		if (!(val4[0] <= val5[0])) {
			temp = val4[0];
			val4[0] = val5[0];
			val5[0] = temp;
		}
	}
}


//If both players are still playing after this runs, it is a tie.
void Poker::compare() {
	int p1win = getWinningValue(&first);
	int p2win = getWinningValue(&first);
	if (p1win > p2win)
		second.setIsPlayerPlaying(0);
	else if (p2win > p1win) 
		first.setIsPlayerPlaying(0);
	else {
		p1win = getHighestValue(&first);
		p2win = getHighestValue(&second);
		if (p1win > p2win)
			second.setIsPlayerPlaying(0);
		else if (p2win > p1win)
			first.setIsPlayerPlaying(0);
	}
}

int Poker::getWinningValue(Player* player) {
	int winValue = 0;
	int card1Val = player->getCardValue(1);
	int card1Suit = player->getCardfaceValue(1);
	int card2Val = player->getCardValue(2);
	int card2Suit = player->getCardfaceValue(2);
	int card3Val = player->getCardValue(3);
	int card3Suit = player->getCardfaceValue(3);
	int card4Val = player->getCardValue(4);
	int card4Suit = player->getCardfaceValue(4);
	int card5Val = player->getCardValue(5);
	int card5Suit = player->getCardfaceValue(5);

	numberOrder(&card1Val, &card2Val, &card3Val, &card4Val, &card5Val);
	
	//Check for Flush(18), then for Straight Flush (21)
	if (card1Suit == card2Suit && card2Suit == card3Suit && card3Suit == card4Suit && card4Suit == card5Suit) {
		winValue = 18;
		if ((card1Val + 1) == card2Val && (card2Val + 1) == card3Val && (card3Val + 1) == card4Val && (card4Val + 1) == card5Val)
			winValue = 21;
	}

	//Check for Two of a kind(14), then Two pairs(15), then Three of a kind(16), then Full house(19), then Four of a kind(20)
	//Find pair
	else if (card1Val == card2Val) {
		if (card2Val == card3Val) {
			if (card4Val == card5Val)
				winValue = 19;
			else if (card3Val == card4Val)
				winValue = 20;
			else
				winValue = 16;
		}
		else if (card3Val == card4Val) {
			if (card4Val == card5Val)
				winValue = 19;
			else
				winValue = 15;
		}
		else if (card4Val == card5Val)
			winValue = 15;
		else
			winValue = 14;
	}
	else if (card2Val == card3Val) {
		if (card3Val == card4Val) {
			if (card4Val == card5Val)
				winValue = 20;
			else
				winValue = 16;
		}
		else if (card4Val == card5Val)
			winValue = 15;
		else
			winValue = 14;
	}
	else if (card3Val == card4Val) {
		if (card4Val == card5Val)
			winValue = 16;
		else
			winValue = 14;
	}
	else if (card4Val == card5Val)
		winValue = 14;
	
	//Check for Straight (17)
	else if ((card1Val + 1) == card2Val && (card2Val + 1) == card3Val && (card3Val + 1) == card4Val && (card4Val + 1) == card5Val)
		winValue = 17;

	//Check for High Card (0 = Ace, King = 12)
	else
		winValue = card5Val;

	return winValue;
}


int Poker::getHighestValue(Player* person) {
	int highValue = person->getCardValue(1);
	if (highValue < person->getCardValue(2))
		highValue = person->getCardValue(2);
	if (highValue < person->getCardValue(3))
		highValue = person->getCardValue(3);
	if (highValue < person->getCardValue(4))
		highValue = person->getCardValue(4);
	if (highValue < person->getCardValue(5))
		highValue = person->getCardValue(5);
	return highValue;
}

void Poker::rewards() {
	if (first.getIsPLayerPlaying() == 0) {
		second.win(pot);
		cout << "PFirst Player wins!\n\n";
		first.displayschips();
		second.displayschips();
		pot = 0;
	}
	else if (second.getIsPLayerPlaying() == 0) {
		first.win(pot);
		cout << "Second wins!\n\n";
		first.displayschips();
		second.displayschips();
		pot = 0;
	}
	else {
		cout << "Draw!\n\n";
		first.win(pot / 2);
		second.win(pot / 2);
		pot = 0;
	}
}

int Poker::theEnd() {
	if (first.getchips() < 10 || second.getchips() < 10)
		return 1;
	return 0;
}
