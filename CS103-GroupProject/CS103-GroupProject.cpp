// Sample.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
const int SIZE = 100;
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


void teacher_registration_screen();

void register_teacher(fstream& teacher_stream);

void login_teacher(fstream& teacher_stream);



int main()
{
	int choice;
	fstream teacher_stream;
	while (1)
	{
		cout << "School name: " << endl;
		cout << "Contact details: " << endl;
		cout << "Latest events or upcoming events details: " << endl;
		cout << "Term dates: " << endl;
		cout << "1.Log in teacher" << endl;
		cout << "2.Log in parent" << endl;
		cout << "3.Log in Admin" << endl;
		cout << "4.Quit" << endl;
		cout << "Enter your choice:";
		cin >> choice;
		cin.ignore();
		switch (choice)
		{
		case 1:
			teacher_registration_screen();
			break;
		case 2:
			//login parent
			break;
		case 3:
			//login admin
			break;
		case 4:
			exit(0);
		default:
			cout << "Enter a valid option!!!" << endl;
			break;

		}
	}
	system("CLS");
}


void teacher_registration_screen()
{
	int choice;
	fstream teacher_stream;
	system("CLS");

	while (1)
	{
		cout << "1.Register" << endl;
		cout << "2.Login" << endl;
		cout << "3.Go Back" << endl;
		cout << "Enter your choice:";
		cin >> choice;
		cin.ignore();

		if (choice == 1)
		{
			register_teacher(teacher_stream);
		}
		else if (choice == 2)
		{
			login_teacher(teacher_stream);
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
	system("CLS");
}

void register_teacher(fstream& teacher_stream)
{

	system("CLS");

	Teacher t;
	teacher_stream.open("teacher_registration.dat", ios::out | ios::app | ios::binary);

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
	cout << "Enter your username:";
	cin.getline(t.username, SIZE);
	cout << "Enter your password:";
	cin.getline(t.password, SIZE);

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
	int choice;

	system("CLS");


	teacher_stream.open("teacher_registration.dat", ios::in | ios::binary);

	if (!teacher_stream)
	{
		cout << "\nUnable to access the file" << endl;
	}
	else
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
			cout << "Either the username or password is incorrect" << endl;
		}

	}
	teacher_stream.close();
	system("pause");
	system("CLS");
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
