#include <iostream>
using namespace std;

class CTime {
private:
	int Hour, Min, Sec;
public:
	CTime(int newh = 0, int newm = 0, int news = 0);
	friend istream& operator>>(istream& is, CTime& a);
	friend ostream& operator<<(ostream& os, CTime& a);

	int Chuyen_s();
	void Settime();
	CTime operator+(int news);
	CTime operator-(int news);
	CTime& operator++(); //++a
	CTime operator++(int); //a++
	CTime& operator--();
	CTime operator--(int);
	CTime operator-(CTime& b);
};

int main(){
	CTime a, b, c;
	cout << " Thoi diem thu nhat.";
	cin >> a;
	cout << "\n Thoi diem thu hai.";
	cin >> b;

	cout << a << " - " << b << " = ";
	c = a - b;
	cout << c << "\n";

	cout << a << " + 5s = ";
	a = a + 5;
	cout << a << "\n";

	cout << b << " - 15s = ";
	b = b - 15;
	cout << b << "\n";

	++a;
	cout << a << "\n";
	b--;
	cout << b;
}

CTime::CTime(int newh, int newm, int news){
	Hour = newh;
	Min = newm;
	Sec = news;
}

istream& operator>>(istream& is, CTime& a){
	cout << "\n Hay nhap vao mot thoi diem trong ngay.";
	cout << "\n Nhap gio: ";
	is >> a.Hour;
	cout << " Nhap phut: ";
	is >> a.Min;
	cout << " Nhap giay: ";
	is >> a.Sec;
	a.Settime();
	return is;
}

ostream& operator<<(ostream& os, CTime& a){
	os << a.Hour << "h " << a.Min << "m " << a.Sec << "s ";
	return os;
}

int CTime::Chuyen_s(){
	int time;
	time = Hour * 3600 + Min * 60 + Sec;
	return time;
}

void CTime::Settime(){
	int time = Chuyen_s();
	while (time < 0)
		time += 24 * 3600;
	while (time > 24 * 3600)
		time -= 24 * 3600;
	Hour = time / 3600;
	time = time - Hour * 3600;
	Min = time / 60;
	Sec = time - Min * 60;
}

CTime CTime::operator+(int news){
	CTime tong(Hour, Min, Sec);
	tong.Sec += news;
	if (tong.Sec > 60 || tong.Sec < 0) tong.Settime();
	return tong;
}
CTime CTime::operator-(int news){
	CTime hieu(Hour, Min, Sec);
	hieu.Sec -= news;
	if (hieu.Sec > 60 || hieu.Sec < 0) hieu.Settime();
	return hieu;
}

CTime& CTime::operator++(){
	Sec++;
	if (Sec > 60 || Sec < 0) Settime();
	return *this;
}

CTime CTime::operator++(int){
	CTime t = *this;
	Sec++;
	if (Sec > 60 || Sec < 0) Settime();
	return t;
}

CTime& CTime::operator--(){
	Sec--;
	if (Sec > 60 || Sec < 0) Settime();
	return *this;
}

CTime CTime::operator--(int){
	CTime t = *this;
	Sec--;
	if (Sec > 60 || Sec < 0) Settime();
	return t;
}

CTime CTime::operator-(CTime& b){
	CTime hieu;
	hieu.Hour = Hour - b.Hour;
	hieu.Min = Min - b.Min;
	hieu.Sec = Sec - b.Sec;
	hieu.Settime();
	return hieu;
}