#include "List.h"

///////////////      ITERATOR     ////////////////////

List::Iterator::Iterator(Element* Temp) :Temp(Temp)
{
	cout << "ItConstructor:\t" << this << endl;
}
List::Iterator::~Iterator()
{
	cout << "ItDestructor:\t" << this << endl;
}
List::Iterator& List::Iterator::operator++()
{
	Temp = Temp->pNext;
	return *this;
}
List::Iterator& List::Iterator::operator--()
{
	Temp = Temp->pPrev;
	return *this;
}

const int& List::Iterator::operator*()const
{
	return Temp->Data;
}
int& List::Iterator::operator*()
{
	return Temp->Data;
}

bool List::Iterator::operator!=(const Iterator& other)const
{
	return this->Temp != other.Temp;
}

List::Iterator::operator bool()const
{
	return Temp;
}

/////////////// REVERS ITERATOR ////////////////////

List::ReverseIterator::ReverseIterator(Element* Temp) :Temp(Temp)
{
	cout << "RItConstruvtor:\t" << this << endl;
}
List::ReverseIterator::~ReverseIterator()
{
	cout << "RItDestruvtor:\t" << this << endl;
}
List::ReverseIterator& List::ReverseIterator::operator++()
{
	Temp = Temp->pPrev;
	return *this;
}
List::ReverseIterator& List::ReverseIterator::operator--()
{
	Temp = Temp->pNext;
	return *this;
}
const int& List::ReverseIterator::operator*()const
{
	return Temp->Data;
}
int& List::ReverseIterator::operator*()
{
	return Temp->Data;
}
bool List::ReverseIterator::operator!=(const ReverseIterator& other)const
{
	return this->Temp != other.Temp;
}

List::ReverseIterator::operator bool()const
{
	return this->Temp;
}
///////////////       LIST      ////////////////////

const List::Iterator List::begin()const
{
	return this->Head;
}

const List::Iterator List::end()const
{
	return nullptr;
}
const List::ReverseIterator List::rbegin()const
{
	return Tail;
}
List::ReverseIterator List::rbegin()
{
	return Tail;
}
const List::ReverseIterator List::rend()const
{
	return nullptr;
}
List::ReverseIterator List::rend()
{
	return nullptr;
}
List::List()
{
	Head = Tail = nullptr;
	size = 0;
	cout << "LConstructor:\t" << this << endl;
}
List::List(const std::initializer_list<int>& il) :List()
{
	for (const int* it = il.begin(); it != il.end(); it++)
	{
		push_back(*it);
	}
	cout << "ILConstructor:\t" << this << endl;
}
List::List(const List& other) :List()
{
	for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)
		push_back(Temp->Data);
	cout << "CopyConstructor:\t" << this << endl;
}
List::~List()
{
	//while (Head)pop_front();
	while (Tail)pop_back();
	cout << "LDestructor:\t" << this << endl;
}

//			Operators:
List& List::operator=(const List& other)
{
	if (this == &other)return *this;
	//while (Head)pop_front();
	this->~List();
	for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)
		push_back(Temp->Data);
	cout << "CopyAssignment:\t" << this << endl;
	return *this;
}


//			Adding elements:
void List::push_front(int Data)
{
	/*Element* New = new Element(Data);
	if (Head == nullptr && Tail == nullptr)
	{
		Head = Tail = New;
		size++;
		return;
	}
	New->pNext = Head;
	Head->pPrev = New;
	Head = New;
	size++;*/

	if (Head == nullptr && Tail == nullptr)
		Head = Tail = new Element(Data);
	else
		Head = Head->pPrev = new Element(Data, Head);
	size++;
	//////////////////////////////////////////////////
}
void List::push_back(int Data)
{
	if (Head == nullptr && Tail == nullptr)
	{
		Head = Tail = new Element(Data);
	}
	else
	{
		/*Element* New = new Element(Data);
		New->pPrev = Tail;
		Tail->pNext = New;
		Tail = New;*/
		Tail = Tail->pNext = new Element(Data, nullptr, Tail);
	}
	size++;
}
void insert(int Index, int value)
{

}

//			Removing elements:

void List::pop_front()
{
	if (Head == nullptr && Tail == nullptr)return;
	if (Head == Tail)
	{
		delete Head;
		Head = Tail = nullptr;
	}
	else
	{
		Head = Head->pNext;
		delete Head->pPrev;
		Head->pPrev = nullptr;
	}
	size--;
}

void List::pop_back()
{
	if (Head == Tail)
	{
		delete Head;
		Head = Tail = nullptr;
	}
	else
	{
		Tail = Tail->pPrev;
		delete Tail->pNext;
		Tail->pNext = nullptr;
	}
	size--;
}
void List::erase(int Index)
{
	if (Index == 0)
	{
		pop_front();
		return;
	}
	if (Index == size - 1)
	{
		pop_back();	//TODO
		return;
	}
	if (Index >= size)
	{
		return;
	}
	Element* Temp;
	if (Index < size / 2)
	{
		//Если, элемент ближе к началу списка, 
		//то заходим с головы, и идем от начала списка до нужного элемента.
		Temp = Head;
		for (int i = 0; i < Index; i++)Temp = Temp->pNext;
	}
	else
	{
		//Иначе, заходим через Хвост, и движемся по списку в обратном направлении, 
		//от конца, до нужного элемента.
		Temp = Tail;
		for (int i = 0; i < size - Index - 1; i++)Temp = Temp->pPrev;
	}
	//Не важно, как мы дошли до элемента, процедура удаления будет одна:
	Temp->pPrev->pNext = Temp->pNext;	//В pNext предыдущего элемента от Temp (Temp->pPrev) записываем адрес элемента, следующего за Temp
	Temp->pNext->pPrev = Temp->pPrev;
	delete Temp;
	size--;
}

//			Methods:

void List::print()
{
	//for (Element* Temp = Head; Temp; Temp++/*Temp = Temp->pNext*/)
	for (Iterator it = Head; it; ++it)
	{
		//cout << Temp->pPrev << tab << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
		cout << *it << "\t";
	}
	cout << "List size: \t" << size << endl;
}
void List::print_reverse()
{
	for (Element* Temp = Tail; Temp; Temp++/*Temp = Temp->pPrev*/)
	{
		cout << Temp->pPrev << tab << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
	}
	cout << "List size: \t" << size << endl;
}