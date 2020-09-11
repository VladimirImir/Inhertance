#pragma once
#include<iostream>
#include<string>
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

template<typename T>
class List
{
	class Element
	{
		T Data;
		Element* pNext;
		Element* pPrev;
	public:
		Element(T Data, Element* pNext = nullptr, Element* pPrev = nullptr);
		~Element();
		friend class List;
		friend class Iterator;
		friend class ReverseIterator;
	};// *Head, *Tail;
	Element* Head;
	Element* Tail;
	int size;
public:

	class Iterator
	{
		Element* Temp;
	public:
		Iterator(Element* Temp = nullptr) ;
		~Iterator();
		Iterator& operator++();
		Iterator& operator--();
		const T& operator*()const;

		T& operator*();

		bool operator!=(const Iterator& other)const;

		operator bool()const;
	};

	class ReverseIterator
	{
		Element* Temp;
	public:
		ReverseIterator(Element* Temp = nullptr);
		~ReverseIterator();
		ReverseIterator& operator++();
		ReverseIterator& operator--();
		const T& operator*()const;
		T& operator*();
		bool operator!=(const ReverseIterator& other)const;

		operator bool()const;
	};

	const Iterator begin()const;
	const Iterator end()const;
	const ReverseIterator rbegin()const;
	ReverseIterator rbegin();
	const ReverseIterator rend()const;
	ReverseIterator rend();
	List();
	List(const std::initializer_list<T>& il);
	List(const List& other) ;
	~List();

	//			Operators:
	List& operator=(const List& other);


	//			Adding elements:
	void push_front(T Data);
	void push_back(T Data);

	//			Removing elements:

	void pop_front();

	void pop_back();
	void erase(int Index);

	//			Methods:

	void print();
	void print_reverse();
};