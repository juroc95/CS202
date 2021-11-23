//Juhwan Lee
//CS202
//Program 3
//This program is a monster battle program. The user has four monster options and can create
//monsters and confront opponents. Operator overloading and dynamic casting play a very
//important role in this program.

#include "BST.h"

class snode
{
	public:
		snode();
		void set_data(skill * newdata);
		void set_previous(snode * newprev);
		void set_next(snode * newnext);
		skill*& get_data();
		snode*& get_previous();
		snode*& get_next();
	protected:
		skill * data;
		snode * previous;
		snode * next;
};

class ARR
{
	public:
		ARR();
		~ARR();
		void destructor(snode * & head);
		int insert(skill * newdata);
		int insert(snode * & head, skill * newdata);
		int display_attack(monster * myobject);
		int display_attack(snode * head);
		int display_defense(monster * myobject);
		int display_defense(snode * head);
		int retrieve_attack(monster * myobject, attack & myattack, int choice);
		int retrieve_attack(snode * head, attack & myattack, int choice);
		int retrieve_defense(monster * myobject, defense & mydefense, int choice);
		int retrieve_defense(snode * head, defense & mydefense, int choice);
		int retrieve_opponent_attack(int monster, int opponent_attack, attack & opattack);
		int retrieve_opponent_attack(snode * head, int opponent_attack, attack & opattack);
		int retrieve_opponent_defense(int monster, int opponent_defense, defense & opdefense);
		int retrieve_opponent_defense(snode * head, int opponent_defense, defense & opdefense);
		int remove_attack(monster * myobject, int choice);
		int remove_attack(snode * & head, int choice);
		int remove_defense(monster * myobject, int choice);
		int remove_defense(snode * & head, int choice);
		int remove_all();
		int remove_all(snode * & head);
	protected:
		snode ** head;
		int size;
};
