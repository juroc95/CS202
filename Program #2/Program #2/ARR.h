//Juhwan Lee
//Program 2
//This program will support three different ways to communicate in these
//unusual times. There will be a base class for general communication
//that is common among the three classes. This will be an abstract base class.

#include "LLL.h"

//array of linear linked list class (message list)
class ARR
{
	public:
		ARR();
		~ARR();
		void destroy_ARR(node * & head);
		int insert(communication * newdata, int message_type);
		int insert(node * & head, communication * newdata);
		int display_main(communication * current);
		int display_main(node * head);
		int display_direct(communication * current);
		int display_direct(node * head, communication * current);
		int search(communication * tosearch);			//not used in the program
		int search(node * head, communication * tosearch);	//not used in the program
		int remove(communication * toremove);			//not used in the program
		int remove(node * & head, communication * toremove);	//not used in the program
		int remove_all();					//not used in the program
		int remove_all(node * & head);				//not used in the program
	protected:
		node ** head;
		int size;
};
