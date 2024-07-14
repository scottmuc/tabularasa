#include <iostream>

using namespace std;

double promptForImput(string message) {
	cout << message;
	double input;
	cin >> input;
	return input;
}

int main() {
	double a = promptForImput("enter a: ");
	double b = promptForImput("enter b: ");
	double c = promptForImput("enter c: ");
	double d = promptForImput("enter d: ");
	double e = promptForImput("enter e: ");
	double f = promptForImput("enter f: ");
	cout << "\n";

	double x_demoninator = (a * e - b * d);
	double y_demoninator = (b * d - a * e);

	if (y_demoninator == 0 || x_demoninator == 0) {
		cout << "No solution possible!";
		return 0;
	}

	double X = (c * e - b * f) / x_demoninator;
	double Y = (c * d - a * f) / y_demoninator;

	cout << a << "X + " << b << "Y = " << c << "\n";
	cout << d << "X + " << e << "Y = " << f << "\n\n";
	cout << "X = " << X << "  Y = " << Y << "\n";
	return 0;
}
