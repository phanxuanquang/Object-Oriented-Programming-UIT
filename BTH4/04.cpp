#include <iostream>
using namespace std;

class stack {
    int current_size = -1;
    int* arr = new int[1000];
public:
    void stack_export(int x);
    void push(int);
};
void to_binary(int number);
void to_octal(int number);
void to_hexa(int number);

void call_menu() {
    cout << "________________________________" << endl;
    cout << "1. Doi sang he nhi phan" << endl;
    cout << "2. Doi sang he bat phan" << endl;
    cout << "3. Doi sang he thap luc phan" << endl;
    cout << "________________________________" << endl;
}
void choose(int x) {
    int choice;
    cout << "Lua chon cua ban la: ";
    cin >> choice;
    switch (choice){
    case 1:
        system("cls");
        to_binary(x);
        call_menu();
        choose(x);
        break;
    case 2:
        system("cls");
        to_octal(x);
        call_menu();
        choose(x);
        break;
    case 3:
        system("cls");
        to_hexa(x);
        call_menu();
        choose(x);
        break;
    default:
        system("cls");
        cout << "Lua chon khong hop le, hay nhap lai" << endl;
        call_menu();
        choose(x);
        break;
    }
}

int main(){
    int x;
    stack Stack;
    cout << "So can phan tich la ";
    cin >> x;
    call_menu();
    choose(x);
}

void to_binary(int number) {
    if (number == 0)
        cout << number << " = " << 0;
    else {
        stack binary;
        int print = number;
        while (number > 0) {
            int temp = number % 2;
            binary.push(temp);
            number /= 2;
        }
        binary.stack_export(print);
    }
    cout << " (2)" << endl;
}
void to_octal(int number) {
    if (number == 0)
        cout << number << " = " << 0;
    else {
        stack octal;
        int print = number;
        while (number > 0) {
            int temp = number % 8;
            octal.push(temp);
            number /= 8;
        }
        octal.stack_export(print);
    }
    cout << " (8)" << endl;
}
void to_hexa(int number) {
    if (number == 0)
        cout << number << " = " << 0;
    else {
        stack hexa;
        int print = number;
        while (number > 0) {
            int temp = number % 16;
            hexa.push(temp);
            number /= 16;
        }
        hexa.stack_export(print);
    }
    cout << " (16)" << endl;
}

void stack::stack_export(int x) {
    cout << x << " = ";
    for (int i = current_size; i >= 0; i--) {
        if (arr[i] < 10)
            cout << arr[i];
        else cout << char(arr[i] + 55);
    }
}
void stack::push(int add_element) {
    current_size++;
    arr[current_size] = add_element;
}