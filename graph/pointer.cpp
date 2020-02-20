#include <iostream>
using namespace std;

void func(int *b)
{
	int a = 10;
	if (b < &a)
		cout << "upward";
	else
		cout << "downward";
}

int main()
{
	int a = 10;
	func(&a);
	return 0;
}