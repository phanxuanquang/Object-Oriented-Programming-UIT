#include <iostream>
using namespace std;

class Time {
    int hour;
    int minute;
    int second;

public:
    Time(int hour = 0, int minute = 0, int second = 0) {
        this->hour = hour;
        this->minute = minute;
        this->second = second;
    }

    Time operator+(Time other_time);

    void input();
    void output();
};

int main() {
    Time time1, time2;

    cout << "Nhap thoi diem dau tien: " << endl;
    time1.input();

    cout << "Nhap thoi diem thu hai: " << endl;
    time2.input();

    Time time_total = time1 + time2;

    cout << "Thoi diem dau tien la: ";
    time1.output();

    cout << "Thoi diem thu hai la:  ";
    time2.output();

    cout << "Tong thoi gian la:     ";
    time_total.output();

    return 0;
}

Time Time::operator+(Time otherTime) {
    int totalSeconds = second + otherTime.second;
    int carryMinutes = totalSeconds / 60;
    totalSeconds %= 60;

    int totalMinutes = minute + otherTime.minute + carryMinutes;
    int carryHours = totalMinutes / 60;
    totalMinutes %= 60;

    int totalHours = hour + otherTime.hour + carryHours;

    return Time(totalHours, totalMinutes, totalSeconds);
}

void Time::input() {
    cout << "Nhap gio: ";
    cin >> hour;
    while (hour < 0) {
        cout << "Gio phai la so nguyen duong." << endl;
        cout << "Nhap lai gio: ";
        cin >> hour;
    }

    cout << "Nhap phut: ";
    cin >> minute;
    while (minute < 0 || minute >= 60) {
        cout << "Phut phai nam trong khoang (0;60)." << endl;
        cout << "Nhap lai phut: ";
        cin >> minute;
    }

    cout << "Nhap giay: ";
    cin >> second;
    while (second < 0 || second >= 60) {
        cout << "Giay phai nam trong khoang (0;60)." << endl;
        cout << "Nhap lai giay: ";
        cin >> second;
    }
}
void Time::output() {
    if (minute == 0 && second == 0)
        cout << hour << " gio " << endl;
    else if (second == 0)
        cout << hour << " gio " << minute << " phut " << endl;
    else
        cout << hour << " gio " << minute << " phut " << second << " giay " << endl;
}
