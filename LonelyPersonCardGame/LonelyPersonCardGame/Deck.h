/**
Name: Karl Pedroche
Date: 4/16/2020
File: Deck.h
Purpose: Header file for Deck Class
**/

#pragma once
#include <iostream>
#include "Queue.h"
#include "Card.h"
#include <string>

using namespace std;

class Deck
{
private:
	Queue deck;
public:
	Deck();
	Card getTopCard();
	void shuffle();
	void printDeck();
	void addCard(string n);
	void sortAscend();
	void sortDescend();
	int getSize();
	void getTail();
	void getHead();
	bool noMembers();
};