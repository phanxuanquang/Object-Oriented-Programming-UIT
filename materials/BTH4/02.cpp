#include <iostream>
using namespace std;

class Stack {
	int maxSize, currentSize;
	int* arr = new int[maxSize];
public:
	Stack() {
		currentSize = -1;
	}
	void importSize();
	void output();
	void deleteStack();

	bool isEmpty();
	bool isFull();

	void push(int);
	void pop();

	int getValueAtTop();
};
void addElementTo(Stack&);
void showMenu();
void handleTasksFor(Stack&);

int main() {
	Stack Stack;
	Stack.importSize();
	showMenu();
	handleTasksFor(Stack);
}

void addElementTo(Stack& stack) {
	int element;
	cout << "Phan tu muon them la: ";
	cin >> element;
	system("cls");
	stack.push(element);
}
void showMenu() {
	cout << "_____________________________________________" << endl;
	cout << "1. Push (them phan tu tren dau ngan xep)" << endl;
	cout << "2. Pop (lay ra phan tu tren dau ngan xep" << endl;
	cout << "3. In ra phan tu tren dau ngan xep" << endl;
	cout << "4. In ra ngan xep hien tai" << endl;
	cout << "5. Xoa ngan xep da tao" << endl;
	cout << "_____________________________________________" << endl;
}
void handleTasksFor(Stack& stack) {
	int choice;
	cout << "Lua chon cua ban la: ";
	cin >> choice;
	system("cls");
	switch (choice) {
	case 1:
		addElementTo(stack);
		break;
	case 2:
		stack.pop();
		break;
	case 3:
		cout << "Phan tu tren dau ngan xep la " << stack.getValueAtTop() << endl;
		break;
	case 4:
		stack.output();
		break;
	case 5:
		stack.deleteStack();
		break;
	default:
		cout << "Lua chon khong hop le, hay nhap lai." << endl;
		break;
	}
	showMenu();
	handleTasksFor(stack);
}

void Stack::importSize() {
	cout << "Cho trong toi da cua ngan xep la ";
	cin >> maxSize;
}
void Stack::output() {
	if (!isEmpty()) {
		cout << "Ngan xep hien tai la: ";
		for (int i = currentSize; i >= 0; i--)
			cout << arr[i] << " ";
	}
	else cout << "Ngan xep rong";
	cout << endl;
}
bool Stack::isEmpty() {
	if (currentSize == -1)
		return true;
	return false;
}
bool Stack::isFull() {
	if (currentSize == maxSize - 1)
		return true;
	return false;
}
void Stack::push(int element) {
	if (!isFull()) {
		currentSize++;
		arr[currentSize] = element;
		cout << "Da them phan tu " << element << " vao ngan xep" << endl;
	}
	else cout << "Ngan xep da day" << endl;
}
void Stack::pop() {
	if (!isEmpty()) {

		cout << "Da lay phan tu " << arr[currentSize] << " khoi ngan xep" << endl;
		currentSize--;
	}
	else cout << "Ngan xep rong" << endl;
}
int Stack::getValueAtTop() {
	if (!isEmpty())
		return arr[currentSize];
	else {
		cout << "Ngan xep rong" << endl;
		return -1;
	}
}
void Stack::deleteStack() {
	currentSize = -1;
	cout << "Da xoa ngan xep." << endl;
}
