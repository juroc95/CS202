//Juhwan Lee
//CS202
//Program 3
//This program is a monster battle program. The user has four monster options and can create
//monsters and confront opponents. Operator overloading and dynamic casting play a very
//important role in this program.

#include "battle.h"
using namespace std;

//default constructor for skill
skill::skill()
	: monster(NULL), name(NULL)
{
}

//copy constructor for skill
skill::skill(const skill & source)
{
	if(source.monster)
	{
		monster = new char [strlen(source.monster) + 1];
		strcpy(monster, source.monster);
	}
	else
		monster = NULL;
	if(source.name)
	{
		name = new char [strlen(source.name) + 1];
		strcpy(name, source.name);
	}
	else
		name = NULL;
}

//destructor for skill
skill::~skill()
{
	if(monster)
		delete [] monster;
	if(name)
		delete [] name;
	monster = name = NULL;
}

//operator overloading (=)
skill& skill::operator = (const skill & source)
{
	if(monster)
		delete [] monster;
	monster = new char [strlen(source.monster) + 1];
	strcpy(monster, source.monster);
	if(name)
		delete [] name;
	name = new char [strlen(source.name) + 1];
	strcpy(name, source.name);
	return *this;
}

//skill type identificiation function
int skill::skill_type()
{
	return 99;
}

//set data members
int skill::set(char * newmonster, char * newname)
{
	if(monster)
		delete [] monster;
	monster = new char [strlen(newmonster) + 1];
	strcpy(monster, newmonster);
	if(name)
		delete [] name;
	name = new char [strlen(newname) + 1];
	strcpy(name, newname);
	return 1;
}

//display
int skill::display()
{
	if(monster && name)
		cout << name << endl;
	return 1;
}

//search function
bool skill::is_match(int choice)
{
	return false;
}

//default constructor for attack
attack::attack()
	: attack_type(0)
{
}

//copy constructor for attack
attack::attack(const attack & source)
	: skill(source), attack_type(source.attack_type)
{
}

//operator overloading (=)
attack& attack::operator = (const attack & source)
{
	if(this == &source)
		return *this;
	skill::operator = (source);
	attack_type = source.attack_type;
	return *this;
}

//operator overloading (>)
bool attack::operator > (const attack & source) const
{
	if(attack_type == 1 && source.attack_type == 3)
		return true;
	if(attack_type == 3 && source.attack_type == 2)
		return true;
	if(attack_type == 2 && source.attack_type == 1)
		return true;
	else
		return false;
}

//operator overloading (<)
bool attack::operator < (const attack & source) const
{
	if(attack_type == 3 && source.attack_type == 1)
		return true;
	if(attack_type == 2 && source.attack_type == 3)
		return true;
	if(attack_type == 1 && source.attack_type == 2)
		return true;
	else
		return false;
}

//operator overloading (==)
bool attack::operator == (const attack & source) const
{
	if(attack_type == source.attack_type)
		return true;
	else
		return false;
}

//skill type identification function
int attack::skill_type()
{
	if(strcmp(monster, "Vampire") == 0)
		return 0;
	if(strcmp(monster, "Witch") == 0)
		return 2;
	if(strcmp(monster, "Werewolf") == 0)
		return 4;
	if(strcmp(monster, "Devil") == 0)
		return 6;
	else
		return 99;
}

//set data members
int attack::set(char * newmonster, char * newname, int newtype)
{
	skill::set(newmonster, newname);
	attack_type = newtype;
	return 1;
}

//display attack option
int attack::display()
{
	cout << endl << "********** option " << attack_type << " **********" << endl;
	skill::display();
	return 1;
}

//search function
bool attack::is_match(int choice)
{
	if(attack_type == choice)
		return true;
	else
		return false;
}

//default constructor for defense
defense::defense()
	: defense_type(0)
{
}

//copy constructor for defense
defense::defense(const defense & source)
	: skill(source), defense_type(source.defense_type)
{
}

//operator overloading (=)
defense& defense::operator = (const defense & source)
{
	if(this == &source)
		return *this;
	skill::operator = (source);
	defense_type = source.defense_type;
	return *this;
}

//skill type identification function
int defense::skill_type()
{
	if(strcmp(monster, "Vampire") == 0)
		return 1;
	if(strcmp(monster, "Witch") == 0)
		return 3;
	if(strcmp(monster, "Werewolf") == 0)
		return 5;
	if(strcmp(monster, "Devil") == 0)
		return 7;
	else
		return 99;
}

//set data members
int defense::set(char * newmonster, char * newname, int newtype)
{
	skill::set(newmonster, newname);
	defense_type = newtype;
	return 1;
}

//display defense option
int defense::display()
{
	cout << endl << "********** option " << defense_type << " **********" << endl;
	skill::display();
	return 1;
}

//search function
bool defense::is_match(int choice)
{
	if(defense_type == choice)
		return true;
	else
		return false;
}

//operator overloading (>)
bool defense::operator > (const defense & source) const
{
	if(defense_type == 1 && source.defense_type == 3)
		return true;
	if(defense_type == 3 && source.defense_type == 2)
		return true;
	if(defense_type == 2 && source.defense_type == 1)
		return true;
	else
		return false;
}

//operator overloading (<)
bool defense::operator < (const defense & source) const
{
	if(defense_type == 3 && source.defense_type == 1)
		return true;
	if(defense_type == 2 && source.defense_type == 3)
		return true;
	if(defense_type == 1 && source.defense_type == 2)
		return true;
	else
		return false;
}

//operator overloading (==)
bool defense::operator == (const defense & source) const
{
	if(defense_type == source.defense_type)
		return true;
	else
		return false;
}
