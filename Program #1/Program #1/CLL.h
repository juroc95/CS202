//Juhwan Lee
//Program 1
//This program will support emergency relief efforts.
//We want to allow easy cataloging of donations dropped off or
//made available and then allow those in need to browse what is
//available.

#include "effort.h"

class housing_node
{
	public:
		housing data;
		housing_node * next;
};

class food_node
{
	public:
		food data;
		food_node * next;
};

class clothing_node
{
	public:
		clothing data;
		clothing_node * next;
};

class CLL
{
	public:
		CLL();
		~CLL();

		void housing_destructor();
		void housing_destructor(housing_node * & housing_rear);
		void food_destructor();
		void food_destructor(food_node * & food_rear);
		void clothing_destructor();
		void clothing_destructor(clothing_node * & clothing_rear);

		int insert_housing(const housing & new_data);
		int insert_housing(housing_node * & housing_rear, const housing & new_data);
		int remove_housing(char toremove[]);
		int remove_housing(housing_node * & housing_rear, char toremove[]);
		int display_housing();
		int display_housing(housing_node * housing_rear);
		int search_housing(char tosearch[]);
		int search_housing(housing_node * housing_rear, char tosearch[]);
		
		int insert_food(const food & new_data);
		int insert_food(food_node * & food_rear, const food & new_data);
		int remove_food(char toremove[]);
		int remove_food(food_node * & food_rear, char toremove[]);
		int display_food();
		int display_food(food_node * food_rear);
		int search_food(char tosearch[]);
		int search_food(food_node * food_rear, char tosearch[]);

		int insert_clothing(const clothing & new_data);
		int insert_clothing(clothing_node * & clothing_rear, const clothing & new_data);
		int remove_clothing(char toremove[]);
		int remove_clothing(clothing_node * & clothing_rear, char toremove[]);
		int display_clothing();
		int display_clothing(clothing_node * clothing_rear);
		int search_clothing(char tosearch[]);
		int search_clothing(clothing_node * clothing_rear, char tosearch[]);
	protected:
		housing_node * housing_rear;
		food_node * food_rear;
		clothing_node * clothing_rear;
};
