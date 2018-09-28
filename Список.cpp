#include <iostream>
#include <conio.h>
using namespace std;


template<typename D>
struct Elem
{
	D data;
	Elem *next, *prev;
};

template<typename D>
class Mylist{
private:
	Elem<D> * head, *tail;		//������ � �����
	int count;	//���������� ���������
public:
	Mylist();
	Mylist(const Mylist&);
	~Mylist();
	int GetCount();						//�������� ����������
	Elem<D>* GetElem(int);					//�������� �������
	void DelAll();						//������� ��� �������� � ������
	void DelElemet(int pos = 0);		//������� ������������ �������
	void Insert(int pos = 0);			//������� ��������
	void AddTail(D n);					//�������� ������� � ������
	void AddHead(D n);					//�������� ������� � �����
	void Print();						//������� ���� ������
	void PrintPos(int pos);				//������� ������������ �������
	
	Mylist& operator= (const Mylist&);
	//�������� ���� �������, �����������	
	Mylist operator+(const Mylist&);
	//��������������� ������
	Mylist operator-();

	bool operator == (const Mylist&);
	bool operator != (const Mylist&);
	bool operator <= (const Mylist&);
	bool operator >= (const Mylist&);
	bool operator < (const Mylist&);
	bool operator > (const Mylist&);
};

template<typename D>
Mylist<D>::Mylist() {
	head = tail = NULL;
	count = 0;
}

template<typename D>
Mylist<D>::Mylist(const Mylist & L)
{
	head = tail = NULL;
	count = 0;

	Elem<D> *temp = L.head;

	while (temp != 0) {
		AddTail(temp->data);
		temp = temp->next;
	}
}

template<typename D>
Mylist<D>::~Mylist() {
	DelAll();
}

template<typename D>
void Mylist<D>::AddHead(D n) {

	Elem<D> *temp = new Elem<D>;

	temp->prev = 0;
	temp->data = n;
	temp->next = head;

	if (head != 0)
		head->prev = temp;

	// ���� ������� ������, �� �� ������������ � ������ � �����
	if (count == 0)
		head = tail = temp;
	else

		// ����� ����� ������� - ��������
		head = temp;
	count++;
}

template <typename D>
void Mylist<D>::AddTail(D n) {
	Elem<D> * temp = new Elem<D>;

	temp->next = 0;
	temp->data = n;
	temp->prev = tail;

	if (tail != 0)
		tail->next = temp;

	// ���� ������� ������, �� �� ������������ � ������ � �����
	if (count == 0)
		head = tail = temp;
	else
		// ����� ����� ������� - ���������
		tail = temp;

	count++;
}

template <typename D>

void Mylist<D>::Insert(int pos) {
	if (pos == 0)
	{
		cout << "Input position: ";
		cin >> pos;
	}

	// ������� �� 1 �� Count?
	if (pos < 1 || pos > count + 1)
	{
		// �������� �������
		cout << "Incorrect position !!!\n";
		return;
	}

	if (pos == count + 1)
	{
		// ����������� ������
		D data;
		cout << "Input new number: ";
		cin >> data;
		// ���������� � ����� ������
		AddTail(data);
		return;
	}
	else if (pos == 1)
	{
		// ����������� ������
		D data;
		cout << "Input new number: ";
		cin >> data;
		// ���������� � ������ ������
		AddHead(data);
		return;
	}

	// �������
	int i = 1;

	// ����������� �� ������ n - 1 ���������
	Elem<D> * Ins = head;

	while (i < pos)
	{
		// ������� �� ��������, 
		// ����� ������� �����������
		Ins = Ins->next;
		i++;
	}

	// ������� �� ��������, 
	// ������� ������������
	Elem<D> * PrevIns = Ins->prev;

	// ������� ����� �������
	Elem<D> * temp = new Elem<D>;

	// ������ ������
	cout << "Input new number or symbol: ";
	cin >> temp->data;

	// ��������� ������
	if (PrevIns != 0 && count != 1)
		PrevIns->next = temp;

	temp->next = Ins;
	temp->prev = PrevIns;
	Ins->prev = temp;

	count++;
}

template <typename D>
void Mylist<D>::DelElemet(int pos) {
	if (pos == 0) {
		cout << "Input position: ";
		cin >> pos;
	}

	if (pos < 1 || pos > count) {
		cout << "Incorrect position !!!\n";
		return;
	}
	int i = 1;

	Elem<D> * Del = head;

	while (i < pos)
	{
		// ������� �� ��������, 
		// ������� ���������
		Del = Del->next;
		i++;
	}

	// ������� �� ��������, 
	// ������� ������������ ����������
	Elem<D>* PrevDel = Del->prev;
	// ������� �� ��������, ������� ������� �� ���������
	Elem<D>* AfterDel = Del->next;

	// ���� ������� �� ������
	if (PrevDel != 0 && count != 1)
		PrevDel->next = AfterDel;
	// ���� ������� �� �����
	if (AfterDel != 0 && count != 1)
		AfterDel->prev = PrevDel;

	// ��������� �������?
	if (pos == 1)
		head = AfterDel;
	if (pos == count)
		tail = PrevDel;

	// �������� ��������
	delete Del;

	count--;
}

template<typename D>
void Mylist<D>::PrintPos(int pos) {
	if (pos == 0) {
		cout << "Input position: ";
		cin >> pos;
	}

	if (pos < 1 || pos > count) {
		cout << "Incorrect position !!!\n";
		return;
	}

	Elem<D> * temp;

	// ���������� � ����� ������� 
	// ������� ���������
	if (pos <= count / 2)
	{
		// ������ � ������
		temp = head;
		int i = 1;

		while (i < pos)
		{
			// ��������� �� ������� ��������
			temp = temp->next;
			i++;
		}
	}
	else
	{
		// ������ � ������
		temp = tail;
		int i = 1;

		while (i <= count - pos)
		{
			// ��������� �� ������� ��������
			temp = temp->prev;
			i++;
		}
	}
	// ����� ��������
	cout << pos << " element: ";
	cout << temp->data << endl;
}

template<typename D>
Mylist<D> & Mylist<D>::operator=(const Mylist & L)
{
	if (this == &L) {
		return *this;
	}
	this->~Mylist();

	Elem<D> * temp = L.head;

	// �������� ��������
	while (temp != 0)
	{
		AddTail(temp->data);
		temp = temp->next;
	}

	return *this;
}

template<typename D>
Mylist<D> Mylist<D>::operator+(const Mylist & L)
{
	Mylist<D> Result(*this);
	Elem<D> * temp = L.head;
	while (temp != 0)
	{
		Result.AddTail(temp->data);
		temp = temp->next;
	}

	return Result;
}

template<typename D>
Mylist<D> Mylist<D>::operator-()
{
	Mylist<D> Result;

	Elem<D> * temp = head;
	// �������� �������� ������, ������� � ���������,
	// � ���� ����� ���������� ��������� � ������,
	// ����� ������� ��������� ������ Result ����� ���������
	// �������� � �������� �������
	while (temp != 0)
	{
		Result.AddHead(temp->data);
		temp = temp->next;
	}

	return Result;
}

template<typename D>
bool Mylist<D>::operator==(const Mylist & L)
{
	if (count != L.count)
		return false;

	Elem<D> *t1, *t2;

	t1 = head;
	t2 = L.head;

	// ��������� �� ����������
	while (t1 != 0)
	{
		// ������� ������, �������
		// ��������� �� ���������� ��������
		if (t1->data != t2->data)
			return false;

		t1 = t1->next;
		t2 = t2->next;
	}

	return true;
}

template<typename D>
bool Mylist<D>::operator!=(const Mylist & L)
{
	return !(*this == L);
}

template<typename D>
bool Mylist<D>::operator<=(const Mylist & L)
{
	if (count < L.count)
		return true;
	// ��������� �� ����������
	if (*this == L)
		return true;
	return false;
}

template<typename D>
bool Mylist<D>::operator>=(const Mylist & L)
{
	if (count > L.count)
		return true;
	// ��������� �� ����������
	if (*this == L)
		return true;
	return false;
}

template<typename D>
bool Mylist<D>::operator<(const Mylist & L)
{
	if (count > L.count)
		return true;
	return false;
}

template<typename D>
bool Mylist<D>::operator>(const Mylist & L)
{
	if (count < L.count)
		return true;
	return false;
}

template<typename D>
void Mylist<D>::Print() {
	if (count != 0)
	{
		Elem<D> * temp = head;
		cout << "( ";
		while (temp->next != 0)
		{
			cout << temp->data << ", ";
			temp = temp->next;
		}

		cout << temp->data << " )\n";
	}
}

template<typename D>
void Mylist<D>::DelAll() {
	while (count != 0)
		DelElemet(1);
}

template<typename D>
int Mylist<D>::GetCount() {
	return count;
}

template<typename D>
Elem<D> * Mylist<D>::GetElem(int pos) {
	Elem<D> *temp = head;

	// ������� �� 1 �� Count?
	if (pos < 1 || pos > count)
	{
		// �������� �������
		cout << "Incorrect position !!!\n";
		return 0;
	}

	int i = 1;
	// ���� ������ ��� �������
	while (i < pos && temp != 0)
	{
		temp = temp->next;
		i++;
	}

	if (temp == 0)
		return 0;
	else
		return temp;
}

int main() {
	Mylist<char> L;
	const int n = 10;
	char a[n] = { 'a','b','j','q','r','x','u','w','y','b'};
	// ��������� ��������, ������� �� ������ ��������, � ������,
	// �� �������� - � �����
	for (int i = 0; i < n; i++) {
			L.AddHead(a[i]);
	}
	cout << "List L:\n";
	L.Print();

	cout << L.GetCount();

	L.DelElemet(5);
	cout << endl;

	cout << "List L:\n";
	L.Print();

	L.Insert(5);

	cout << "List L:\n";
	L.Print();
	
	L.PrintPos(8);
	L.PrintPos(2);

	Mylist<char> T;
	T = L;

	cout << "List T:\n";
	T.Print();

	// ���������� ��� ������ (������ � ������������ ���������)
	cout << "List Sum:\n";
	Mylist<char> Sum = -L + T;
	// ���������� ������
	Sum.Print();
	_getch();
	return 0;
}
