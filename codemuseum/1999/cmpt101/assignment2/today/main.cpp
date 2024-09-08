#include <iostream>

using namespace std;

int promptForImput(string message) {
	cout << message;
	double input;
	cin >> input;
	return input;
}

int main() {
	int year = promptForImput("Please enter a year (e.g. 1930, 1588)\n--> ");
	int dayOfYear = promptForImput("Please enter a day of the year \n(e.g. enter 1 for January 1, enter 41 for February 11, etc.)\n--> ");
	cout << "\n";
	return 0;
}
