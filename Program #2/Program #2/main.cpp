//Juhwan Lee
//Program 2
//This program will support three different ways to communicate in these
//unusual times. There will be a base class for general communication
//that is common among the three classes. This will be an abstract base class.

#include "ARR.h"
using namespace std;

int main()
{
	discord discord_account;
	slack slack_account;
	zoom zoom_account;

	LLL account_list;
	ARR message_list;

	int menu = '0';

	while(menu != 50)
	{
		cout << "1. Start Discord" << endl;
		cout << "2. Start Slack" << endl;
		cout << "3. Start Zoom" << endl;
		cout << "4. Display account list" << endl;
		cout << "5. Quit" << endl;
	
		cin >> menu;
		cin.ignore(100, '\n');

		if(menu == 5)
			menu = 50;

		//Discord session starts
		while(menu == 1)
		{
			cout << "1. Create account" << endl;
			cout << "2. Log in" << endl;
			cout << "3. Quit" << endl;
			cin >> menu;
			cin.ignore(100, '\n');
			if(menu == 3)
				menu = 99;
			if(menu == 1)
			{
				discord_account.set_account();
				discord * ptr = new discord(discord_account);
				account_list.insert(ptr);
				cout << "Account created" << endl;
				menu = 0;//log in success
			}
			if(menu == 2)
			{
				discord_account.set_account();
				discord * ptr = new discord(discord_account);
				if(account_list.search(ptr) == 1)
					menu = 0;//log in success
				else
				{	
					cout << "The account does not exist" << endl;
					menu = 1;
				}
			}
			//after log in discord
			while(menu == 0)
			{
				cout << "1. Send a message to main channel" << endl;
				cout << "2. Send a direct message" << endl;
				cout << "3. Display main channel" << endl;
				cout << "4. Display direct message" << endl;
				cout << "5. Display all users" << endl;
				cout << "6. Quit" << endl;
				cin >> menu;
				cin.ignore(100, '\n');
				if(menu == 6)
					menu = 99;
				if(menu == 1)
				{
					discord_account.send_message_toall();
					discord * ptr = new discord(discord_account);
					message_list.insert(ptr, 1);
					menu = 0;
				}
				if(menu == 2)
				{
					discord_account.send_direct_message();
					discord * ptr = new discord(discord_account);
					message_list.insert(ptr, 2);
					menu = 0;
				}
				if(menu == 3)
				{
					discord * ptr = &discord_account;
					message_list.display_main(ptr);
					menu = 0;
				}
				if(menu == 4)
				{
					discord * ptr = &discord_account;
					if(message_list.display_direct(ptr) == 0)
						cout << "There is no message to display" << endl;
					menu = 0;
				}
				if(menu == 5)
				{
					account_list.display_discord();
					menu = 0;
				}
			}
		}
		//Discord session ends
					
		//Slack session starts
		while(menu == 2)
		{
			cout << "1. Create account" << endl;
			cout << "2. Log in" << endl;
			cout << "3. Quit" << endl;
			cin >> menu;
			cin.ignore(100, '\n');
			if(menu == 3)
				menu = 99;
			if(menu == 1)
			{
				slack_account.set_account();
				slack * ptr = new slack(slack_account);
				account_list.insert(ptr);
				cout << "Account created" << endl;
				menu = 0;//log in success
			}
			if(menu == 2)
			{
				slack_account.set_account();
				slack * ptr = new slack(slack_account);
				if(account_list.search(ptr) == 1)
					menu = 0;//log in success
				else
				{	
					cout << "The account does not exist" << endl;
					menu = 2;
				}
			}
			//after log in slack
			while(menu == 0)
			{
				cout << "1. Send a message to main channel" << endl;
				cout << "2. Send a direct message" << endl;
				cout << "3. Display main channel" << endl;
				cout << "4. Display direct message" << endl;
				cout << "5. Quit" << endl;
				cin >> menu;
				cin.ignore(100, '\n');
				if(menu == 5)
					menu = 99;
				if(menu == 1)
				{
					slack_account.send_message_toall();
					slack * ptr = new slack(slack_account);
					message_list.insert(ptr, 1);
					menu = 0;
				}
				if(menu == 2)
				{
					slack_account.send_direct_message();
					slack * ptr = new slack(slack_account);
					message_list.insert(ptr, 2);
					menu = 0;
				}
				if(menu == 3)
				{
					slack * ptr = &slack_account;
					message_list.display_main(ptr);
					menu = 0;
				}
				if(menu == 4)
				{
					slack * ptr = &slack_account;
					if(message_list.display_direct(ptr) == 0)
						cout << "There is no message to display" << endl;
					menu = 0;
				}
			}
		}
		//Slack session ends
	
		//Zoom session starts
		while(menu == 3)
		{
			cout << "1. Create account" << endl;
			cout << "2. Log in" << endl;
			cout << "3. Quit" << endl;
			cin >> menu;
			cin.ignore(100, '\n');
			if(menu == 3)
				menu = 99;
			if(menu == 1)
			{
				zoom_account.set_account();
				zoom * ptr = new zoom(zoom_account);
				account_list.insert(ptr);
				cout << "Account created" << endl;
				menu = 0;//log in success
			}
			if(menu == 2)
			{
				zoom_account.set_account();
				zoom * ptr = new zoom(zoom_account);
				if(account_list.search(ptr) == 1)
					menu = 0;//log in success
				else
				{	
					cout << "The account does not exist" << endl;
					menu = 3;
				}
			}
			//after log in zoom
			while(menu == 0)
			{
				cout << "1. Send a message to main channel" << endl;
				cout << "2. Send a direct message" << endl;
				cout << "3. Display main channel" << endl;
				cout << "4. Display direct message" << endl;
				cout << "5. Quit" << endl;
				cin >> menu;
				cin.ignore(100, '\n');
				if(menu == 5)
					menu = 99;
				if(menu == 1)
				{
					zoom_account.send_message_toall();
					zoom * ptr = new zoom(zoom_account);
					message_list.insert(ptr, 1);
					menu = 0;
				}
				if(menu == 2)
				{
					zoom_account.send_direct_message();
					zoom * ptr = new zoom(zoom_account);
					message_list.insert(ptr, 2);
					menu = 0;
				}
				if(menu == 3)
				{
					zoom * ptr = &zoom_account;
					message_list.display_main(ptr);
					menu = 0;
				}
				if(menu == 4)
				{
					zoom * ptr = &zoom_account;
					if(message_list.display_direct(ptr) == 0)
						cout << "There is no message to display" << endl;
					menu = 0;
				}
			}
		}
		//Zoom session ends

		//Display account list
		if(menu == 4)
			account_list.display();
		
	}

	return 0;
}
