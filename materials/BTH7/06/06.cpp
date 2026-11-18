#include <iostream>
#include <time.h> 
#include <windows.h>
using namespace std;

int random(int, int);

class animal {
protected:
    int childAmount;
    int milkAmount;
public:
    virtual string animalName() = 0;
    virtual void talk() = 0;
    void print();
};

class cow : public animal {
public:
    cow() {
        childAmount = random(1, 5);
        milkAmount = random(0, 20);
    }
    string animalName() {
        return "BO";
    }
    void talk();
};

class sheep : public animal {
public:
    sheep() {
        childAmount = random(1, 5);
        milkAmount = random(0, 5);
    }
    string animalName() {
        return "COU";
    }
    void talk();
};

class goat : public animal {
public:
    goat() {
        childAmount = random(1, 5);
        milkAmount = random(0, 10);
    }
    string animalName() {
        return "DE";
    }
    void talk();
};

void animalTalk(animal**, int);
void animalExport(animal**, int);

int main() {
    animal* arr[3];
    arr[0] = new cow;
    arr[1] = new sheep;
    arr[2] = new goat;
    animalTalk(arr, 3);
    system("pause");
    animalExport(arr, 3);
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

void animal::print() {
    cout << animalName() << endl;
    cout << "  So con sau mot lua sinh la " << childAmount << endl;
    cout << "  So lit sua thu duoc la " << milkAmount << endl;
}

void cow::talk() {
    cout << "  Bo keu: TAU DOI QUA !" << endl;
    PlaySound(TEXT("Cow.wav"), NULL, SND_SYNC);
}
void sheep::talk() {
    cout << "  Cuu keu: TAU CUNG DOI QUA !" << endl;
    PlaySound(TEXT("Sheep.wav"), NULL, SND_SYNC);
}
void goat::talk() {
    cout << "  De keu: BO MAY DOI ROI DAY !" << endl;
    PlaySound(TEXT("Goat.wav"), NULL, SND_SYNC);
}

void animalTalk(animal** arr, int size) {
    cout << "Hom nay bi chu bo doi, bon gia suc bat dau keu la am i" << endl;
    Sleep(1000);
    for (int i = 0; i < 3; i++)
        arr[i]->talk();
}
void animalExport(animal** arr, int size) {
    system("cls");
    for (int i = 0; i < 3; i++)
        arr[i]->print();
}