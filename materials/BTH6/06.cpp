#include <iostream>;
#include <string>
using namespace std;

class CString {
	string s;
public:
	CString(){
		s = "";
	}
	friend istream& operator>>(istream& is, CString& a);
	friend ostream& operator<<(ostream& os, CString& a);
	void setString(string value);
	CString operator+(CString value);
	bool operator!=(CString value);
	~CString() {}
};

int main() {
	CString s1, s2;
	cin >> s1 >> s2;
	CString total = s1 + s2;
	cout << s1 << " + " << s2 << " = " << total << endl;
	if (s1 != s2)
		cout << s1 << " != " << s2 << endl;
	else cout << s1 << " = " << s2 << endl;
}

istream& operator>>(istream& is, CString& a) {
	cout << "Xau nhap vao la ";
	is >> a.s;
	return is;
}
ostream& operator<<(ostream& os, CString& a) {
	os << a.s;
	return os;
}

void CString::setString(string value) {
	this->s = value;
}
CString CString::operator+(CString value) {
	CString result;
	result.s = s + value.s;
	return result;
}
bool CString::operator!=(CString value) {
	if (s.compare(value.s) != 0)
		return true;
	return false;
}