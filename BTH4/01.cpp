#include <iostream>
using namespace std;
class time {
    int hour;
    int minute;
    int second;
public:
    time() {
    }
    time(int hour, int minute, int second) {
        this->hour = hour;
        this->minute = minute;
        this->second = second;
    }
    time operator+(time);
    void import();
    void print();
};
int main()
{
    time a, b;
    cout << "Thoi diem dau tien: " << endl;
    a.import();
    system("cls");
    cout << "Thoi diem thu hai: " << endl;
    b.import();
    system("cls");
    cout << "Thoi gian nhap vao: " << endl;
    cout << "Thoi diem dau tien la: ";
    a.print();
    cout << "Thoi diem thu hai:     ";
    b.print();
    cout << endl;
    time time_total = a + b;
    cout << "Tong thoi gian la ";
    time_total.print();
    cout << endl;
    system("pause");
}
time time::operator+(time x) {
    time temp(0, 0, 0);
    temp.second = second + x.second;
    temp.minute = minute + x.minute;
    temp.hour = hour + x.hour;
    while (temp.second >= 60) {
        temp.minute++;
        temp.second -= 60;
    }
    while (temp.minute >= 60) {
        temp.hour++;
        temp.minute -= 60;
    }
    return temp;
}
void time::import() {
    cout << "Nhap gio: ";
    cin >> hour;
    while (hour < 0) {
        cout << "Gio phai la so nguyen duong" << endl;
        cout << " Nhap lai gio: ";
        cin >> hour;
    }
    cout << "Nhap phut: ";
    cin >> minute;
    while (minute < 0 || minute >= 60) {
        cout << "Phut phai nam trong khoang (0;60)" << endl;
        cout << " Nhap lai phut: ";
        cin >> minute;
    }
    cout << "Nhap giay: ";
    cin >> second;
    while (second < 0 || second >= 60) {
        cout << "Giay phai nam trong khoang (0;60)" << endl;
        cout << " Nhap lai giay: ";
        cin >> second;
    }
}
void time::print() {
    if (minute == 0 && second == 0)
        cout << hour << " gio " << endl;
    else if (second == 0)
        cout << hour << " gio " << minute << " phut " << endl;
    else cout << hour << " gio " << minute << " phut " << second << " giay " << endl;
}