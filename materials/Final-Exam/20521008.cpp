#include <iostream>
#include <string>
#include <time.h> 
using namespace std;

int random(int min, int max);

class ChungCu {
protected:
    string ten;
    int soTang;
    double dienTich;
    string tenQL;
    string soHuu;
public:
    void importInfo();
    string guiThongBao();
    virtual double tienPhong() = 0;
};

class CCVinHome : public ChungCu {
public:
    CCVinHome();
    double tienPhong();
};

class CCBcon : public ChungCu {
public:
    CCBcon();
    double tienPhong();
};

void ChungCu_import(ChungCu**, int, int);
void ChungCu_listExport(ChungCu**, int);
void ChungCu_tienPhong(ChungCu**, int);

int main(){
    int VinHome_Amount, Bcon_Amount;

    cout << "So chung cu VinHome la: ";
    cin >> VinHome_Amount;
    cout << "So chung cu Bcon la: ";
    cin >> Bcon_Amount;
    system("cls");

    int size = VinHome_Amount + Bcon_Amount;
    ChungCu** a = new ChungCu*[size];

    ChungCu_import(a, VinHome_Amount, Bcon_Amount);
    ChungCu_listExport(a, size);
    ChungCu_tienPhong(a, size);
    system("pause");
}

int random(int min, int max) {
    static bool first = true;
    if (first) {
        srand(time(NULL));
        first = false;
    }
    return min + rand() % ((max + 1) - min);
}

void ChungCu::importInfo() {
    cout << "  Ten chung cu: ";
    getline(cin, ten);
    cout << "  So tang: ";
    cin >> soTang;
    cout << "  Dien tich chung: ";
    cin >> dienTich;
    cin.ignore();
    cout << "  Ten quan ly: ";
    getline(cin, tenQL);

}
string ChungCu::guiThongBao() {
    return tenQL + " – " + ten + " – " + soHuu;
}

CCVinHome::CCVinHome() {
    soHuu = "Vinhomes";
}
double CCVinHome::tienPhong() {
    if (dienTich > 600)
        return random(10, 15) * 6 * soTang;
    else return random(6, 10) * 6 * soTang;
}

CCBcon::CCBcon() {
    soHuu = "Bcons";
}
double CCBcon::tienPhong() {
    if (dienTich > 600)
        return random(8, 12) * 6 * soTang;
    else return random(5, 8) * 6 * soTang;
}

void ChungCu_import(ChungCu** x, int a, int b) {
    ChungCu* temp;
    cin.ignore();
    for (int i = 0; i < a; i++) {
        cout << "Thong tin chung cu VinHome thu " << i + 1 << ": " << endl;
        temp = new CCVinHome;
        temp->importInfo();
        x[i] = temp;
    }
    system("cls");
    for (int i = a; i < a + b; i++) {
        cout << "Thong tin chung cu Bcon thu " << i - a + 1 << ": " << endl;
        temp = new CCBcon;
        temp->importInfo();
        x[i] = temp;
    }
    system("cls");
}
void ChungCu_listExport(ChungCu** x, int size) {
    for (int i = 0; i < size; i++)
        cout << x[i]->guiThongBao() << endl;
}
void ChungCu_tienPhong(ChungCu** x, int size) {
    double total = 0;
    for (int i = 0; i < size; i++)
        total += x[i]->tienPhong();
    cout << "\nTong so tien thu ve moi thang cua ban quan ly chung cu lang dai hoc la " << total << "000 (VND)" << endl;
}