//Juhwan Lee
//Program 2
//This program will support three different ways to communicate in these
//unusual times. There will be a base class for general communication
//that is common among the three classes. This will be an abstract base class.

#include <iostream>
#include <cctype>
#include <cstring>

//base class
class communication
{
	public:
		communication();
		communication(const communication & source);
		virtual ~communication();
		virtual int program_type();
		void set_account();
		int compare_account(communication * source);
		virtual void display_account();
		void send_message_toall();
		void send_direct_message();
		virtual void display_message();
		int check_reciever(communication * source);
	protected:
		char * username;
		char * reciever;
		char * message;
};

//discord class
class discord :public communication
{
	public:
		discord();
		discord(const discord & source);
		int program_type();
		void set_account();
		void display_account();
		void display_message();
		int display_user();
	protected:
		char program[20];
};

//slack class
class slack :public communication
{
	public:
		slack();
		slack(const slack & source);
		int program_type();
		void set_account();
		void display_account();
		void display_message();
	protected:
		char program[20];
};

//zoom class
class zoom :public communication
{
	public:
		zoom();
		zoom(const zoom & source);
		int program_type();
		void set_account();
		void display_account();
		void display_message();
	protected:
		char program[20];
};
