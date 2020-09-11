#include "List.h"
#include "List.cpp"


//#define BASE_CHECK
//#define COPY_METHODS
//#define ITERATORS_CHECK

void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef BASE_CHECK
	int n;
	cout << "Input list size: "; cin >> n;
	List list;
	list.pop_front();
	for (int i = 0; i < n; i++)
	{
		list.push_back(rand() % 100);
	}
	list.print();
	//list.pop_front();
	list = list;
	//list.print_reverse();
#endif // BASE_CHECK


	/*int index;
	int data;
	cout << "Type index of deleting element: "; cin >> index;
	list.erase(index);

	list.print();
	//list.print_reverse();
	cout << "¬ведите индекс: "; cin >> index;
	cout << "¬ведите значение по индуксы: "; cin >> data;
	list.insert(index, data);
	list.print();*/

#ifdef COPY_METHODS
	cout << "\n===============================================\n";
	List list2;
	list2.push_back(123);
	list2.push_back(234);
	list2.push_back(345);
	cout << "\n-----------------------------------------------\n";
	list2 = list;
	cout << "\n-----------------------------------------------\n";
	list2.print();
	list2.print_reverse();
	cout << "\n===============================================\n";
#endif // COPY_METHODS

#ifdef ITERATORS_CHECK
	List list = { 3, 5, 8, 13, 21 };
	list.print();
	for (int i : list)
	{
		cout << i << tab;
	}
	cout << endl;
	for (List::Iterator it = list.begin(); it != list.end(); ++it)
	{
		cout << *it << "\t";
	}
	cout << endl;
	//for (List::Iterator it = list.end(); it; --it)
	for (List::ReverseIterator rit = list.rbegin(); rit != list.rend(); ++rit)
	{
		cout << *rit << "\t";
	}
	cout << endl;
#endif // ITERATORS_CHECK

	//Class<type> object;
	//List<int> list;

	List<int> list1{ 3, 5,8 ,13,21 };
	for (List<int>::Iterator it = list1.begin(); it != list1.end(); ++it)
	{
		cout << *it << tab;
	}
	cout << endl;
	for (List<int>::ReverseIterator it = list1.rbegin(); it != list1.rend(); ++it)
	{
		cout << *it << tab;
	}
	cout << endl;
	////////////////////////////////////////////////////////////////////
	List<double> list2 = { 2.5, 3.14, 8.2, 12.21 };
	for (double i : list2) 
	{
		cout << i << tab;
	}
	cout << endl;
	////////////////////////////////////////////////////////////////////
	List<std::string> list3 = { "живет","на", "свете"};
	list3.push_front("’ќрошо");
	list3.push_back("¬инни-пух");
	for (std::string i : list3)
	{
		cout << i << tab;
	}
	cout << endl;
	for (List<std::string>::ReverseIterator it = list3.rbegin(); it != list3.rend(); ++it)
	{
		cout << *it << tab;
	}
	cout << endl;
}