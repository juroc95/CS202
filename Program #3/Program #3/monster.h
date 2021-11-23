//Juhwan Lee
//CS202
//Program 3
//This program is a monster battle program. The user has four monster options and can create
//monsters and confront opponents. Operator overloading and dynamic casting play a very
//important role in this program.

#include "battle.h"

class monster
{
	public:
		monster();
		monster(const monster & source);
		virtual ~monster();

		//operator overloading for BST functions
		bool operator <= (const monster & source) const;
		bool operator == (const monster & source) const;
		bool operator >= (const monster & source) const;

		int set_name();
		virtual int display();
		int search(char * search);
	protected:
		char * name;
};

class vampire :public monster
{
	public:
		vampire();
		vampire(const vampire & source);
		~vampire();
		int display();
	protected:
		char * type;
		char * ability;
};

class witch :public monster
{
	public:
		witch();
		witch(const witch & source);
		~witch();
		int display();
	protected:
		char * type;
		char * ability;
};

class werewolf :public monster
{
	public:
		werewolf();
		werewolf(const werewolf & source);
		~werewolf();
		int display();
	protected:
		char * type;
		char * ability;
};

class devil :public monster
{
	public:
		devil();
		devil(const devil & source);
		~devil();
		int display();
	protected:
		char * type;
		char * ability;
};
