#include <iostream>
#include "GameBoard.h"
#include <string>
#include "gameOver.h"
#include "InvalidMoveException.h"

using namespace std;

int main()
{
	bool gameTime = true;
	GameBoard newGame;
	string option ,optionTwo,optionThree;
	newGame.fillHand();
	try
	{
		while (gameTime == true)
		{
			newGame.displayBoard();
			cout << endl << "Select your move" << endl;
			cout << "1) Place something in the Sorted Pile" << endl;
			cout << "2) Move a card / cards to a certain other pile (If viable)" << endl;
			cout << "3) Flip cards in discard pile" << endl;
			cin >> option;
			if (option == "1")
			{
				try
				{
					cout << "Select a card you want to put into a sorted pile :";
					cin >> optionTwo;
					cout << "===================================================================" << endl;
					newGame.toSorted(optionTwo);
				}
				catch(InvalidMoveException)
				{
					cout << "===================================================================" << endl;
					cout << "Invalid option" << endl;
				}

			}
			if (option == "2")
			{
				try
				{
					cout << "Select the card you want to move" << endl;
					cin >> optionTwo;
					cout << "Select the column you want to put it in (1-7): ";
					cin >> optionThree;
					for (int i = 0; i < optionThree.size(); i++)
					{
						if (isdigit(optionThree[i]) == false)
						{
							throw InvalidMoveException();
						}
					}
					cout << "===================================================================" << endl;
					if (stoi(optionThree) >= 0 && stoi(optionThree) <= 7)
					{
						newGame.moveCards(optionTwo, stoi(optionThree));
					}
					else
					{
						throw 2;
					}
				}
				catch (int x)
				{
					cout << "===================================================================" << endl;
 					cout << "Invalid Input" << endl;
				}
				catch (InvalidMoveException)
				{
					cout << "===================================================================" << endl;
					cout << "Invalid option" << endl;
				}
			}
			if (option == "3")
			{					
			cout << "===================================================================" << endl;
			try
			{
				cout << "Putting 3 more cards into the discard pile" << endl;
				newGame.fillHand();
			}
			catch (NullException)
			{
				cout << "There are no more cards in the deck." << endl;
			}
			}
			
			if (newGame.checkScore() == true)
			{
				gameTime = false;
			}
		}
	}
	catch (gameOver)
	{
		newGame.printToOutfile("You lost");
		string someString = "Points: " + to_string(newGame.getPoints());
		newGame.printToOutfile(someString);
		cout << "===================================================================" << endl;
		cout << "You did not manage to win." << endl;
		cout << "Game Over" << endl;
		cout << "Points: " << newGame.getPoints();
	}
	if (gameTime == false)
	{
		newGame.printToOutfile("You Win");
		string someString = "Points: " + to_string(newGame.getPoints());
		newGame.printToOutfile(someString);
		cout << "You Win!" << endl << "Points: " << newGame.getPoints() << endl;
	}
	newGame.closeOutfile();
	return 0;
}