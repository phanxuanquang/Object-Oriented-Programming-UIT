#include <iostream>
using namespace std;

class stack {
	int max_size, current_size;
	int* arr = new int[max_size];
public:
	stack(){
		current_size = -1;
	}
	void import_size();
	void stack_export();
	bool isEmpty();
	bool isFull();
	void push(int);
	void pop();
	int getTop();
	void deleteStack();
};
void addElement_to(stack&);
void call_menu();
void choose(stack&);

int main() {
	stack Stack;
	Stack.import_size();
	call_menu();
	choose(Stack);
}

void addElement_to(stack& x) {
	int add_element;
	cout << "Phan tu muon them la: ";
	cin >> add_element;
	system("cls");
	x.push(add_element);
}
void call_menu() {
	cout << "_____________________________________________" << endl;
	cout << "1. Push (them phan tu tren dau ngan xep)" << endl;
	cout << "2. Pop (lay ra phan tu tren dau ngan xep" << endl;
	cout << "3. In ra phan tu tren dau ngan xep" << endl;
	cout << "4. In ra ngan xep hien tai" << endl;
	cout << "5. Xoa ngan xep da tao" << endl;
	cout << "_____________________________________________" << endl;
}
void choose(stack& x) {
	int choice;
	cout << "Lua chon cua ban la: ";
	cin >> choice;
	switch (choice) {
	case 1:
		system("cls");
		addElement_to(x);
		call_menu();
		choose(x);
		break;
	case 2:
		system("cls");
		x.pop();
		call_menu();
		choose(x);
		break;
	case 3:
		system("cls");
		cout << "Phan tu tren dau ngan xep la " << x.getTop() << endl;
		call_menu();
		choose(x);
		break;
	case 4:
		system("cls");
		x.stack_export();
		call_menu();
		choose(x);
		break;
	case 5:
		system("cls");
		x.deleteStack();
		cout << "Da xoa ngan xep" << endl;
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

void stack::import_size() {
	cout << "Cho trong toi da cua ngan xep la ";
	cin >> max_size;
}
void stack::stack_export() {
	if (!isEmpty()) {
		cout << "Ngan xep hien tai la: ";
		for (int i = current_size; i >= 0; i--)
			cout << arr[i] << " ";
	}
	else cout << "Ngan xep rong";
	cout << endl;
}
bool stack::isEmpty() {
	if (current_size == -1)
		return true;
	return false;
}
bool stack::isFull() {
	if (current_size == max_size - 1)
		return true;
	return false;
}
void stack::push(int add_element) {
	if (!isFull()) {
		current_size++;
		arr[current_size] = add_element;
		cout << "Da them phan tu " << add_element << " vao ngan xep" << endl;
	}
	else cout << "Ngan xep da day" << endl;
}
void stack::pop() {
	if (!isEmpty()) {

		cout << "Da lay phan tu " << arr[current_size] << " khoi ngan xep" << endl;
		current_size--;
	}
	else cout << "Ngan xep rong" << endl;
}
int stack::getTop() {
	if (!isEmpty())
		return arr[current_size];
	else {
		cout << "Ngan xep rong" << endl;
		return -1;
	}
}
void stack::deleteStack() {
	current_size = -1;
}