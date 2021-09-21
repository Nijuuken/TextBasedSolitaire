/**
Name: Karl Pedroche
Date: 4/16/2020
File: Card.cpp
Purpose: Cpp file for Card class
**/
#include <iostream>
#include "Card.h"
#include <string>

using namespace std;

Card::Card()
{
	faceUp = false;
}

//Desc: Sets the card type
//Pre: Given String
//Post: cardType is set to given string
void Card::setType(string n)
{
	cardType = n;
 }

//Desc: Forces the card to go face Ups
//Pre: Nothing
//Post: Card is face up
void Card::show()
{
	faceUp = true;
}

//Desc: returns the type of card it is
//Pre: Card exists
//Post: If card is face down, "?" is returned, otherwise it returns its cardtype
string Card::getType()
{
	if (faceUp == false) return "?";
	return cardType;
}

//Desc: Flips the card
//Pre: Card exists
///Post If card is face up, it is flipped face down and vice versa
void Card::flip()
{
	if (faceUp == false)
	{
		faceUp = true;
		return;
	}
	else
	{
		faceUp = false;
		return;
	}
}

//Desc: Gets Suite of card
//Pre: cardtype exists
//Post: A char is returned
char  Card::getSuite()
{
	return cardType[cardType.length()-1];
}
char Card::getColor()
{
	if (getSuite() == 'C' || getSuite() == 'S')
	{
		return 'b';
	}
	if (getSuite() == 'D' || getSuite() == 'H')
	{
		return 'r';
	}
	throw 4;
}

//Desc: Gets numeral value of card
//Pre: cardType exists
//Post: returns a number based on number or if it was a king, queen, jack, or ace.
int Card::getValue()
{

	if (cardType[0] == 'K') { return 13; }//If Card is an King, number 13 is returned

	if (cardType[0] == 'Q') { return 12; } //If Card is an Queen, number 12 is returned

	if (cardType[0] == 'J') {return 11;} //If Card is an Jack, number 11 is returned
	
	if (cardType[0] == 'A') { return 1; } //If Card is an Ace, number 1 is returned
	string number = "";
	for (int i = 0; i < cardType.length()-1; i++)
	{
		number += (cardType[i]);
	}
	return stoi(number);
}