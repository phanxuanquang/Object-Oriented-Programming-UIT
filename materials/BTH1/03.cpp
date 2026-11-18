#include <iostream>
using namespace std;

class Fraction {
	int numerator, denominator;

public:
	Fraction() {}

	int getNumerator() {
		return this->numerator;
	}
	int getDenominator() {
		return this->denominator;
	}

	void input();
	void output();

	void simplify();
	
	Fraction operator+(Fraction);
	Fraction operator-(Fraction);
	Fraction operator*(Fraction);
	Fraction operator/(Fraction);
};

void getTotalOf(Fraction x, Fraction y);
void getSubtractionOf(Fraction x, Fraction y);
void getMultiplicationOf(Fraction x, Fraction y);
void getDivisionOf(Fraction x, Fraction y);

int main()
{
	Fraction a, b;
	cout << "Nhap phan so thu nhat:" << endl;
	a.input();
	cout << "Nhap phan so thu hai:" << endl;
	b.input();

	system("cls");

	cout << "Tong cua hai phan so la ";
	getTotalOf(a, b);
	cout << "Hieu cua hai phan so la ";
	getSubtractionOf(a, b);
	cout << "Tich cua hai phan so la ";
	getMultiplicationOf(a, b);
	cout << "Thuong cua hai phan so la ";
	getDivisionOf(a, b);

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
Fraction Fraction::operator+(Fraction x) {
	Fraction temp;
	temp.numerator = numerator * x.denominator + x.numerator * denominator;
	temp.denominator = x.denominator * denominator;
	temp.simplify();
	return temp;
}
Fraction Fraction::operator-(Fraction x) {
	Fraction temp;
	temp.numerator = numerator * x.denominator - x.numerator * denominator;
	temp.denominator = x.denominator * denominator;
	temp.simplify();
	return temp;
}
Fraction Fraction::operator*(Fraction x) {
	Fraction temp;
	temp.numerator = numerator * x.numerator;
	temp.denominator = x.denominator * denominator;
	temp.simplify();
	return temp;
}
Fraction Fraction::operator/(Fraction x) {
	Fraction temp;
	temp.numerator = numerator * x.denominator;
	temp.denominator = denominator * x.numerator;
	temp.simplify();
	return temp;
}

void getTotalOf(Fraction x, Fraction y) {
	Fraction temp;
	temp = x + y;
	temp.output();
}
void getSubtractionOf(Fraction x, Fraction y) {
	Fraction temp;
	temp = x - y;
	temp.output();
}
void getMultiplicationOf(Fraction x, Fraction y) {
	Fraction temp;
	temp = x * y;
	temp.output();
}
void getDivisionOf(Fraction x, Fraction y) {
	if (y.getNumerator() == 0)
		cout << "khong ton tai" << endl;
	else {
		Fraction temp;
		temp = x / y;
		temp.output();
	}
}
