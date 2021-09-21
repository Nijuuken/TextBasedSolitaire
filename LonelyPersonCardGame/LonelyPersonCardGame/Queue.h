/**
Name: Karl Pedroche
Date: 4/16/2020
File: Queue.h
Purpose: Header file for queue
**/
#pragma once
#include<iostream>
#include "Card.h"
#include <stdlib.h>
#include <time.h>  
#include "NullException.h"

class Queue
{

	struct Node
	{
		Card number;
		Node* next;
	};

private:
	Node* head;
	Node* tail;
	int size;
public:
	// Constructor which sets the head, tail, size, and capacity
	Queue()
	{
		head = nullptr;
		tail = nullptr;
	}
	//Desc: Gets size of queue
	//Pre: Queue is already initialized
	//Post: returns size of queue
	int getSize()

	{
		int number = 0;
		Node* temp = new Node();
		temp = head;
		while (temp != tail)
		{
			number++;
			temp = temp->next;
		}
		//cout << endl;
		return number;
	}
	//Desc: sets the variable Size to the current size of the queue
	//Pre: getsSize() exists
	//Post: size is set to the current size of queue
	void setSize()
	{
		size = getSize();
	}
	//Desc: Checks is deck is empty
	//Pre: head initialized
	//Post: If head is a nullptr, it returns true. false if otherwise
	bool isEmpty()
	{
		if (head == nullptr)
			return true;
		else
			return false;
	}
	//Desc: Adds a new object to the queue
	//Pre: Card class and string is given
	//Post: new Card class with type set to given string and added to the queue
	void enqueue(Card x, string n)
	{
		x.setType(n);
		Node* temp = new Node();
		temp->number = x;
		if (tail == NULL) {
			head = tail = temp;
			return;
		}
		tail->next = temp;
		tail = temp;
		setSize();
	}
	//Desc: Removes item from list and returns it
	//Pre: class is filled
	//Post: head is returned as a Card class and is removed from the queue
	Card dequeue()
	{
		Card number = head->number;

		if (head == nullptr)
			throw 2;

		Node* temp = head;
		head = head->next;
		if (head == NULL)
			tail = NULL;

		delete (temp);
		return number;
	}
	
	//Desc: Shuffles the queue
	//Pre: Deck is filled. Probably needs at least 3 entities to shuffle
	//Post: A shuffled queue
	void shuffle()
	{
		srand(time(NULL));
		int random;
		int i;
		bool same = false;
		Node* tempOne = new Node();
		Node* tempTwo = new Node();
		Node* view = new Node();
		Card tempCard;
		for (int o = 0; o != 5000; o++)
		{
			
			tempOne = head;
			tempTwo = head;
			i = 0;
			random = rand() % (size  + 1);
			//cout << random << " " << endl;
			//cout << "Random number picked " << random << endl;
			i = 0;
			while (i < random-1)
			{
				if (i < random - 2)
				tempTwo = tempTwo->next;
				tempOne = tempOne->next;
				i++;
			}
			i = 0;
			
			//cout << "Num One " << tempOne->number.getType() << endl;
			//cout << "Num two " << tempTwo->number.getType() << endl;
			same = false;
			if (tempOne == tempTwo) same = true;
			if (same == true)
			{
				tempTwo = head;
				head = head->next;
			}
			else
			{
				tempTwo->next = tempTwo->next->next;
			}
			tail->next = tempOne;
			tail = tempOne;
			tail->next = nullptr;
			
			/*
			cout << "test" << endl;
			cout <<"Head " << head->number.getType() << endl;
			view = head;
			
			while (view != nullptr)
			{
				//cout << i << " "<< (i%15) << endl;
				if ((i%15) == 0)
				{
					cout << endl;
				}
				cout << view->number.getType() << ", ";
				view = view->next;
				i++;
			}
			cout << endl;
			cout << "--------------------------------------------------------------------" << endl;
			*/
		}
		cout << endl;
	}


	//Desc: Sorts the queue in ascending order
	//Pre: Queue is filled
	//Post: Queue is sorted in ascending order
	void sortAscend()
	{
		bool firstSwap = false;
		int counter = 0;
		int someNumber = size;
		Node* tempOne = new Node();
		Node* tempTwo = new Node();
		Node* tempThree = new Node();
		Node* swap = new Node();
		tempOne = head;
		tempTwo = head;
		for (int o = 0; o < size; o++)
		{
			firstSwap = true;
			//view = head;
			tempOne = head;
			tempTwo = head;
			tempThree = head;
			tempTwo = tempTwo->next;
			tempOne = tempOne->next->next; //Wil be the one ahead
			//cout << "Comparingg " << tempThree->number.getValue() << " to " << tempTwo->number.getValue() << endl;
			if (firstSwap == true)
			{
				if (tempThree->number.getValue() > tempTwo->number.getValue())
				{
					head = tempTwo;
					tempTwo->next = tempThree;
					tempThree->next = tempOne;
					tempTwo = tempThree;
					tempThree = head;
				}
				firstSwap = false;
			}
			for (int i = 0; i < size-1; i++)
			{
				//cout << "Comparing tempTwo " << tempTwo->number.getValue() << " to tempOne " << tempOne->number.getValue() << endl;
				if (tempTwo->number.getValue() > tempOne->number.getValue())
				{

					//cout << " tempTwo "<<tempTwo->number.getValue() << " greater than tempOne " << tempOne->number.getValue() << endl;
					tempThree->next = tempOne;
					tempTwo->next = tempOne->next;
					tempOne->next = tempTwo;
					//cout <<"Swapping "<< tempOne->number.getValue() << " with " << tempTwo->number.getValue() << endl;
					swap = tempOne;
					tempOne = tempTwo;
					tempTwo = swap;
					counter = 0;
				}
				tempOne = tempOne->next;
				tempTwo = tempTwo->next;
				tempThree = tempThree->next;
				//cout << "head" << head->number.getType() <<" tail: "<< tail->number.getType()<< endl;
			}
			tail = tempTwo;
		}
		

	}

	//Desc: Sorts the queue in descending order
	//Pre: Queue is filled
	//Post: Queue is sorted in descending order
	void sortDescend()
	{
		bool firstSwap = false;
		int counter = 0;
		int someNumber = size;
		Node* tempOne = new Node();
		Node* tempTwo = new Node();
		Node* tempThree = new Node();
		//Node* view = new Node();
		Node* swap = new Node();
		tempOne = head;
		tempTwo = head;
		for (int o = 0; o < size; o++)
		{
			firstSwap = true;
			//view = head;
			tempOne = head;
			tempTwo = head;
			tempThree = head;
			tempTwo = tempTwo->next;
			tempOne = tempOne->next->next; //Wil be the one ahead
			//cout << "Comparingg " << tempThree->number.getValue() << " to " << tempTwo->number.getValue() << endl;
			if (firstSwap == true)
			{
				if (tempThree->number.getValue() < tempTwo->number.getValue())
				{
					head = tempTwo;
					tempTwo->next = tempThree;
					tempThree->next = tempOne;
					tempTwo = tempThree;
					tempThree = head;
				}
				firstSwap = false;
			}
			for (int i = 0; i < size - 1; i++)
			{

				if (tempTwo->number.getValue() < tempOne->number.getValue())
				{
					tempThree->next = tempOne;
					tempTwo->next = tempOne->next;
					tempOne->next = tempTwo;

					swap = tempOne;
					tempOne = tempTwo;
					tempTwo = swap;

					counter = 0;

				}
				tempOne = tempOne->next;
				tempTwo = tempTwo->next;
				tempThree = tempThree->next;

			}
			tail = tempTwo;

		}
	}

	//Desc: Prints out the members of the queue
	//Pre: queue isn't empty
	//Post: queue is printed out
	void displayQueue()
	{
		Node* temp = new Node;
		temp = head;
		if (isEmpty())
		{
			throw NullException();
		}
		setSize();
		for (int i = 0; i <= size; i++)
		{
			temp->number.flip();
			if (i <= size-1)
			{
				cout << temp->number.getType() << ", ";
			}
			else 
			{
				cout << temp->number.getType() << " ";
			}
			temp = temp->next;
		}
	}

	//Desc: prints out the tail
	//Pre: tail exists
	//Post: tail's type is printed out
	void getTail()
	{
		tail->number.flip();
		cout << tail->number.getType() << endl;
		tail->number.flip();
	}

	// Desc: prints out the head
		//Pre: head exists
		//Post: head's type is printed out
	void getHead()
	{
		head->number.flip();
		cout << head->number.getType() << endl;
		head->number.flip();
	}
};

