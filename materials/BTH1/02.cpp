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

	void input();
	void output();

	Fraction operator-(Fraction);
};

void compare(Fraction, Fraction);

void main()
{
	Fraction a, b;

	cout << "\nPhan so thu nhat: " << endl;
	a.input();

	cout << "\nPhan so thu hai: " << endl;
	b.input();

	cout << endl;
	compare(a, b);
	cout << endl;

	system("pause");
}

void Fraction::input() {
	cout << " Tu so la: ";
	cin >> numerator;
	cout << " Mau so la: ";
	cin >> denominator;
	while (denominator == 0) {
		cout << "Mau so phai khac 0. Mau so moi la: ";
		cin >> denominator;
	}
}
void Fraction::output() {
	if (numerator % denominator == 0)
		cout << numerator / denominator;
	else cout << numerator << "/" << denominator << " ";
}
Fraction Fraction::operator-(Fraction x) {
	Fraction result;
	result.numerator = numerator * x.denominator - x.numerator * denominator;
	result.denominator = x.denominator * denominator;
	return result;
}

void compare(Fraction x, Fraction y) {
	Fraction subtractResult = x - y;
	int temp = subtractResult.getNumerator() * subtractResult.getDenominator();

	if (temp > 0) {
		cout << "Phan so lon nhat la ";
		x.output();
	}
	else if (temp < 0) {
		cout << "Phan so lon nhat la ";
		y.output();
	}
	else cout << "Hai phan so bang nhau";

	cout << endl;
}
