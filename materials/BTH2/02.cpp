#include <iostream>
#include <string>
using namespace std;

class Candidate {
    string name, ID;
    int birthDay, birthMonth, birthYear;
    double mathScore, literatureScore, englishScore;

public:
    void import();
    void print();
    void checkValidScore(double&);
    bool isScoreTotalAbove15() {
        if (mathScore + literatureScore + englishScore > 15)
            return true;
        return false;
    }
};

void listImport(Candidate[], int);
void printMatchedCandidates(Candidate[], int);

int main()
{
    int quantity;
    cout << "So thi sinh la ";
    cin >> quantity;
    system("cls");

    Candidate* list = new Candidate[quantity];
    listImport(list, quantity);

    printMatchedCandidates(list, quantity);

    system("pause");
}

void Candidate::import() {
    cin.ignore();
    cout << "Ho va ten thi sinh: ";
    getline(cin, name);
    cout << " Ma thi sinh: ";
    getline(cin, ID);
    cout << " Ngay sinh: ";
    cin >> birthDay;
    cout << " Thang sinh: ";
    cin >> birthMonth;
    cout << " Nam sinh: ";
    cin >> birthYear;

    cout << " Diem toan: ";
    cin >> mathScore;
    checkValidScore(mathScore);
    cout << " Diem van: ";
    cin >> literatureScore;
    checkValidScore(literatureScore);
    cout << " Diem tieng Anh: ";
    cin >> englishScore;
    checkValidScore(englishScore);

    system("cls");
}
void Candidate::print() {
    cout << "  Ho va ten thi sinh: " << name << endl;
    cout << "  Ngay sinh: " << birthDay << "/" << birthMonth << "/" << birthYear << endl;
    cout << "  Diem toan: " << mathScore << endl;
    cout << "  Diem van: " << literatureScore << endl;
    cout << "  Diem tieng Anh: " << englishScore << endl;
    cout << endl;
}
void Candidate::checkValidScore(double& x) {
    while (x > 10 || x < 0) {
        cout << "Diem so khong hop le. Gia tri diem moi la: ";
        cin >> x;
    }
}

void listImport(Candidate arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Thi sinh thu " << i + 1 << ": " << endl << " ";
        arr[i].import();
    }
}
void printMatchedCandidates(Candidate arr[], int size) {
    bool hasCandidateAbove15 = false;

    cout << "Cac thi sinh co tong diem lon hon 15: " << endl;
    for (int i = 0; i < size; i++)
        if (arr[i].isScoreTotalAbove15()) {
            hasCandidateAbove15 = true;
            cout << "  Thi sinh thu " << i + 1 << ": " << endl;
            arr[i].print();
        }

    if (hasCandidateAbove15 == false)
        cout << "Khong co trong danh sach" << endl;
}
