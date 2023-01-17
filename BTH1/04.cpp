#include <iostream>
using namespace std;

class Date {
	int day, month, year;

public:
	Date() {}
	Date(int day, int month, int year) {
		this->day = day;
		this->month = month;
		this->year = year;
	}

	bool isValidDate();
	Date getNextDate();

	void Import();
	void Export();
};

bool isLeapYear(int year);

int main()
{
	Date date;
	cout << "Nhap ngay thang nam: " << endl;
	date.Import();

	system("cls");

	cout << "Ngay tiep theo la ";
	date.getNextDate().Export();

	system("pause");
}

bool isLeapYear(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		return true;
	return false;
}

bool Date::isValidDate() {
	if (year < 0)
		return false;
	if (month < 1 || month > 12)
		return false;
	if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && (day > 31))
		return false;
	if ((month == 4 || month == 6 || month == 9 || month == 11) && (day > 30))
		return false;
	if ((isLeapYear(year) && month == 2 && day > 29) || (!isLeapYear(year) && month == 2 && day > 28))
		return false;
	return true;
}
Date Date::getNextDate()
{
	Date nextDate(this->day, this->month, this->year);
	nextDate.day++;

	if (nextDate.month == 1 || nextDate.month == 3 || nextDate.month == 5 || nextDate.month == 7 || nextDate.month == 8 || nextDate.month == 10 || nextDate.month == 12)
	{
		if (nextDate.day >= 31 && nextDate.month != 12)
		{
			nextDate.day = 1;
			nextDate.month++;
		}
		else if (nextDate.day >= 31 && nextDate.month == 12) {
			nextDate.day = 1;
			nextDate.month = 1;
			nextDate.year++;
		}
	}

	if ((nextDate.month == 4 || nextDate.month == 6 || nextDate.month == 9 || nextDate.month == 11))
	{
		if (day >= 30)
		{
			day = 1;
			month++;
		}
	}

	if (isLeapYear(nextDate.year) && nextDate.month == 2) {
		if (nextDate.day >= 29)
		{
			nextDate.day = 1;
			nextDate.month++;
		}
	}

	return nextDate;
}
void Date::Import() {
	cout << "  Nhap ngay: ";
	cin >> day;
	cout << "  Nhap thang: ";
	cin >> month;
	cout << "  Nhap nam: ";
	cin >> year;
	if (!isValidDate()) {
		cout << "Ngay thang nam khong hop le, vui long nhap lai" << endl;
		Import();
	}
}
void Date::Export() {
	cout << day << "/" << month << "/" << year << endl;
}
