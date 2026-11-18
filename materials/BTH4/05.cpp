#include <iostream>
using namespace std;

class Queue {
    int size;
    int* arr = new int[size];
    int head, tail;
public:
    Queue() {
        this->head = -1;
        this->tail = -1;
    }
    int get_max_size() {
        return size;
    }
    void input();
    void output();
    void EnQueue(int);
    void DeQueue();
    bool isEmpty();
    bool isFull();
    int getCurrentSize();
    void deleteQueue();
};

void removeElementFrom(Queue&);
void getCurrentSizeOf(Queue&);
void showMenu();
void handleTaskFor(Queue&);

int main() {
    Queue queue;
    queue.input();
    handleTaskFor(queue);
    system("pause");
}

void addElementTo(Queue& a) {
    if (a.isFull())
        cout << "Hang doi da day" << endl;
    else {
        int x;
        cout << "Phan tu muon them la: ";
        cin >> x;
        system("cls");
        a.EnQueue(x);
        cout << "Da them" << endl;
    }
}
void removeElementFrom(Queue& a) {
    system("cls");
    if (a.isEmpty())
        cout << "Hang doi rong" << endl;
    else {
        a.DeQueue();
        cout << "Da xoa phan tu khoi hang doi" << endl;
    }
}
void getCurrentSizeOf(Queue& queue) {
    if (queue.isEmpty())
        cout << "Hang doi rong" << endl;
    else cout << "Hang doi hien tai co " << queue.getCurrentSize() << " phan tu" << endl;
}
void showMenu() {
    cout << "=======================================" << endl;
    cout << "1. EnQueue (them 1 phan tu vao cuoi hang doi)" << endl;
    cout << "2. DeQueue (xoa phan tu o dau hang doi)" << endl;
    cout << "3. In ra hang doi hien tai" << endl;
    cout << "4. In ra so phan tu trong hang doi" << endl;
    cout << "5. Xoa hang doi hien tai" << endl;
    cout << "=======================================" << endl;
}
void handleTaskFor(Queue& queue) {
    showMenu();
    int choice;
    cout << "Lua chon cua ban la: ";
    cin >> choice;
    system("cls");
    switch (choice) {
    case 1:
        addElementTo(queue);
        break;
    case 2:
        removeElementFrom(queue);
        break;
    case 3:
        queue.output();
        break;
    case 4:
        getCurrentSizeOf(queue);
        break;
    case 5:
        queue.deleteQueue();
        break;
    default:
        cout << "Lua chon khong hop le, vui long nhap lai" << endl;
        break;
    }
    handleTaskFor(queue);
}

void Queue::input() {
    cout << "So phan tu toi da cua hang doi: ";
    cin >> size;
}
void Queue::output() {
    if (isEmpty())
        cout << "Hang doi rong";
    else {
        cout << "Hang doi hien tai la: ";
        for (int i = head; i <= tail; i++)
            cout << arr[i] << " ";
    }
    cout << endl;
}
void Queue::EnQueue(int add_element) {
    if (head == -1)
        head++;
    tail++;
    arr[tail] = add_element;
}
void Queue::DeQueue() {
    head++;
}
bool Queue::isEmpty() {
    if (getCurrentSize() == 0)
        return true;
    return false;
}
bool Queue::isFull() {
    if (getCurrentSize() == size)
        return true;
    return false;
}
int Queue::getCurrentSize() {
    return (tail - head + 1);
}
void Queue::deleteQueue() {
    cout << "Da xoa hang doi hien tai" << endl;
    head = tail = -1;
}
