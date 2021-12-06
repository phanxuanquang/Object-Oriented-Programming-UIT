#include <iostream>
using namespace std;
class toancuc
{
public:
	toancuc();

	~toancuc();
};
toancuc A;
int main() {
	cout << "Hello, world.\n";
	return 0;
}
toancuc::toancuc()
{
	cout << "Entering the Hello program saying...\n";
}
toancuc::~toancuc()
{
	cout << "Then exiting...";
}
