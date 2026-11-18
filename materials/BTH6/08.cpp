#include <iostream>
using namespace std;

class CVector{
private:
	int n;
	int* arr;
public:
	friend class CMatrix;
	CVector(int newn = 0);
	~CVector();
	//CVector& operator=(CVector vt);
	friend istream& operator>>(istream& is, CVector& vt);
	friend ostream& operator<<(ostream& os, CVector vt);
};

class CMatrix{
private:
	int row, col;
	int** arr;
public:
	CMatrix(int r = 1, int c = 1);
	~CMatrix();
	//CMatrix& operator=(CMatrix mt);
	friend istream& operator>>(istream& is, CMatrix& mt);
	friend ostream& operator<<(ostream& os, CMatrix mt);

	CMatrix operator*(CMatrix& b);
	CMatrix operator*(CVector& vt);

};

int main(){
	CVector vt1;
	cout << " Nhap vao mot vecto X\n";
	cin >> vt1;
	cout << " X = " << vt1;
	CMatrix mt1, mt2, mt3, tich;
	cout << "\n Nhap vao ma tran thu nhat A\n";
	cin >> mt1;
	cout << mt1;
	cout << "\n Nhap vao ma tran thu hai B\n";
	cin >> mt2;
	cout << mt2;
	cout << "A * B = \n";
	tich = mt1 * mt2;
	cout << tich << "\n";
	
	cout << "\n Nhap vao ma tran thu ba C\n";
	cin >> mt3;
	cout << mt3 << "\n";
	cout << " C * X = \n";
	tich = mt3 * vt1;
	cout << tich;
	return 0;
}
CVector::CVector(int newn) :n(newn){
	arr = new int[n];
	for (int i = 0; i < n; i++){
		arr[i] = 0;
	}
}

CVector::~CVector(){
}

istream& operator>>(istream& is, CVector& vt){
	cout << " Nhap vao so chieu cua khong gian: ";
	is >> vt.n;
	delete[]vt.arr;
	vt.arr = new int[vt.n];
	for (int i = 0; i < vt.n; i++)
	{
		cout << "x" << i + 1 << " = ";
		is >> vt.arr[i];
	}
	return is;
}
ostream& operator<<(ostream& os, CVector vt){
	os << "(";
	for (int i = 0; i < vt.n - 1; i++){
		os << vt.arr[i] << ", ";
	}
	os << vt.arr[vt.n - 1] << ")";
	return os;
}
CMatrix::CMatrix(int r, int c) :row(r), col(c){
	arr = new int* [row];
	int i, j;
	for (i = 0; i < row; i++)
		arr[i] = new int[col];
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			arr[i][j] = 0;
		}
	}
}
CMatrix::~CMatrix(){
}

istream& operator>>(istream& is, CMatrix& mt){
	for (int i = 0; i < mt.col; i++)
		delete[]mt.arr[i];
	delete[]mt.arr;

	cout << " Nhap so hang: ";
	is >> mt.row;
	cout << " Nhap so cot: ";
	is >> mt.col;

	mt.arr = new int* [mt.col];
	int i, j;
	for (i = 0; i < mt.row; i++)
		mt.arr[i] = new int[mt.col];
	for (i = 0; i < mt.row; i++)
	{
		for (j = 0; j < mt.col; j++)
		{
			cout << "a[" << i << "][" << j << "] = ";
			is >> mt.arr[i][j];
		}
	}
	return is;
}
ostream& operator<<(ostream& os, CMatrix mt){
	for (int i = 0; i < mt.row; i++){
		for (int j = 0; j < mt.col; j++){
			os << mt.arr[i][j] << "\t";
		}
		cout << "\n";
	}
	return os;
}

CMatrix CMatrix::operator*(CMatrix& b){
	if (col != b.row) return CMatrix();
	CMatrix tich(row, b.col);
	for (int i = 0; i < tich.row; i++)
		for (int j = 0; j < tich.col; j++)
			for (int k = 0; k < col; k++)
				tich.arr[i][j] += arr[i][k] * b.arr[k][j];
	return tich;
}
CMatrix CMatrix::operator*(CVector& vt){
	if (col != 1) return CMatrix();
	CMatrix tich(row, vt.n);
	for (int i = 0; i < tich.row; i++)
		for (int j = 0; j < vt.n; j++){
			tich.arr[i][j] = arr[i][0] * vt.arr[j];
		}
	return tich;
}