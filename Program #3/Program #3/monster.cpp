//Juhwan Lee
//CS202
//Program 3
//This program is a monster battle program. The user has four monster options and can create
//monsters and confront opponents. Operator overloading and dynamic casting play a very
//important role in this program.

#include "monster.h"
using namespace std;

//default constructor for monster
monster::monster()
	: name(NULL)
{
}

//copy constructor for monster
monster::monster(const monster & source)
{
	if(source.name)
	{
		name = new char [strlen(source.name) + 1];
		strcpy(name, source.name);
	}
	else
		name = NULL;
}

//destructor for monster
monster::~monster()
{
	if(name)
		delete [] name;
	name = NULL;
}

//operator overloading for BST functions (<=)
bool monster::operator <= (const monster & source) const
{
	if(strcmp(name, source.name) <= 0)
		return true;
	else
		return false;
}

//operator overloading for BST functions (==)
bool monster::operator == (const monster & source) const
{
	if(strcmp(name, source.name) == 0)
		return true;
	else
		return false;
}

//operator overloading for BST functions (>=)
bool monster::operator >= (const monster & source) const
{
	if(strcmp(name, source.name) >= 0)
		return true;
	else
		return false;
}

//the user can set the name of the monster
int monster::set_name()
{
	if(name)
		delete [] name;
	char temp[100];
	cout << "Please enter the name of the monster: ";
	cin.get(temp, 100, '\n');
	cin.ignore(100, '\n');
	name = new char [strlen(temp) + 1];
	strcpy(name, temp);
	return 1;
}

//display the monster
int monster::display()
{
	if(name)
	{
		cout << endl << "Monster name: " << name << endl;
		return 1;
	}
	else
		return 0;
}

//search function
int monster::search(char * search)
{
	if(strcmp(name, search) == 0)
		return 1;
	if(strcmp(search, name) <= 0)
		return 2;
	else
		return 0;
}

//default constructor for vampire
vampire::vampire()
{
	char temp1[100];
	char temp2[100];
	strcpy(temp1, "Vampire");
	strcpy(temp2, "Sharp teeth and vampiric");
	type = new char [strlen(temp1) + 1];
	strcpy(type, temp1);
	ability = new char [strlen(temp2) + 1];
	strcpy(ability, temp2);
}

//copy constructor for vampire
vampire::vampire(const vampire & source)
	: monster(source)
{
	if(source.type)
	{
		type = new char [strlen(source.type) + 1];
		strcpy(type, source.type);
	}
	else
		type = NULL;
	if(source.ability)
	{
		ability = new char [strlen(source.ability) + 1];
		strcpy(ability, source.ability);
	}
	else
		ability = NULL;
}

//destructor for vampire
vampire::~vampire()
{
	if(type)
		delete [] type;
	if(ability)
		delete [] ability;
	type = ability = NULL;
}

//display vampire
int vampire::display()
{
	monster::display();
	if(type && ability)
	{
		cout << "Monster type: " << type << endl;
		cout << "Special ability: " << ability << endl << endl;
		return 1;
	}
	else
		return 0;
}

//default constructor for witch
witch::witch()
{
	char temp1[100];
	char temp2[100];
	strcpy(temp1, "Witch");
	strcpy(temp2, "Flies on a broom");
	type = new char [strlen(temp1) + 1];
	strcpy(type, temp1);
	ability = new char [strlen(temp2) + 1];
	strcpy(ability, temp2);
}

//copy constructor for witch
witch::witch(const witch & source)
	: monster(source)
{
	if(source.type)
	{
		type = new char [strlen(source.type) + 1];
		strcpy(type, source.type);
	}
	else
		type = NULL;
	if(source.ability)
	{
		ability = new char [strlen(source.ability) + 1];
		strcpy(ability, source.ability);
	}
	else
		ability = NULL;
}

//destructor for witch
witch::~witch()
{
	if(type)
		delete [] type;
	if(ability)
		delete [] ability;
	type = ability = NULL;
}

//display witch
int witch::display()
{
	monster::display();
	if(type && ability)
	{
		cout << "Monster type: " << type << endl;
		cout << "Special ability: " << ability << endl << endl;
		return 1;
	}
	else
		return 0;
}

//default constructor for werewolf
werewolf::werewolf()
{
	char temp1[100];
	char temp2[100];
	strcpy(temp1, "Werewolf");
	strcpy(temp2, "Has sharp claws");
	type = new char [strlen(temp1) + 1];
	strcpy(type, temp1);
	ability = new char [strlen(temp2) + 1];
	strcpy(ability, temp2);
}

//copy constructor for werewolf
werewolf::werewolf(const werewolf & source)
	: monster(source)
{
	if(source.type)
	{
		type = new char [strlen(source.type) + 1];
		strcpy(type, source.type);
	}
	else
		type = NULL;
	if(source.ability)
	{
		ability = new char [strlen(source.ability) + 1];
		strcpy(ability, source.ability);
	}
	else
		ability = NULL;
}

//destructor for werewolf
werewolf::~werewolf()
{
	if(type)
		delete [] type;
	if(ability)
		delete [] ability;
	type = ability = NULL;
}

//display werewolf
int werewolf::display()
{
	monster::display();
	if(type && ability)
	{
		cout << "Monster type: " << type << endl;
		cout << "Special ability: " << ability << endl << endl;
		return 1;
	}
	else
		return 0;
}

//default constructor for devil
devil::devil()
{
	char temp1[100];
	char temp2[100];
	strcpy(temp1, "Devil");
	strcpy(temp2, "Controls people's mind");
	type = new char [strlen(temp1) + 1];
	strcpy(type, temp1);
	ability = new char [strlen(temp2) + 1];
	strcpy(ability, temp2);
}

//copy constructor for devil
devil::devil(const devil & source)
	: monster(source)
{
	if(source.type)
	{
		type = new char [strlen(source.type) + 1];
		strcpy(type, source.type);
	}
	else
		type = NULL;
	if(source.ability)
	{
		ability = new char [strlen(source.ability) + 1];
		strcpy(ability, source.ability);
	}
	else
		ability = NULL;
}

//destructor for devil
devil::~devil()
{
	if(type)
		delete [] type;
	if(ability)
		delete [] ability;
	type = ability = NULL;
}

//display devil
int devil::display()
{
	monster::display();
	if(type && ability)
	{
		cout << "Monster type: " << type << endl;
		cout << "Special ability: " << ability << endl << endl;
		return 1;
	}
	else
		return 0;
}
