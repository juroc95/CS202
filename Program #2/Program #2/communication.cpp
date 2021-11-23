//Juhwan Lee
//Program 2
//This program will support three different ways to communicate in these
//unusual times. There will be a base class for general communication
//that is common among the three classes. This will be an abstract base class.

#include "communication.h"
using namespace std;

//default constructor for base class
communication::communication()
	: username(NULL), reciever(NULL), message(NULL)
{
}

//copy constructor for base class
communication::communication(const communication & source)
{
	if(source.username)
	{
		username = new char [strlen(source.username) + 1];
		strcpy(username, source.username);
	}
	else
		username = NULL;
	if(source.reciever)
	{
		reciever = new char [strlen(source.reciever) + 1];
		strcpy(reciever, source.reciever);
	}
	else
		reciever = NULL;
	if(source.message)
	{
		message = new char [strlen(source.message) + 1];
		strcpy(message, source.message);
	}
	else
		message = NULL;
}

//destructor for base class
communication::~communication()
{
	delete [] username;
	delete [] reciever;
	delete [] message;
	username = NULL;
	reciever = NULL;
	message = NULL;
}

//virtual function for program type
int communication::program_type()
{
	return 0;
}

//set username
void communication::set_account()
{
	char temp[100];
	cout << "Please enter user name: ";
	cin.get(temp, 100, '\n');
	cin.ignore(100, '\n');
	if(!username)
	{	
		username = new char [strlen(temp) + 1];
		strcpy(username, temp);
	}
	else
	{
		delete [] username;
		username = new char [strlen(temp) + 1];
		strcpy(username, temp);
	}
}

//function for log in process
int communication::compare_account(communication * source)
{
	if(strcmp(username, source->username) == 0)
		return 1;
	else
		return 0;
}

//display account function
void communication::display_account()
{
	if(username)
		cout << "User name: " << username << endl;
	else
		cout << "User name could not be displayed." << endl;
}

//set message and set reciever to everyone
void communication::send_message_toall()
{
	char temp1[100] = "Everyone";
	char temp2[100];
	cout << "Please type message: ";
	cin.get(temp2, 100, '\n');
	cin.ignore(100, '\n');
	if(!message)
	{	
		message = new char [strlen(temp2) + 1];
		strcpy(message, temp2);
	}
	else
	{
		delete [] message;
		message = new char [strlen(temp2) + 1];
		strcpy(message, temp2);
	}
	if(!reciever)
	{
		reciever = new char [strlen(temp1) + 1];
		strcpy(reciever, temp1);
	}
	else
	{
		delete [] reciever;
		reciever = new char [strlen(temp1) + 1];
		strcpy(reciever, temp1);
	}
	cout << "Message sent" << endl;
}

//set message and reciever
void communication::send_direct_message()
{
	char temp1[100];
	char temp2[100];
	cout << "Please type reciever: ";
	cin.get(temp1, 100, '\n');
	cin.ignore(100, '\n');
	cout << "Please type message: ";
	cin.get(temp2, 100, '\n');
	cin.ignore(100, '\n');
	if(!reciever)
	{
		reciever = new char [strlen(temp1) + 1];
		strcpy(reciever, temp1);
	}
	else
	{
		delete [] reciever;
		reciever = new char [strlen(temp1) + 1];
		strcpy(reciever, temp1);
	}
	if(!message)
	{
		message = new char [strlen(temp2) + 1];
		strcpy(message, temp2);
	}
	else
	{
		delete [] message;
		message = new char [strlen(temp2) + 1];
		strcpy(message, temp2);
	}
	cout << "Message sent" << endl;
}

//display message function
void communication::display_message()
{
	cout << "********************" << endl;
	if(username)
		cout << "From: " << username << endl;
	if(reciever)
		cout << "Reciever: " << reciever << endl;
	if(message)
		cout << "Message: " << message << endl;
	cout << "********************" << endl;
}

//compare function for display direct message function
int communication::check_reciever(communication * source)
{
	if(strcmp(reciever, source->username) == 0)
		return 1;
	else
		return 0;
}

//********** discord **********

//default constructor for discord class
discord::discord()
	: program("Discord")
{
}

//copy constructor for discord class
discord::discord(const discord & source)
	: communication(source), program("Discord")
{
}

//program type function for ARR insertion
int discord::program_type()
{
	return 1;
}

//set username
void discord::set_account()
{
	communication::set_account();
}

//display account function
void discord::display_account()
{
	cout << "********************" << endl;
	cout << "Program: " << program << endl;
	communication::display_account();
	cout << "********************" << endl;
}

//display message function
void discord::display_message()
{
	communication::display_message();
}

//unique discord function (RTTI in LLL)
int discord::display_user()
{
	if(username)
	{
		cout << "********************" << endl;
		cout << "User name: " << username << endl;
		cout << "********************" << endl;
	}
	return 1;
}

//********** slack **********

//default constructor for slack class
slack::slack()
	: program("Slack")
{
}

//copy constructor for slack class
slack::slack(const slack & source)
	: communication(source), program("Slack")
{
}

//program type function for ARR insertion
int slack::program_type()
{
	return 2;
}

//set username
void slack::set_account()
{
	communication::set_account();
}

//display account function
void slack::display_account()
{
	cout << "********************" << endl;
	cout << "Program: " << program << endl;
	communication::display_account();
	cout << "********************" << endl;
}

//display message function
void slack::display_message()
{
	communication::display_message();
}

//********** zoom **********

//default constructor for zoom class
zoom::zoom()
	: program("Zoom")
{
}

//copy constructor for zoom class
zoom::zoom(const zoom & source)
	: communication(source), program("Zoom")
{
}

//program type function for ARR insertion
int zoom::program_type()
{
	return 3;
}

//set username
void zoom::set_account()
{
	communication::set_account();
}

//display account function
void zoom::display_account()
{
	cout << "********************" << endl;
	cout << "Program: " << program << endl;
	communication::display_account();
	cout << "********************" << endl;
}

//display message function
void zoom::display_message()
{
	communication::display_message();
}
