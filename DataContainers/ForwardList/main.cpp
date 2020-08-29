#include<iostream>
//using namespace std;
using std::cin;
using std::cout;
using std::endl;
using std::cerr;

class Element
{
    int Data;         // Содержит значени элемента
    Element* pNext;   // Адрес след. элемента
    //static int count; // Кол-во элементов
public:
    Element(int Data, Element* pNext = nullptr) :Data(Data), pNext(pNext)
    {
        //count++;
        //cout << "EConstructor:\t" << this << endl;
    }
    ~Element()
    {
        //count--;
        //cout << "EDestructor:\t" << this << endl;
    }
    friend class Iterator;
    friend class ForwardList;
};

//int Element::count = 0;

class Iterator
{
    Element* Temp;
public:
    Iterator(Element* Temp = nullptr)
    {
        this->Temp = Temp;
        cout << "ItConstructor:\t" << this << endl;
    }
    ~Iterator()
    {
        cout << "ItDestructor:\t" << this << endl;
    }

    Iterator& operator++()
    {
        Temp = Temp->pNext;
        return *this;
    }
    Iterator operator++(int)
    {
        Iterator old = *this;
        Temp = Temp->pNext;
        return old;
    }

    int& operator*()
    {
        return Temp->Data;
    }

    bool operator!=(const Iterator& other)const
    {
        return this->Temp != other.Temp;
    }
    bool operator!=(Element* other_el)const
    {
        return this->Temp != other_el;
    }
    operator bool()const
    {
        return Temp;
    }
};

class ForwardList
{
    Element* Head;
    int size;
public:
    int get_size()const
    {
        return this->size;
    }
    Iterator begin()
    {
        return Head;
    }
    Iterator end()
    {
        return nullptr;
    }
    ForwardList()
    {
        this->Head = nullptr;
        size = 0;
        cout << "LConstructor:\t" << this << endl;
    }
    ForwardList(int size) :ForwardList()
    {
        while (size--)push_front(0);
    }
    ForwardList(const std::initializer_list<int>& il)
    {
        for (const int* it = il.begin(); it != il.end(); it++)
        {
            push_back(*it);
        }
    }
    ForwardList(const ForwardList& other)
    {
        this->Head = nullptr;
        this->size = 0;
        for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)push_back(Temp->Data);
        cout << "LCopyConstructor:\t" << this << endl;
    }
    ~ForwardList()
    {
        while (Head != nullptr)pop_front();
        cout << "LDestructor:\t" << this << endl;
    }

    // Operators:
    int& operator[](int index)
    {
        if (index >= this->size)throw std::exception("Error: Out of range");
        Element* Temp = Head;
        for (int i = 0; i < index; i++)Temp = Temp->pNext;
        return Temp->Data;
    }

    // Methods:
    // Добавление элементов
    void push_front(int Data)
    {
        Element* New = new Element(Data); // Создали новый элемент, и сохранили в него добавляемое значение.
        // Теперь этот элемент нужно включить в список.
        New->pNext = Head;
        Head = New;

        Head = new Element(Data, Head);

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
        if (index == 0)
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

    // Удаление элементов
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
    // Methods:

    void print()
    {
#ifdef old_style
        Element* Temp = Head; // Temp - это итератор
             // Итератор - это указатель, при помощи которого можно получить доступ к элементам структуры данных
        while (Temp != nullptr)
        {
            cout << Temp << "\t" << Temp->Data << "\t" << Temp->pNext << endl;
            Temp = Temp->pNext; // Переход на след. элемент
        }
#endif // old_style
        //for (Iterator Temp = Head; Temp; Temp++/*Temp = Temp->pNext*/)
        for (Iterator Temp = begin(); Temp != end(); Temp++/*Temp = Temp->pNext*/)
        {
            //cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
            cout << *Temp << endl;
        }
        //cout << "List size: " << size << endl;

    }
};
#define delimiter "\n------------------------------------\n"
//#define BASE_CHECK
//#define PREFORMANCE_CHECK


void main()
{
    setlocale(LC_ALL, "");
    //int n; // размер списка
    //cout << "Input list size: "; cin >> n;
#ifdef BASE_CHECK
    ForwardList list;
    for (int i = 0; i < n; i++)
    {
        list.push_front(rand() % 100);
    }
    //list.push_back(123);
    list.print();
    cout << delimiter;
    ForwardList list2 = list;
    list2.print();
    /*list.pop_front();
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
    list.print();*/
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

#ifdef PREFORMANCE_CHECK
    ForwardList list(n); //создается список на N элементов
    //list.print();
    try
    {
        for (int i = 0; i < list.get_size(); i++)
        {
            list[i] = rand() % 100;
        }
        cout << endl;
        cout << "List loaded " << endl;
        for (int i = 0; i < list.get_size(); i++)
        {
            //cout << list[i] << "\t";
        }
        cout << endl;
        cout << "List printed " << endl;
    }
    catch (const std::exception & e)
    {
        cerr << e.what() << endl;
    }
#endif // PREFORMANCE_CHECK

    //const int n = 5;
    int arr[] = { 3, 5, 8, 13, 21 };
    /*for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
    {
        cout << arr[i] << tab;
    }
    cout << endl;*/
    for (int i : arr)
    {
        cout << i << "\t";
    }
    cout << endl;

    ForwardList list = { 3, 5, 8, 13, 21 };
    list.print();
    for (int i : list)
    {
        cout << i << "\t";
    }
    cout << endl;

}