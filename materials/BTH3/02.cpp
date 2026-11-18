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
    
    double getDistanceTo(Point);

    Point operator+(Point);
};

class TamGiac {
    Point a, b, c;

public:
    void input();
    void output();

    bool isValidTriangle();

    void moveFollowVector(Point);
    Point getCentroidPoint();
};

void printMenu();
void choose(TamGiac&);

void moveTriangle(TamGiac&);
void printCentoroidPointOf(TamGiac);

int main() {
    TamGiac triangle;
    triangle.input();
    system("cls");
    choose(triangle);
    system("pause");
}

void printMenu() {
    cout << "_______________________________" << endl;
    cout << "0. Thoat" << endl;
    cout << "1. Nhap tam giac" << endl;
    cout << "2. Xuat tam giac" << endl;
    cout << "3. Tinh tien tam giac" << endl;
    cout << "4. Lay trong tam tam giac" << endl;
    cout << "_______________________________" << endl;
}
void choose(TamGiac& triangle) {
    printMenu();
    int x;
    cout << "Lua chon cua ban la ";
    cin >> x;
    system("cls");
    switch (x) {
    case 0:
        return;
    case 1:
        triangle.input();
        break;
    case 2:
        triangle.output();
        break;
    case 3:
        moveTriangle(triangle);
        break;
    case 4:
        printCentoroidPointOf(triangle);
        break;
    default:
        cout << "Lua chon khong ton tai" << endl;
        break;
    }
    choose(triangle);
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
    cout << "(" << x << "," << y << ")" << endl;
}
void Point::set(double x, double y) {
    this->x = x;
    this->y = y;
}
double Point::getDistanceTo(Point anotherPoint) {
    return sqrt((x - anotherPoint.getX()) * (x - anotherPoint.getX()) + (y - anotherPoint.getY()) * (y - anotherPoint.getY()));
}
Point Point::operator+(Point move) {
    Point temp;
    temp.x = x + move.x;
    temp.y = y + move.y;
    return temp;
}

void TamGiac::input() {
    cout << "Nhap toa do ba dinh cua tam giac: " << endl;

    cout << "Dinh thu nhat: ";
    a.input();
    cout << "Dinh thu hai: ";
    b.input();
    cout << "Dinh thu ba: ";
    c.input();

    if (!isValidTriangle()) {
        system("cls");
        cout << "Tam giac nay khong ton tai. Vui long nhap lai toa do ba dinh cua tam giac." << endl;
        input();
    }
}
void TamGiac::output() {
    cout << "Toa do ba dinh cua tam giac: " << endl;
    cout << " Dinh thu nhat: ";
    a.output();
    cout << " Dinh thu hai: ";
    b.output();
    cout << " Dinh thu ba: ";
    c.output();
}
bool TamGiac::isValidTriangle() {
    double edgeAB = a.getDistanceTo(b);
    double edgeBC = b.getDistanceTo(c);
    double edgeAC = a.getDistanceTo(c);

    if ((edgeAB + edgeBC > edgeAC) && (edgeBC + edgeAC > edgeAB) && (edgeAB + edgeAC > edgeBC))
        return true;
    return false;
}
void TamGiac::moveFollowVector(Point vector) {
    a = a + vector;
    b = b + vector;
    c = c + vector;
}
Point TamGiac::getCentroidPoint() {
    Point result = a + b + c;
    result.set(result.getX() / 3, result.getY() / 3);
    return result;
}

void moveTriangle(TamGiac& triangle) {
    Point vectorForMoving;
    cout << "Nhap toa do vector tinh tien:";
    vectorForMoving.input();
    triangle.moveFollowVector(vectorForMoving);
    system("cls");
    cout << "Da tinh tien tam giac theo vector (" << vectorForMoving.getX() << "," << vectorForMoving.getY() << ")." << endl;
    triangle.output();
}
void printCentoroidPointOf(TamGiac triangle) {
    cout << "Toa do trong tam tam giac la ";
    triangle.getCentroidPoint().output();
}
