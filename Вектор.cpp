#include <iostream> 
#include <conio.h>
#include <vector>
#include <numeric>
#include <algorithm>

int main() {
	std::vector<int> v(10);
	std::iota(v.begin(), v.begin() + 10, 0);
	std::random_shuffle(v.begin(), v.end());
	v.erase(std::remove(v.begin(), v.end(), 8), v.end());
	_getch();
	return 0;
}