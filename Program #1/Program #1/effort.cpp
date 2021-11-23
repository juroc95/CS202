//Juhwan Lee
//Program 1
//This program will support emergency relief efforts.
//We want to allow easy cataloging of donations dropped off or
//made available and then allow those in need to browse what is
//available.

#include "effort.h"
using namespace std;

//defaut constructor for base class
effort::effort()
	: name(NULL)
{
}

//copy constructor for base class
effort::effort(const effort & source)
{
	if(source.name)
	{
		name = new char [strlen(source.name) + 1];
		strcpy(name, source.name);
	}
	else
		name = NULL;
}

//destructor for base class
effort::~effort()
{
	delete [] name;
	name = NULL;
}

//default constructor for housing
housing::housing()
	: street(NULL), zip(NULL)
{
}

//copy constructor for housing
housing::housing(const housing & source): effort(source)
{
	if(source.street)
	{
		street = new char [strlen(source.street) + 1];
		strcpy(street, source.street);
	}
	else
		street = NULL;
	if(source.zip)
	{
		zip = new char [strlen(source.zip) + 1];
		strcpy(zip, source.zip);
	}
	else
		zip = NULL;
}

//destructor for housing
housing::~housing()
{
	delete [] street;
	delete [] zip;
	street = NULL;
	zip = NULL;
}

//default constructor for food
food::food()
	: year(0), month(0), day(0)
{
}

//default constructor for clothing
clothing::clothing()
	: size(NULL)
{
}

//copy constructor for clothing
clothing::clothing(const clothing & source): effort(source)
{
	if(source.size)
	{
		size = new char [strlen(source.size) + 1];
		strcpy(size, source.size);
	}
	else
		size = NULL;
}

//destructor for clothing
clothing::~clothing()
{
	delete [] size;
	size = NULL;
}

void effort::set_effort()
{
	char newname[100];
	cout << "Please enter its name : ";
	cin.get(newname, 100, '\n');
	cin.ignore(100, '\n');
	name = new char [strlen(newname) + 1];
	strcpy(name, newname);
}

void effort::change_name()
{
	if(name)
	{
		char newname[100];
		cout << "Please enter its name : ";
		cin.get(newname, 100, '\n');
		cin.ignore(100, '\n');
		delete [] name;
		name = new char [strlen(newname) + 1];
		strcpy(name, newname);
	}
}

void effort::display_name()const
{
	if(name)
		cout << "Name : " << name << endl;
	else
		cout << "Name : empty" << endl;
}

int effort::ismatch(char source[])
{
	if(strcmp(name, source) == 0)
		return 1;
	else
		return 0;
}

void effort::copy_name(const effort & source)
{
	if(source.name)
	{
		name = new char [strlen(source.name) + 1];
		strcpy(name, source.name);
	}
	else
		name = NULL;
}

void housing::set_housing()
{
	set_effort();
	char newstreet[100];
	char newzip[100];
	cout << "Please enter the street address : ";
	cin.get(newstreet, 100, '\n');
	cin.ignore(100, '\n');
	cout << "Please enter the zip code : ";
	cin.get(newzip, 100, '\n');
	cin.ignore(100, '\n');
	street = new char [strlen(newstreet) + 1];
	strcpy(street, newstreet);
	zip = new char [strlen(newzip) + 1];
	strcpy(zip, newzip);
}

void housing::change_housing()
{
	change_name();
	if(street)
	{
		char newstreet[100];
		cout << "Please enter the street address : ";
		cin.get(newstreet, 100, '\n');
		cin.ignore(100, '\n');
		delete [] street;
		street = new char [strlen(newstreet) + 1];
		strcpy(street, newstreet);
	}
	if(zip)
	{	
		char newzip[100];
		cout << "Please enter the zip code : ";
		cin.get(newzip, 100, '\n');
		cin.ignore(100, '\n');
		delete [] zip;
		zip = new char [strlen(newzip) + 1];
		strcpy(zip, newzip);
	}
}


void housing::display()const
{
	display_name();
	if(street)
		cout << "Street : " << street << endl;
	else
		cout << "Street : empty" << endl;
	if(zip)
		cout << "Zip : " << zip << endl;
	else
		cout << "Zip : empty" << endl;
}

int housing::ismatch(char source[])
{
	int var = 0;
	var = effort::ismatch(source);
	return var;
}

void housing::copy(const housing & source)
{
	copy_name(source);
	if(source.street)
	{
		street = new char [strlen(source.street) +1];
		strcpy(street, source.street);
	}
	else
		street = NULL;
	if(source.zip)
	{
		zip = new char [strlen(source.zip) + 1];
		strcpy(zip, source.zip);
	}
	else
		zip = NULL;
}

void food::set_food()
{
	set_effort();
	cout << "Please enter the expiration date : " << endl;
	cout << "Year : ";
	cin >> year;
	cin.ignore(100, '\n');
	cout << "Month : ";
	cin >> month;
	cin.ignore(100, '\n');
	cout << "Day : ";
	cin >> day;
	cin.ignore(100, '\n');
}

void food::change_food()
{
	change_name();
	cout << "Please enter the expiration date : " << endl;
	cout << "Year : ";
	cin >> year;
	cin.ignore(100, '\n');
	cout << "Month : ";
	cin >> month;
	cin.ignore(100, '\n');
	cout << "Day : ";
	cin >> day;
	cin.ignore(100, '\n');
}

void food::display()const
{
	display_name();
	cout << "Expiration date : " << year << " . " << month << " . " << day << endl;
}

int food::ismatch(char source[])
{
	int var = 0;
	var = effort::ismatch(source);
	return var;
}

void food::copy(const food & source)
{
	copy_name(source);
	year = source.year;
	month = source.month;
	day = source.day;
}

void clothing::set_clothing()
{
	set_effort();
	char newsize[100];
	cout << "Please enter the size : ";
	cin.get(newsize, 100, '\n');
	cin.ignore(100, '\n');
	size = new char [strlen(newsize) + 1];
	strcpy(size, newsize);
}

void clothing::change_clothing()
{
	change_name();
	if(size)
	{
		char newsize[100];
		cout << "Please enter the size : ";
		cin.get(newsize, 100, '\n');
		cin.ignore(100, '\n');
		delete [] size;
		size = new char [strlen(newsize) + 1];
		strcpy(size, newsize);
	}
}

void clothing::display()const
{
	display_name();
	if(size)
		cout << "Size : " << size << endl;
	else
		cout << "Size : empty" << endl;
}

int clothing::ismatch(char source[])
{
	int var = 0;
	var = effort::ismatch(source);
	return var;
}

void clothing::copy(const clothing & source)
{
	copy_name(source);
	if(source.size)
	{
		size = new char [strlen(source.size) + 1];
		strcpy(size, source.size);
	}
	else
		size = NULL;
}
