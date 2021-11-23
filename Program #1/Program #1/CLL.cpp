//Juhwan Lee
//Program 1
//This program will support emergency relief efforts.
//We want to allow easy cataloging of donations dropped off or
//made available and then allow those in need to browse what is
//available.

#include "CLL.h"
using namespace std;

//default constructor for CLL
CLL::CLL()
	: housing_rear(NULL), food_rear(NULL), clothing_rear(NULL)
{
}

//destructor for CLL
CLL::~CLL()
{
	housing_destructor();
	food_destructor();
	clothing_destructor();
}

void CLL::housing_destructor()
{
	if(!housing_rear)
		return;
	return housing_destructor(housing_rear);
}

void CLL::housing_destructor(housing_node * & housing_rear)
{
	if(this->housing_rear == housing_rear->next)
	{
		delete housing_rear;
		housing_rear = NULL;
		return;
	}
	housing_destructor(housing_rear->next);
	if(!housing_rear->next)
	{
		delete housing_rear;
		housing_rear = NULL;
		return;
	}
}

void CLL::food_destructor()
{
	if(!food_rear)
		return;
	return food_destructor(food_rear);
}

void CLL::food_destructor(food_node * & food_rear)
{
	if(this->food_rear == food_rear->next)
	{
		delete food_rear;
		food_rear = NULL;
		return;
	}
	food_destructor(food_rear->next);
	if(!food_rear->next)
	{
		delete food_rear;
		food_rear = NULL;
		return;
	}
}

void CLL::clothing_destructor()
{
	if(!clothing_rear)
		return;
	return clothing_destructor(clothing_rear);
}

void CLL::clothing_destructor(clothing_node * & clothing_rear)
{
	if(this->clothing_rear == clothing_rear->next)
	{
		delete clothing_rear;
		clothing_rear = NULL;
		return;
	}
	clothing_destructor(clothing_rear->next);
	if(!clothing_rear->next)
	{
		delete clothing_rear;
		clothing_rear = NULL;
		return;
	}
}

//wrapper function for housing insertion
int CLL::insert_housing(const housing & new_data)
{
	if(!housing_rear)
	{
		housing_rear = new housing_node;
		housing_rear->data.copy(new_data);
		housing_rear->next = housing_rear;
		return 1;
	}
	return insert_housing(housing_rear, new_data);
}

//recursive function for housing insertion
int CLL::insert_housing(housing_node * & housing_rear, const housing & new_data)
{
	if(this->housing_rear == housing_rear->next)
	{
		housing_rear->next = new housing_node;
		housing_rear->next->data.copy(new_data);
		housing_rear->next->next = this->housing_rear;
		return 1;
	}
	return insert_housing(housing_rear->next, new_data);
}

//wrapper function for housing deletion
int CLL::remove_housing(char toremove[])
{
	//if list is empty
	if(!housing_rear)
		return 0;
	//if there is only one item
	if(housing_rear->next == housing_rear)
	{
		if(housing_rear->data.ismatch(toremove) == 1)
		{
			delete housing_rear;
			housing_rear = NULL;
			return 1;
		}
		else
			return 0;
	}
	return remove_housing(housing_rear, toremove);
}

//recursive function for housing deletion
int CLL::remove_housing(housing_node * & housing_rear, char toremove[])
{
	if(this->housing_rear == housing_rear->next)
	{
		if(housing_rear->data.ismatch(toremove) == 1)
		{
			housing_node * temp1 = housing_rear->next;
			housing_node * temp2 = housing_rear;
			while(temp2->next != housing_rear)
				temp2 = temp2->next;
			delete housing_rear;
			housing_rear = temp1;
			temp2->next = housing_rear;
			return 1;
		}
		else
			return 0;
	}
	if(housing_rear->data.ismatch(toremove) == 1)
	{
		housing_node * temp1 = housing_rear->next;
		housing_node * temp2 = housing_rear;
		while(temp2->next != housing_rear)
			temp2 = temp2->next;
		delete housing_rear;
		housing_rear = temp1;
		temp2->next = housing_rear;
		return 1;
	}
	return remove_housing(housing_rear->next, toremove);
}

//wrapper function for display housing
int CLL::display_housing()
{
	if(!housing_rear)
	{
		cout << "Housing list is empty" << endl;
		return 0;
	}
	return display_housing(housing_rear);
}

//recursive function for display housing
int CLL::display_housing(housing_node * housing_rear)
{
	if(this->housing_rear == housing_rear->next)
	{
		housing_rear->data.display();
		return 1;
	}
	housing_rear->data.display();
	return display_housing(housing_rear->next);
}

//wrapper function for housing search
int CLL::search_housing(char tosearch[])
{
	if(!housing_rear)
	{
		cout << "Housing list is empty" << endl;
		return 0;
	}
	return search_housing(housing_rear, tosearch);
}

//recursive function for housing search
int CLL::search_housing(housing_node * housing_rear, char tosearch[])
{
	if(this->housing_rear == housing_rear->next)
	{
		if(housing_rear->data.ismatch(tosearch) == 1)
		{
			housing_rear->data.display();
			return 1;
		}
		else
		{
			cout << "There is no match" << endl;
			return 0;
		}
	}
	if(housing_rear->data.ismatch(tosearch) == 1)
	{
		housing_rear->data.display();
		return 1;
	}
	return search_housing(housing_rear->next, tosearch);
}

//wrapper function for food insertion
int CLL::insert_food(const food & new_data)
{
	if(!food_rear)
	{
		food_rear = new food_node;
		food_rear->data.copy(new_data);
		food_rear->next = food_rear;
		return 1;
	}
	return insert_food(food_rear, new_data);
}

//recursive function for food insertion
int CLL::insert_food(food_node * & food_rear, const food & new_data)
{
	if(this->food_rear == food_rear->next)
	{
		food_rear->next = new food_node;
		food_rear->next->data.copy(new_data);
		food_rear->next->next = this->food_rear;
		return 1;
	}
	return insert_food(food_rear->next, new_data);
}

//wrapper function for food deletion
int CLL::remove_food(char toremove[])
{
	//if list is empty
	if(!food_rear)
		return 0;
	//if there is only one item
	if(food_rear->next == food_rear)
	{
		if(food_rear->data.ismatch(toremove) == 1)
		{
			delete food_rear;
			food_rear = NULL;
			return 1;
		}
		else
			return 0;
	}
	return remove_food(food_rear, toremove);
}

//recursive function for food deletion
int CLL::remove_food(food_node * & food_rear, char toremove[])
{
	if(this->food_rear == food_rear->next)
	{
		if(food_rear->data.ismatch(toremove) == 1)
		{
			food_node * temp1 = food_rear->next;
			food_node * temp2 = food_rear;
			while(temp2->next != food_rear)
				temp2 = temp2->next;
			delete food_rear;
			food_rear = temp1;
			temp2->next = food_rear;
			return 1;
		}
		else
			return 0;
	}
	if(food_rear->data.ismatch(toremove) == 1)
	{
		food_node * temp1 = food_rear->next;
		food_node * temp2 = food_rear;
		while(temp2->next != food_rear)
			temp2 = temp2->next;
		delete food_rear;
		food_rear = temp1;
		temp2->next = food_rear;
		return 1;
	}
	return remove_food(food_rear->next, toremove);
}

//wrapper function for food display
int CLL::display_food()
{
	if(!food_rear)
	{
		cout << "Food list is empty" << endl;
		return 0;
	}
	return display_food(food_rear);
}

//recursive function for food display
int CLL::display_food(food_node * food_rear)
{
	if(this->food_rear == food_rear->next)
	{
		food_rear->data.display();
		return 1;
	}
	food_rear->data.display();
	return display_food(food_rear->next);
}

//wrapper function for food search
int CLL::search_food(char tosearch[])
{
	if(!food_rear)
	{
		cout << "Food list is empty" << endl;
		return 0;
	}
	return search_food(food_rear, tosearch);
}

//recursive function for food search
int CLL::search_food(food_node * food_rear, char tosearch[])
{
	if(this->food_rear == food_rear->next)
	{
		if(food_rear->data.ismatch(tosearch) == 1)
		{
			food_rear->data.display();
			return 1;
		}
		else
		{
			cout << "There is no match" << endl;
			return 0;
		}
	}
	if(food_rear->data.ismatch(tosearch) == 1)
	{
		food_rear->data.display();
		return 1;
	}
	return search_food(food_rear->next, tosearch);
}

//wrapper function for clothing insertion
int CLL::insert_clothing(const clothing & new_data)
{
	if(!clothing_rear)
	{
		clothing_rear = new clothing_node;
		clothing_rear->data.copy(new_data);
		clothing_rear->next = clothing_rear;
		return 1;
	}
	return insert_clothing(clothing_rear, new_data);
}

//recursive function for clothing insertion
int CLL::insert_clothing(clothing_node * & clothing_rear, const clothing & new_data)
{
	if(this->clothing_rear == clothing_rear->next)
	{
		clothing_rear->next = new clothing_node;
		clothing_rear->next->data.copy(new_data);
		clothing_rear->next->next = this->clothing_rear;
		return 1;
	}
	return insert_clothing(clothing_rear->next, new_data);
}

//wrapper function for clothing deletion
int CLL::remove_clothing(char toremove[])
{
	//if list is empty
	if(!clothing_rear)
		return 0;
	//if there is only one item
	if(clothing_rear->next == clothing_rear)
	{
		if(clothing_rear->data.ismatch(toremove) == 1)
		{
			delete clothing_rear;
			clothing_rear = NULL;
			return 1;
		}
		else
			return 0;
	}
	return remove_clothing(clothing_rear, toremove);
}

//recursive function for clothing deletion
int CLL::remove_clothing(clothing_node * & clothing_rear, char toremove[])
{
	if(this->clothing_rear == clothing_rear->next)
	{
		if(clothing_rear->data.ismatch(toremove) == 1)
		{
			clothing_node * temp1 = clothing_rear->next;
			clothing_node * temp2 = clothing_rear;
			while(temp2->next != clothing_rear)
				temp2 = temp2->next;
			delete clothing_rear;
			clothing_rear = temp1;
			temp2->next = clothing_rear;
			return 1;
		}
		else
			return 0;
	}
	if(clothing_rear->data.ismatch(toremove) == 1)
	{
		clothing_node * temp1 = clothing_rear->next;
		clothing_node * temp2 = clothing_rear;
		while(temp2->next != clothing_rear)
			temp2 = temp2->next;
		delete clothing_rear;
		clothing_rear = temp1;
		temp2->next = clothing_rear;
		return 1;
	}
	return remove_clothing(clothing_rear->next, toremove);
}

//wrapper function for display clothing
int CLL::display_clothing()
{
	if(!clothing_rear)
	{
		cout << "Clothing list is empty" << endl;
		return 0;
	}
	return display_clothing(clothing_rear);
}

//recursive function for display clothing
int CLL::display_clothing(clothing_node * clothing_rear)
{
	if(this->clothing_rear == clothing_rear->next)
	{
		clothing_rear->data.display();
		return 1;
	}
	clothing_rear->data.display();
	return display_clothing(clothing_rear->next);
}

//wrapper function for serch clothing
int CLL::search_clothing(char tosearch[])
{
	if(!clothing_rear)
	{
		cout << "Clothing list is empty" << endl;
		return 0;
	}
	return search_clothing(clothing_rear, tosearch);
}

//recursive function for search clothing
int CLL::search_clothing(clothing_node * clothing_rear, char tosearch[])
{
	if(this->clothing_rear == clothing_rear->next)
	{
		if(clothing_rear->data.ismatch(tosearch) == 1)
		{
			clothing_rear->data.display();
			return 1;
		}
		else
		{
			cout << "There is no match" << endl;
			return 0;
		}
	}
	if(clothing_rear->data.ismatch(tosearch) == 1)
	{
		clothing_rear->data.display();
		return 1;
	}
	return search_clothing(clothing_rear->next, tosearch);
}

