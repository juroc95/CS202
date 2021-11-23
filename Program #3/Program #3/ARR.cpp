//Juhwan Lee
//CS202
//Program 3
//This program is a monster battle program. The user has four monster options and can create
//monsters and confront opponents. Operator overloading and dynamic casting play a very
//important role in this program.

#include "ARR.h"
using namespace std;

//default constructor for skill node
snode::snode()
	: data(NULL), previous(NULL), next(NULL)
{
}

//set data
void snode::set_data(skill * newdata)
{
	data = newdata;
}

//set previous
void snode::set_previous(snode * newprev)
{
	previous = newprev;
}

//set next
void snode::set_next(snode * newnext)
{
	next = newnext;
}

//get data
skill*& snode::get_data()
{
	return data;
}

//get previous
snode*& snode::get_previous()
{
	return previous;
}

//get next
snode*& snode::get_next()
{
	return next;
}

//default constructor for array of DLL
ARR::ARR()
{
	size = 8;
	head = new snode* [size];
	for(int i = 0; i < size; ++i)
	{
		head[i] = NULL;
	}
}

//destructor for array of DLL
ARR::~ARR()
{
	if(!head)
		return;
	for(int i = 0; i < size; ++i)
	{
		destructor(head[i]);
	}
}

//destructor for array of DLL (recursive)
void ARR::destructor(snode * & head)
{
	if(!head)
		return;
	destructor(head->get_next());
	delete head->get_data();
	head->set_previous(NULL);
	delete head;
	head = NULL;
}

//insert (wrapper)
int ARR::insert(skill * newdata)
{
	if(newdata->skill_type() == 0)
		return insert(head[0], newdata);
	if(newdata->skill_type() == 1)
		return insert(head[1], newdata);
	if(newdata->skill_type() == 2)
		return insert(head[2], newdata);
	if(newdata->skill_type() == 3)
		return insert(head[3], newdata);
	if(newdata->skill_type() == 4)
		return insert(head[4], newdata);
	if(newdata->skill_type() == 5)
		return insert(head[5], newdata);
	if(newdata->skill_type() == 6)
		return insert(head[6], newdata);
	if(newdata->skill_type() == 7)
		return insert(head[7], newdata);
	else
		return 0;
}

//insert (recursive)
int ARR::insert(snode * & head, skill * newdata)
{
	if(!head)
	{
		head = new snode;
		head->set_data(newdata);
		head->set_previous(NULL);
		head->set_next(NULL);
		return 1;
	}
	if(!head->get_next())
	{
		head->get_next() = new snode;
		head->get_next()->set_data(newdata);
		head->get_next()->set_previous(head);
		head->get_next()->set_next(NULL);
		return 1;
	}
	return insert(head->get_next(), newdata);
}

//display attack (wrapper)
int ARR::display_attack(monster * myobject)
{
	vampire * ptr1 = dynamic_cast<vampire*>(myobject);
	if(ptr1)
		return display_attack(head[0]);
	witch * ptr2 = dynamic_cast<witch*>(myobject);
	if(ptr2)
		return display_attack(head[2]);
	werewolf * ptr3 = dynamic_cast<werewolf*>(myobject);
	if(ptr3)
		return display_attack(head[4]);
	devil * ptr4 = dynamic_cast<devil*>(myobject);
	if(ptr4)
		return display_attack(head[6]);
	else
		return 0;
}

//display attack (recursive)
int ARR::display_attack(snode * head)
{
	if(!head)
		return 0;
	head->get_data()->display();
	display_attack(head->get_next());
	return 1;
}

//display defense (wrapper)
int ARR::display_defense(monster * myobject)
{
	vampire * ptr1 = dynamic_cast<vampire*>(myobject);
	if(ptr1)
		return display_defense(head[1]);
	witch * ptr2 = dynamic_cast<witch*>(myobject);
	if(ptr2)
		return display_defense(head[3]);
	werewolf * ptr3 = dynamic_cast<werewolf*>(myobject);
	if(ptr3)
		return display_defense(head[5]);
	devil * ptr4 = dynamic_cast<devil*>(myobject);
	if(ptr4)
		return display_defense(head[7]);
	else
		return 0;
}

//display defense (recursive)
int ARR::display_defense(snode * head)
{
	if(!head)
		return 0;
	head->get_data()->display();
	display_defense(head->get_next());
	return 1;
}

//retrieve attack (wrapper)
int ARR::retrieve_attack(monster * myobject, attack & myattack, int choice)
{
	vampire * ptr1 = dynamic_cast<vampire*>(myobject);
	if(ptr1)
		return retrieve_attack(head[0], myattack, choice);
	witch * ptr2 = dynamic_cast<witch*>(myobject);
	if(ptr2)
		return retrieve_attack(head[2], myattack, choice);
	werewolf * ptr3 = dynamic_cast<werewolf*>(myobject);
	if(ptr3)
		return retrieve_attack(head[4], myattack, choice);
	devil * ptr4 = dynamic_cast<devil*>(myobject);
	if(ptr4)
		return retrieve_attack(head[6], myattack, choice);
	else
		return 0;
}

//retrieve attack (recursive)
int ARR::retrieve_attack(snode * head, attack & myattack, int choice)
{
	if(!head)
		return 0;
	if(head->get_data()->is_match(choice))
	{
		attack * ptr = dynamic_cast<attack*>(head->get_data());
		//operator overloading (=)
		myattack = (*ptr);
		return 1;
	}
	return retrieve_attack(head->get_next(), myattack, choice);
}

//retrieve defense (wrapper)
int ARR::retrieve_defense(monster * myobject, defense & mydefense, int choice)
{
	vampire * ptr1 = dynamic_cast<vampire*>(myobject);
	if(ptr1)
		return retrieve_defense(head[1], mydefense, choice);
	witch * ptr2 = dynamic_cast<witch*>(myobject);
	if(ptr2)
		return retrieve_defense(head[3], mydefense, choice);
	werewolf * ptr3 = dynamic_cast<werewolf*>(myobject);
	if(ptr3)
		return retrieve_defense(head[5], mydefense, choice);
	devil * ptr4 = dynamic_cast<devil*>(myobject);
	if(ptr4)
		return retrieve_defense(head[7], mydefense, choice);
	else
		return 0;
}

//retrieve defense (recursive)
int ARR::retrieve_defense(snode * head, defense & mydefense, int choice)
{
	if(!head)
		return 0;
	if(head->get_data()->is_match(choice))
	{
		defense * ptr = dynamic_cast<defense*>(head->get_data());
		//operator overloading (=)
		mydefense = (*ptr);
		return 1;
	}
	return retrieve_defense(head->get_next(), mydefense, choice);
}

//retrieve opponent attack (wrapper)
int ARR::retrieve_opponent_attack(int monster, int opponent_attack, attack & opattack)
{
	if(monster == 1)
		return retrieve_opponent_attack(head[0], opponent_attack, opattack);
	if(monster == 2)
		return retrieve_opponent_attack(head[2], opponent_attack, opattack);
	if(monster == 3)
		return retrieve_opponent_attack(head[4], opponent_attack, opattack);
	if(monster == 4)
		return retrieve_opponent_attack(head[6], opponent_attack, opattack);
	else
		return 0;
}

//retrieve opponent attack (recursive)
int ARR::retrieve_opponent_attack(snode * head, int opponent_attack, attack & opattack)
{
	if(!head)
		return 0;
	if(head->get_data()->is_match(opponent_attack))
	{
		attack * ptr = dynamic_cast<attack*>(head->get_data());
		//operator overloading (=)
		opattack = (*ptr);
		return 1;
	}
	return retrieve_opponent_attack(head->get_next(), opponent_attack, opattack);
}

//retrieve opponent defense (wrapper)
int ARR::retrieve_opponent_defense(int monster, int opponent_defense, defense & opdefense)
{
	if(monster == 1)
		return retrieve_opponent_defense(head[1], opponent_defense, opdefense);
	if(monster == 2)
		return retrieve_opponent_defense(head[3], opponent_defense, opdefense);
	if(monster == 3)
		return retrieve_opponent_defense(head[5], opponent_defense, opdefense);
	if(monster == 4)
		return retrieve_opponent_defense(head[7], opponent_defense, opdefense);
	else
		return 0;
}

//retrieve opponent defense (recursive)
int ARR::retrieve_opponent_defense(snode * head, int opponent_defense, defense & opdefense)
{
	if(!head)
		return 0;
	if(head->get_data()->is_match(opponent_defense))
	{
		defense * ptr = dynamic_cast<defense*>(head->get_data());
		//operator overloading (=)
		opdefense = (*ptr);
		return 1;
	}
	return retrieve_opponent_defense(head->get_next(), opponent_defense, opdefense);
}

//remove attack (wrapper)
int ARR::remove_attack(monster * myobject, int choice)
{
	vampire * ptr1 = dynamic_cast<vampire*>(myobject);
	if(ptr1)
		return remove_attack(head[0], choice);
	witch * ptr2 = dynamic_cast<witch*>(myobject);
	if(ptr2)
		return remove_attack(head[2], choice);
	werewolf * ptr3 = dynamic_cast<werewolf*>(myobject);
	if(ptr3)
		return remove_attack(head[4], choice);
	devil * ptr4 = dynamic_cast<devil*>(myobject);
	if(ptr4)
		return remove_attack(head[6], choice);
	else
		return 0;
}

//remove attack (recursive)
int ARR::remove_attack(snode * & head, int choice)
{
	if(!head)
		return 0;
	if(head->get_data()->is_match(choice))
	{
		if(head->get_next() == NULL)
		{
			delete head->get_data();
			head->set_previous(NULL);
			delete head;
			head = NULL;
		}
		if(head->get_previous() == NULL)
		{
			snode * temp = head;
			head = head->get_next();
			head->set_previous(NULL);
			delete temp->get_data();
			temp->set_next(NULL);
			delete temp;
			temp = NULL;
		}
		else
		{
			snode * temp = head;
			head->get_next()->set_previous(head->get_previous());
			head = head->get_next();
			delete temp->get_data();
			temp->set_previous(NULL);
			temp->set_next(NULL);
			delete temp;
			temp = NULL;
		}
		return 1;
	}
	return remove_attack(head->get_next(), choice);
}

//remove defense (wrapper)
int ARR::remove_defense(monster * myobject, int choice)
{
	vampire * ptr1 = dynamic_cast<vampire*>(myobject);
	if(ptr1)
		return remove_defense(head[1], choice);
	witch * ptr2 = dynamic_cast<witch*>(myobject);
	if(ptr2)
		return remove_defense(head[3], choice);
	werewolf * ptr3 = dynamic_cast<werewolf*>(myobject);
	if(ptr3)
		return remove_defense(head[5], choice);
	devil * ptr4 = dynamic_cast<devil*>(myobject);
	if(ptr4)
		return remove_defense(head[7], choice);
	else
		return 0;
}

//remove defense (recursive)
int ARR::remove_defense(snode * & head, int choice)
{
	if(!head)
		return 0;
	if(head->get_data()->is_match(choice))
	{
		if(head->get_next() == NULL)
		{
			delete head->get_data();
			head->set_previous(NULL);
			delete head;
			head = NULL;
		}
		if(head->get_previous() == NULL)
		{
			snode * temp = head;
			head = head->get_next();
			head->set_previous(NULL);
			delete temp->get_data();
			temp->set_next(NULL);
			delete temp;
			temp = NULL;
		}
		else
		{
			snode * temp = head;
			head->get_next()->set_previous(head->get_previous());
			head = head->get_next();
			delete temp->get_data();
			temp->set_previous(NULL);
			temp->set_next(NULL);
			delete temp;
			temp = NULL;
		}
		return 1;
	}
	return remove_attack(head->get_next(), choice);
}

//remove all (wrapper)
int ARR::remove_all()
{
	if(!head)
		return 0;
	for(int i = 0; i < size; ++i)
	{
		remove_all(head[i]);
	}
	return 1;
}

//remove all (recursive)
int ARR::remove_all(snode * & head)
{
	if(!head)
		return 0;
	remove_all(head->get_next());
	delete head->get_data();
	head->set_previous(NULL);
	delete head;
	head = NULL;
	return 1;
}
