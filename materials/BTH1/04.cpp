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

	void input();
	void output();

	bool isLeapYear();
	bool isValidDate();

	Date getNextDate();
};

int main(){
	Date date;
	cout << "Nhap ngay thang nam: " << endl;
	date.input();

	cout << "Ngay tiep theo la ";
	date.getNextDate().output();

	system("pause");
}

void Date::input() {
	cout << "  Nhap ngay: ";
	cin >> day;
	cout << "  Nhap thang: ";
	cin >> month;
	cout << "  Nhap nam: ";
	cin >> year;

	if (!isValidDate()) {
		system("cls");
		cout << "Ngay thang nam khong hop le, vui long nhap lai" << endl;
		input();
	}
}
void Date::output() {
	cout << day << "/" << month << "/" << year << endl;
}

bool Date::isLeapYear(){
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		return true;
	return false;
}
bool Date::isValidDate() {
	if (year < 1 || day < 1)
		return false;
	if (month < 1 || month > 12)
		return false;
	if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && (day > 31))
		return false;
	if ((month == 4 || month == 6 || month == 9 || month == 11) && (day > 30))
		return false;
	if ((isLeapYear() && month == 2 && day > 29) || (!isLeapYear() && month == 2 && day > 28))
		return false;
	return true;
}

Date Date::getNextDate() {
	Date tempDate(++this->day, this->month, this->year);

	if (tempDate.day > 31) {
		tempDate.day = 1;
		tempDate.month++;
		if (tempDate.month > 12) {
			tempDate.month = 1;
			tempDate.year++;
		}
	}
	else if (tempDate.day > 30) {
		if ((tempDate.month == 4 || tempDate.month == 6 || tempDate.month == 9 || tempDate.month == 11))
		{
			tempDate.day = 1;
			tempDate.month++;
		}
	}
	else if (tempDate.month == 2) {
		if (isLeapYear()) {
			if (tempDate.day > 29)
			{
				tempDate.day = 1;
				tempDate.month++;
			}
		}
		else {
			if (tempDate.day > 28)
			{
				tempDate.day = 1;
				tempDate.month++;
			}
		}
	}

	return tempDate;
}
