#include<iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "teacher.h"
#include "student.h"
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



void register_teacher(fstream& teacher_stream)  //function to register teacher
{
	system("CLS");
	char user_name[SIZE];
	Teacher t;
	teacher_stream.open("teacher_registration.dat", ios::out | ios::app | ios::binary);  //opening teacher_registration file
	//enter values
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
	cout << "Enter your classroom number:";
	cin.getline(t.class_num, SIZE);
	cout << "Enter the year you teach:";
	cin.getline(t.year, SIZE);

	teacher_stream.close();

	//check for duplicate username
	cout << "Enter your username:";
	cin.getline(user_name, SIZE);
	while (checkUsernameTeacher(teacher_stream, user_name) == true)
	{
		cout << "\nUsername already exist.Try again.\n\nEnter your username:";
		cin.getline(user_name, SIZE);
	}

	teacher_stream.open("teacher_registration.dat", ios::out | ios::app | ios::binary);

	strcpy_s(t.username, user_name); //copying the temporay username which was checked to the structure variable 
	//


	cout << "Enter your password:";
	cin.getline(t.password, SIZE);

	system("CLS");

	cout << "\nRegistering you to the system....." << endl;
	teacher_stream.write(reinterpret_cast<char*>(&t), sizeof(t));  // writing to file
	cout << "Successfully registered you to the system....." << endl;

	teacher_stream.close();//close file to prevent memory leakage
	system("pause");
	system("CLS");
}

void login_teacher(fstream& teacher_stream , fstream& student_stream)  //function to login teacher
{
	Teacher t;
	char username[SIZE];
	char password[SIZE];
	bool flag = false;
	bool exit = false;

	int choice, i = 1;

	system("CLS");


	teacher_stream.open("teacher_registration.dat", ios::in | ios::binary); //open teacher_registration file

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
				if (strcmp(username, t.username) == 0 && strcmp(password, t.password) == 0)  //checking if username or password is same
				{
					system("CLS");

					cout << "\nWELCOME " << t.name << endl;

					while (exit!=true)
					{
						cout << "1.Manage student records" << endl;
						cout << "2.Logout" << endl;
						cout << "Enter your choice:";
						cin >> choice;
						cin.ignore();

						if (choice == 1)
						{
							display_student_record_screen(student_stream);  //function to display student record screen
						}

						else if (choice == 2)
						{
							exit = true;
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
				if (i >3)
				{
					cout << "!!Please login after some time!!\n";
				}

			}

		} while ((flag == false) && (i <= 3)); //maximum 3 login attempts

	}
	teacher_stream.close(); //close file
	system("pause");
	system("CLS");
}

bool checkUsernameTeacher(fstream& teacher_stream, char* user_name)  //function to check for duplicate username for teachers 
{
	Teacher t;
	bool user_exists = false;

	teacher_stream.open("teacher_registration.dat", ios::in | ios::binary);  //opening teacgher_registration file

	if (!teacher_stream)
	{
		cout << "\nUnable to access the file" << endl;
	}
	else
	{

		teacher_stream.read(reinterpret_cast<char*>(&t), sizeof(t));
		while (!teacher_stream.eof())
		{
			if (strcmp(user_name, t.username) == 0) //if input username is username then user_exists == true
			{
				user_exists = true;
			}

			teacher_stream.read(reinterpret_cast<char*>(&t), sizeof(t));
		}
	}
	teacher_stream.close(); //closing the file to prevent memory leakage

	return user_exists;
}