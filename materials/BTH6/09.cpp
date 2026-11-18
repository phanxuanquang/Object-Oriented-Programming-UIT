#include <iostream>
using namespace std;

class INTERGER {
private:
	int x;
public:
	INTERGER(int newx = 0);

	~INTERGER();
	INTERGER& operator++();
	INTERGER operator++(int);
	INTERGER& operator--();
	INTERGER operator--(int);
	friend istream& operator>>(istream& is, INTERGER& a);
	friend ostream& operator<<(ostream& os, INTERGER a);
	friend INTERGER operator+(INTERGER a, INTERGER b);
	friend INTERGER operator-(INTERGER a, INTERGER b);
	friend INTERGER operator*(INTERGER a, INTERGER b);
	friend INTERGER operator/(INTERGER a, INTERGER b);
	friend INTERGER operator%(INTERGER a, INTERGER b);
};

int main(){
	INTERGER a, b;
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	cout << "a + 1 = " << a++ << endl;
	cout << "b - 1 = " << --b << endl;
	cout << a << " x " << b << " + 9 - " << a << " = " << a * b + 9 - a << "\n";
	cout << a << " / " << b << " = " << a / b << "\n";
	cout << a << " % " << b << " = " << a % b << endl;
	return 0;
}
INTERGER::INTERGER(int newx) :x(newx)
{
}

INTERGER::~INTERGER()
{
}

INTERGER& INTERGER::operator++()
{
	x++;
	return *this;
}

INTERGER INTERGER::operator++(int)
{
	INTERGER t = *this;
	x++;
	return t;
}

INTERGER& INTERGER::operator--()
{
	--x;
	return *this;
}

INTERGER INTERGER::operator--(int)
{
	INTERGER t(x);
	x--;
	return t;
}

istream& operator>>(istream& is, INTERGER& a)
{

	is >> a.x;
	return is;
}

ostream& operator<<(ostream& os, INTERGER a)
{
	os << a.x;
	return os;
}

INTERGER operator+(INTERGER a, INTERGER b)
{
	return INTERGER(a.x + b.x);
}

INTERGER operator-(INTERGER a, INTERGER b)
{
	return INTERGER(a.x - b.x);
}

INTERGER operator*(INTERGER a, INTERGER b)
{
	return INTERGER(a.x * b.x);
}

INTERGER operator/(INTERGER a, INTERGER b)
{
	return INTERGER(a.x / b.x);
}

INTERGER operator%(INTERGER a, INTERGER b)
{
	return INTERGER(a.x % b.x);
}