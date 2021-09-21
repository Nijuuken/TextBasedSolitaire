/**
Name: Karl Pedroche
Date: 4/16/2020
File: Card.h
Purpose: Header file for Card Class
**/

#pragma once
#include <iostream>
#include <string>
using namespace std;

class Card
{
private: 
	string cardType;
	bool faceUp;
public:
	Card();
	void flip();
	char getSuite();
	char getColor();
	void show();
	int getValue();
	string getType();
	void setType(string n);
};