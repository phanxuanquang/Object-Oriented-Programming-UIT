#include <iostream>
using namespace std;

class PhanSo {
	int numerator, denominator;
public:
	int getNumerator();
	void set(int, int);

	void input();
	void output();

	void simplify();

	PhanSo operator+(PhanSo);
	PhanSo operator-(PhanSo);
	PhanSo operator*(PhanSo);
	PhanSo operator/(PhanSo);
};

void getTotalOf(PhanSo, PhanSo);
void getTubtractionOf(PhanSo, PhanSo);
void getMultiplicationOf(PhanSo, PhanSo);
void getDivisionOf(PhanSo, PhanSo);

void print(PhanSo&);

int main()
{
	PhanSo a, b;
	cout << "Nhap phan so thu nhat" << endl;
	a.input();
	cout << "Nhap phan so thu hai" << endl;
	b.input();

	getTotalOf(a, b);
	getTubtractionOf(a, b);
	getMultiplicationOf(a, b);
	getDivisionOf(a, b);

	cout << endl;
	system("pause");
}

int PhanSo::getNumerator() {
	return numerator;
}
void PhanSo::set(int tu, int mau) {
	this->numerator = tu;
	this->denominator = mau;
}

void PhanSo::input() {
	cout << " Tu so la: ";
	cin >> numerator;
	cout << " Mau so la: ";
	cin >> denominator;
	while (denominator == 0) {
		cout << "Mau so phai khac 0. \n Mau so moi la: ";
		cin >> denominator;
	}
	system("cls");
}
void PhanSo::output() {
	if (numerator % denominator == 0)
		cout << numerator / denominator;
	else cout << numerator << "/" << denominator << " ";
}

void PhanSo::simplify() {
	for (int i = numerator; i >= 1; i--)
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

PhanSo PhanSo::operator+(PhanSo x) {
	PhanSo temp;
	temp.numerator = numerator * x.denominator + x.numerator * denominator;
	temp.denominator = x.denominator * denominator;
	temp.simplify();
	return temp;
}
PhanSo PhanSo::operator-(PhanSo x) {
	PhanSo temp;
	temp.numerator = numerator * x.denominator - x.numerator * denominator;
	temp.denominator = x.denominator * denominator;
	temp.simplify();
	return temp;
}
PhanSo PhanSo::operator*(PhanSo x) {
	PhanSo temp;
	temp.numerator = numerator * x.numerator;
	temp.denominator = x.denominator * denominator;
	temp.simplify();
	return temp;
}
PhanSo PhanSo::operator/(PhanSo x) {
	PhanSo temp;
	temp.numerator = numerator * x.denominator;
	temp.denominator = x.numerator * denominator;
	temp.simplify();
	return temp;
}

void getTotalOf(PhanSo x, PhanSo y) {
	cout << "Tong cua hai phan so la ";
	PhanSo tot = x + y;
	tot.output();
}
void getTubtractionOf(PhanSo x, PhanSo y) {
	cout << "\nHieu cua hai phan so la ";
	PhanSo sub = x - y;
	sub.output();
}
void getMultiplicationOf(PhanSo x, PhanSo y) {
	cout << "\nTich cua hai phan so la ";
	PhanSo mul = x * y;
	mul.output();
}
void getDivisionOf(PhanSo x, PhanSo y) {
	cout << "\nThuong cua hai phan so la ";
	if (y.getNumerator() == 0)
		cout << "khong ton tai" << endl;
	else {
		PhanSo div = x / y;
		div.output();
	}
}
