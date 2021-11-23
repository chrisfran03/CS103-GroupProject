#include<iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "teacher.h"
using namespace std;

const int SIZE = 100;
char user_name[SIZE];

struct Teacher
{
	char name[SIZE];
	char gender[SIZE];
	char dob[SIZE];
	char email[SIZE];
	char contact_num[SIZE];
	char class_num[SIZE];
	char year[SIZE];
	char username[SIZE];
	char password[SIZE];
};



void register_teacher(fstream& teacher_stream)
{
	system("CLS");
	char user_name[SIZE];
	Teacher t;
	teacher_stream.open("teacher_registration.dat", ios::out | ios::app | ios::binary);

	cout << "Enter your full name:";
	cin >> t.name;
	cout << "Enter your gender:";
	cin >> t.gender;
	cout << "Enter your DOB:";
	cin >> t.dob;
	cout << "Enter your email:";
	cin >> t.email;
	cout << "Enter your contact number:";
	cin >> t.contact_num;
	cout << "Enter your classroom number:";
	cin >> t.class_num;
	cout << "Enter the year you teach:";
	cin >> t.year;

	teacher_stream.close();

	//
	cout << "Enter your username:";
	cin >> user_name;
	while (checkUsername(teacher_stream, user_name) == true)
	{
		cout << "\nUsername already exist.Try again.\n\nEnter your username:";
		cin >> user_name;
	}

	teacher_stream.open("teacher_registration.dat", ios::out | ios::app | ios::binary);

	strcpy_s(t.username, user_name);
	//


	cout << "Enter your password:";
	cin >> t.password;


	cin.ignore();
	system("CLS");

	cout << "\nRegistering you to the system....." << endl;
	teacher_stream.write(reinterpret_cast<char*>(&t), sizeof(t));
	cout << "Successfully registered you to the system....." << endl;

	teacher_stream.close();
	system("pause");
	system("CLS");
}

void login_teacher(fstream& teacher_stream)
{
	Teacher t;
	char username[SIZE];
	char password[SIZE];
	bool flag = false;
	int choice, i = 1;

	system("CLS");


	teacher_stream.open("teacher_registration.dat", ios::in | ios::binary);

	if (!teacher_stream)
	{
		cout << "\nUnable to access the file" << endl;
	}
	else
	{
		do
		{

			cout << "Username:";
			cin.getline(username, SIZE);
			cout << "Password:";
			cin.getline(password, SIZE);
			cout << endl;


			teacher_stream.read(reinterpret_cast<char*>(&t), sizeof(t));
			while (!teacher_stream.eof())
			{
				if (strcmp(username, t.username) == 0 && strcmp(password, t.password) == 0)
				{
					system("CLS");

					cout << "\nWELCOME " << t.name << endl;

					while (1)
					{
						cout << "1.Create student record" << endl;
						cout << "2.Logout" << endl;
						cout << "Enter your choice:";
						cin >> choice;
						cin.ignore();

						if (choice == 1)
						{
							//Create student record registration screen here
						}

						else if (choice == 2)
						{
							break;
						}
						else
						{
							cout << "Enter a valid option" << endl;
						}
					}
					flag = true;
				}
				teacher_stream.read(reinterpret_cast<char*>(&t), sizeof(t));
			}

			if (flag == false)
			{

				teacher_stream.close();
				cout << "Either the username or password is incorrect" << endl;
				i++;
				teacher_stream.open("teacher_registration.dat", ios::in | ios::binary);

			}

		} while ((flag == false) && (i <= 3));

	}
	teacher_stream.close();
	system("pause");
	system("CLS");
}

bool checkUsername(fstream& teacher_stream, char* user_name)
{
	Teacher t;
	bool user_exists = false;

	teacher_stream.open("teacher_registration.dat", ios::in | ios::binary);

	if (!teacher_stream)
	{
		cout << "\nUnable to access the file" << endl;
	}
	else
	{

		teacher_stream.read(reinterpret_cast<char*>(&t), sizeof(t));
		while (!teacher_stream.eof())
		{
			if (strcmp(user_name, t.username) == 0)
			{
				user_exists = true;
			}

			teacher_stream.read(reinterpret_cast<char*>(&t), sizeof(t));
		}
	}
	teacher_stream.close();

	return user_exists;
}