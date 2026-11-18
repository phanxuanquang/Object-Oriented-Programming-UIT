#include <iostream>
using namespace std;

class Point {
    double x, y;

public:
    void set(double, double);

    double getX();
    double getY();

    void input();
    void output();

    Point operator+(Point);
};

class DaGiac {
    int vertexSize;
    Point vertices[];

public:
    void input();
    void ouput();

    void moveFollowVector(Point);
    Point getCentroidPoint();
};

void printMenu();
void choose(DaGiac&);

void movePolygon(DaGiac&);
void printCenteroidPointOf(DaGiac);

int main() {
    DaGiac polygon;
    polygon.input();
    system("cls");
    choose(polygon);
    system("pause");
}

void printMenu() {
    cout << "_______________________________" << endl;
    cout << "0. Thoat" << endl;
    cout << "1. Nhap da giac" << endl;
    cout << "2. Xuat da giac" << endl;
    cout << "3. Tinh tien da giac" << endl;
    cout << "4. Lay trong tam da giac" << endl;
    cout << "_______________________________" << endl;
}
void choose(DaGiac& polygon) {
    printMenu();
    int choice;
    cout << "Nhap lua chon: ";
    cin >> choice;
    system("cls");
    switch (choice) {
    case 0:
        return;
    case 1:
        polygon.input();
        break;
    case 2:
        polygon.ouput();
        break;
    case 3:
        movePolygon(polygon);
        break;
    case 4:
        printCenteroidPointOf(polygon);
        break;
    default:
        cout << "Lua chon khong hop le" << endl;
        break;
    }
    choose(polygon);
}

double Point::getX() {
    return x;
}
double Point::getY() {
    return y;
}
void Point::input() {
    cout << "\n Hoanh do: ";
    cin >> x;
    cout << " Tung do: ";
    cin >> y;
}
void Point::output() {
    cout << "(" << x << "," << y << ") ";
}
void Point::set(double x, double y) {
    this->x = x;
    this->y = y;
}
Point Point::operator+(Point move) {
    Point temp;
    temp.x = x + move.x;
    temp.y = y + move.y;
    return temp;
}

void DaGiac::input() {
    cout << "So luong dinh cua da giac la ";
    cin >> vertexSize;
    system("cls");
    cout << "Nhap toa do dinh cua da giac: " << endl;
    for (int i = 0; i < vertexSize; i++) {
        cout << "Nhap dinh thu " << i + 1 << ": ";
        vertices[i].input();
    }
}
void DaGiac::ouput() {
    cout << "Toa do cac dinh cua da giac la: ";
    for (int i = 0; i < vertexSize; i++)
        vertices[i].output();
    cout << endl;
}
void DaGiac::moveFollowVector(Point vector) {
    for (int i = 0; i < vertexSize; i++)
        vertices[i] = vertices[i] + vector;
}
Point DaGiac::getCentroidPoint() {
    Point temp;
    temp.set(0, 0);
    for (int i = 0; i < vertexSize; i++)
        temp = temp + vertices[i];
    temp.set(temp.getX() / vertexSize, temp.getY() / vertexSize);
    return temp;
}

void movePolygon(DaGiac& polygon) {
    Point vectorForMoving;
    cout << "Nhap toa do vector tinh tien:";
    vectorForMoving.input();
    system("cls");
    polygon.moveFollowVector(vectorForMoving);
    cout << "Da tinh tien da giac theo vector (" << vectorForMoving.getX() << "," << vectorForMoving.getY() << ")." << endl;
    polygon.ouput();
}
void printCenteroidPointOf(DaGiac polygon) {
    cout << "Toa do trong tam da giac la ";
    polygon.getCentroidPoint().output();
    cout << endl;
}
