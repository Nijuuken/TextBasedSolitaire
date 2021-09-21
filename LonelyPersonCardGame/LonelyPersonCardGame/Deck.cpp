/**
Name: Karl Pedroche
Date: 4/16/2020
File: Deck.Cpp
Purpose: Cpp file for Deck Class
**/
#include <iostream>
#include "Queue.h"
#include "Card.h"
#include "Deck.h"
using namespace std;

Deck::Deck()
{
	deck.enqueue(Card(), "AH");
	deck.enqueue(Card(), "2H");
	deck.enqueue(Card(), "3H");
	deck.enqueue(Card(), "4H");
	deck.enqueue(Card(), "5H");
	deck.enqueue(Card(), "6H");
	deck.enqueue(Card(), "7H");
	deck.enqueue(Card(), "8H");
	deck.enqueue(Card(), "9H");
	deck.enqueue(Card(), "10H");
	deck.enqueue(Card(), "JH");
	deck.enqueue(Card(), "QH");
	deck.enqueue(Card(), "KH");
	deck.enqueue(Card(), "AD");
	deck.enqueue(Card(), "2D");
	deck.enqueue(Card(), "3D");
	deck.enqueue(Card(), "4D");
	deck.enqueue(Card(), "5D");
	deck.enqueue(Card(), "6D");
	deck.enqueue(Card(), "7D");
	deck.enqueue(Card(), "8D");
	deck.enqueue(Card(), "9D");
	deck.enqueue(Card(), "10D");
	deck.enqueue(Card(), "JD");
	deck.enqueue(Card(), "QD");
	deck.enqueue(Card(), "KD");
	deck.enqueue(Card(), "AC");
	deck.enqueue(Card(), "2C");
	deck.enqueue(Card(), "3C");
	deck.enqueue(Card(), "4C");
	deck.enqueue(Card(), "5C");
	deck.enqueue(Card(), "6C");
	deck.enqueue(Card(), "7C");
	deck.enqueue(Card(), "8C");
	deck.enqueue(Card(), "9C");
	deck.enqueue(Card(), "10C");
	deck.enqueue(Card(), "JC");
	deck.enqueue(Card(), "QC");
	deck.enqueue(Card(), "KC");
	deck.enqueue(Card(), "AS");
	deck.enqueue(Card(), "2S");
	deck.enqueue(Card(), "3S");
	deck.enqueue(Card(), "4S");
	deck.enqueue(Card(), "5S");
	deck.enqueue(Card(), "6S");
	deck.enqueue(Card(), "7S");
	deck.enqueue(Card(), "8S");
	deck.enqueue(Card(), "9S");
	deck.enqueue(Card(), "10S");
	deck.enqueue(Card(), "JS");
	deck.enqueue(Card(), "QS");
	deck.enqueue(Card(), "KS");
}

//Desc: Lets other files access it's queue
//Pre: deck queue exists
//Post: head of deck is returned
Card Deck::getTopCard()
{
	Card temp = deck.dequeue();
	return temp;
}

//Desc: Shuffles deck
//Pre: deck exists and rand and <stdlib.h> <time.h> are included
//Post: Tells the queue to shuffle itself
void Deck::shuffle()
{
	cout << "Shuffling Deck" << endl;
	deck.shuffle();
}


//Desc: Prints out the deck
//Pre: deck exists
//Post: Deck is printed out
void Deck::printDeck()
{
	int size = deck.getSize();
	string type;
	Card temp;
	for (int o = 0; o <= size; o++)
	{
		if ((o % 15) == 0)
		{
			cout << endl;
		}
		temp = deck.dequeue();
		temp.flip();
		cout << temp.getType() << ", ";
		type = temp.getType();
		temp.flip();
		deck.enqueue(Card(), type);
		
	}
	cout << endl << endl;
}

//Desc: Adds to the deck
//Pre: deck exists and string is given
//Post: A new card is created and put into the deck queue
void Deck::addCard(string n)
{
	deck.enqueue(Card(), n);
}

//Desc: Sorts deck in ascending order
//Pre: deck exists
//Post: tells the deck to sort itself in ascending order
void Deck::sortAscend()
{
	cout << "Sorting Ascending Order" << endl;
	deck.sortAscend();
	printDeck();
}

//Desc: Sorts deck in descending order
//Pre: deck exists
//Post: tells the deck to sort itself in descending order
void Deck::sortDescend()
{
	cout << "Sorting Descending Order" << endl;
	deck.sortDescend();
	printDeck();
}


//Desc: gets the size of the deck
//Pre: deck exists
//Post: Deck asks the queue how big it is
int Deck::getSize()
{
	return deck.getSize() + 1;
}
//Desc: Gets the tail of the queue
//Pre: Queue exists
//Post: Card class of tail is printed out
void Deck::getTail()
{
	deck.getTail();
}

//Desc: Gets the head of the queue
//Pre: Queue exists
//Post: Card class of head is printed out
void Deck::getHead()
{
	deck.getHead();
}

//Desc: Lets other classess access it's queue's isEmpty() function
//Pre: Queue exists
//Post: gives bool statement if deck is empty
bool Deck::noMembers()
{
	return deck.isEmpty();
}
