#include <iostream>
using namespace std;

class Stack {
    int size = -1;
    int* arr = new int[10000000];

public:
    void output(int);
    void push(int);
};
void convertToBinaryFrom(int number);
void convertToOctalFrom(int number);
void convertToHexaFrom(int number);

void showMenu();
void handleTasksFor(int);

int main() {
    int number;
    Stack stack;

    cout << "So can phan tich la ";
    cin >> number;

    showMenu();
    handleTasksFor(number);
}

void showMenu() {
    cout << "________________________________" << endl;
    cout << "1. Doi sang he nhi phan" << endl;
    cout << "2. Doi sang he bat phan" << endl;
    cout << "3. Doi sang he thap luc phan" << endl;
    cout << "________________________________" << endl;
}
void handleTasksFor(int number) {
    int choice;
    cout << "Lua chon cua ban la: ";
    cin >> choice;
    system("cls");

    switch (choice) {
    case 1:
        convertToBinaryFrom(number);
        break;
    case 2:
        convertToOctalFrom(number);
        break;
    case 3:
        convertToHexaFrom(number);
        break;
    default:
        cout << "Lua chon khong hop le, hay nhap lai." << endl;
        break;
    }

    showMenu();
    handleTasksFor(number);
}

void convertToBinaryFrom(int number) {
    if (number == 0)
        cout << number << " = " << 0;
    else {
        Stack binary;
        int print = number;
        while (number > 0) {
            int temp = number % 2;
            binary.push(temp);
            number /= 2;
        }
        binary.output(print);
    }
    cout << " (2)" << endl;
}
void convertToOctalFrom(int number) {
    if (number == 0)
        cout << number << " = " << 0;
    else {
        Stack octal;
        int print = number;
        while (number > 0) {
            int temp = number % 8;
            octal.push(temp);
            number /= 8;
        }
        octal.output(print);
    }
    cout << " (8)" << endl;
}
void convertToHexaFrom(int number) {
    if (number == 0)
        cout << number << " = " << 0;
    else {
        Stack hexa;
        int print = number;
        while (number > 0) {
            int temp = number % 16;
            hexa.push(temp);
            number /= 16;
        }
        hexa.output(print);
    }
    cout << " (16)" << endl;
}

void Stack::output(int number) {
    cout << number << " = ";
    for (int i = size; i >= 0; i--) {
        if (arr[i] < 10)
            cout << arr[i];
        else cout << char(arr[i] + 55);
    }
}
void Stack::push(int newElement) {
    size++;
    arr[size] = newElement;
}
