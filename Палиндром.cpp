#include <cstdlib>
#include <iostream>
#include <conio.h>

using namespace std;

bool Palindrom(int sum)
{
	int p, k, m;
	k = 0;
	m = sum;
	while (m > 0)
	{
		p = m % 10;
		m = m / 10;
		k = k * 10 + p;
	}
	return sum == k ?  true: false ;
}

int main()
{
	int sum = 0;
	for (int i = 1000, j = 1000; i >= 100, j >= 100; i--, j--) {
		sum = i * j;
		if (Palindrom(sum)) {
			cout << i <<" * "<< j <<" = "<<sum << endl;
			break;
		}
		sum = 0;
	}
	cout << endl;

	_getch();
	return 0;
}
