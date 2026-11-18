#include <iostream>
using namespace std;

class ComplexNumber {
	double real, imaginary;

public:
	friend istream& operator>>(istream& is, ComplexNumber& a);
	friend ostream& operator<<(ostream& os, ComplexNumber& a);

	ComplexNumber operator+(ComplexNumber a);
	ComplexNumber operator-(ComplexNumber a);
	ComplexNumber operator*(ComplexNumber a);
	ComplexNumber operator/(ComplexNumber a);

	bool operator==(ComplexNumber a);
	bool operator!=(ComplexNumber a);
	bool operator>(ComplexNumber a);
	bool operator>=(ComplexNumber a);
	bool operator<(ComplexNumber a);
	bool operator<=(ComplexNumber a);
};

int main() {
	ComplexNumber a, b, c;
	bool result;
	cout << "So thuc thu nhat: " << endl;
	cin >> a;
	cout << "So thuc thu hai: " << endl;
	cin >> b;
	system("cls");

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << endl;

	c = a + b;
	cout << "a + b = " << c << endl;
	c = a - b;
	cout << "a - b = " << c << endl;
	c = a * b;
	cout << "a * b = " << c << endl;
	c = a / b;
	cout << "a : b = " << c << endl;
	cout << endl;

	if (a == b)
		cout << a << " = " << b << endl;
	if (a != b)
		cout << a << " != " << b << endl;
	if (a >= b)
		cout << a << " >= " << b << endl;
	if (a <= b)
		cout << a << " <= " << b << endl;
	if (a > b)
		cout << a << " > " << b << endl;
	if (a < b)
		cout << a << " < " << b << endl;
	cout << endl;

	system("pause");
}


istream& operator>>(istream& is, ComplexNumber& a) {
	cout << " Phan thuc: ";
	is >> a.real;
	cout << " Phan ao: ";
	is >> a.imaginary;
	return is;
}

ostream& operator<<(ostream& os, ComplexNumber& a) {
	if (a.imaginary > 0)
		cout << a.real << " + " << a.imaginary << "i";
	else if (a.imaginary == 0)
		cout << a.real;
	else cout << a.real << " - " << -a.imaginary << "i";
	return os;
}

ComplexNumber ComplexNumber::operator+(ComplexNumber a) {
	ComplexNumber result;
	result.real = real + a.real;
	result.imaginary = imaginary + a.imaginary;
	return result;
}

ComplexNumber ComplexNumber::operator-(ComplexNumber a) {
	ComplexNumber result;
	result.real = real - a.real;
	result.imaginary = imaginary - a.imaginary;
	return result;
}

ComplexNumber ComplexNumber::operator*(ComplexNumber a) {
	ComplexNumber result;
	result.real = real * a.real - imaginary * a.imaginary;
	result.imaginary = real * a.imaginary + imaginary * a.real;
	return result;
}

ComplexNumber ComplexNumber::operator/(ComplexNumber a) {
	ComplexNumber result;
	result.real = (real * a.real + imaginary * a.imaginary) / sqrt(a.real * a.real + a.imaginary * a.imaginary);
	result.imaginary = (real * a.imaginary - imaginary * a.real) / sqrt(a.real * a.real + a.imaginary * a.imaginary);
	return result;
}

bool ComplexNumber::operator==(ComplexNumber a) {
	double module = real * real + imaginary * imaginary;
	double moduleA = a.real * a.real + a.imaginary * a.imaginary;
	if (module == moduleA)
		return true;
	return false;
}

bool ComplexNumber::operator!=(ComplexNumber a) {
	double module = real * real + imaginary * imaginary;
	double moduleA = a.real * a.real + a.imaginary * a.imaginary;
	if (module != moduleA)
		return true;
	return false;
}

bool ComplexNumber::operator>(ComplexNumber a) {
	double module = real * real + imaginary * imaginary;
	double moduleA = a.real * a.real + a.imaginary * a.imaginary;
	if (module > moduleA)
		return true;
	return false;
}

bool ComplexNumber::operator>=(ComplexNumber a) {
	double module = real * real + imaginary * imaginary;
	double moduleA = a.real * a.real + a.imaginary * a.imaginary;
	if (module >= moduleA)
		return true;
	return false;
}

bool ComplexNumber::operator<(ComplexNumber a) {
	double module = real * real + imaginary * imaginary;
	double moduleA = a.real * a.real + a.imaginary * a.imaginary;
	if (module < moduleA)
		return true;
	return false;
}

bool ComplexNumber::operator<=(ComplexNumber a) {
	double module = real * real + imaginary * imaginary;
	double moduleA = a.real * a.real + a.imaginary * a.imaginary;
	if (module <= moduleA)
		return true;
	return false;
}
