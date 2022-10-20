#include <iostream>
#include"Collatz Sequence Functions.hpp"

struct collatzNodePar
{
	int item;
	collatzNodePar* link;
};

int main()
{
	// Declarations
	int userInputtedCollatzRange;
	int longestCollatzNumber;
	int longestCollatzSequence;
	bool returnCheck = true;
	collatzNodePar* head = new collatzNodePar;

	// Get user input
	while (returnCheck == true)
	{
		std::cout << "Enter an integer 100 or less: ";
		std::cin >> userInputtedCollatzRange;
		if (userInputtedCollatzRange > 100 || userInputtedCollatzRange < 1 || userInputtedCollatzRange % 1 != 0)
		{
			std::cout << "Please enter a valid integer number" << std::endl << std::endl;
			continue;
		}
		std::cout << std::endl;
		returnCheck = false;
	}
	// Calculations & assignments
	std::pair<int, int> collatzValues = calculateLongestSequence(userInputtedCollatzRange);
	head->item = collatzValues.first;
	head->link = nullptr;
	createCollatzSequence(&head);

	// Output

	printf("The number %d produces the longest Collatz sequence of %d terms.\nHere are those terms:\n", collatzValues.first, collatzValues.second);
	traversePrintCollatzSequence(&head);
	delete head;
	head = nullptr;
}