//Juhwan Lee
//CS202
//Program 3
//This program is a monster battle program. The user has four monster options and can create
//monsters and confront opponents. Operator overloading and dynamic casting play a very
//important role in this program.

#include "BST.h"
using namespace std;

//default constructor for BST
BST::BST()
	: root(NULL)
{
}

//destructor for BST
BST::~BST()
{
	destructor(root);
}

//destructor for BST (recursive)
void BST::destructor(node * & root)
{
	if(!root)
		return;
	destructor(root->get_left());
	destructor(root->get_right());
	delete root->get_data();
	delete root;
	root = NULL;
	return;
}

//insertion (wrapper)
int BST::insert(monster * newdata)
{
	return insert(root, newdata);
}

//insertion (recursive)
int BST::insert(node * & root, monster * newdata)
{
	if(!root)
	{
		root = new node;
		root->set_data(newdata);
		root->set_left(NULL);
		root->set_right(NULL);
		return 1;
	}
	//operator overloading (<=)
	if((*newdata) <= (*root->get_data()))
		return insert(root->get_left(), newdata);
	else
		return insert(root->get_right(), newdata);
}

//display all (wrapper)
int BST::display_all()
{
	return display_all(root);
}

//display all (recursive)
int BST::display_all(node * root)
{
	if(!root)
		return 0;
	display_all(root->get_left());
	root->get_data()->display();
	display_all(root->get_right());
	return 1;
}

//remove (wrapper)
int BST::remove(char * toremove)
{
	return remove(root, toremove);
}

//remove (recursive)
int BST::remove(node * & root, char * toremove)
{
	if(!root)
		return 0;
	remove(root->get_left(), toremove);
	remove(root->get_right(), toremove);
	if(root->get_data()->search(toremove) == 1)
	{
		if(!root->get_left() && !root->get_right())
		{
			delete root->get_data();
			delete root;
			root = NULL;
			return 1;
		}
		if(root->get_left() && !root->get_right())
		{
			node * hold = root->get_left();
			delete root->get_data();
			delete root;
			root = hold;
			return 1;
		}
		if(!root->get_left() && root->get_right())
		{
			node * hold = root->get_right();
			delete root->get_data();
			delete root;
			root = hold;
			return 1;
		}
		if(root->get_left() && root->get_right())
		{
			node * current = root->get_right();
			node * previous = root;
			if(!current->get_left())
			{
				vampire * ptr1 = dynamic_cast<vampire*>(current->get_data());
				if(ptr1)
				{
					delete root->get_data();
					root->get_data() = new vampire(*ptr1);
				}
				witch * ptr2 = dynamic_cast<witch*>(current->get_data());
				if(ptr2)
				{
					delete root->get_data();
					root->get_data() = new witch(*ptr2);
				}
				werewolf * ptr3 = dynamic_cast<werewolf*>(current->get_data());
				if(ptr3)
				{
					delete root->get_data();
					root->get_data() = new werewolf(*ptr3);
				}
				devil * ptr4 = dynamic_cast<devil*>(current->get_data());
				if(ptr4)
				{
					delete root->get_data();
					root->get_data() = new devil(*ptr4);
				}
				root->set_right(current->get_right());
				delete current->get_data();
				delete current;
				return 1;
			}
			else
			{
				while(current->get_left())
				{
					previous = current;
					current = current->get_left();
				}
				vampire * ptr1 = dynamic_cast<vampire*>(current->get_data());
				if(ptr1)
				{
					delete root->get_data();
					root->get_data() = new vampire(*ptr1);
				}
				witch * ptr2 = dynamic_cast<witch*>(current->get_data());
				if(ptr2)
				{
					delete root->get_data();
					root->get_data() = new witch(*ptr2);
				}
				werewolf * ptr3 = dynamic_cast<werewolf*>(current->get_data());
				if(ptr3)
				{
					delete root->get_data();
					root->get_data() = new werewolf(*ptr3);
				}
				devil * ptr4 = dynamic_cast<devil*>(current->get_data());
				if(ptr4)
				{
					delete root->get_data();
					root->get_data() = new devil(*ptr4);
				}
				if(!current->get_right())
				{
					previous->set_left(NULL);
					delete current->get_data();
					delete current;
					return 1;
				}
				else
				{
					previous->set_left(current->get_right());
					delete current->get_data();
					delete current;
					return 1;
				}
			}
		}
	}
	return 0;
}

//retrieve (wrapper)
int BST::retrieve(monster * & myobject, char * search)
{
	return retrieve(root, myobject, search);
}

//retrieve (recursive)
int BST::retrieve(node * root, monster * & myobject, char * search)
{
	if(!root)
		return 0;
	if(root->get_data()->search(search) == 1)
	{
		vampire * ptr1 = dynamic_cast<vampire*>(root->get_data());
		if(ptr1)
		{
			if(myobject)
				delete myobject;
			myobject = new vampire(*ptr1);
		}
		witch * ptr2 = dynamic_cast<witch*>(root->get_data());
		if(ptr2)
		{
			if(myobject)
				delete myobject;
			myobject = new witch(*ptr2);
		}
		werewolf * ptr3 = dynamic_cast<werewolf*>(root->get_data());
		if(ptr3)
		{
			if(myobject)
				delete myobject;
			myobject = new werewolf(*ptr3);
		}
		devil * ptr4 = dynamic_cast<devil*>(root->get_data());
		if(ptr4)
		{
			if(myobject)
				delete myobject;
			myobject = new devil(*ptr4);
		}
		return 1;
	}
	if(root->get_data()->search(search) == 2)
		return retrieve(root->get_left(), myobject, search);
	else
		return retrieve(root->get_right(), myobject, search);
}

//remove all (wrapper)
int BST::remove_all()
{
	return remove_all(root);
}

//remove all (recursive)
int BST::remove_all(node * & root)
{
	if(!root)
		return 0;
	remove_all(root->get_left());
	remove_all(root->get_right());
	delete root->get_data();
	delete root;
	root = NULL;
	return 1;
}
