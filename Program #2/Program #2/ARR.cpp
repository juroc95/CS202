//Juhwan Lee
//Program 2
//This program will support three different ways to communicate in these
//unusual times. There will be a base class for general communication
//that is common among the three classes. This will be an abstract base class.

#include "ARR.h"
using namespace std;

//default constructor for array of linear linked list class
ARR::ARR()
{
	size = 6;
	head = new node* [size];
	for(int i = 0; i < size; ++i)
	{
		head[i] = NULL;
	}
}

//destructor for array of linear linked list (wrapper)
ARR::~ARR()
{
	if(!head)
		return;
	for(int i = 0; i < size; ++i)
	{
		destroy_ARR(head[i]);
	}
}

//destructor for array of linear linked list (recursive)
void ARR::destroy_ARR(node * & head)
{
	if(!head)
		return;
	destroy_ARR(head->get_next());
	delete head->get_data();
	delete head;
	head = NULL;
}

//insertion wrapper function
int ARR::insert(communication * newdata, int message_type)
{
	if(newdata->program_type() == 1 && message_type == 1)
		return insert(head[0], newdata);
	if(newdata->program_type() == 1 && message_type == 2)
		return insert(head[1], newdata);
	if(newdata->program_type() == 2 && message_type == 1)
		return insert(head[2], newdata);
	if(newdata->program_type() == 2 && message_type == 2)
		return insert(head[3], newdata);
	if(newdata->program_type() == 3 && message_type == 1)
		return insert(head[4], newdata);
	else
		return insert(head[5], newdata);
}

//insertion
int ARR::insert(node * & head, communication * newdata)
{
	if(!head)
	{
		head = new node;
		head->set_data(newdata);
		head->set_next(NULL);
		return 1;
	}
	return insert(head->get_next(), newdata);
}

//display main channel (wrapper)
int ARR::display_main(communication * current)
{
	if(current->program_type() == 1)
		return display_main(head[0]);
	if(current->program_type() == 2)
		return display_main(head[2]);
	else
		return display_main(head[4]);
}

//display main channel
int ARR::display_main(node * head)
{
	if(!head)
		return 0;
	head->get_data()->display_message();
	return display_main(head->get_next());
}

//display direct message (wrapper)
int ARR::display_direct(communication * current)
{
	if(current->program_type() == 1)
		return display_direct(head[1], current);
	if(current->program_type() == 2)
		return display_direct(head[3], current);
	else
		return display_direct(head[5], current);
}

//display direct message
int ARR::display_direct(node * head, communication * current)
{
	if(!head)
		return 0;
	if(head->get_data()->check_reciever(current) == 1)
	{
		head->get_data()->display_message();
		return 1 + display_direct(head->get_next(), current);
	}
	else
		return display_direct(head->get_next(), current);
}

//search (wrapper)
int ARR::search(communication * tosearch)
{
	if(tosearch->program_type() == 1)
		return search(head[1], tosearch);
	if(tosearch->program_type() == 2)
		return search(head[3], tosearch);
	else
		return search(head[5], tosearch);
}	

//search (recursive)
int ARR::search(node * head, communication * tosearch)
{
	if(!head)
		return 0;
	if(head->get_data()->check_reciever(tosearch) == 1)
		return 1;
	return search(head->get_next(), tosearch);
}

//remove (wrapper)
int ARR::remove(communication * toremove)
{
	if(toremove->program_type() == 1)
		return remove(head[1], toremove);
	if(toremove->program_type() == 2)
		return remove(head[3], toremove);
	else
		return remove(head[5], toremove);
}

//remove (recursive)
int ARR::remove(node * & head, communication * toremove)
{
	if(!head)
		return 0;
	if(head->get_data()->check_reciever(toremove) == 1)
	{
		node * temp = head->get_next();
		delete head->get_data();
		delete head;
		head = temp;
		return 1;
	}
	return remove(head->get_next(), toremove);
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
int ARR::remove_all(node * & head)
{
	if(!head)
		return 0;
	remove_all(head->get_next());
	delete head->get_data();
	delete head;
	head = NULL;
	return 1;
}
