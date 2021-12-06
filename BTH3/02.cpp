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
class TamGiac {
    point a, b, c;
public:
    void TamGiac_import();
    void TamGiac_export();
    void move_vector();
    point centroid();
};

void call_menu();
void choice(TamGiac&);

int main() {
    TamGiac x;
    call_menu();
    choice(x);
    system("pause");
}

void call_menu() {
    cout << "_______________________________" << endl;
    cout << "1. Nhap tam giac" << endl;
    cout << "2. Xuat tam giac" << endl;
    cout << "3. Tinh tien tam giac" << endl;
    cout << "4. Lay trong tam tam giac" << endl;
    cout << "_______________________________" << endl;
}
void choice(TamGiac& a) {
    int x;
    cout << "Nhap lua chon: ";
    cin >> x;
    switch (x) {
    case 1:
        system("cls");
        a.TamGiac_import();
        call_menu();
        choice(a);
        break;
    case 2:
        system("cls");
        a.TamGiac_export();
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
        cout << "Toa do trong tam tam giac la ";
        a.centroid().point_export();
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
void point::point_import() {
    cout << "\n Hoanh do: ";
    cin >> x;
    cout << " Tung do: ";
    cin >> y;
}
void point::point_export() {
    cout << "(" << x << "," << y << ")" << endl;
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

void TamGiac::TamGiac_import() {
    cout << "Nhap toa do ba dinh cua tam giac: " << endl;
    cout << "Dinh thu nhat: ";
    a.point_import();
    cout << "Dinh thu hai: ";
    b.point_import();
    cout << "Dinh thu ba: ";
    c.point_import();
}
void TamGiac::TamGiac_export() {
    cout << "Toa do ba dinh cua tam giac la: " << endl;
    cout << "Dinh thu nhat co toa do ";
    a.point_export();
    cout << "Dinh thu hai co toa do ";
    b.point_export();
    cout << "Dinh thu ba co toa do ";
    c.point_export();
}
void TamGiac::move_vector() {
    point vector_move;
    cout << "Nhap toa do vector tinh tien:" << endl;
    vector_move.point_import();
    system("cls");
    a = a + vector_move;
    b = b + vector_move;
    c = c + vector_move;
    cout << "Da tinh tien tam giac theo vector (" << vector_move.get_x() << "," << vector_move.get_y() << ")" << endl;
}
point TamGiac::centroid() {
    point temp = a + b + c;
    temp.set(temp.get_x() / 3, temp.get_y() / 3);
    return temp;
}