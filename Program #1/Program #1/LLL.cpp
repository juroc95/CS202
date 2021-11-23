//Juhwan Lee
//Program 1
//This program will support emergency relief efforts.
//We want to allow easy cataloging of donations dropped off or
//made available and then allow those in need to browse what is
//available.

#include "LLL.h"
using namespace std;

//default constructor for search node
search_node::search_node()
	: data(NULL), frequency(1), next(NULL)
{
}

//default constructor for LLL
LLL::LLL()
	: head(NULL)
{
}

//destructor for LLL
LLL::~LLL()
{
	if(!head)
		return;
	destructor(head);
}

void LLL::destructor(search_node * & head)
{
	if(!head->next)
	{
		delete [] head->data;
		delete head;
		head = NULL;
		return;
	}
	destructor(head->next);
	if(!head->next)
	{
		delete [] head->data;
		delete head;
		head = NULL;
		return;
	}
}

//wrapper function for insertion
int LLL::insert(char toinsert[])
{
	return insert(head, toinsert);
}

//recursive function for insertion
int LLL::insert(search_node * & head, char toinsert[])
{
	if(!head)
	{
		head = new search_node;
		head->data = new char [strlen(toinsert) + 1];
		strcpy(head->data, toinsert);
		head->frequency = 1;
		head->next = NULL;
		return 1;
	}
	if(strcmp(head->data, toinsert) == 0)
	{
		head->frequency = head->frequency + 1;
		return 1;
	}
	return insert(head->next, toinsert);
}

//wrapper function for display
int LLL::display()
{
	if(!head)
	{
		cout << "The list is empty" << endl;
		return 1;
	}
	return display(head);
}

//recursive function for display
int LLL::display(search_node * head)
{
	if(!head)
	{
		return 1;
	}
	cout << "Name : " << head->data << endl;
	cout << "Search frequency : " << head->frequency << endl;
	return display(head->next);
}

//wrapper function for sorting list
int LLL::sort_list()
{
	if(!head)
		return 1;
	return sort_list(head);
}

//recursive function for sorting list
int LLL::sort_list(search_node * & head)
{
	if(!head->next)
		return 1;
	if(head->frequency < head->next->frequency)
	{
		char * temp1 = NULL;
		int temp2 = 0;
		temp1 = head->data;
		head->data = head->next->data;
		head->next->data = temp1;
		temp2 = head->frequency;
		head->frequency = head->next->frequency;
		head->next->frequency = temp2;
	}
	return sort_list(head->next);
}

//wrapper function for sorting checking
int LLL::is_sorted()
{
	if(!head)
		return 1;
	return is_sorted(head);
}

//recursive function for sorting checking
int LLL::is_sorted(search_node * head)
{
	if(!head->next)
		return 1;
	if(head->frequency < head->next->frequency)
		return 0;
	return is_sorted(head->next);
}
