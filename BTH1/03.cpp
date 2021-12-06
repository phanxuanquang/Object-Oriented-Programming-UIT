#include <iostream>
using namespace std;
class fraction {
	int numerator, denominator;
public:
	fraction() {
	}
	int get_numerator() {
		return this->numerator;
	}
	int get_denominator() {
		return this->denominator;
	}
	void import();
	void print();
	void simplify();
	fraction operator+(fraction);
	fraction operator-(fraction);
	fraction operator*(fraction);
	fraction operator/(fraction);
	~fraction() {
	}
};
void total(fraction x, fraction y);
void subtract(fraction x, fraction y);
void multiply(fraction x, fraction y);
void divide(fraction x, fraction y);
void main()
{
	fraction* a = new fraction;
	cout << "Nhap phan so thu nhat:" << endl;
	a->import();
	fraction *b = new fraction;
	cout << "Nhap phan so thu hai:" << endl;
	b->import();
	cout << "Tong cua hai phan so la ";
	total(*a, *b);
	cout << "Hieu cua hai phan so la ";
	subtract(*a, *b);
	cout << "Tich cua hai phan so la ";
	multiply(*a, *b);
	cout << "Thuong cua hai phan so la ";
	divide(*a, *b);
	delete a, b;
	system("pause");
}
void fraction::import() {
	cout << " Tu so la: ";
	cin >> numerator;
	cout << " Mau so la: ";
	cin >> denominator;
	while (denominator == 0) {
		cout << "Mau so phai khac 0. Mau so moi la: ";
		cin >> denominator;
	}
}
void fraction::print() {
	if (numerator % denominator == 0)
		cout << numerator / denominator;
	else cout << numerator << "/" << denominator << " ";
	cout << endl;
}
void fraction::simplify() {
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
fraction fraction::operator+(fraction x) {
	fraction temp;
	temp.numerator = numerator * x.denominator + x.numerator * denominator;
	temp.denominator = x.denominator * denominator;
	temp.simplify();
	return temp;
}
fraction fraction::operator-(fraction x) {
	fraction temp;
	temp.numerator = numerator * x.denominator - x.numerator * denominator;
	temp.denominator = x.denominator * denominator;
	temp.simplify();
	return temp;
}
fraction fraction::operator*(fraction x) {
	fraction temp;
	temp.numerator = numerator * x.numerator;
	temp.denominator = x.denominator * denominator;
	temp.simplify();
	return temp;
}
fraction fraction::operator/(fraction x) {
	fraction temp;
	temp.numerator = numerator * x.denominator;
	temp.denominator = denominator * x.numerator;
	temp.simplify();
	return temp;
}
void total(fraction x, fraction y) {
	fraction temp;
	temp = x + y;
	temp.print();
}
void subtract(fraction x, fraction y) {
	fraction temp;
	temp = x - y;
	temp.print();
}
void multiply(fraction x, fraction y) {
	fraction temp;
	temp = x * y;
	temp.print();
}
void divide(fraction x, fraction y) {
	if (y.get_numerator() == 0)
		cout << "khong ton tai" << endl;
	else {
		fraction temp;
		temp = x / y;
		temp.print();
	}
}