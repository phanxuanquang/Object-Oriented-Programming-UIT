#include <iostream>
using namespace std;

class CTimeSpan{
private:
	int h, m, s;
public:
	CTimeSpan(int newh = 0, int newm = 0, int news = 0);
	friend istream& operator>>(istream& is, CTimeSpan& a);
	friend ostream& operator<<(ostream& os, CTimeSpan& a);

	int Chuyen_s();
	void Settime();
	CTimeSpan operator+(CTimeSpan b);
	CTimeSpan operator-(CTimeSpan b);
	bool operator==(CTimeSpan b);
	bool operator!=(CTimeSpan b);
	bool operator>(CTimeSpan b);
	bool operator<(CTimeSpan b);
	bool operator<=(CTimeSpan b);
	bool operator>=(CTimeSpan b);
};

int main(){
	CTimeSpan time1, time2, sum, sub;
	bool SoSanh;
	cout << "\n Nhap gio thu nhat";
	cin >> time1;
	cout << "\n Nhap gio thu hai";
	cin >> time2;
	cout << "\n Tong hai gio: ";
	sum = time1 + time2;
	cout << sum;
	cout << "\n Hieu hai gio: ";
	sub = time1 - time2;
	cout << sub;

	SoSanh = (time1 == time2);
	cout << "\n Bang nhau: " << SoSanh;
	
	SoSanh = (time1 != time2);
	cout << "\n Khac nhau: " << SoSanh;

	SoSanh = (time1 > time2);
	cout << "\n Gio thu nhat > gio thu hai: " << SoSanh;
	
	SoSanh = (time1 >= time2);
	cout << "\n Gio thu nhat >= gio thu hai: " << SoSanh;
	
	SoSanh = (time1 < time2);
	cout << "\n Gio thu nhat < gio thu hai: " << SoSanh;
	
	SoSanh = (time1 <= time2);
	cout << "\n Gio thu nhat <= gio thu hai: " << SoSanh;
	
	cout << "\n Gio thu nhat sau khi duoc chuan hoa: ";
	cout << time1;
	cout << "\n Gio thu hai sau khi duoc chuan hoa: ";
	cout << time2;
	return 0;
}

CTimeSpan::CTimeSpan(int newh, int newm, int news){
	h = newh;
	m = newm;
	s = news;
}

istream& operator>>(istream& is, CTimeSpan& a){
	cout << "\n Nhap gio: ";
	is >> a.h;
	cout << " Nhap phut: ";
	is >> a.m;
	cout << " Nhap giay: ";
	is >> a.s;
	return is;
}

ostream& operator<<(ostream& os, CTimeSpan& a){
	a.Settime();
	os << "\n Gio: ";
	os << a.h << "h " << a.m << "m " << a.s << "s";
	return os;
}


int CTimeSpan::Chuyen_s(){
	int time;
	time = h * 3600 + m * 60 + s;
	return time;
}

void CTimeSpan::Settime(){
	int time = Chuyen_s();
	h = abs(time / 3600);
	m = abs((time - h * 3600) / 60);
	s = abs(time - h * 3600 - m * 60);
}


CTimeSpan CTimeSpan::operator+(CTimeSpan b){
	CTimeSpan tong;
	tong.h = h + b.h;
	tong.m = m + b.m;
	tong.s = s + b.s;
	tong.Settime();
	return tong;
}

CTimeSpan CTimeSpan::operator-(CTimeSpan b){
	CTimeSpan hieu;
	hieu.h = h - b.h;
	hieu.m = m - b.m;
	hieu.s = s - b.s;
	hieu.Settime();
	return hieu;
}

bool CTimeSpan::operator==(CTimeSpan b){
	if (Chuyen_s() == b.Chuyen_s()) return true;
	return false;
}

bool CTimeSpan::operator!=(CTimeSpan b){
	if (Chuyen_s() != b.Chuyen_s()) return true;
	return false;
}

bool CTimeSpan::operator>(CTimeSpan b){
	if (Chuyen_s() > b.Chuyen_s()) return true;
	return false;
}

bool CTimeSpan::operator<(CTimeSpan b){
	if (Chuyen_s() < b.Chuyen_s())
		return true;
	return false;
}

bool CTimeSpan::operator<=(CTimeSpan b){
	if (Chuyen_s() <= b.Chuyen_s()) return true;
	return false;
}

bool CTimeSpan::operator>=(CTimeSpan b){
	if (Chuyen_s() >= b.Chuyen_s()) return true;
	return false;
}