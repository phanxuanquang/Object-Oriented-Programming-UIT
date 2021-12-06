#include <iostream>
using namespace std;

class queue {
    int max_size;
    int* arr = new int[max_size];
    int element;
    int front, rear;
public:
    queue(){
        this->front = -1;
        this->rear = -1;
    }
    int get_max_size() {
        return max_size;
    }
    void import();
    void print();
    void EnQueue(int);
    void DeQueue();
    bool check_Empty();
    bool check_Full();
    int amount();
    void delete_Queue();
};

void add(queue&);
void remove_head(queue& a);
void call_menu();
void choose(queue&);

int main(){
    queue a;
    a.import();
    system("cls");
    call_menu();
    choose(a);
    system("pause");
}

void add_tail(queue& a) {
    if (a.check_Full())
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
void remove_head(queue& a) {
    system("cls");
    if (a.check_Empty())
        cout << "Hang doi rong" << endl;
    else {
        a.DeQueue();
        cout << "Da xoa phan tu khoi hang doi" << endl;
    }
}
void call_menu() {
    cout << "=======================================" << endl;
    cout << "1. EnQueue (them 1 phan tu vao cuoi hang doi)" << endl;
    cout << "2. DeQueue (xoa phan tu o dau hang doi)" << endl;
    cout << "3. In ra hang doi hien tai" << endl;
    cout << "4. In ra so phan tu trong hang doi" << endl;
    cout << "5. Xoa hang doi hien tai" << endl;
    cout << "=======================================" << endl;
}
void choose(queue& x) {
    int choice;
    cout << "Lua chon cua ban la: ";
    cin >> choice;
    switch (choice) {
    case 1:
        system("cls");
        add_tail(x);
        call_menu();
        choose(x);
        break;
    case 2:
        system("cls");
        remove_head(x);
        call_menu();
        choose(x);
        break;
    case 3:
        system("cls");
        x.print();
        call_menu();
        choose(x);
        break;
    case 4:
        system("cls");
        if (x.check_Empty())
            cout << "Hang doi rong" << endl;
        else cout << "Hang doi hien tai co " << x.amount() << " phan tu" << endl;
        call_menu();
        choose(x);
        break;
    case 5:
        system("cls");
        x.delete_Queue();
        call_menu();
        choose(x);
        break;
    default:
        system("cls");
        cout << "Lua chon khong hop le, vui long nhap lai" << endl;
        call_menu();
        choose(x);
        break;
    }
}

void queue::import() {
    cout << "So phan tu toi da cua hang doi: ";
    cin >> max_size;
}
void queue::print() {
    if (check_Empty())
        cout << "Hang doi rong";
    else {
        cout << "Hang doi hien tai la: ";
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
    }
    cout << endl;
}
void queue::EnQueue(int add_element) {
    if (front == -1)
        front++;
    rear++;
    arr[rear] = add_element;
}
void queue::DeQueue() {
    front++;
}
bool queue::check_Empty() {
    if (amount() == 0)
        return true;
    return false;
}
bool queue::check_Full() {
    if (amount() == max_size)
        return true;
    return false;
}
int queue::amount() {
    return (rear - front + 1);
}
void queue::delete_Queue() {
    cout << "Da xoa hang doi hien tai" << endl;
    front = rear = -1;
}