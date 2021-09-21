#pragma once
#include <iostream>
#include "Queue.h"
#include "Card.h"
#include <string>
#include "Deck.h"
#include "Stack.h"
#include <fstream>

using namespace std;

class GameBoard
{
private:
	Stack colOne;
	Stack colTwo;
	Stack colThree;
	Stack colFour;
	Stack colFive;
	Stack colSix;
	Stack colSeven;
	Stack swapStack;
	Stack sortedDiamond;
	Stack sortedHeart;
	Stack sortedClubs;
	Stack sortedSpade;
	Stack displayStack;
	Stack hand;
	int points;
	int flips;
	Deck deck;
	ofstream output;
public:
	GameBoard();
	int getPoints();
	void print();
	void fillHand();
	void displayHand();
	bool ValidMoveToBoard(int numberOne, char colorOne, int numberTwo, char colorTwo);
	void returnHandtoDeck();
	void displayBoard();
	void sortPileScore();
	void MOVEMASTER9000(char* n, int* i);
	void toSorted(string n);
	void checkFlips();
	void movingPilars(string n, char* flag, int* position);
	bool verifyExistance(Card w);
	void eraseExistance(Card w);
	void uncoverTop();
	void moveCards(string n, int o);
	bool checkScore();
	void closeOutfile();
	void printToOutfile(string n);
};
