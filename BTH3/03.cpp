#include <iostream>
using namespace std;

class point {
    double x, y;
public:
    void set(double, double);
    double get_x();
    double get_y();
    void point_import();
    void point_export();
    point operator+(point);
};

class DaGiac {
    int amount;
    point a[];
public:
    void DaGiac_import();
    void DaGiac_export();
    void move_vector();
    point centroid();
};

void call_menu();
void choice(DaGiac&);

int main() {
    DaGiac x;
    call_menu();
    choice(x);
    system("pause");
}

void call_menu() {
    cout << "_______________________________" << endl;
    cout << "1. Nhap da giac" << endl;
    cout << "2. Xuat da giac" << endl;
    cout << "3. Tinh tien da giac" << endl;
    cout << "4. Lay trong tam da giac" << endl;
    cout << "_______________________________" << endl;
}
void choice(DaGiac& a) {
    int x;
    cout << "Nhap lua chon: ";
    cin >> x;
    switch (x) {
    case 1:
        system("cls");
        a.DaGiac_import();
        call_menu();
        choice(a);
        break;
    case 2:
        system("cls");
        a.DaGiac_export();
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
        cout << "Toa do trong tam da giac la ";
        a.centroid().point_export();
        cout << endl;
        call_menu();
        choice(a);
        break;
    default:
        system("cls");
        cout << "Lua chon khong hop le" << endl;
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
void point::point_import() {
    cout << "\n Hoanh do: ";
    cin >> x;
    cout << " Tung do: ";
    cin >> y;
}
void point::point_export() {
    cout << "(" << x << "," << y << ") ";
}
void point::set(double x, double y) {
    this->x = x;
    this->y = y;
}
point point::operator+(point move) {
    point temp;
    temp.x = x + move.x;
    temp.y = y + move.y;
    return temp;
}

void DaGiac::DaGiac_import() {
    cout << "So luong dinh cua da giac la ";
    cin >> amount;
    system("cls");
    cout << "Nhap toa do dinh cua da giac: " << endl;
    for (int i = 0; i < amount; i++) {
        cout << "Nhap dinh thu " << i + 1 << ": ";
        a[i].point_import();
    }
}
void DaGiac::DaGiac_export() {
    cout << "Toa do cac dinh cua da giac la: " << endl;
    for (int i = 0; i < amount; i++) 
        a[i].point_export();
    cout << endl;
}
void DaGiac::move_vector() {
    point vector_move;
    cout << "Nhap toa do vector tinh tien:";
    vector_move.point_import();
    system("cls");
    for (int i = 0; i < amount; i++)
        a[i] = a[i] + vector_move;
    cout << "Da tinh tien da giac theo vector (" << vector_move.get_x() << "," << vector_move.get_y() << ")" << endl;
}
point DaGiac::centroid() {
    point temp;
    temp.set(0, 0);
    for (int i = 0; i < amount; i++)
        temp = temp + a[i];
    temp.set(temp.get_x() / amount, temp.get_y() / amount);
    return temp;
}