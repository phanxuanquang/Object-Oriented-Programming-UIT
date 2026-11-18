#include <iostream>
using namespace std;

class general
{
public:
	general();

	~general();
};

general A;
int main() {
	cout << "Hello, world.\n";
	return 0;
}

general::general()
{
	cout << "Entering the Hello program saying...\n";
}
general::~general()
{
	cout << "Then exiting...";
}
