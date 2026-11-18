#include <iostream>

using namespace std;

class Stack {
    int currentSize = -1;
    int* arr = new int[1000];

public:
    void output(int x);
    void push(int);
};

bool isPrime(int);
void addToStack(int, int, Stack&);

int main() {
    int number;
    Stack stack;
    cout << "So can phan tich la ";
    cin >> number;

    for (int i = 2; i < number - 1; i++) {
        if (number % i == 0 && isPrime(i))
            addToStack(number, i, stack);
    }
    system("cls");

    stack.output(number);
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

void addToStack(int number, int index, Stack& stack) {
    while (number % index == 0) {
        stack.push(index);
        number /= index;
    }
}

void Stack::output(int x) {
    cout << x << " = ";
    for (int i = currentSize; i > 0; i--)
        cout << arr[i] << " * ";
    cout << arr[0] << endl;
}

void Stack::push(int addElement) {
    currentSize++;
    arr[currentSize] = addElement;
}
