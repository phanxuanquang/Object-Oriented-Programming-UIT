#include <iostream>
using namespace std;

class DaThuc
{
private:
	int bac = 0;
	int* arr = NULL;
public:
	DaThuc(int newbac = 0);
	DaThuc(const DaThuc& x);
	friend istream& operator>>(istream& is, DaThuc& a);
	friend ostream& operator<<(ostream& os, DaThuc a);

	DaThuc operator+(DaThuc& b);
	DaThuc operator-(DaThuc b);
	DaThuc operator*(DaThuc b);

	int operator[](int i);

	DaThuc& operator++();
	DaThuc operator++(int);
	DaThuc& operator--();
	DaThuc operator--(int);
	~DaThuc();
};

int main(){
	DaThuc a, b, cong, tru, nhan;
	cout << "\n Nhap da thuc thu nhat F1(x).";
	cin >> a;
	cout << " F1(x) = " << a;
	cout << "\n Nhap da thuc thu hai F2(x).";
	cin >> b;
	cout << " F2(x) = " << b;
	
	cout << "\n F1(x) + F2(x) = ";
	cong = a + b;
	cout << cong;
	cout << "\n F1(x) - F2(x) = ";
	tru = a - b;
	cout << tru;
	cout << "\n F1(x) * F2(x) = ";
	nhan = a * b;
	cout << nhan;
	cout << "\n He so cua x^1 cua F1(x): " << a[1] << "\n";

	a++;
	cout << a;

	--b;
	cout << b;
	return 0;
}
DaThuc::DaThuc(int newbac){
	bac = newbac;
	arr = new int[bac + 1];
	for (int i = 0; i <= bac; i++){
		arr[i] = 0;
	}
}

DaThuc::DaThuc(const DaThuc& x)
{
	bac = x.bac;
	arr = new int[bac + 1];
	for (int i = 0; i <= bac; i++){
		arr[i] = x.arr[i];
	}
}

istream& operator>>(istream& is, DaThuc& a){
	cout << "\n Hay nhap bac cua da thuc: ";
	is >> a.bac;
	a.arr = new int[a.bac + 1];
	for (int i = 0; i <= a.bac; i++){
		cout << " He so cua x^" << i << " : ";
		is >> a.arr[i];
	}
	return is;
}
ostream& operator<<(ostream& os, DaThuc a){
	for (int i = a.bac; i > 0; i--){
		os << a.arr[i] << "x^" << i << " + ";
	}
	os << a.arr[0];
	os << "\n";
	return os;
}

DaThuc DaThuc::operator+(DaThuc& b){
	DaThuc tong;
	if (bac > b.bac){
		tong.bac = bac;
	}
	else{
		tong.bac = b.bac;
	}
	delete[]tong.arr;
	tong.arr = new int[tong.bac + 1];
	for (int i = 0; i <= tong.bac; i++){
		if (i <= bac && i <= b.bac)	{
			tong.arr[i] = arr[i] + b.arr[i];
		}
		else{
			if (i > bac) tong.arr[i] = b.arr[i];
			else
				if (i > b.bac) tong.arr[i] = arr[i];
		}
	}
	return tong;
}

DaThuc DaThuc::operator-(DaThuc b){
	//a-b
	DaThuc hieu;
	if (bac > b.bac){
		hieu.bac = bac;
	}
	else{
		hieu.bac = b.bac;
	}
	hieu.arr = new int[hieu.bac + 1];
	for (int i = 0; i <= hieu.bac; i++){
		if (i <= bac && i <= b.bac){
			hieu.arr[i] = arr[i] - b.arr[i];
		}
		else{
			if (i > bac) hieu.arr[i] = -b.arr[i];
			else
				if (i > b.bac) hieu.arr[i] = arr[i];
		}
	}
	return hieu;
}

DaThuc DaThuc::operator*(DaThuc b){
	DaThuc nhan;
	nhan.bac = bac + b.bac;
	nhan.arr = new int[nhan.bac + 1];
	for (int k = 0; k <= nhan.bac; k++){
		nhan.arr[k] = 0;
	}
	for (int i = 0; i <= bac; i++)
		for (int j = 0; j <= b.bac; j++){
			nhan.arr[i + j] += arr[i] * b.arr[j];
		}
	return nhan;
}

int DaThuc::operator[](int i){
	return arr[i];
}

DaThuc& DaThuc::operator++(){
	arr[0] = arr[0] + 1;
	return *this;
}

DaThuc DaThuc::operator++(int){
	DaThuc t(*this);
	arr[0]++;
	return t;
}

DaThuc& DaThuc::operator--(){
	arr[0]--;
	return *this;
}

DaThuc DaThuc::operator--(int){
	DaThuc t(*this);
	arr[0]--;
	return t;
}

DaThuc::~DaThuc()
{}