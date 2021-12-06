#include <iostream>
using namespace std;
class date {
public:
	int day;
	int month;
	long year;
};
void import(date& x, int& Month_LastDate);
void month_case(date& x, int& Month_LastDate);
void nextDate(date x, date& y, int n);
void main() {
	date date1, date2;
	int Month_LastDate;
	import(date1, Month_LastDate);
	month_case(date1, Month_LastDate);
	nextDate(date1, date2, Month_LastDate);
	cout << "Ngay tiep theo la " << date2.day << "/" << date2.month << "/" << date2.year << endl;
	system("pause");
}
void import(date& x, int& Month_LastDate)
{
	cout << " Nhap ngay: ";
	cin >> x.day;
	cout << " Nhap thang: ";
	cin >> x.month;
	cout << " Nhap nam: ";
	cin >> x.year;
}
void month_case(date& x, int& Month_LastDate) {
	switch (x.month)
	{
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		Month_LastDate = 31;
		break;
	case 4: case 6: case 9: case 11:
		Month_LastDate = 30;
		break;
	case 2:
		if (x.year % 400 == 0 || (x.year % 4 == 0 && x.year % 100 != 0))
			Month_LastDate = 29;
		else Month_LastDate = 28;
		break;
	default: 
		Month_LastDate = 0;
		break;
	}
	while (Month_LastDate == 0 || x.year < 1 || (Month_LastDate != 0 && (x.day > Month_LastDate || x.day < 1)))
	{
		cout << endl << "Ngay thanh nam khong hop le, vui long nhap lai." << endl;
		import(x, Month_LastDate);
	}
}
void nextDate(date x, date& y, int n)
{
	if (x.day < n)
	{
		y.day = x.day + 1;
		y.month = x.month;
		y.year = x.year;
	}
	else
	{
		if (x.month != 12)
		{
			y.day = 1;
			y.month = x.month + 1;
			y.year = x.year;
		}
		else
		{
			y.day = 1;
			y.month = 1;
			y.year = x.year + 1;
		}
	}
}