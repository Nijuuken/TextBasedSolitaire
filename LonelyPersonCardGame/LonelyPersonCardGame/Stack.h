#pragma once
#include <iostream>
#include "Card.h"
#include "NullException.h"
#include <string>
using namespace std;



class Stack
{
	struct Node
	{
		Card number;
		Node* next;
	};
private:
	Node* head;
public:
	//Desc: Constructor
	//pre:
	//post: new instance of stack
	Stack()
	{
		head = nullptr;
	}

	//Desc: gets size of stack
	//Pre: stack exists
	//Post: size of stack is returned
	int getSize()
	{
		if (head == nullptr)
		{
			return 0;
		}
		Node* temp = new Node();
		temp = head;
		int number = 0;
		while (temp != nullptr)
		{
			temp = temp->next;
			number++;
		}
		return number;
	}

	//Desc: Checks if stack is empty
	//Pre: head exists
	//Post: If head is a nullptr, true is returned
	bool isEmpty()
	{
		if (head == nullptr)
			return true;
		else
			return false;
	}
	//Desc: Take Cards away from stack
	//Pre: stack has cards in it
	//Post: Card is returns and removed from the top of the stack
	Card pop()
	{
		Card num;
		if (isEmpty())
			throw NullException();
		else
		{
			Node* point = head;
			num = point->number;
			head = head->next;
			free(point);
			return num;
		}
	}
	//Desc: Cards are added to the top of the stack
	//Pre: Given Card object
	//Post: Card is put into the top of the stack
	void push(Card number)
	{
		Node* temp = new Node();
		temp->number = number;
		if (isEmpty())
			temp->next = nullptr;
		else
			temp->next = head;
		head = temp;
	}
	//Desc: Makes the topmost card go faceup
	//Pre: head exists
	//Post: head's faceUp variable is set to true
	void reveal()
	{
		head->number.show();
	}

	//Desc: lets you access the top of the stack without removing it
	//Pre: stack is filled
	//Post: topmost Card class is returned but not removed from the stack
	Card peek()
	{
		if (isEmpty())
			throw NullException();
		else
		{
			return head->number;
		}
	}

	//Desc: Prints out a stack in a upper triangle
	//Pre: several stacks (7) are initiated
	//Post: Prints out the game board
	string displayRow(int n)
	{
		Node* temp = new Node();
		temp = head;
		int size = getSize();
		for (int i = 0; i < size-1 - n; i++)
		{
			if (temp != nullptr)
			{
				temp = temp->next;
			}
		}
		if (size-1  < n)
		{
			return " ";
		}
		return  temp->number.getType();;
	}
	
	//Desc: Prints out stack as a list
	//Pre:  Stack is filled
	//Post: Stack is printed out as a list 
	void displayStack()
	{
		Node* temp = new Node();
		temp = head;
		if (isEmpty())
		{
			throw NullException();
		}
		int size = getSize();
		for (int i = 0; i < size; i++)
		{
			if (i <= size - 1)
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

	//Desc: Looks for a cardType based of given string
	//Pre: given string, and integer passed by reference
	//Post: returns true if object of sought after cardType is found. Also returns level of depth of said card by reference
	bool findCard(string n, int* level)
	{
		if (head == nullptr)
		{
			return false;
		}
		Node* temp = new Node();
		temp = head;
		int number = 0;
		while (temp != nullptr && temp->number.getType() != "?")
		{
			*level = *level + 1;
			if (temp != nullptr && temp->number.getType() == n)
			{
				return true;
			}
			temp = temp->next;
			
		}
		return false;
	}
};