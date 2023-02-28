#include <iostream>
using namespace std;

class Stack {
    int currentSize = -1;
    int* arr = new int[1000];

public:
    void stackExport(int x);
    void push(int);
};

void toBinary(int number);
void toOctal(int number);
void toHexa(int number);

void callMenu();

void choose(int);

int main() {
    int number;
    Stack stack;
    cout << "So can phan tich la ";
    cin >> number;

    choose(number);
}

void callMenu() {
    cout << "________________________________" << endl;
    cout << " (0) Thoat chuong trinh." << endl;
    cout << " (1) Doi sang he nhi phan." << endl;
    cout << " (2) Doi sang he bat phan." << endl;
    cout << " (3) Doi sang he thap luc phan." << endl;
    cout << "________________________________" << endl;
}
void choose(int number) {
    callMenu();

    int choice;
    cout << "Lua chon cua ban la: ";
    cin >> choice;

    system("cls");
    switch (choice) {
    case 0:
        return;
    case 1:
        toBinary(number);
        break;
    case 2:
        toOctal(number);
        break;
    case 3:
        toHexa(number);
        break;
    default:
        cout << "Lua chon khong hop le, hay nhap lai" << endl;
        break;
    }
    choose(number);
}

void toBinary(int number) {
    if (number == 0) {
        cout << number << " = " << 0;
    }
    else {
        Stack binary;
        int print = number;
        while (number > 0) {
            int temp = number % 2;
            binary.push(temp);
            number /= 2;
        }
        binary.stackExport(print);
    }
    cout << " (2)" << endl;
}
void toOctal(int number) {
    if (number == 0) {
        cout << number << " = " << 0;
    }
    else {
        Stack octal;
        int print = number;
        while (number > 0) {
            int temp = number % 8;
            octal.push(temp);
            number /= 8;
        }
        octal.stackExport(print);
    }
    cout << " (8)" << endl;
}
void toHexa(int number) {
    if (number == 0) {
        cout << number << " = " << 0;
    }
    else {
        Stack hexa;
        int print = number;
        while (number > 0) {
            int temp = number % 16;
            hexa.push(temp);
            number /= 16;
        }
        hexa.stackExport(print);
    }
    cout << " (16)" << endl;
}

void Stack::stackExport(int x) {
    cout << x << " = ";
    for (int i = currentSize; i >= 0; i--) {
        if (arr[i] < 10) {
            cout << arr[i];
        }
        else {
            cout << char(arr[i] + 55);
        }
    }
}
void Stack::push(int addElement) {
    currentSize++;
    arr[currentSize] = addElement;
}
