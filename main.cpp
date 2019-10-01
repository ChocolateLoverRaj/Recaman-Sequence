#include <iostream>
using namespace std;

void processSequence(int numberOfTerms) {
	int* terms;
	terms = new int[numberOfTerms];

	terms[0] = 0;
	cout << "Term Number " << 0 << " is: " << 0 << endl;

	int currentTermNumber = 1;
	int lastTerm = 0;
	int largestTerm = 0;

	for (currentTermNumber; currentTermNumber < numberOfTerms; currentTermNumber++) {
		int thisTerm;
		bool termTaken = false;
		for (int j = 0; j < numberOfTerms; j++) {
			if (terms[j] == lastTerm - currentTermNumber) {
				termTaken = true;
			}
		}

		if (!termTaken && lastTerm - currentTermNumber > 0) {
			thisTerm = lastTerm - currentTermNumber;
		}
		else {
			thisTerm = lastTerm + currentTermNumber;
		}

		if (thisTerm > largestTerm) {
			largestTerm = thisTerm;
		}
		lastTerm = thisTerm;
		terms[currentTermNumber] = thisTerm;

		cout << "Term Number " << currentTermNumber << " is: " << thisTerm << endl;
	};

	cout << "The Largest Term Number Was: " << largestTerm << endl;

	delete[] terms;
}

int main()
{
	int numberOfTerms;

	cout << "How many terms would you like to calculate? " << endl; cin >> numberOfTerms;
	while (true) {
		if (numberOfTerms >= 2) {
			processSequence(numberOfTerms);

			break;
		}
		else {
			cout << "Please enter a number that's 2 or greater " << endl; cin >> numberOfTerms;
		}
	}

	system("pause");
	return 0;
}