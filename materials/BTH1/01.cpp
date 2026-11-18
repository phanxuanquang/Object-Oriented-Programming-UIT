#include <iostream>
using namespace std;

class Fraction {
	int numerator, denominator;

public:
	int getNumerator() {
		return this->numerator;
	}
	int getDenominator() {
		return this->denominator;
	}

	void simplify();

	void input();
	void output();
};

int main()
{
	Fraction a;
	a.input();

	cout << "Ket qua rut gon la ";
	a.output();

	system("pause");
}

void Fraction::input() {
	cout << "Tu so la: ";
	cin >> numerator;
	cout << "Mau so la: ";
	cin >> denominator;
	while (denominator == 0) {
		cout << "  Mau so phai khac 0. Mau so moi la: ";
		cin >> denominator;
	}
	cout << endl;
}
void Fraction::output() {
	simplify();
	if (numerator % denominator == 0)
		cout << numerator / denominator;
	else cout << numerator << "/" << denominator;
	cout << endl;
}

void Fraction::simplify() {
	for (int i = abs(numerator); i >= 1; i--)
		if (numerator % i == 0 && denominator % i == 0) {
			numerator /= i;
			denominator /= i;
			if ((numerator < 0 && denominator < 0) || (numerator > 0 && denominator < 0)) {
				numerator *= -1;
				denominator *= -1;
			}
			break;
		}
}
