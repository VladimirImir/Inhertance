#include <iostream>
#include <string>
using namespace std;

class Box
{
	double width;
	double heigth;
	double length;
public:
	double get_width()const
	{
		return width;
	}	
	double get_heigth()const
	{
		return heigth;
	}	
	double get_length()const
	{
		return length;
	}
	double set_width(double width)
	{
		if (width < 0) width = -width;
		return this->width = width;
	}	
	double set_heigth(double heigth)
	{
		if (heigth < 0) heigth = -heigth;
		return this->heigth = heigth;
	}
	double set_length(double length)
	{
		if (length < 0) length = -length;
		return this->length = length;
	}
	//			Constructors:
	Box(double width, double heigth, double length) :
		width(set_width(width)),
		heigth(set_heigth(heigth)),
		length(set_length(length))
	{
		cout << "BConstructor:\t" << this << endl;
	}
	~Box()
	{
		cout << "BDestructor:\t" << this << endl;
	}

	//		Methods:
	void print()const
	{
		cout << width << "x" << heigth << "x" << length << endl;
	}
};

class GiftBox : public Box
{
	string cover;
	bool bant;
public:
	const string& get_cover()const
	{
		return this->cover;
	}
	bool get_bant()const
	{
		return this->bant;
	}

	GiftBox
	(
		double width, double heigth, double length, 
		const string& cover, bool bant
	) : Box(width, heigth, length)
	{
		this->cover = cover;
		this->bant = bant;
		cout << "GBConstructor:\t" << this << endl;
	}
	~GiftBox()
	{
		cout << "GBDestructor:\t" << this << endl;
	}
	void print()const
	{
		Box::print();
		cout << cover << endl;
		cout << "Bant: " << (bant ? "yes" : "no") << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	/*Box box(2, 1, 3);
	box.print();*/
	GiftBox gb(2, 1, 3, "with flowers", true);
	gb.print();
}