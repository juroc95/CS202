#include "monster.h"

class node
{
	public:
		node();
		void set_data(monster * newdata);
		void set_left(node * newleft);
		void set_right(node * newright);
		monster*& get_data();
		node*& get_left();
		node*& get_right();
	protected:
		monster * data;
		node * left;
		node * right;
};
