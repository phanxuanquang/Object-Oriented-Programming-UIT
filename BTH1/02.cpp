#include <iostream>
using namespace std;
class fraction {
	int numerator, denominator;
public:
	int get_numerator() {
		return this->numerator;
	}
	int get_denominator() {
		return this->denominator;
	}
	void import();
	void print();
	fraction operator-(fraction);
	~fraction() {
	}
};
void compare(fraction, fraction);
void main()
{
	fraction *a = new fraction;
	cout << "\nNhap phan so thu nhat: " << endl;
	a->import();
	fraction* b = new fraction;
	cout << "\nNhap phan so thu hai: " << endl;
	b->import();
	cout << endl;
	compare(*a, *b);
	cout << endl;
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
}
fraction fraction::operator-(fraction x) {
	fraction temp;
	temp.numerator = numerator * x.denominator - x.numerator * denominator;
	temp.denominator = x.denominator * denominator;
	return temp;
}
void compare(fraction x, fraction y) {
	fraction temp = x - y;
	int temp1 = temp.get_numerator() * temp.get_denominator();
	if (temp1 > 0) {
		cout << "Phan so lon nhat la ";
		x.print();
	}
	else if (temp1 < 0) {
		cout << "Phan so lon nhat la ";
		y.print();
	}
	else cout << "Hai phan so bang nhau";
	cout << endl;
}