#include <iostream>
using namespace std;

class CDate{
private:
	int Day, Month, Year;
	bool LeapYear = false;
	int months[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
public:
	CDate(int newday = 1, int newmonth = 1, int newyear = 1);
	friend istream& operator>>(istream& is, CDate& date);
	friend ostream& operator<<(ostream& os, CDate date);
	void Check();
	CDate operator+(int newday);
	CDate operator-(int newday);
	CDate& operator++();
	CDate operator++(int);
	CDate& operator--();
	CDate operator--(int);

	int operator-(CDate b);
};

int main(){
	CDate a, b;
	int day;
	cout << "\n Nhap vao thoi diem thu nhat";
	cin >> a;
	cout << a;
	cout << "\n Nhap vao thoi diem thu hai";
	cin >> b;
	cout << b;
	cout << "\n " << a << " + 5 = ";
	a = a + 5;
	cout << a;
	cout << "\n " << b << " - 8 = ";
	b = b - 8;
	cout << b << "\n";
	
	a++;
	cout << a << "\n";
	--b;
	cout << b << "\n";

	cout << a << " - " << b << " = ";
	day = a - b;
	cout << day << " ngay.";
	return 0;
}

CDate::CDate(int newday, int newmonth, int newyear){
	Day = newday;
	Month = newmonth;
	Year = newyear;

}

istream& operator>>(istream& is, CDate& date){
	cout << "\n Ngay: ";
	is >> date.Day;
	cout << " Thang: ";
	is >> date.Month;
	while (date.Month < 1 || date.Month >12){
		cout << " Mot nam co 12 thang.";
		cout << "\n Thang: ";
		is >> date.Month;
	}
	cout << " Nam: ";
	is >> date.Year;
	while (date.Year < 1){
		cout << " Vui long nhap nam sau cong nguyen, nam > 0.";
		cout << "\n Ban da nhap sai, vui long nhap lai.";
		cout << "\n Nam: ";
		is >> date.Year;
	}
	if (date.Year % 400 == 0 || (date.Year % 4 == 0 && date.Year % 100 != 0)){
		date.LeapYear = true;
		date.months[1] = 29;
	}
	while (date.Day > date.months[date.Month - 1] || date.Day < 0){
		cout << "\n Thang " << date.Month << " co " << date.months[date.Month - 1] << " ngay.";
		cout << "\n Ban da nhap sai, vui long nhap lai.";
		cout << "\n Ngay: ";
		is >> date.Day;
	}
	return is;
}

ostream& operator<<(ostream& os, CDate date){
	os << date.Day << "/" << date.Month << "/" << date.Year;
	return os;
}

void CDate::Check(){
	while (Day > months[Month - 1]){
		Day -= months[Month - 1];
		Month++;
		if (Month == 13){
			Year++;
			if (Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0)){
				this->LeapYear = true;
				this->months[1] = 29;
			}
			else{
				LeapYear = false;
				months[1] = 28;
			}
			Month = 1;
		}
	}
	while (Day < 1){
		Month--;
		if (Month == 0){
			Year--;
			Month = 12;
			if (Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0)){
				this->LeapYear = true;
				this->months[1] = 29;
			}
			else{
				LeapYear = false;
				months[1] = 28;
			}
		}
		Day += months[Month - 1];
	}
}

CDate CDate::operator+(int newday){
	CDate tong(Day, Month, Year);
	tong.Day += newday;
	tong.Check();
	return tong;
}

CDate CDate::operator-(int newday){
	CDate hieu(Day, Month, Year);
	hieu.Day -= newday;
	hieu.Check();
	return hieu;
}

CDate& CDate::operator++(){
	*this = *this + 1;
	return *this;
}

CDate CDate::operator++(int){
	CDate t = *this;
	*this = *this + 1;
	return t;
}

CDate& CDate::operator--(){
	*this = *this - 1;
	return *this;
}

CDate CDate::operator--(int){
	CDate t = *this;
	*this = *this - 1;
	return t;
}

int CDate::operator-(CDate b){
	//tinh so ngay

	int time = 0;
	int year = 0;
	CDate temp;

	//tinh dau nam toi a
	temp.Year = Year;
	while (temp.Month != Month){
		time += months[temp.Month - 1];
		temp.Month++;
	}
	time += Day - temp.Day + 1;

	//tinh b toi cuoi nam
	temp = b;
	time = time + b.months[b.Month - 1] - temp.Day + 1;
	while (temp.Month != 12){
		time += b.months[temp.Month];
		temp.Month++;
	}

	if (Year == b.Year){
		if (Month < b.Month) time = time - 2;
		if (months[1] == 29) time = 366 - time;
		else time = 365 - time;
		if (time < 0) time = 0 - time;
		return time;
	}

	int MaxYear;
	if (Year > b.Year){
		year = Year - (b.Year + 1);
		MaxYear = Year;
	}
	else{
		year = b.Year - Year + 1;
		MaxYear = b.Year + 1;
		time -= 2;
	}

	int* arryear = new int[year];

	for (int i = year - 1; i >= 0; i--)
		arryear[i] = MaxYear - year + i;

	int timeyear = 0;
	for (int j = 0; j < year; j++){
		if (arryear[j] % 400 == 0 || (arryear[j] % 4 == 0 && arryear[j] % 100 != 0))
			timeyear += 366;
		else timeyear += 365;
	}
	if (Year > b.Year)
		time += timeyear;
	else time = timeyear - time;
	return time;
}