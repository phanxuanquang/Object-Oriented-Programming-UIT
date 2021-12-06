#include <iostream>
using namespace std;

class PhanSo {
	int numerator, denominator;
public:
	int get_numerator();
	void set(int, int);
	void import();
	void simplify();
	void print();
	PhanSo operator+(PhanSo);
	PhanSo operator-(PhanSo);
	PhanSo operator*(PhanSo);
	PhanSo operator/(PhanSo);
};

void total(PhanSo, PhanSo);
void subtract(PhanSo, PhanSo);
void multiply(PhanSo, PhanSo);
void divide(PhanSo, PhanSo);
void print(PhanSo&);

int main()
{
	PhanSo a, b;
	cout << "Nhap phan so thu nhat" << endl;
	a.import();
	cout << "Nhap phan so thu hai" << endl;
	b.import();
	total(a, b);
	subtract(a, b);
	multiply(a, b);
	divide(a, b);
	system("pause");
}

int PhanSo::get_numerator() {
	return numerator;
}
void PhanSo::import() {
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
void PhanSo::print() {
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
void PhanSo::set(int tu, int mau) {
	this->numerator = tu;
	this->denominator = mau;
}

PhanSo PhanSo::operator+(PhanSo x) {
	PhanSo temp;
	temp.numerator = numerator * x.denominator + x.numerator * denominator;
	temp.denominator = x.denominator * denominator;
	return temp;
}
PhanSo PhanSo::operator-(PhanSo x) {
	PhanSo temp;
	temp.numerator = numerator * x.denominator - x.numerator * denominator;
	temp.denominator = x.denominator * denominator;
	return temp;
}
PhanSo PhanSo::operator*(PhanSo x) {
	PhanSo temp;
	temp.numerator = numerator * x.numerator;
	temp.denominator = x.denominator * denominator;
	return temp;
}
PhanSo PhanSo::operator/(PhanSo x) {
	PhanSo temp;
	temp.numerator = numerator * x.denominator;
	temp.denominator = x.numerator * denominator;
	return temp;
}

void total(PhanSo x, PhanSo y) {
	cout << " Tong cua hai phan so la ";
	PhanSo sum = x + y;
	print(sum);
}
void subtract(PhanSo x, PhanSo y) {
	cout << " Hieu cua hai phan so la ";
	PhanSo sub = x - y;
	print(sub);
}
void multiply(PhanSo x, PhanSo y) {
	cout << " Tich cua hai phan so la ";
	PhanSo mul = x * y;
	print(mul);
}
void divide(PhanSo x, PhanSo y) {
	cout << " Thuong cua hai phan so la ";
	if (y.get_numerator() == 0)
		cout << "khong ton tai" << endl;
	else {
		PhanSo div = x / y;
		print(div);
	}
}
void print(PhanSo& x) {
	x.simplify();
	x.print();
	cout << endl;
}