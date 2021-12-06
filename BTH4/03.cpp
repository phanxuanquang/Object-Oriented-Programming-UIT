#include <iostream>
using namespace std;

class stack {
    int current_size = -1;
    int* arr = new int[1000];
public:
    void stack_export(int x);
    void push(int);
};

bool isPrime(int);
void add_toStack(int, int, stack&);

int main()
{
    int x;
    stack Stack;
    cout << "So can phan tich la ";
    cin >> x;
    for (int i = 2; i < x - 1; i++) {
        if (x % i == 0 && isPrime(i))
            add_toStack(x, i, Stack);
    }
    system("cls");
    Stack.stack_export(x);
    system("pause");
}

bool isPrime(int x) {
    if (x < 2)
        return false;
    for (int i = 2; i < x - 1; i++)
        if (x % i == 0)
            return false;
    return true;
}
void add_toStack(int number, int index, stack& Stack) {
    while (number % index == 0) {
        Stack.push(index);
        number /= index;
    }
}

void stack::stack_export(int x) {
    cout << x << " = ";
    for (int i = current_size; i > 0; i--)
        cout << arr[i] << " * ";
    cout << arr[0] << endl;
}
void stack::push(int add_element) {
        current_size++;
        arr[current_size] = add_element;
}
