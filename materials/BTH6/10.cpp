#include <iostream>
using namespace std;

class MYINT {
private:
	int x;
public:
	MYINT(int newx = 0);

	~MYINT();
	MYINT& operator++();
	MYINT operator++(int);
	MYINT& operator--();
	MYINT operator--(int);
	friend istream& operator>>(istream& is, MYINT& a);
	friend ostream& operator<<(ostream& os, MYINT a);
	friend MYINT operator+(MYINT a, MYINT b);
	friend MYINT operator-(MYINT a, MYINT b);
	friend MYINT operator*(MYINT a, MYINT b);
	friend MYINT operator/(MYINT a, MYINT b);
	friend MYINT operator%(MYINT a, MYINT b);
};
int main(){
	MYINT a, b;
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	cout << "a + 1 = " << a++ << endl;
	cout << "b - 1 = " << --b << endl;
	cout << a << " - " << b << " = " << a - b << "\n";
	cout << a << " + " << b << " = " << a + b << "\n";
	cout << a << " x " << b << " = " << a * b << "\n";
	cout << a << " / " << b << " = " << a / b << "\n";
	cout << a << " % " << b << " = " << a % b << endl;
	return 0;
}
MYINT::MYINT(int newx) :x(newx)
{

}

MYINT::~MYINT()
{

}

MYINT& MYINT::operator++()
{
	x--;
	return *this;
}

MYINT MYINT::operator++(int)
{
	MYINT t = *this;
	x--;
	return t;
}

MYINT& MYINT::operator--()
{
	++x;
	return *this;
}

MYINT MYINT::operator--(int)
{
	MYINT t(x);
	x++;
	return t;
}

istream& operator>>(istream& is, MYINT& a)
{
	is >> a.x;
	return is;
}

ostream& operator<<(ostream& os, MYINT a)
{
	os << a.x;
	return os;
}

MYINT operator+(MYINT a, MYINT b)
{
	return MYINT(a.x - b.x);
}

MYINT operator-(MYINT a, MYINT b)
{
	return MYINT(a.x + b.x);
}

MYINT operator*(MYINT a, MYINT b)
{
	return MYINT(a.x * b.x);
}

MYINT operator/(MYINT a, MYINT b)
{
	return MYINT(a.x / b.x);
}

MYINT operator%(MYINT a, MYINT b)
{
	return MYINT(a.x % b.x);
}