#include <iostream>
#include <string>
using namespace std;

class Candidate {
    string name, ID;
    int date_Birth, month_Birth, year_Birth;
    double math_score, literature_score, english_score;
public:
    void import();
    void print();
    void check(double&);
    double score_total();
};

void list_import(Candidate[], int);
void check_score(Candidate[], int);

int main()
{
    int amount;
    cout << "So thi sinh la ";
    cin >> amount;
    system("cls");
    Candidate* list = new Candidate[amount];
    list_import(list, amount);
    check_score(list, amount);
    system("pause");
}

void Candidate::import() {
    int temp = getchar();
    cout << "Ho va ten thi sinh: ";
    getline(cin, name);
    cout << " Ma thi sinh: ";
    getline(cin, ID);
    cout << " Ngay sinh: ";
    cin >> date_Birth;
    cout << " Thang sinh: ";
    cin >> month_Birth;
    cout << " Nam sinh: ";
    cin >> year_Birth;
    cout << " Diem toan: ";
    cin >> math_score;
    check(math_score);
    cout << " Diem van: ";
    cin >> literature_score;
    check(literature_score);
    cout << " Diem tieng Anh: ";
    cin >> english_score;
    check(english_score);
    system("cls");
}
void Candidate::print() {
    cout << " Ho va ten thi sinh: " << name << endl;
    cout << " Ma thi sinh: " << ID << endl;
    cout << " Ngay sinh: " << date_Birth << endl;
    cout << " Thang sinh: " << month_Birth << endl;
    cout << " Nam sinh: " << year_Birth << endl;
    cout << " Diem toan: " << math_score << endl;
    cout << " Diem van: " << literature_score << endl;
    cout << " Diem tieng Anh: " << english_score << endl;
    cout << endl;
}
void Candidate::check(double& x) {
    while (x > 10 || x < 0) {
        cout << "Diem so khong hop le. Gia tri diem moi la: ";
        cin >> x;
    }
}
double Candidate::score_total() {
    return math_score + literature_score + english_score;
}

void list_import(Candidate arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Thi sinh thu " << i + 1 << ": " << endl << " ";
        arr[i].import();
    }
}
void check_score(Candidate arr[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++)
        if (arr[i].score_total() > 15)
            count++;
    if (count == 0)
        cout << "Khong co thi sinh nao co tong diem lon hon 15" << endl;
    else {
        cout << "Thong tin cac thi sinh co tong diem lon hon 15 la: " << endl << endl;
        for (int i = 0; i < size; i++)
            if (arr[i].score_total() > 15) {
                cout << "Thi sinh thu " << i + 1 << ": " << endl;
                arr[i].print();
            }
    }
}