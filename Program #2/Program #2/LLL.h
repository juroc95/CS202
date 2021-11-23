//Juhwan Lee
//Program 2
//This program will support three different ways to communicate in these
//unusual times. There will be a base class for general communication
//that is common among the three classes. This will be an abstract base class.

#include "communication.h"

//node class
class node
{
	public:
		node();
		void set_data(communication * newdata);
		void set_next(node * newnext);
		communication*& get_data();
		node*& get_next();
	protected:
		communication * data;
		node * next;
};

//linear linked list class (account list)
class LLL
{
	public:
		LLL();
		~LLL();
		void destroy_LLL(node * & head);
		void insert(communication * newdata);
		void insert(node * & head, communication * newdata);
		void display();
		void display(node * head);
		int display_discord();			//unique discord function for RTTI
		int display_discord(node * head);	//unique discord function for RTTI
		int search(communication * newdata);
		int search(node * head, communication * newdata);
		int remove(communication * current);			//not used in the program
		int remove(node * & head, communication * current);	//not used in the program
		int remove_all();					//not used in the program
		int remove_all(node * & head);				//not used in the program
	protected:
		node * head;
};

