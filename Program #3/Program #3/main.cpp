//Juhwan Lee
//CS202
//Program 3
//This program is a monster battle program. The user has four monster options and can create
//monsters and confront opponents. Operator overloading and dynamic casting play a very
//important role in this program.

#include "ARR.h"
#include <cstdlib>
using namespace std;

int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (RAND_MAX + 1.0);
	return min + static_cast<int>((max - min + 1) * (rand() * fraction));
}

int main()
{
	char search[100];
	int menu = 0;
	int choice = 0;

	attack attack_object;
	attack myattack;
	attack opattack;
	defense defense_object;
	defense mydefense;
	defense opdefense;
	skill * sptr;

	vampire object1;
	witch object2;
	werewolf object3;
	devil object4;
	monster * mptr;
	monster * myobject = new monster;

	ARR skill_list;
	BST monster_list;

	/************* setting array of DLL with initial values ***************/
	char monster1[20] = "Vampire";
	char monster2[20] = "Witch";
	char monster3[20] = "Werewolf";
	char monster4[20] = "Devil";

	char vattack1[20] = "Vampire Attack 1";
	char vattack2[20] = "Vampire Attack 2";
	char vattack3[20] = "Vampire Attack 3";

	char wattack1[20] = "Witch Attack 1";
	char wattack2[20] = "Witch Attack 2";
	char wattack3[20] = "Witch Attack 3";

	char weattack1[20] = "Werewolf Attack 1";
	char weattack2[20] = "Werewolf Attack 2";
	char weattack3[20] = "Werewolf Attack 3";

	char dattack1[20] = "Devil Attack 1";
	char dattack2[20] = "Devil Attack 2";
	char dattack3[20] = "Devil Attack 3";

	char vdefense1[20] = "Vampire Defense 1";
	char vdefense2[20] = "Vampire Defense 2";
	char vdefense3[20] = "Vampire Defense 3";

	char wdefense1[20] = "Witch Defense 1";
	char wdefense2[20] = "Witch Defense 2";
	char wdefense3[20] = "Witch Defense 3";

	char wedefense1[20] = "Werewolf Defense 1";
	char wedefense2[20] = "Werewolf Defense 2";
	char wedefense3[20] = "Werewolf Defense 3";

	char ddefense1[20] = "Devil Defense 1";
	char ddefense2[20] = "Devil Defense 2";
	char ddefense3[20] = "Devil Defense 3";

	attack_object.set(monster1, vattack1, 1);
	sptr = new attack(attack_object);
	skill_list.insert(sptr);
	attack_object.set(monster1, vattack2, 2);
	sptr = new attack(attack_object);
	skill_list.insert(sptr);
	attack_object.set(monster1, vattack3, 3);
	sptr = new attack(attack_object);
	skill_list.insert(sptr);

	attack_object.set(monster2, wattack1, 1);
	sptr = new attack(attack_object);
	skill_list.insert(sptr);
	attack_object.set(monster2, wattack2, 2);
	sptr = new attack(attack_object);
	skill_list.insert(sptr);
	attack_object.set(monster2, wattack3, 3);
	sptr = new attack(attack_object);
	skill_list.insert(sptr);

	attack_object.set(monster3, weattack1, 1);
	sptr = new attack(attack_object);
	skill_list.insert(sptr);
	attack_object.set(monster3, weattack2, 2);
	sptr = new attack(attack_object);
	skill_list.insert(sptr);
	attack_object.set(monster3, weattack3, 3);
	sptr = new attack(attack_object);
	skill_list.insert(sptr);

	attack_object.set(monster4, dattack1, 1);
	sptr = new attack(attack_object);
	skill_list.insert(sptr);
	attack_object.set(monster4, dattack2, 2);
	sptr = new attack(attack_object);
	skill_list.insert(sptr);
	attack_object.set(monster4, dattack3, 3);
	sptr = new attack(attack_object);
	skill_list.insert(sptr);

	defense_object.set(monster1, vdefense1, 1);
	sptr = new defense(defense_object);
	skill_list.insert(sptr);
	defense_object.set(monster1, vdefense2, 2);
	sptr = new defense(defense_object);
	skill_list.insert(sptr);
	defense_object.set(monster1, vdefense3, 3);
	sptr = new defense(defense_object);
	skill_list.insert(sptr);

	defense_object.set(monster2, wdefense1, 1);
	sptr = new defense(defense_object);
	skill_list.insert(sptr);
	defense_object.set(monster2, wdefense2, 2);
	sptr = new defense(defense_object);
	skill_list.insert(sptr);
	defense_object.set(monster2, wdefense3, 3);
	sptr = new defense(defense_object);
	skill_list.insert(sptr);

	defense_object.set(monster3, wedefense1, 1);
	sptr = new defense(defense_object);
	skill_list.insert(sptr);
	defense_object.set(monster3, wedefense2, 2);
	sptr = new defense(defense_object);
	skill_list.insert(sptr);
	defense_object.set(monster3, wedefense3, 3);
	sptr = new defense(defense_object);
	skill_list.insert(sptr);

	defense_object.set(monster4, ddefense1, 1);
	sptr = new defense(defense_object);
	skill_list.insert(sptr);
	defense_object.set(monster4, ddefense2, 2);
	sptr = new defense(defense_object);
	skill_list.insert(sptr);
	defense_object.set(monster4, ddefense3, 3);
	sptr = new defense(defense_object);
	skill_list.insert(sptr);
	/****************************************************/

	cout << "Welcome to Halloween game!" << endl << endl;
	cout << "There are four types of monsters: " << endl << endl;
	cout << "1. Vampire (Sharp teeth and vampiric)" << endl;
	cout << "2. Witch (Flies on a broom)" << endl;
	cout << "3. Werewolf (Has sharp claws)" << endl;
       	cout << "4. Devil (Controls people's mind)" << endl << endl;

	do 
	{
		cout << "What do you want to do?: " << endl << endl;
		cout << "1. Create monster" << endl; 
		cout << "2. Display available monsters" << endl;
		cout << "3. Choose monster (Monster battle)" << endl;
		cout << "4. Quit" << endl << endl;

		cin >> menu;
		cin.ignore(100, '\n');

		if(menu == 1)
		{
			cout << "What type of monster do you want to create?: " << endl << endl;
			cout << "1. Vampire" << endl;
			cout << "2. Witch" << endl;
			cout << "3. Werewolf" << endl;
			cout << "4. Devil" << endl << endl;

			cin >> menu;
			cin.ignore(100, '\n');

			if(menu == 1)
			{
				object1.set_name();
				mptr = new vampire(object1);
				monster_list.insert(mptr);
				cout << endl << "Monster created!" << endl << endl;
			}
			if(menu == 2)
			{
				object2.set_name();
				mptr = new witch(object2);
				monster_list.insert(mptr);
				cout << endl << "Monster created!" << endl << endl;
			}
			if(menu == 3)
			{
				object3.set_name();
				mptr = new werewolf(object3);
				monster_list.insert(mptr);
				cout << endl << "Monster created!" << endl << endl;
			}
			if(menu == 4)
			{
				object4.set_name();
				mptr = new devil(object4);
				monster_list.insert(mptr);
				cout << endl << "Monster created!" << endl << endl;
			}
			menu = 1;
		}
		if(menu == 2)
		{
			if(monster_list.display_all() == 0)
				cout << "Monster list is empty!" << endl << endl;
		}
		if(menu == 3)
		{
			cout << "Please enter the monster name: ";
			cin.get(search, 100, '\n');
			cin.ignore(100, '\n');
			if(monster_list.retrieve(myobject, search) == 1)
			{
				cout << endl << "Data retrieved!" << endl;
				skill_list.display_attack(myobject);
				cout << endl << "Choose your attack option (1-3): ";
				cin >> choice;
				cin.ignore(100, '\n');
				skill_list.retrieve_attack(myobject, myattack, choice);
				skill_list.display_defense(myobject);
				cout << endl << "Choose your defense option (1-3): ";
				cin >> choice;
				cin.ignore(100, '\n');
				skill_list.retrieve_defense(myobject, mydefense, choice);
				int opponent1 = getRandomNumber(1, 4);
				int opponent2 = getRandomNumber(1, 3);
				int opponent3 = getRandomNumber(1, 3);
				if(opponent1 == 1)
					cout << endl << "Opponent monster: Vampire" << endl;
				if(opponent1 == 2)
					cout << endl << "Opponent monster: Witch" << endl;
				if(opponent1 == 3)
					cout << endl << "Opponent monster: Werewolf" << endl;
				if(opponent1 == 4)
					cout << endl << "Opponent monster: Devil" << endl;
				skill_list.retrieve_opponent_attack(opponent1, opponent2, opattack);
				skill_list.retrieve_opponent_defense(opponent1, opponent3, opdefense);
				cout << endl << "Opponent attack option: " << endl;
				opattack.display();
				cout << endl << "Opponent defense option: " << endl;
				opdefense.display();
				if(myattack > opattack && opdefense < mydefense)
					cout << endl << "Battle result: WIN!" << endl << endl;
				if(myattack > opattack && opdefense == mydefense)
					cout << endl << "Battle result: WIN!" << endl << endl;
				if(myattack == opattack && opdefense < mydefense)
					cout << endl << "Battle result: WIN!" << endl << endl;
				if(myattack > opattack && opdefense > mydefense)
					cout << endl << "Battle result: DRAW!" << endl << endl;
				if(myattack < opattack && opdefense < mydefense)
					cout << endl << "Battle result: DRAW!" << endl << endl;
				if(myattack == opattack && opdefense == mydefense)
					cout << endl << "Battle result: DRAW!" << endl << endl;
				if(myattack < opattack && opdefense > mydefense)
					cout << endl << "Battle result: LOSE!" << endl << endl;
				if(myattack < opattack && opdefense == mydefense)
					cout << endl << "Battle result: LOSE!" << endl << endl;
				if(myattack == opattack && opdefense > mydefense)
					cout << endl << "Battle result: LOSE!" << endl << endl;
			}
			else
				cout << endl << "Data is not retrieved!" << endl << endl;
		}
	} while(menu != 4);

	return 0;
}
