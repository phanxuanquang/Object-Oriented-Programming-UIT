#include <iostream>
using namespace std;

class point {
    double x, y;
public:
    void change(double, double);
    double get_x();
    double get_y();
    void point_import();
    void point_export();
    void move_vector();
};

void call_menu();
void choice(point&);

int main() {
    point x;
    cout << "Nhap toa do cua diem: ";
    x.point_import();
    call_menu();
    choice(x);
    system("pause");
}

void call_menu() {
    cout << "_______________________________" << endl;
    cout << "1. Lay hoanh do" << endl;
    cout << "2. Lay tung do" << endl;
    cout << "3. Tinh tien diem" << endl;
    cout << "4. Thay doi toa do diem" << endl;
    cout << "5. Xuat toa do diem" << endl;
    cout << "_______________________________" << endl;
}
void choice(point& a) {
    int x;
    cout << "Nhap lua chon: ";
    cin >> x;
    switch (x) {
        case 1:
            system("cls");
            cout << "Hoanh do cua diem la " << a.get_x() << endl;
            call_menu();
            choice(a);
            break;
        case 2:
            system("cls");
            cout << "Tung do cua diem la " << a.get_y() << endl;
            call_menu();
            choice(a);
            break;
        case 3:
            system("cls");
            a.move_vector();
            call_menu();
            choice(a);
            break;
        case 4:
            system("cls");
            point new_point;
            cout << "Nhap toa do diem moi" << endl;
            new_point.point_import();
            a.change(new_point.get_x(), new_point.get_y());
            cout << "Thay doi toa do diem thanh cong";
            call_menu();
            choice(a);
            break;
        case 5:
            system("cls");
            cout << "Diem co toa do ";
            a.point_export();
            call_menu();
            choice(a);
            break;
        default:
            system("cls");
            cout << "Lua chon khong ton tai" << endl;
            call_menu();
            choice(a);
            break;
    }
}

double point::get_x() {
    return x;
}
double point::get_y() {
    return y;
}
void point::change(double x, double y) {
    this->x = x;
    this->y = y;
}
void point::point_import() {
    cout << "\n Hoanh do: ";
    cin >> x;
    cout << " Tung do: ";
    cin >> y;
}
void point::point_export() {
    cout << "(" << x << "," << y << ")" << endl;
}
void point::move_vector() {
    double x, y;
    cout << "Hoanh do cua vector tinh tien: ";
    cin >> x;
    cout << "Tung do cua vector tinh tien: ";
    cin >> y;
    system("cls");
    change(x + this->x, y + this->y);
    cout << "Tinh tien diem thanh cong" << endl;
}