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
	void simplify();
	~fraction() {
	}
};
void main()
{
	fraction *a = new fraction;
	a->import();
	cout << "Phan so sau khi rut gon la: ";
	a->print();
	delete a;
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
	cout << endl;
}
void fraction::print() {
	simplify();
	if (numerator % denominator == 0)
		cout << numerator / denominator;
	else cout << numerator << "/" << denominator;
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