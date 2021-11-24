#include<iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "parent.h"
#include "student.h"
using namespace std;

const int SIZE = 100;

struct Parent
{
	char name[SIZE];
	char gender[SIZE];
	char dob[SIZE];
	char email[SIZE];
	char contact_num[SIZE];
	char child_full_name[SIZE];
	char class_num[SIZE];
	char child_parent_full_name[SIZE];
	char emergency_contact_num[SIZE];
	char username[SIZE];
	char password[SIZE];
};

void register_parent(fstream& parent_stream)
{

	system("CLS");

	Parent t;
	parent_stream.open("parent_registration.dat", ios::out | ios::app | ios::binary);

	cout << "Enter your full name:";
	cin.getline(t.name, SIZE);
	
	cout << "Enter your gender:";
	cin.getline(t.gender, SIZE);
	
	cout << "Enter your DOB:";
	cin.getline(t.dob, SIZE);
	
	cout << "Enter your email:";
	cin.getline(t.email, SIZE);
	
	cout << "Enter your contact number:";
	cin.getline(t.contact_num, SIZE);
	
	cout << "Enter your child full name:";
	cin.getline(t.child_full_name, SIZE);
	
	cout << "Enter your child classroom number:";
	cin.getline(t.class_num, SIZE);

	cout << "Enter your child parent full name:";
	cin.getline(t.child_parent_full_name, SIZE);

	cout << "Enter the emergency_congtact_num:";
	cin.getline(t.emergency_contact_num, SIZE);
	
	cout << "Enter your username:";
	cin.getline(t.username, SIZE);
	
	cout << "Enter your password:";
	cin.getline(t.password, SIZE);

	system("CLS");

	cout << "\nRegistering you to the system....." << endl;
	parent_stream.write(reinterpret_cast<char*>(&t), sizeof(t));
	cout << "Successfully registered you to the system....." << endl;

	parent_stream.close();
	system("pause");
	system("CLS");
}

void login_parent(fstream& parent_stream)
{
	Parent t;
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


			parent_stream.read(reinterpret_cast<char*>(&t), sizeof(t));
			while (!parent_stream.eof())
			{
				if (strcmp(username, t.username) == 0 && strcmp(password, t.password) == 0)
				{
					system("CLS");

					cout << "\nWELCOME " << t.name << endl;

					while (1)
					{
						cout << "1.view child report" << endl;
						cout << "2.view school notice" << endl;
						cout << "3.Logout" << endl;
						cout << "Enter your choice:";
						cin >> choice;
						cin.ignore();

						if (choice == 1)
						{
							//Create student report screen here
							StudentRecordProcess();
						}

						else if (choice == 2)
						{
							//Create school notice screen here
							fstream noticeFile("notice.txt");
							string notice;
							while (getline(noticeFile, notice))
							{
								cout << notice << endl;
							}
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
				parent_stream.read(reinterpret_cast<char*>(&t), sizeof(t));
			}

			if (flag == false)
			{

				parent_stream.close();
				cout << "Either the username or password is incorrect" << endl;
				i++;
				parent_stream.open("teacher_registration.dat", ios::in | ios::binary);

			}

		} while ((flag == false) && (i <= 3));

	}
	parent_stream.close();
	system("pause");
	system("CLS");
}