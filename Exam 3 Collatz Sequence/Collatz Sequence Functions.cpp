#include <iostream>
#include "Collatz Sequence Functions.hpp"


struct collatzNodePar
{
	int item;
	collatzNodePar* link;
};

int calculateNextCollatzNumber(int inputPar)
{
	switch (inputPar%2)
	{
	case 0: // even numbers
		return inputPar/ 2;
		break;
	case 1: // odd numbers
		return 3 * inputPar + 1;
		break;
	default: // error statment in case inputPar is not an integer
		std::cout << "the value inputed is invalid, please use only whole numbers!";
	}
}

 std::pair<int, int> calculateLongestSequence(int inputPar)
{
	int longestCollatzSequence = 0;
	int longestCollatzNumber = 0;

	// check for all collatz sequences equal to and below the inputPar
	for (int i = inputPar; i >= 1; i--) 
	{
		if (calculateCollatzSequenceLength(i) > longestCollatzSequence)
		{
			longestCollatzSequence = calculateCollatzSequenceLength(i);
			longestCollatzNumber = i;
		}
	}

	return std::make_pair(longestCollatzNumber,longestCollatzSequence);
}

int calculateCollatzSequenceLength(int inputPar)
{
	int collatzValue = inputPar;
	int collatzSequenceCount = 1;
	while (collatzValue != 1)
	{
		collatzValue = calculateNextCollatzNumber(collatzValue);
		collatzSequenceCount++;
	}
	return collatzSequenceCount;
}

void createCollatzSequence(collatzNodePar** head_ref)
{
	// initialize nextCollatzNode
	collatzNodePar* currentNode = *head_ref; // current node is set to the head_ref

	while (currentNode->item != 1) // so long as next_ref is not 1
	{
		// Get value of number stored in previous node
		int currentCollatzNumber = currentNode->item;

		// create a new node and set the next_ref to that new node
		currentNode->link = new collatzNodePar;
		currentNode = currentNode->link;

		// new node initialization
		currentNode->link = nullptr;
		currentNode->item = calculateNextCollatzNumber(currentCollatzNumber);
	}
}

void traversePrintCollatzSequence(collatzNodePar** head_ref)
{
	// initialize nextCollatzNode
	collatzNodePar* currentNode = *head_ref; // current node is set to the head_ref

	// traverse and print Collatz linked list sequence
	while (currentNode != nullptr)
	{
		// print the current item
		if (currentNode->link != nullptr)
		{
			std::cout << currentNode->item << " -> ";
		}
		else 
		{
			std::cout << currentNode->item << std::endl;
		}
		
		// change the next_ref to the next node
		currentNode = currentNode->link;
	}
	destroyLinkedList(head_ref);
}

void destroyLinkedList(collatzNodePar** head_ref)
{
	collatzNodePar* currentNode = *head_ref; // current node is set to the head_ref

	while (currentNode != nullptr)
	{
		collatzNodePar* nodeToDelete = new collatzNodePar; // create a node to delete
		nodeToDelete = currentNode; // set current node to the node to delete
		currentNode = currentNode->link; // move current  node to the next node
		delete nodeToDelete; // delete the node to delete
		nodeToDelete = nullptr; // ^ Part 2
	}
	delete currentNode; // delete the current node
	currentNode = nullptr; // ^ part 2
}

// Important Links:
// https://www.geeksforgeeks.org/write-a-function-to-delete-a-linked-list
// https://www.geeksforgeeks.org/returning-multiple-values-from-a-function-using-tuple-and-pair-in-c/