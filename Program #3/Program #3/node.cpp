//Juhwan Lee
//CS202
//Program 3
//This program is a monster battle program. The user has four monster options and can create
//monsters and confront opponents. Operator overloading and dynamic casting play a very
//important role in this program.

#include "node.h"
using namespace std;

//default constructor for node
node::node()
	: data(NULL), left(NULL), right(NULL)
{
}

//set data
void node::set_data(monster * newdata)
{
	data = newdata;
}

//set left
void node::set_left(node * newleft)
{
	left = newleft;
}

//set right
void node::set_right(node * newright)
{
	right = newright;
}

//get data
monster*& node::get_data()
{
	return data;
}

//get left
node*& node::get_left()
{
	return left;
}

//get right
node*& node::get_right()
{
	return right;
}
