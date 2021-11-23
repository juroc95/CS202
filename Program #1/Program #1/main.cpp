//Juhwan Lee
//Program 1
//This program will support emergency relief efforts.
//We want to allow easy cataloging of donations dropped off or
//made available and then allow those in need to browse what is
//available.

#include "CLL.h"
#include "LLL.h"
using namespace std;

int main()
{
	housing housing_object;
	food food_object;
	clothing clothing_object;

	CLL effort_list;
	LLL browsing_history;
	
	int menu = 0;
	char response = 'y';

	while(menu != 3)
	{
		cout << "What type of user are you?" << endl;
		cout << "1. Relief item provider" << endl;
		cout << "2. People who need help" << endl;
		cout << "3. Quit" << endl;
	
		cin >> menu;
		cin.ignore(100, '\n');
	
		//provider menu
		if(menu == 1)
		{
			cout << "What do you want to perform?" << endl;
			cout << "1. Provide item" << endl;
			cout << "2. Display browsing history" << endl;

			cin >> menu;
			cin.ignore(100, '\n');

			//insert item
			while(menu == 1 && tolower(response) == 'y')
			{
				cout << "What are you providing?" << endl;
				cout << "1. Housing" << endl;
				cout << "2. Food" << endl;
				cout << "3. Clothing" << endl;

				cin >> menu;
				cin.ignore(100, '\n');

				if(menu == 1)
				{
					housing_object.set_housing();
					effort_list.insert_housing(housing_object);
				}

				if(menu == 2)
				{
					food_object.set_food();
					effort_list.insert_food(food_object);
				}
			
				if(menu == 3)
				{
					clothing_object.set_clothing();
					effort_list.insert_clothing(clothing_object);
				}

				menu = 1;
				cout << "Again? (Y/N) :";
				cin >> response;
				cin.ignore(100, '\n');
			}

			response = 'y';

			//display browsing history
			if(menu == 2)
			{
				while(browsing_history.is_sorted() == 0)
					browsing_history.sort_list();
				browsing_history.display();
				menu = 1;
			}
		}
	
		//people who need help menu
		if(menu == 2)
		{
			cout << "What do you want to perform?" << endl;
			cout << "1. Search" << endl;
			cout << "2. Get help" << endl;
	
			cin >> menu;
			cin.ignore(100, '\n');
	
			//search
			while(menu == 1 && tolower(response) == 'y')
			{
				cout << "What do you want to search?" << endl;
				cout << "1. Housing" << endl;
				cout << "2. Food" << endl;
				cout << "3. Clothing" << endl;

				cin >> menu;
				cin.ignore(100, '\n');

				if(menu == 1)
				{
					char tosearch[100];
					cout << "Please enter its name: ";
					cin.get(tosearch, 100, '\n');
					cin.ignore(100, '\n');
					browsing_history.insert(tosearch);
					effort_list.search_housing(tosearch);
				}

				if(menu == 2)
				{
					char tosearch[100];
					cout << "Please enter its name: ";
					cin.get(tosearch, 100, '\n');
					cin.ignore(100, '\n');
					browsing_history.insert(tosearch);
					effort_list.search_food(tosearch);
				}

				if(menu == 3)
				{
					char tosearch[100];
					cout << "Please enter its name: ";
					cin.get(tosearch, 100, '\n');
					cin.ignore(100, '\n');
					browsing_history.insert(tosearch);
					effort_list.search_clothing(tosearch);
				}

				menu = 1;
				cout << "Again? (Y/N) : ";
				cin >> response;
				cin.ignore(100, '\n');
			}
	
			//get help
			while(menu == 2 && tolower(response) == 'y')
			{
				cout << "What do you need?" << endl;
				cout << "1. Housing" << endl;
				cout << "2. Food" << endl;
				cout << "3. Clothing" << endl;
	
				cin >> menu;
				cin.ignore(100, '\n');
	
				//housing
				if(menu == 1)
				{
					char toremove[100];
					effort_list.display_housing();
					cout << "Please enter what you need : ";
					cin.get(toremove, 100, '\n');
					cin.ignore(100, '\n');
					if(effort_list.remove_housing(toremove))
						cout << "Success" << endl;
					else
						cout << "There is no match" << endl;
				}
	
				//food
				if(menu == 2)
				{
					char toremove[100];
					effort_list.display_food();
					cout << "Please enter what you need : ";
					cin.get(toremove, 100, '\n');
					cin.ignore(100, '\n');
					if(effort_list.remove_food(toremove))
						cout << "Success" << endl;
					else
						cout << "There is no match" << endl;
				}
	
				//clothing
				if(menu == 3)
				{
					char toremove[100];
					effort_list.display_clothing();
					cout << "Please enter what you need : ";
					cin.get(toremove, 100, '\n');
					cin.ignore(100, '\n');
					if(effort_list.remove_clothing(toremove))
						cout << "Success" << endl;
					else
						cout << "There is no match" << endl;
				}
	
				menu = 2;
				cout << "Again? (Y/N) : ";
				cin >> response;
				cin.ignore(100, '\n');
			}
			
			response = 'y';
			
		}		
	}

	return 0;
}
