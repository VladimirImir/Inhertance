#include <iostream>
#include<string>
using namespace std;

class Human
{
	string name;
	string surname;
	int age;
	bool gender;
public:
	const string& get_name()const
	{
		return name;
	}	
	const string& get_surname()const
	{
		return surname;
	}
	int get_age()const
	{
		return age;
	}
	bool get_gender()const
	{
		return gender;
	}
	const string& set_name(const string& name)
	{
		return this->name = name;
	}	
	const string& set_surname(const string& surname)
	{
		return this->surname = surname;
	}
	int set_age(int age)
	{
		return this->age = age;
	}
	bool set_gender(bool gender)
	{
		return this->gender = gender;
	}
	//		Constructor:
	Human(const string& name, const string& surname, int age, bool gender)
	{
		this->name = name;
		this->surname = surname;
		this->age = age;
		this->gender = gender;
	}
	~Human()
	{

	}
	//		Methods:
	void print()const
	{
		cout << "Neme: " << name << endl << "Surneme: " << surname << endl << "Age: " << age << endl << "Gender: " << gender << endl;
	}
};

class Student : public Human
{
	string group;
	int rating;
	bool attendance;
	string specialty;
public:
	const string& get_group()const
	{
		return group;
	}
	int get_rating()const
	{
		return rating;
	}
	bool get_attendance()const
	{
		return attendance;
	}
	const string& get_specialty()const
	{
		return specialty;
	}
	const string& set_group(const string& group)
	{
		return this->group = group;
	}
	int set_rating(int rating)
	{
		return this->rating = rating;
	}
	bool set_attendance(bool attendance)
	{
		return this->attendance = attendance;
	}
	const string& set_specialty(const string& specialty)
	{
		return this->specialty = specialty;
	}
	//		Constructor:
	Student(const string& group, int rating, bool attendance, const string& specialty, const string& name, const string& surname, int age, bool gender) : Human(name, surname, age, gender)
	{
		this->group = group;
		this->rating = rating;
		this->attendance = attendance;
		this->specialty = specialty;
	}
	~Student()
	{

	}
	void print()
	{
		Human::print();
		cout << "Group: " << group << endl << "Rating: " << rating << " %" << endl << "Attendance: " << attendance << endl << "Specialty: " << specialty << endl;
	}
};

class Teacher : public Human
{
	string subject;
	string experience;
	string specialty;
	string evil;
public:
	const string& get_subject()const
	{
		return subject;
	}
	const string& get_experience()const
	{
		return experience;
	}
	const string& get_specialty()const
	{
		return specialty;
	}
	const string& get_evil()const
	{
		return evil;
	}
	const string& set_subject(const string& subject)
	{
		return this->subject = subject;
	}
	const string& set_experience(const string& experience)
	{
		return this->experience = experience;
	}
	const string& set_specialty(const string& specialty)
	{
		return this->specialty = specialty;
	}
	const string& set_evil(const string& evil)
	{
		return this->evil = evil;
	}
	//		Constructor:
	Teacher(const string& subject, const string& experience, const string& specialty, const string& evil, const string& name, const string& surname, int age, bool gender) : Human(name, surname, age, gender)
	{
		this->subject = subject;
		this->experience = experience;
		this->specialty = specialty;
		this->evil = evil;
	}
	~Teacher()
	{

	}
	void print()
	{
		Human::print();
		cout << "Subject: " << subject << endl << "Experience: " << experience << endl << "Specialty: " << specialty << endl << "Evil: " << evil << endl;
	}

};

class Graduate :public Student
{
	string diploma_theme;
public:
	const string& get_diploma_theme()
	{
		return diploma_theme;
	}

};

void main()
{
	setlocale(LC_ALL, "");
	cout << "\t\t\t\t\"Human\"" << endl;
	Human Human("Петя", "Петров", 20, true);
	Human.print();
	cout << "\t\t\t\t\"Student\"" << endl;
	Student Student("Разработка ПО", 100, true, "Software development", "Вася", "Васёв", 25, true);
	Student.print();
	cout << "\t\t\t\t\"Teacher\"" << endl;
	Teacher Teacher("Web development", "10 Лет", "Web development", "Не всегда!", "Иван", "Иванов", 35, true);
	Teacher.print();
}