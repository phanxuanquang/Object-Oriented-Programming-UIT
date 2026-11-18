#include <iostream>
using namespace std;

class Point {
    double x, y;

public:
    Point() {
        x = y = 0;
    }

    double getX();
    double getY();

    void set(double, double);

    void input();
    void output();
};

void printMenu();
void choose(Point&);

void printPointX(Point);
void printPointY(Point);
void printPoint(Point);
void changePoint(Point&);
void move_vector(Point&);

int main() {
    Point point;
    cout << "Nhap toa do cua diem: ";
    point.input();

    choose(point);

    system("pause");
}

double Point::getX() {
    return x;
}
double Point::getY() {
    return y;
}
void Point::set(double x, double y) {
    this->x = x;
    this->y = y;
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

void printPointX(Point point) {
    cout << "Hoanh do cua diem la " << point.getX() << endl;
}
void printPointY(Point point) {
    cout << "Hoanh do cua diem la " << point.getY() << endl;
}
void printPoint(Point point) {
    cout << "Toa do cua diem la ";
    point.output();
}
void changePoint(Point &point) {
    int newX, newY;
    cout << "Hoang do moi: ";
    cin >> newX;
    cout << "Tung do moi: ";
    cin >> newY;
    system("cls");

    point.set(newX, newY);

    cout << "Thay doi toa do diem thanh cong. Toa do moi la ";
    point.output();
}
void move_vector(Point& point) {
    double vectorX, vectorY;
    cout << "Hoanh do cua vector tinh tien: ";
    cin >> vectorX;
    cout << "Tung do cua vector tinh tien: ";
    cin >> vectorY;
    system("cls");

    point.set(vectorX + point.getX(), vectorY + point.getY());

    cout << "Tinh tien diem thanh cong. Toa do moi la ";
    point.output();
}

void printMenu() {
    cout << "_______________________________" << endl;
    cout << " 1. Lay hoanh do" << endl;
    cout << " 2. Lay tung do" << endl;
    cout << " 3. Tinh tien diem" << endl;
    cout << " 4. Thay doi toa do diem" << endl;
    cout << " 5. Xuat toa do diem" << endl;
    cout << " 6. Thoat" << endl;
    cout << "_______________________________" << endl;
}
void choose(Point& point) {
    printMenu();

    int choice;
    cout << "Lua chon cua ban la: ";
    cin >> choice;
    system("cls");

    switch (choice) {
    case 1:
        printPointX(point);
        break;
    case 2:
        printPointY(point);
        break;
    case 3:
        move_vector(point);
        break;
    case 4:
        changePoint(point);
        break;
    case 5:
        printPoint(point);
        break;
    case 6:
        return;
    default:
        cout << "Lua chon khong ton tai" << endl;
        break;
    }
    
    choose(point);
}
