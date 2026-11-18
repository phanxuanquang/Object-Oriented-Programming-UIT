#include <iostream>
#include<string>
using namespace std;

class Student {
    string name;
    double mathGrade, literatureGrade;

public:
    void input();
    double getAverageGrade();
};

int main()
{
    Student student;
    cout << "Nhap thong tin hoc sinh: " << endl;
    student.input();

    cout << "Diem trung binh: " << student.getAverageGrade() << endl;
    system("pause");
}

void Student::input() {
    cout << " Ho va ten: ";
    cin.ignore();
    getline(cin, name);
    cout << " Diem toan: ";
    cin >> mathGrade;
    cout << " Diem van: ";
    cin >> literatureGrade;
    while (mathGrade < 0 || mathGrade > 10 || literatureGrade > 10 || literatureGrade < 0)
    {
        system("cls");
        cout << endl << "Diem so khong hop le, hay nhap lai thong tin hoc sinh." << endl;
        input();
    }
}
double Student::getAverageGrade() {
    return (mathGrade + literatureGrade) / 2;
}
