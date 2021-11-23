//Juhwan Lee
//CS202
//Program 3
//This program is a monster battle program. The user has four monster options and can create
//monsters and confront opponents. Operator overloading and dynamic casting play a very
//important role in this program.

#include <iostream>
#include <cctype>
#include <cstring>

class skill
{
	public:
		skill();
		skill(const skill & source);
		~skill();

		//operator overloading for ARR functions
		virtual skill& operator = (const skill & source);

		virtual int skill_type();
		virtual int set(char * newmonster, char * newname);
		virtual int display();
		virtual bool is_match(int choice);
	protected:
		char * monster;
		char * name;
};

class attack :public skill
{
	public:
		attack();
		attack(const attack & source);

		//operator overloading for ARR functions
		attack& operator = (const attack & source);
		//operator overloading for monster battle
		bool operator > (const attack & source) const; 
		bool operator < (const attack & source) const;
		bool operator == (const attack & source) const;

		int skill_type();
		int set(char * newmonster, char * newname, int newtype);
		int display();
		bool is_match(int choice);
	protected:
		int attack_type;
};

class defense :public skill
{
	public:
		defense();
		defense(const defense & source);

		//operator overloading for ARR functions
		defense& operator = (const defense & source);
		//operator overloading for monster battle
		bool operator > (const defense & source) const; 
		bool operator < (const defense & source) const;
		bool operator == (const defense & source) const;

		int skill_type();
		int set(char * newmonster, char * newname, int newtype);
		int display();
		bool is_match(int choice);
	protected:
		int defense_type;
};
