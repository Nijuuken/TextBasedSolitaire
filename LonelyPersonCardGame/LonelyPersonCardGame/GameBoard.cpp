#include <iostream>
#include "Queue.h"
#include "Card.h"
#include <string>
#include "Deck.h"
#include "Stack.h"
#include "GameBoard.h"
#include <iomanip>
#include "NullException.h"
#include "gameOver.h"
#include "InvalidMoveException.h"

using namespace std;

GameBoard::GameBoard()
{
	Card throwaway;
	output.open("cis200Solitaire.txt");
	throwaway.setType("AD");
	points = 0;
	flips = 0;
	deck.printDeck();
	//deck.getTail();
	//deck.getHead();

	deck.sortAscend();
	//deck.getTail();
	//deck.getHead();

	deck.sortDescend();
	//deck.getTail();
	//deck.getHead();

	//Uncomment this to randomize the deck
	deck.shuffle();
	colOne.push(deck.getTopCard());
	colTwo.push(deck.getTopCard());
	colTwo.push(deck.getTopCard());
	
	colThree.push(deck.getTopCard());
	colThree.push(deck.getTopCard());
	colThree.push(deck.getTopCard());
	
	colFour.push(deck.getTopCard());
	colFour.push(deck.getTopCard());
	colFour.push(deck.getTopCard());
	colFour.push(deck.getTopCard());
	
	colFive.push(deck.getTopCard());
	colFive.push(deck.getTopCard());
	colFive.push(deck.getTopCard());
	colFive.push(deck.getTopCard());
	colFive.push(deck.getTopCard());
	
	colSix.push(deck.getTopCard());
	colSix.push(deck.getTopCard());
	colSix.push(deck.getTopCard());
	colSix.push(deck.getTopCard());
	colSix.push(deck.getTopCard());
	colSix.push(deck.getTopCard());	
	colSeven.push(deck.getTopCard());
	colSeven.push(deck.getTopCard());
	colSeven.push(deck.getTopCard());
	colSeven.push(deck.getTopCard());
	colSeven.push(deck.getTopCard());
	colSeven.push(deck.getTopCard());
	colSeven.push(deck.getTopCard());

	colOne.reveal();
	colTwo.reveal();
	colThree.reveal();
	colFour.reveal();
	colFive.reveal();
	colSix.reveal();
	colSeven.reveal();
	//deck.printDeck();
	//deck.getTail();
	//deck.getHead();
};

//Desc: Closes output file
//outfile was already created and atattched to a txt file
//detatches pointer from txt file
void GameBoard::closeOutfile()
{
	output.close();
}

//Desc: Prints out the cards
//Pre:  column stacks are initialized
//Post: cards are printed out
void GameBoard::print()
{
	int biggestColumn = 0;
	biggestColumn = colOne.getSize();
	if (colTwo.getSize() > biggestColumn) biggestColumn = colTwo.getSize();
	if (colThree.getSize() > biggestColumn) biggestColumn = colThree.getSize();
	if (colFour.getSize() > biggestColumn) biggestColumn = colFour.getSize();
	if (colFive.getSize() > biggestColumn) biggestColumn = colFive.getSize();
	if (colSix.getSize() > biggestColumn) biggestColumn = colSix.getSize();
	if (colSeven.getSize() > biggestColumn) biggestColumn = colSeven.getSize();
	cout << setw(6) << "   P 1:" << setw(2) << colOne.displayRow(0) << setw(6) << "   P 2:" << setw(2) << colTwo.displayRow(0);
	cout << setw(6) << "   P 3:" << setw(2) << colThree.displayRow(0) << setw(6) << "   P 4:" << setw(2) << colFour.displayRow(0);
	cout << setw(6) << "   P 5:" << setw(2) << colFive.displayRow(0) << setw(6) << "   P 6:" << setw(2) << colSix.displayRow(0);
	cout << setw(6) << "   P 7:" << setw(2) << colSeven.displayRow(0) << endl;
	for (int i = 1; i < biggestColumn + 1; i++)
	{
		cout << setw(9) << colOne.displayRow(i) << setw(9) << colTwo.displayRow(i);
		cout << setw(9) << colThree.displayRow(i) << setw(9) << colFour.displayRow(i);
		cout << setw(9) << colFive.displayRow(i) << setw(9) << colSix.displayRow(i);
		cout << setw(9) << colSeven.displayRow(i) << endl;
	}
}

//Desc: Puts discard pile back into deck
//Pre: deck and hand exosts. Deck also has to be empty 
//Post: All cards from discarded is put into the deck
void GameBoard::checkFlips()
{
	if (deck.noMembers() && hand.isEmpty())
	{
		output << "Both deck and discard pile is empty" << endl;
		cout << "There are no Cards to put back into the deck" << endl;
		throw NullException();
	}
	output << "There are no more cards in the deck" << endl;
	output << "Putting cards in discard pile back into deck" << endl;
	cout << "There are no more cards in the deck" << endl;
	cout << " Putting cards in discard pile back into deck" << endl;
	int deckSize = hand.getSize();
	Card temp;
	for (int i = 0; i < deckSize; i++)
	{
		temp = hand.pop();
		deck.addCard(temp.getType());
	}
	flips++;
	output << "Number of Flips: " << flips << endl;

	if (flips == 3)
		throw gameOver();
}

//Desc: Prints out sorted pile score
//Pre: Sorted Piles exist
//Post: Sorted Piles are printed out
void GameBoard::sortPileScore()
{
		cout << " Diamond Pile: " << setw(2) << sortedDiamond.getSize() << setw(2) << " Heart Pile: " << setw(2) << sortedHeart.getSize() << setw(2);
		cout << " Clubs Pile: " << setw(2) << sortedClubs.getSize() << setw(2) << " Spade Pile: " << setw(2) << sortedSpade.getSize()<< endl;
}

//Desc: gets game points
//Pre: points exist
//Post: game points returned
int GameBoard::getPoints()
{
	return points;
}

//Desc: Fills the hand (Discard Pile) in 3 card intervals
//Pre: Hand stack and deck queue exists and is filled
//Post: 3 card classes from the deck are put into the Hand (Discard pile)
//		if there are none, discard pile is returned to the deck and "flips" go up by one
void GameBoard::fillHand()
{
	Card temp;
	if (deck.noMembers() == true)
	{
		checkFlips();
	}
	int numberOfCards = deck.getSize();
	//deck.getTail();
	//deck.getHead();

	if (numberOfCards > 3)
	{
		for (int i = 0; i < 3; i++)
		{
			temp = deck.getTopCard();
			temp.flip();
			hand.push(temp);
		}
		output << "Getting 3 cards from the deck" << endl;
	}
	else
	{
		for (int i = 0; i < numberOfCards; i++)
		{
			temp = deck.getTopCard();
			temp.flip();
			hand.push(temp);
		}
		output << "Getting "<<numberOfCards <<" cards from the deck" << endl;
	}
}

//Desc: Prints out the cards in your hand
//Pre: Hand stack exists
//Post: Prints out cards in your hand, if any
void GameBoard::displayHand()
{
	cout << "Discard Pile:" << endl;
	try
	{
		cout << "[ ";
		 cout << hand.peek().getType();
		cout << " ]";
	}
	catch(NullException)
	{
		cout << "Your Hand is empty! ]" << endl;
	}
}

//Desc: The Game Board of this Program
//Pre: dispSortPile(), print(), and displayHand() exist
//Post: All of the methods above are executed
void GameBoard::displayBoard()
{
	cout << "===================================================================" << endl;
	cout << setw(100) << "Gabriel's Solitaire" << endl;
	sortPileScore();
	print();
	displayHand();
}

//Desc: Returns Cards in Hand to Deck
//Pre: Hand stack and deck queue exist with cards in them
// Post: Hand stack contents is emptied to deck queue
void GameBoard::returnHandtoDeck()
{
	Card temp;
	for (int i = 0; i < hand.getSize(); i++)
	{
		temp = hand.pop();
		deck.addCard(temp.getType());
	}
}

//Desc: Checks if imaginary card exists withing the game
//Pre: given hypothetical card, and all the stacks exist
//Post: If "real" version of imaginary card isn't found false is returned
bool GameBoard::verifyExistance(Card w)
{
	if (hand.isEmpty() == false && hand.peek().getType() == w.getType())
	{
		return true;
	}
	if (colOne.isEmpty() == false && colOne.peek().getType() == w.getType())
	{
		return true;
	}
	if (colTwo.isEmpty() == false && colTwo.peek().getType() == w.getType())
	{
		return true;
	}
	if (colThree.isEmpty() == false && colThree.peek().getType() == w.getType())
	{
		return true;
	}
	if (colFour.isEmpty() == false && colFour.peek().getType() == w.getType())
	{
		return true;
	}
	if (colFive.isEmpty() == false && colFive.peek().getType() == w.getType())
	{
		return true;
	}
	if (colSix.isEmpty() == false && colSix.peek().getType() == w.getType())
	{
		return true;
	}
	if (colSeven.isEmpty() == false && colSeven.peek().getType() == w.getType())
	{
		return true;
	}
	return false;
}


//Desc: The imaginary card took the real one's place and now it's out to kill i-
//Pre: imaginary card already found it's "real" counterpart within the stacks
//Post: The copy inside any one of the stacks is removed
void GameBoard::eraseExistance(Card w)
{
	Card arsNova;

	if (hand.isEmpty() == false && hand.peek().getType() == w.getType())
	{
		arsNova = hand.pop();
	}
	if (colOne.isEmpty() == false && colOne.peek().getType() == w.getType())
	{
		arsNova = colOne.pop();
	}
	if (colTwo.isEmpty() == false && colTwo.peek().getType() == w.getType())
	{
		arsNova = colTwo.pop();
	}
	if (colThree.isEmpty() == false && colThree.peek().getType() == w.getType())
	{
		arsNova = colThree.pop();
	}
	if (colFour.isEmpty() == false && colFour.peek().getType() == w.getType())
	{
		arsNova = colFour.pop();
	}
	if (colFive.isEmpty() == false && colFive.peek().getType() == w.getType())
	{
		arsNova = colFive.pop();
	}
	if (colSeven.isEmpty() == false && colSix.peek().getType() == w.getType())
	{
		arsNova = colSix.pop();
	}
	if (colSeven.isEmpty() == false && colSeven.peek().getType() == w.getType())
	{
		arsNova = colSeven.pop();
	}
}

//Desc: User tries to put a card into the sorted pile
//Pre: given a string and all 7 game stacks and discard stack exist
//Post: If no card matched the string or if no card can go into the sorted piles, an exception is thrown. 
//	Else, the card will go into its respective pilr 
void GameBoard::toSorted(string o)
{
	Card temp;
	temp.setType(o);
	temp.flip();
	if (verifyExistance(temp) == false)
	{
		throw InvalidMoveException();
	}
	char n = temp.getSuite();
	switch (n)
	{
	case 'D': //If card in hand is a diamond
	{
		if (sortedDiamond.getSize() == 0)
		{
			if (temp.getValue() == 1)
			{
				output << "Putting " << temp.getType() << " into the sorted Diamond Pile" << endl;
				cout << "The " << temp.getType() << " went to the sorted Diamond Pile" << endl;
				sortedDiamond.push(temp);
				points += 10; 
				eraseExistance(temp);
				uncoverTop();
				return;
			}
			throw InvalidMoveException();
		}
		else
		{
			if (temp.getValue() == (sortedDiamond.peek().getValue() + 1))
			{
				output << "Putting " << temp.getType() << " into the sorted Diamond Pile" << endl;
				cout << "The " << temp.getType() << " went to the sorted Diamond Pile" << endl;
				sortedDiamond.push(temp);
				points += 10; 
				eraseExistance(temp);
				uncoverTop();
				return;
			}
			throw InvalidMoveException();
		}
		break;
	}
	case 'H'://If card in hand is a heart
	{
		if (sortedHeart.getSize() == 0)
		{
			if (temp.getValue() == 1)
			{
				output << "Putting " << temp.getType() << " into the sorted Heart Pile" << endl;
				cout << "The " << temp.getType() << " went to the sorted Heart Pile" << endl;
				sortedHeart.push(temp);
				points += 10; 
				eraseExistance(temp);
				uncoverTop();
				return;
			}
			throw InvalidMoveException();
		}
		else
		{
			if (temp.getValue() == (sortedHeart.peek().getValue() + 1))
			{
				output << "Putting " << temp.getType() << " into the sorted Heart Pile" << endl;
				cout << "The " << temp.getType() << " went to the sorted Heart Pile" << endl;
				sortedHeart.push(temp);
				points += 10;
				eraseExistance(temp);
				uncoverTop();
				return;
			}
			throw InvalidMoveException();
		}
		break;
	}
	case 'C'://If card in hand is a club
	{
		if (sortedClubs.getSize() == 0)
		{
			if (temp.getValue() == 1)
			{
				output << "Putting " << temp.getType() << " into the sorted Clubs Pile" << endl;
				cout << "The " << temp.getType() << " went to the sorted Clubs Pile" << endl;
				sortedClubs.push(temp);
				points += 10; 
				eraseExistance(temp);
				uncoverTop();
				return;
			}
			throw InvalidMoveException();
		}
		else
		{
			if (temp.getValue() == (sortedClubs.peek().getValue() + 1))
			{
				output << "Putting " << temp.getType() << " into the sorted Clubs Pile" << endl;
				cout << "The " << temp.getType() << " went to the sorted Clubs Pile" << endl;
				sortedClubs.push(temp);
				points += 10; 
				eraseExistance(temp);
				uncoverTop();
				return;
			}
			throw InvalidMoveException();
		}
		break;
	}
	case 'S'://If card in hand is a spade
	{
		if (sortedSpade.getSize() == 0)
		{
			if (temp.getValue() == 1)
			{
				output << "Putting " << temp.getType() << " into the sorted Spade Pile" << endl;
				cout << "The " << temp.getType() << " went to the sorted Spade Pile" << endl;
				sortedSpade.push(temp);
				points += 10; 
				eraseExistance(temp);
				uncoverTop();
				return;
			}
			throw InvalidMoveException();
		}
		else
		{
			if (temp.getValue() == (sortedSpade.peek().getValue() + 1))
			{
				output << "Putting " << temp.getType() << " into the sorted Spade Pile" << endl;
				cout << "The " << temp.getType() << " went to the sorted Spade Pile" << endl;
				sortedSpade.push(temp);
				points += 10; 
				eraseExistance(temp);
				uncoverTop();
				return;
			}
			throw InvalidMoveException();
		}
		break;
	}
	throw InvalidMoveException();
	}
}

bool GameBoard::checkScore()
{
	if (points == 560)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Desc: Unflips any facedown cards that are on the surface
//Pre: the 2 game stacks exist
//Post: All the topmost cards are revealed if they werent previously
void GameBoard::uncoverTop()
{
	if (colOne.isEmpty() != true) colOne.reveal();
	if (colTwo.isEmpty() != true)colTwo.reveal();
	if (colThree.isEmpty() != true)colThree.reveal();
	if (colFour.isEmpty() != true)colFour.reveal();
	if (colFive.isEmpty() != true)colFive.reveal();
	if (colSix.isEmpty() != true)colSix.reveal();
	if (colSeven.isEmpty() != true)colSeven.reveal();
}

//Desc: Checks if movement to board is valid
//Pre: Both columns exist with cards in them
//Post: If opposite colors and number One is 1 less than number Two, true is returned; otherwise false is.
bool GameBoard::ValidMoveToBoard(int numberOne, char colorOne, int numberTwo, char colorTwo)
{
	if (colorOne != colorTwo && numberOne == numberTwo - 1)
	{
		return true;
	}
	else
	{
		if (colorOne == colorTwo) cout << "They're the same color" << endl;
		if (numberOne == numberTwo - 1) cout << numberOne <<" isn't one less than " << numberTwo << endl;
		return false;
	}
}

//Desc: Find the location of a given cardType within the stacks
//Pre: given a string, char, and depth, hand(discard), and 7 other stacks exist
//Post: flag and position is set to find the cardType from given string
void GameBoard::movingPilars(string n, char* flag, int* position)
{
	while (true)
	{
		if (hand.findCard(n, position) == true)
		{
			*flag = 'd';
			break;
		}
		*position = 0;
		if (colOne.findCard(n, position) == true)
		{
			*flag = '1';
			break;
		}
		*position = 0;
		if (colTwo.findCard(n, position) == true)
		{
			*flag = '2';
			break;
		}
		*position = 0;
		if (colThree.findCard(n, position) == true)
		{
			*flag = '3';
			break;
		}
		*position = 0;
		if (colFour.findCard(n, position) == true)
		{
			*flag = '4';
			break;
		}
		*position = 0;
		if (colFive.findCard(n, position) == true)
		{
			*flag = '5';
			break;
		}
		*position = 0;
		if (colSix.findCard(n, position) == true)
		{
			*flag = '6';
			break;
		}
		*position = 0;
		if (colSeven.findCard(n, position) == true)
		{
			*flag = '7';
			break;
		}
		throw InvalidMoveException();
	}
	
}

//Desc: Take coordinates from movingPillars and take a depth ammount of cards from the flagged stack
//Pre: flag and depth given from movingPillars
//Post: swapStack is loaded with cards
void GameBoard::MOVEMASTER9000(char* flag, int* depth)
{

	switch (*flag)
	{
	case 'd':
	{
		for (int i = 0; i < *depth; i++)
		{
			swapStack.push(hand.pop());
		}
		break;
	}
	case '1':
	{
		for (int i = 0; i < *depth; i++)
		{
			swapStack.push(colOne.pop());
		}
		break;
	}
	case '2':
	{
		for (int i = 0; i < *depth; i++)
		{
			swapStack.push(colTwo.pop());
		}
		break;
	}
	case '3':
	{
		for (int i = 0; i < *depth; i++)
		{
			swapStack.push(colThree.pop());
		}
		break;
	}
	case '4':
	{
		for (int i = 0; i < *depth; i++)
		{
			swapStack.push(colFour.pop());

		}
		break;
	}
	case '5':
	{

		for (int i = 0; i < *depth; i++)
		{
			swapStack.push(colFive.pop());
		}
		break;
	}
	case '6':
	{
		for (int i = 0; i < *depth; i++)
		{
			swapStack.push(colSix.pop());
		}
		break;
	}
	case '7':
	{
		for (int i = 0; i < *depth; i++)
		{
			swapStack.push(colSeven.pop());
		}
		break;
	}

	}
}

//Desc: given a cardType and column, find if cardType exists and if movement to selected column is legal
//Pre: given string, int, and the 8 stacks
//Post: swap or even move columns of cards to given column
void GameBoard::moveCards(string n, int position)
{
	position = position - 1;
	char flag = 'l';
	int someNumber = 0;
	int deep = 0;
	int stackSize = 0;
	Card newCard;
	newCard.setType(n);
	newCard.flip();
	movingPilars(n, &flag, &deep);
	switch (position)
	{
	case 0:
	{
		if ((int)flag == position)
		{
			cout << "This is the same position " << n << " is at!" << endl;
		}
		else
		{
			//If chosen card is a king and you want to move it to an empty column
			if (newCard.getValue() == 13 && colOne.isEmpty())
			{
				MOVEMASTER9000(&flag, &deep);
				stackSize = swapStack.getSize();
				output << "Placing ";
				output << swapStack.peek().getType();
				output << " and any other cards on top of it into column " << position + 1 << endl;
				for (int i = 0; i < stackSize; i++)
				{
					cout << "Card " << swapStack.peek().getType() << " is placed into column 1" << endl;
					colOne.push(swapStack.pop());
					uncoverTop();
					
				}
				return;
			}
			if (colOne.isEmpty())
			{
				throw InvalidMoveException();
			}
			if (ValidMoveToBoard(newCard.getValue(), newCard.getColor(), colOne.peek().getValue(), colOne.peek().getColor()) == true)
			{
				MOVEMASTER9000(&flag, &deep);
				stackSize = swapStack.getSize();
				output << "Placing ";
				output << swapStack.peek().getType();
				output << " and any other cards on top of it into column " << position + 1 << endl;
				for (int i = 0; i < stackSize; i++)
				{
					cout << "Card " << swapStack.peek().getType() << " is placed into column 1" << endl;
					colOne.push(swapStack.pop());
					uncoverTop();
				}
				return;
			}
			else
			{
				throw InvalidMoveException();
			}
		}
		break;
	}
	case 1:
	{
		if ((int)flag == position)
		{
			cout << "This is the same position " << n << " is at!" << endl;
		}
		else
		{
			//If chosen card is a king and you want to move it to an empty column
			if (newCard.getValue() == 13 && colTwo.isEmpty())
			{
				MOVEMASTER9000(&flag, &deep);
				stackSize = swapStack.getSize();
				output << "Placing ";
				output << swapStack.peek().getType();
				output << " and any other cards on top of it into column " << position + 1 << endl;
				for (int i = 0; i < stackSize; i++)
				{
					cout << "Card " << swapStack.peek().getType() << " is placed into column 2" << endl;
					colTwo.push(swapStack.pop());
					uncoverTop();
					
				}
				return;
			}
			if (colTwo.isEmpty())
			{
				throw InvalidMoveException();
			}
			if (ValidMoveToBoard(newCard.getValue(), newCard.getColor(), colTwo.peek().getValue(), colTwo.peek().getColor()) == true)
			{
				MOVEMASTER9000(&flag, &deep);
				stackSize = swapStack.getSize();
				output << "Placing ";
				output << swapStack.peek().getType();
				output << " and any other cards on top of it into column " << position + 1 << endl;
				for (int i = 0; i < stackSize; i++)
				{
					cout << "Card " << swapStack.peek().getType() << " is placed into column 2" << endl;
					colTwo.push(swapStack.pop());
					uncoverTop();
					
				}
				return;
			}
			else
			{
				throw InvalidMoveException();
			}
		}
		break;
	}
	case 2:
	{
		if ((int)flag == position)
		{
			cout << "This is the same position " << n << " is at!" << endl;
		}
		else
		{
			//If chosen card is a king and you want to move it to an empty column
			if (newCard.getValue() == 13 && colThree.isEmpty())
			{
				MOVEMASTER9000(&flag, &deep);
				stackSize = swapStack.getSize();
				output << "Placing ";
				output << swapStack.peek().getType();
				output << " and any other cards on top of it into column " << position + 1 << endl;
				for (int i = 0; i < stackSize; i++)
				{
					cout << "Card " << swapStack.peek().getType() << " is placed into column 3" << endl;
					colThree.push(swapStack.pop());
					uncoverTop();
					
				}
				return;
			}
			if (colThree.isEmpty())
			{
				throw InvalidMoveException();
			}
			if (ValidMoveToBoard(newCard.getValue(), newCard.getColor(), colThree.peek().getValue(), colThree.peek().getColor()) == true)
			{
				MOVEMASTER9000(&flag, &deep);
				stackSize = swapStack.getSize();
				output << "Placing ";
				output << swapStack.peek().getType();
				output << " and any other cards on top of it into column " << position + 1 << endl;
				for (int i = 0; i < stackSize; i++)
				{
					cout << "Card " << swapStack.peek().getType() << " is placed into column 3" << endl;
					colThree.push(swapStack.pop());
					uncoverTop();
					
				}
				return;
			}
			else
			{
				throw InvalidMoveException();
			}
		}
		break;
	}
	case 3:
	{
		if ((int)flag == position)
		{
			cout << "This is the same position " << n << " is at!" << endl;
		}
		else
		{
			//If chosen card is a king and you want to move it to an empty column
			if (newCard.getValue() == 13 && colFour.isEmpty())
			{
				MOVEMASTER9000(&flag, &deep);
				stackSize = swapStack.getSize();
				output << "Placing ";
				output << swapStack.peek().getType();
				output << " and any other cards on top of it into column " << position + 1 << endl;
				for (int i = 0; i < stackSize; i++)
				{
					cout << "Card " << swapStack.peek().getType() << " is placed into column 4" << endl;
					colFour.push(swapStack.pop());
					uncoverTop();
					
				}
				return;
			}
			if (colFour.isEmpty())
			{
				throw InvalidMoveException();
			}
			if (ValidMoveToBoard(newCard.getValue(), newCard.getColor(), colFour.peek().getValue(), colFour.peek().getColor()) == true)
			{
				MOVEMASTER9000(&flag, &deep);
				stackSize = swapStack.getSize();
				output << "Placing ";
				output << swapStack.peek().getType();
				output << " and any other cards on top of it into column " << position + 1 << endl;
				for (int i = 0; i < stackSize; i++)
				{
					cout << "Card " << swapStack.peek().getType() << " is placed into column 4" << endl;
					colFour.push(swapStack.pop());
					uncoverTop();
				}
				return;
			}
			else
			{
				throw InvalidMoveException();
			}
		}
		break;
	}
	case 4:
	{
		if ((int)flag == position)
		{
			cout << "This is the same position " << n << " is at!" << endl;
		}
		else
		{
			//If chosen card is a king and you want to move it to an empty column
			if (newCard.getValue() == 13 && colFive.isEmpty())
			{
				MOVEMASTER9000(&flag, &deep);
				stackSize = swapStack.getSize();
				output << "Placing ";
				output << swapStack.peek().getType();
				output << " and any other cards on top of it into column " << position + 1 << endl;
				for (int i = 0; i < stackSize; i++)
				{
					cout << "Card " << swapStack.peek().getType() << " is placed into column 5" << endl;
					colFive.push(swapStack.pop());
					uncoverTop();
				}
				return;
			}
			if (colFive.isEmpty())
			{
				throw InvalidMoveException();
			}
			if (ValidMoveToBoard(newCard.getValue(), newCard.getColor(), colFive.peek().getValue(), colFive.peek().getColor()) == true)
			{
				MOVEMASTER9000(&flag, &deep);
				stackSize = swapStack.getSize();
				output << "Placing ";
				output << swapStack.peek().getType();
				output << " and any other cards on top of it into column " << position + 1 << endl;
				for (int i = 0; i < stackSize; i++)
				{
					cout << "Card " << swapStack.peek().getType() << " is placed into column 5" << endl;
					colFive.push(swapStack.pop());
					uncoverTop();
				}
				return;
			}
			else
			{
				throw InvalidMoveException();
			}
		}
		break;
	}
	case 5:
	{
		if ((int)flag == position)
		{
			cout << "Card " << swapStack.peek().getType() << " is placed into column 6" << endl;
			cout << "This is the same position " << n << " is at!" << endl;
		}
		else
		{
			//If chosen card is a king and you want to move it to an empty column
			if (newCard.getValue() == 13 && colSix.isEmpty())
			{
				MOVEMASTER9000(&flag, &deep);
				stackSize = swapStack.getSize();
				output << "Placing ";
				output << swapStack.peek().getType();
				output << " and any other cards on top of it into column " << position + 1 << endl;
				for (int i = 0; i < stackSize; i++)
				{
					colSix.push(swapStack.pop());
					uncoverTop();
					return;
				}
				return;
			}
			if (colSix.isEmpty())
			{
				throw InvalidMoveException();
			}
			if (ValidMoveToBoard(newCard.getValue(), newCard.getColor(), colSix.peek().getValue(), colSix.peek().getColor()) == true)
			{
				MOVEMASTER9000(&flag, &deep);
				stackSize = swapStack.getSize();
				output << "Placing ";
				output << swapStack.peek().getType();
				output << " and any other cards on top of it into column " << position + 1 << endl;
				for (int i = 0; i < stackSize; i++)
				{
					cout << "Card " << swapStack.peek().getType() << " is placed into column 6" << endl;
					colSix.push(swapStack.pop());
					uncoverTop();
				}
				return;
			}
			else
			{
				throw InvalidMoveException();
			}
		}
		break;
	}
	case 6:
	{
		if ((int)flag == position)
		{
			cout << "This is the same position " << n << " is at!" << endl;
		}
		else
		{
			//If chosen card is a king and you want to move it to an empty column
			if (newCard.getValue() == 13 && colSeven.isEmpty())
			{
				MOVEMASTER9000(&flag, &deep);
				stackSize = swapStack.getSize();
				output << "Placing ";
				output << swapStack.peek().getType();
				output << " and any other cards on top of it into column " << position + 1 << endl;
				for (int i = 0; i < stackSize; i++)
				{
					cout << "Card " << swapStack.peek().getType() << " is placed into column 7" << endl;
					colSeven.push(swapStack.pop());
					uncoverTop();
					
				}
				return;
			}
			if (colSeven.isEmpty())
			{
				throw InvalidMoveException();
			}
			if (ValidMoveToBoard(newCard.getValue(), newCard.getColor(), colSeven.peek().getValue(), colSeven.peek().getColor()) == true)
			{
				MOVEMASTER9000(&flag, &deep);
				stackSize = swapStack.getSize();
				output << "Placing ";
				output << swapStack.peek().getType();
				output << " and any other cards on top of it into column " << position + 1 << endl;
				for (int i = 0; i < stackSize; i++)
				{
					cout << "Card " << swapStack.peek().getType() << " is placed into column 7" << endl;
					colSeven.push(swapStack.pop());
					uncoverTop();
					
				}
				return;
			}
			else
			{
				throw InvalidMoveException();
			}
		}
		break;
	}
	}
}


//DEsc: Prints given string to outfile
//Pre: Outfile exists and is given a string
//Post: Prints given string to outfile
void GameBoard::printToOutfile(string n)
{
	output << n << endl;
}