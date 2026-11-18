#include <iostream>
using namespace std;

class fraction {
private:
	int numerator, denominator;
public:
	fraction(int newnumerator = 0, int newdenominator = 1);
	friend istream& operator>>(istream& is, fraction& a);
	friend ostream& operator<<(ostream& os, fraction& a);

	float Value();
	void simplity();

	friend fraction operator+(fraction a, fraction b);
	friend fraction operator-(fraction a, fraction b);
	friend fraction operator*(fraction a, fraction b);
	friend fraction operator/(fraction a, fraction b);

	friend bool operator==(fraction a, fraction b);
	friend bool operator!=(fraction a, fraction b);
	friend bool operator>(fraction a, fraction b);
	friend bool operator>=(fraction a, fraction b);
	friend bool operator<(fraction a, fraction b);
	friend bool operator<=(fraction a, fraction b);
};

int main(){
	fraction a, b, c;
	bool ketqua;
	cout << " Nhap PS thu nhat: \n";
	cin >> a;
	cout << " Nhap PS thu hai: \n";
	cin >> b;
	c = 5 + b - a * 3 + b / 2;
	cout << " 5 + " << b << " - " << a << " x 3 + " << b << " : 2 = " << c;
	ketqua = 3 > a;
	if (ketqua)
		cout << "\n (3 > " << a << ") is true" << endl;
	else cout << "\n (3 > " << a << ") is false" << endl;
	return 0;
}

fraction::fraction(int newnumerator, int newdenominator){
	numerator = newnumerator;
	denominator = newdenominator;
}
istream& operator>>(istream& is, fraction& a){
	cout << " Nhap tu so: ";
	is >> a.numerator;
	cout << " Nhap mau so: ";
	is >> a.denominator;
	while (a.denominator == 0){
		cout << " Nhap lai mau so: ";
		cin >> a.denominator;
	}
	return is;
}
ostream& operator<<(ostream& os, fraction& a){
	a.simplity();
	if (a.denominator != 1 && a.numerator != 0)
		os << a.numerator << "/" << a.denominator;
	else os << a.numerator;
	return os;
}

float fraction::Value(){
	float value;
	value = 1.0 * this->numerator / this->denominator;
	return value;
}

void fraction::simplity(){
	int gcd;
	int a = this->numerator;
	int b = this->denominator;
	if (a == 0) return;
	while (a != b){
		if (a < b) b = b - a;
		else a = a - b;
	}
	gcd = a;
	this->numerator = this->numerator / gcd;
	this->denominator = this->denominator / gcd;
}

fraction operator+(fraction a, fraction b){
	fraction tong;
	tong.numerator = a.numerator * b.denominator + a.denominator * b.numerator;
	tong.denominator = a.denominator * b.denominator;
	return tong;
}

fraction operator-(fraction a, fraction b){
	fraction hieu;
	hieu.numerator = a.numerator * b.denominator - a.denominator * b.numerator;
	hieu.denominator = a.denominator * b.denominator;
	return hieu;}

fraction operator*(fraction a, fraction b){
	fraction nhan;
	nhan.numerator = a.numerator * b.numerator;
	nhan.denominator = a.denominator * b.denominator;
	return nhan;
}

fraction operator/(fraction a, fraction b){
	fraction chia;
	chia.numerator = a.numerator * b.denominator;
	chia.denominator = a.denominator * b.numerator;
	return chia;
}

bool operator==(fraction a, fraction b){
	if (a.Value() == b.Value()) return true;
	return false;
}

bool operator!=(fraction a, fraction b){
	if (a.Value() != b.Value()) return true;
	return false;
}

bool operator>(fraction a, fraction b){
	if (a.Value() > b.Value()) return true;
	return false;
}

bool operator>=(fraction a, fraction b){
	if (a.Value() >= b.Value()) return true;
	return false;
}

bool operator<(fraction a, fraction b){
	if (a.Value() < b.Value()) return true;
	return false;
}

bool operator<=(fraction a, fraction b){
	if (a.Value() <= b.Value()) return true;
	return false;
}