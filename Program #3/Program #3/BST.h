//Juhwan Lee
//CS202
//Program 3
//This program is a monster battle program. The user has four monster options and can create
//monsters and confront opponents. Operator overloading and dynamic casting play a very
//important role in this program.

#include "node.h"

class BST
{
	public:
		BST();
		~BST();
		void destructor(node * & root);
		int insert(monster * newdata);
		int insert(node * & root, monster * newdata);
		int display_all();
		int display_all(node * root);
		int retrieve(monster * & myobject, char * search);
		int retrieve(node * root, monster * & myobject, char * search);
		int remove(char * toremove);
		int remove(node * & root, char * toremove);
		int remove_all();
		int remove_all(node * & root);
	protected:
		node * root;
};
