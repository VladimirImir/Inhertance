#include"List.h"

///////////////      ELEMENT     ////////////////////

template<typename T>
List<T>::Element::Element(T Data, Element* pNext, Element* pPrev) :Data(Data), pNext(pNext), pPrev(pPrev)
{
	cout << "EConstructor:\t" << this << endl;
}
template<typename T>
List<T>::Element::~Element()
{
	cout << "EDestructor:\t" << this << endl;
}

///////////////      ITERATOR     ////////////////////
template<typename T>
List<T>::Iterator::Iterator(Element* Temp) :Temp(Temp)
{
	//cout << "ItConstructor:\t" << this << endl;
}
template<typename T>
List<T>::Iterator::~Iterator()
{
	//cout << "ItDestructor:\t" << this << endl;
}
template<typename T>
typename List<T>::Iterator& List<T>::Iterator::operator++()
{
	Temp = Temp->pNext;
	return *this;
}
template<typename T>
typename List<T>::Iterator& List<T>::Iterator::operator--()
{
	Temp = Temp->pPrev;
	return *this;
}

template<typename T>
const T& List<T>::Iterator::operator*()const
{
	return Temp->Data;
}
template<typename T>
T& List<T>::Iterator::operator*()
{
	return Temp->Data;
}
template<typename T>
bool List<T>::Iterator::operator!=(const Iterator& other)const
{
	return this->Temp != other.Temp;
}
template<typename T>
List<T>::Iterator::operator bool()const
{
	return Temp;
}

/////////////// REVERS ITERATOR ////////////////////

template<typename T>
List<T>::ReverseIterator::ReverseIterator(Element* Temp) :Temp(Temp)
{
	//cout << "RItConstruvtor:\t" << this << endl;
}
template<typename T>
List<T>::ReverseIterator::~ReverseIterator()
{
	//cout << "RItDestruvtor:\t" << this << endl;
}
template<typename T>
typename List<T>::ReverseIterator& List<T>::ReverseIterator::operator++()
{
	Temp = Temp->pPrev;
	return *this;
}
template<typename T>
typename List<T>::ReverseIterator& List<T>::ReverseIterator::operator--()
{
	Temp = Temp->pNext;
	return *this;
}
template<typename T>
const T& List<T>::ReverseIterator::operator*()const
{
	return Temp->Data;
}
template<typename T>
T& List<T>::ReverseIterator::operator*()
{
	return Temp->Data;
}
template<typename T>
bool List<T>::ReverseIterator::operator!=(const ReverseIterator& other)const
{
	return this->Temp != other.Temp;
}
template<typename T>
List<T>::ReverseIterator::operator bool()const
{
	return this->Temp;
}

///////////////       LIST      ////////////////////

template<typename T>
typename const List<T>::Iterator List<T>::begin()const
{
	return this->Head;
}
template<typename T>
typename const List<T>::Iterator List<T>::end()const
{
	return nullptr;
}
template<typename T>
typename const List<T>::ReverseIterator List<T>::rbegin()const
{
	return Tail;
}
template<typename T>
typename List<T>::ReverseIterator List<T>::rbegin()
{
	return Tail;
}
template<typename T>
typename const List<T>::ReverseIterator List<T>::rend()const
{
	return nullptr;
}
template<typename T>
typename List<T>::ReverseIterator List<T>::rend()
{
	return nullptr;
}
template<typename T>
List<T>::List()
{
	Head = Tail = nullptr;
	size = 0;
	cout << "LConstructor:\t" << this << endl;
}
template<typename T>
List<T>::List(const std::initializer_list<T>& il) :List()
{
	for (const T* it = il.begin(); it != il.end(); it++)
	{
		push_back(*it);
	}
	cout << "ILConstructor:\t" << this << endl;
}
template<typename T>
List<T>::List(const List& other) :List()
{
	for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)
		push_back(Temp->Data);
	cout << "CopyConstructor:\t" << this << endl;
}
template<typename T>
List<T>::~List()
{
	//while (Head)pop_front();
	while (Tail)pop_back();
	cout << "LDestructor:\t" << this << endl;
}

//			Operators:
template<typename T>
List<T>& List<T>::operator=(const List& other)
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
template<typename T>
void List<T>::push_front(T Data)
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
template<typename T>
void List<T>::push_back(T Data)
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


//			Removing elements:
template<typename T>
void List<T>::pop_front()
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
template<typename T>
void List<T>::pop_back()
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
template<typename T>
void List<T>::erase(int Index)
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
template<typename T>
void List<T>::print()
{
	//for (Element* Temp = Head; Temp; Temp++/*Temp = Temp->pNext*/)
	for (Iterator it = Head; it; ++it)
	{
		//cout << Temp->pPrev << tab << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
		cout << *it << "\t";
	}
	cout << "List size: \t" << size << endl;
}
template<typename T>
void List<T>::print_reverse()
{
	for (Element* Temp = Tail; Temp; Temp++/*Temp = Temp->pPrev*/)
	{
		cout << Temp->pPrev << tab << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
	}
	cout << "List size: \t" << size << endl;
}