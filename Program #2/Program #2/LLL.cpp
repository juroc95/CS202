//Juhwan Lee
//Program 2
//This program will support three different ways to communicate in these
//unusual times. There will be a base class for general communication
//that is common among the three classes. This will be an abstract base class.

#include "LLL.h"
using namespace std;

//default constructor for node class
node::node()
	: data(NULL), next(NULL)
{
}

//setter
void node::set_data(communication * newdata)
{
	data = newdata;
}

//setter
void node::set_next(node * newnext)
{
	next = newnext;
}

//getter
communication*& node::get_data()
{
	return data;
}

//getter
node*& node::get_next()
{
	return next;
}

//default constructor for linear linked list
LLL::LLL()
	: head(NULL)
{
}

//destructor for linear linked list (wrapper)
LLL::~LLL()
{
	if(!head)
		return;
	destroy_LLL(head);
}

//destructor for linear linked list (recursive)
void LLL::destroy_LLL(node * & head)
{
	if(!head)
		return;
	destroy_LLL(head->get_next());
	delete head->get_data();
	delete head;
	head = NULL;
}

//insertion wrapper function
void LLL::insert(communication * newdata)
{
	return insert(head, newdata);
}

//insertion
void LLL::insert(node * & head, communication * newdata)
{
	if(!head)
	{
		head = new node;
		head->set_data(newdata);
		head->set_next(NULL);
		return;
	}
	//if there is a matching account, do not add to the account list
	if(head->get_data()->program_type() == newdata->program_type())
	{
		if(head->get_data()->compare_account(newdata) == 1)
			return;
	}
	return insert(head->get_next(), newdata);
}

//display wrapper function
void LLL::display()
{
	if(!head)
		cout << "Account list is empty" << endl;
	return display(head);
}

//display
void LLL::display(node * head)
{
	if(!head)
		return;
	head->get_data()->display_account();
	return display(head->get_next());
}

//unique discord function (wrapper)
int LLL::display_discord()
{
	if(!head)
		return 0;
	return display_discord(head);
}

//unique discord function
int LLL::display_discord(node * head)
{
	if(!head)
		return 0;
	//RTTI
	discord * ptr = dynamic_cast<discord *>(head->get_data());
	if(ptr)
		ptr->display_user();
	return display_discord(head->get_next());
}

//search wrapper function
int LLL::search(communication * newdata)
{
	if(!head)
		return 0;
	return search(head, newdata);
}

//search
int LLL::search(node * head, communication * newdata)
{
	if(!head)
		return 0;
	if(head->get_data()->program_type() == newdata->program_type())
	{
		if(head->get_data()->compare_account(newdata) == 1)
			return 1;
	}
	return search(head->get_next(), newdata);
}

//remove function (wrapper)
int LLL::remove(communication * current)
{
	if(!head)
		return 0;
	return remove(head, current);
}

//remove function (recursive)
int LLL::remove(node * & head, communication * current)
{
	if(!head)
		return 0;
	if(head->get_data()->program_type() == current->program_type())
	{
		if(head->get_data()->compare_account(current) == 1)
		{
			node * temp = head->get_next();
			delete head->get_data();
			delete head;
			head = temp;
			return 1;
		}
	}
	return remove(head->get_next(), current);
}

//remove all function (wrapper)
int LLL::remove_all()
{
	if(!head)
		return 0;
	return remove_all(head);
}

//remove all function (recursive)
int LLL::remove_all(node * & head)
{
	if(!head)
		return 0;
	remove_all(head->get_next());
	delete head->get_data();
	delete head;
	head = NULL;
	return 1;
}
