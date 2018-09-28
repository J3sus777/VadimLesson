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
	Elem<D> * head, *tail;		//Начало и конец
	int count;	//Количество элементов
public:
	Mylist();
	Mylist(const Mylist&);
	~Mylist();
	int GetCount();						//Получить количество
	Elem<D>* GetElem(int);					//Получить элемент
	void DelAll();						//Удалить все элементы с списка
	void DelElemet(int pos = 0);		//Удалить опредиленный элемент
	void Insert(int pos = 0);			//Вставка элемента
	void AddTail(D n);					//Добавить элемент в начало
	void AddHead(D n);					//Добавить элемент в конец
	void Print();						//Вывести весь список
	void PrintPos(int pos);				//Удалить опредиленный элемент
	
	Mylist& operator= (const Mylist&);
	//Сложение двух списков, дописывание	
	Mylist operator+(const Mylist&);
	//Переворачивание списка
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

	// Если элемент первый, то он одновременно и голова и хвост
	if (count == 0)
		head = tail = temp;
	else

		// иначе новый элемент - головной
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

	// Если элемент первый, то он одновременно и голова и хвост
	if (count == 0)
		head = tail = temp;
	else
		// иначе новый элемент - хвостовой
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

	// Позиция от 1 до Count?
	if (pos < 1 || pos > count + 1)
	{
		// Неверная позиция
		cout << "Incorrect position !!!\n";
		return;
	}

	if (pos == count + 1)
	{
		// Вставляемые данные
		D data;
		cout << "Input new number: ";
		cin >> data;
		// Добавление в конец списка
		AddTail(data);
		return;
	}
	else if (pos == 1)
	{
		// Вставляемые данные
		D data;
		cout << "Input new number: ";
		cin >> data;
		// Добавление в начало списка
		AddHead(data);
		return;
	}

	// Счетчик
	int i = 1;

	// Отсчитываем от головы n - 1 элементов
	Elem<D> * Ins = head;

	while (i < pos)
	{
		// Доходим до элемента, 
		// перед которым вставляемся
		Ins = Ins->next;
		i++;
	}

	// Доходим до элемента, 
	// который предшествует
	Elem<D> * PrevIns = Ins->prev;

	// Создаем новый элемент
	Elem<D> * temp = new Elem<D>;

	// Вводим данные
	cout << "Input new number or symbol: ";
	cin >> temp->data;

	// настройка связей
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
		// Доходим до элемента, 
		// который удаляется
		Del = Del->next;
		i++;
	}

	// Доходим до элемента, 
	// который предшествует удаляемому
	Elem<D>* PrevDel = Del->prev;
	// Доходим до элемента, который следует за удаляемым
	Elem<D>* AfterDel = Del->next;

	// Если удаляем не голову
	if (PrevDel != 0 && count != 1)
		PrevDel->next = AfterDel;
	// Если удаляем не хвост
	if (AfterDel != 0 && count != 1)
		AfterDel->prev = PrevDel;

	// Удаляются крайние?
	if (pos == 1)
		head = AfterDel;
	if (pos == count)
		tail = PrevDel;

	// Удаление элемента
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

	// Определяем с какой стороны 
	// быстрее двигаться
	if (pos <= count / 2)
	{
		// Отсчет с головы
		temp = head;
		int i = 1;

		while (i < pos)
		{
			// Двигаемся до нужного элемента
			temp = temp->next;
			i++;
		}
	}
	else
	{
		// Отсчет с хвоста
		temp = tail;
		int i = 1;

		while (i <= count - pos)
		{
			// Двигаемся до нужного элемента
			temp = temp->prev;
			i++;
		}
	}
	// Вывод элемента
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

	// Копируем элементы
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
	// Копируем элементы списка, начиная с головного,
	// в свой путем добавления элементов в голову,
	// таким образом временный список Result будет содержать
	// элементы в обратном порядке
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

	// Сравнение по содержанию
	while (t1 != 0)
	{
		// Сверяем данные, которые
		// находятся на одинаковых позициях
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
	// Сравнение по содержанию
	if (*this == L)
		return true;
	return false;
}

template<typename D>
bool Mylist<D>::operator>=(const Mylist & L)
{
	if (count > L.count)
		return true;
	// Сравнение по содержанию
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

	// Позиция от 1 до Count?
	if (pos < 1 || pos > count)
	{
		// Неверная позиция
		cout << "Incorrect position !!!\n";
		return 0;
	}

	int i = 1;
	// Ищем нужный нам элемент
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
	// Добавляем элементы, стоящие на четных индексах, в голову,
	// на нечетных - в хвост
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

	// Складываем два списка (первый в перевернутом состоянии)
	cout << "List Sum:\n";
	Mylist<char> Sum = -L + T;
	// Распечатка списка
	Sum.Print();
	_getch();
	return 0;
}
