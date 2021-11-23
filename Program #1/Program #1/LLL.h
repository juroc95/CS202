//Juhwan Lee
//Program 1
//This program will support emergency relief efforts.
//We want to allow easy cataloging of donations dropped off or
//made available and then allow those in need to browse what is
//available.

#include <iostream>
#include <cctype>
#include <cstring>

class search_node
{
	public:
		search_node();
		char * data;
		int frequency;
		search_node * next;
};

class LLL
{
	public:
		LLL();
		~LLL();
		void destructor(search_node * & head);
		int insert(char toinsert[]);
		int insert(search_node * & head, char toinsert[]);
		int display();
		int display(search_node * head);
		int sort_list();
		int sort_list(search_node * & head);
		int is_sorted();
		int is_sorted(search_node * head);
	protected:
		search_node * head;
};
