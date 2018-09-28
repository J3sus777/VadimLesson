#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <conio.h>
using namespace std;

int weight(string word) {
	int count = 0;
	for (int i = 0; i < strlen(word.c_str()); i++) {
		if (word[i] == 'a')count++;
		if (word[i] == 'b')count+=2;
		if (word[i] == 'c')count+=3;
		if (word[i] == 'd')count+=4;
		if (word[i] == 'e')count+=5;
		if (word[i] == 'f')count+=6;
		if (word[i] == 'g')count+=7;
		if (word[i] == 'h')count+=8;
		if (word[i] == 'i')count+=9;
		if (word[i] == 'j')count+=10;
		if (word[i] == 'k')count+=11;
		if (word[i] == 'l')count += 12;
		if (word[i] == 'm')count += 13;
		if (word[i] == 'n')count += 14;
		if (word[i] == 'o')count += 15;
		if (word[i] == 'p')count += 16;
		if (word[i] == 'q')count += 17;
		if (word[i] == 'r')count += 18;
		if (word[i] == 's')count += 19;
		if (word[i] == 't')count += 20;
		if (word[i] == 'u')count += 21;
		if (word[i] == 'v')count += 22;
		if (word[i] == 'w')count += 23;
		if (word[i] == 'x')count += 24;
		if (word[i] == 'y')count += 25;
		if (word[i] == 'z')count += 26;
	}
	return count;
}

int main() {
const int size = 5000;
string arr2[size];
const char* Fname = "Name.txt";
ifstream fin(Fname);
if (!fin.is_open()) {
cout << "Error open";
}
else {
	for (int i = 0; i < size; i++) {
		fin >> arr2[i];
	}
	
}
fin.close();
string word;
int sum=0;
for (int i = 0; i<size; i++) {
	word = arr2[i];
	sum += weight(word);
	word.clear();
}
cout << sum;
for (int i = 1; i < size; ++i)
{
	for (int r = 0; r < size - i; r++)
	{
		if (arr2[r] < arr2[r + 1])
		{
			string temp = arr2[r];
			arr2[r] = arr2[r + 1];
			arr2[r + 1] = temp;
		}
	}
}
ofstream clearfile(Fname, ios::out);
clearfile.close();

ofstream fout(Fname, ios::app);
if (!fout.is_open()) {
	cout << "Error open";
}
else {
	for (int i = 0; i < size; i++) {
		fout << arr2[i] << " ";
	}

}
fout.close();
_getch();
return 0;
}


/*int main() {
const int size = 5000;
string arr[10] = { "vataliy ","andrey ","misha ","valik ","iliya ","petya ","dmitro ","valeria ","nickolay ","roman " };
string arr2[size];
for (int i = 0; i < size; i++) {
arr2[i] = arr[rand() % 10];
}

const char* Fname = "Name.txt";
ofstream fout(Fname, ios::app);
if (!fout.is_open()) {
cout << "Error open";
}
else {
	for (int i = 0; i < size; i++) {
		fout << arr2[i];
	}
	
}
fout.close();
return 0;
}
*/