#include <iostream>
#include<string>
using namespace std;
class student {
public:
    string name;
    double math, literature;
    void import();
    double averageScore();
};
void main()
{
    student hocSinh;
    cout << "Nhap thong tin hoc sinh: " << endl;
    hocSinh.import();
    cout << "Diem trung binh la " << hocSinh.averageScore() << endl;
    system("pause");
}
void student::import() {
    cout << " Ho va ten hoc sinh: ";
    int temp = getchar();
    getline(cin, name);
    cout << " Diem toan: ";
    cin >> math;
    cout << " Diem van: ";
    cin >> literature;
    while (math < 0 || math > 10 || literature > 10 || literature < 0)
    {
        cout << endl << "Diem so khong hop le, hay nhap lai thong tin hoc sinh." << endl;
        import();
    }
}
double student::averageScore() {
    return (math + literature) / 2;
}