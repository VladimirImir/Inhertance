#include<iostream>
using namespace std;

class Element
{
	int Data;         // Содержит значени элемента
	Element* pNext;   // Адрес след. элемента
	static int count; // Кол-во элементов
public:
	Element(int Data, Element* pNext = nullptr) :Data(Data), pNext(pNext)
	{
		count++;
		cout << "EConstructor:\t" << this << endl;
	}
	~Element()
	{
		count--;
		cout << "EDestructor:\t" << this << endl;
	}
	friend class ForwardList;
};

int Element::count = 0;

class ForwardList
{
	Element* Head;
	int size;
public:
	ForwardList()
	{
		this->Head = nullptr;
		size = 0;
		cout << "LConstructor:\t" << this << endl;
	}
	~ForwardList()
	{
		cout << "LDestructor:\t" << this << endl;
	}

	//		Methods:
	//		Добавление элементов
	void push_front(int Data)
	{
		Element* New = new Element(Data); // Создали новый элемент, и сохранили в него добавляемое значение.
		// Теперь этот элемент нужно включить в список.
		New->pNext = Head;
		Head = New;
		size++;
	}

	void push_back(int Data)
	{
		if (Head == nullptr)
		{
			push_front(Data);
			return;
		}
		Element* New = new Element(Data);
		Element* Temp = Head;
		while (Temp->pNext)
		{
			Temp = Temp->pNext;
		}
		Temp->pNext = New;
		size++;
	}

	void insert(int index, int data)
	{
		if (index > size)return;
		if(index == 0)
		{
			push_front(data);
			return;
		}
		Element* New = new Element(data);
		Element* Temp = Head;
		for (int i = 0; i < index - 1; i++)
			Temp = Temp->pNext;
		New->pNext = Temp->pNext;
		Temp->pNext = New;
		size++;
	}

	//		Удаление элементов
	void pop_front()
	{
		Element* to_del = Head; // 1) Запонимаем адрес удаляемого элемента
		Head = Head->pNext;     // 2) Исключаем элемент из списка
		delete to_del;          // 3) Удаляем элемент из памяти
		size--;
	}

	void pop_back()
	{
		Element* Temp = Head;
		while (Temp->pNext->pNext)
		{
			Temp = Temp->pNext;
		}
		delete Temp->pNext;
		Temp->pNext = nullptr;
		size--;
	}

	void erase(int index)
	{
		if (index > size || size == 0)return;
		else if (index == 0)
		{
			pop_front();
			return;
		}

		Element* Iterator = this->Head;
		for (int i = 0; i < index - 1; i++)
		{
			Iterator = Iterator->pNext;
		}

		Element* Index_Delete = Iterator->pNext;

		Iterator->pNext = Index_Delete->pNext;

		delete Index_Delete;
		size--;
	}
	//		Methods:

	void print()
	{
		Element* Temp = Head; // Temp - это итератор
		                      // Итератор - это указатель, при помощи которого можно получить доступ к элементам структуры данных
		while (Temp != nullptr)
		{
			cout << Temp << "\t" << Temp->Data << "\t" << Temp->pNext << endl;
			Temp = Temp->pNext; // Переход на след. элемент
		}
		cout << "List size: " << size << endl;
	}
};
#define delimiter "\n------------------------------------\n"
#define BASE_CHECK

void main()
{
	setlocale(LC_ALL, "");
#ifdef BASE_CHECK
	int n; // размер списка
	cout << "Input list size: "; cin >> n;
	ForwardList list;
	for (int i = 0; i < n; i++)
	{
		list.push_front(rand() % 100);
	}
	list.push_back(123);
	list.print();
	cout << delimiter;
	list.pop_front();
	list.print();
	cout << delimiter;
	list.pop_back();
	list.print();
	cout << delimiter;
	int index;
	int value;
	cout << "Input index: "; cin >> index;
	cout << "Input value: "; cin >> value;
	list.insert(index, value);
	list.print();
	cout << delimiter;
	cout << "Input index: "; cin >> index;
	list.erase(index);
	list.print();
#endif // BASE_CHECK

	/*ForwardList list1;
	list1.push_back(3);
	list1.push_back(5);
	list1.push_back(8);
	list1.push_back(13);
	list1.print();
	cout << delimiter;

	ForwardList list2;
	list2.push_back(21);
	list2.push_back(34);
	list2.push_back(55);
	list2.print();
	cout << delimiter;
	list1.print();*/
}