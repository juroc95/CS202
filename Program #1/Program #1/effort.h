//Juhwan Lee
//Program 1
//This program will support emergency relief efforts.
//We want to allow easy cataloging of donations dropped off or
//made available and then allow those in need to browse what is
//available.

#include <iostream>
#include <cctype>
#include <cstring>

class effort
{
	public:
		effort();
		effort(const effort & source);
		~effort();
		void set_effort();
		void change_name();
		void display_name()const;
		int ismatch(char source[]);
		void copy_name(const effort & source);
	protected:
		char * name;
};

class housing: public effort
{
	public:
		housing();
		housing(const housing & source);
		~housing();
		void set_housing();
		void change_housing();
		void display()const;
		int ismatch(char source[]);
		void copy(const housing & source);
	protected:
		char * street;
		char * zip;
};

class food: public effort
{
	public:
		food();
		void set_food();
		void change_food();
		void display()const;
		int ismatch(char source[]);
		void copy(const food & source);
	protected:
		int year;
		int month;
		int day;
};

class clothing: public effort
{
	public:
		clothing();
		clothing(const clothing & source);
		~clothing();
		void set_clothing();
		void change_clothing();
		void display()const;
		int ismatch(char source[]);
		void copy(const clothing & source);
	protected:
		char * size;
};
