#include<iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "teacher.h"
#include "student.h"
#include "parent.h"

using namespace std;


const int SIZE = 100;
char parent_user_name[SIZE];

struct Parent
{
	char name[SIZE];
	char gender[SIZE];
	char dob[SIZE];
	char email[SIZE];
	char contact_num[SIZE];
	char child_full_name[SIZE];
	char child_classroom_num[SIZE];
	char child_guardian_name[SIZE];
	char emergency_contact_num[SIZE];
	char username[SIZE];
	char password[SIZE];
};



void register_parent(fstream& parent_stream)
{
	system("CLS");
	char parent_user_name[SIZE];
	Parent p;
	parent_stream.open("parent_registration.dat", ios::out | ios::app | ios::binary);

	cout << "Enter your full name:";
	cin.getline(p.name, SIZE);
	cout << "Enter your gender:";
	cin.getline(p.name, SIZE);
	cout << "Enter your DOB:";
	cin.getline(p.name, SIZE);
	cout << "Enter your email:";
	cin.getline(p.email, SIZE);
	cout << "Enter your contact number:";
	cin.getline(p.contact_num, SIZE);
	cout << "Enter your child's full name:";
	cin.getline(p.child_full_name, SIZE);
	cout << "Enter your child's classroom number:";
	cin.getline(p.child_classroom_num, SIZE);
	cout << "Enter your child parent/caregiver full name:";
	cin.getline(p.child_guardian_name, SIZE);
	cout << "Enter the emergency contact number:";
	cin.getline(p.emergency_contact_num, SIZE);

	parent_stream.close();

	//
	cout << "Enter your username:";
	cin >> parent_user_name;
	while (checkUsernameParent(parent_stream, parent_user_name) == true)
	{
		cout << "\nUsername already exist.Try again.\n\nEnter your username:";
		cin >> parent_user_name;
	}

	parent_stream.open("parent_registration.dat", ios::out | ios::app | ios::binary);

	strcpy_s(p.username, parent_user_name);
	//


	cout << "Enter your password:";
	cin >> p.password;


	cin.ignore();
	system("CLS");

	cout << "\nRegistering you to the system....." << endl;
	parent_stream.write(reinterpret_cast<char*>(&p), sizeof(p));
	cout << "Successfully registered you to the system....." << endl;

	parent_stream.close();
	system("pause");
	system("CLS");
}

void login_parent(fstream& parent_stream, fstream& student_stream)
{
	Parent p;
	char username[SIZE];
	char password[SIZE];
	bool flag = false;
	int choice, i = 1;

	system("CLS");


	parent_stream.open("parent_registration.dat", ios::in | ios::binary);

	if (!parent_stream)
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


			parent_stream.read(reinterpret_cast<char*>(&p), sizeof(p));
			while (!parent_stream.eof())
			{
				if (strcmp(username, p.username) == 0 && strcmp(password, p.password) == 0)
				{
					system("CLS");

					cout << "\nWELCOME " << p.name << endl;

					while (1)
					{
						cout << "1.View your child's report" << endl;
						cout << "2.View school notices" << endl;
						cout << "3.Logout" << endl;
						cout << "Enter your choice:";
						cin >> choice;
						cin.ignore();

						if (choice == 1)
						{
							child_report(parent_stream, student_stream,  p.name);
						}

						else if (choice == 2)
						{
							system("CLS");
							cout << "No upcoming events!"<< endl;
							system("pause");
							system("CLS");

							
						}

						else if (choice == 3)
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
				parent_stream.read(reinterpret_cast<char*>(&p), sizeof(p));
			}

			if (flag == false)
			{

				parent_stream.close();
				cout << "Either the username or password is incorrect" << endl;
				i++;
				parent_stream.open("parent_registration.dat", ios::in | ios::binary);
				if (i > 3)
				{
					cout << "!!Please login after some time!!\n";
				}
			}

		} while ((flag == false) && (i <= 3));

	}
	parent_stream.close();
	system("pause");
	system("CLS");
}

bool checkUsernameParent(fstream& parent_stream, char* user_name)
{
	Parent p;
	bool user_exists = false;

	parent_stream.open("parent_registration.dat", ios::in | ios::binary);

	if (!parent_stream)
	{
		cout << "\nUnable to access the file" << endl;
	}
	else
	{

		parent_stream.read(reinterpret_cast<char*>(&p), sizeof(p));
		while (!parent_stream.eof())
		{
			if (strcmp(user_name, p.username) == 0)
			{
				user_exists = true;
			}

			parent_stream.read(reinterpret_cast<char*>(&p), sizeof(p));
		}
	}
	parent_stream.close();

	return user_exists;
}