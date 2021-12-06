// Sample.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

#include "teacher.h"
#include "admin.h"
#include "parent.h"
#include "student.h"

using namespace std;

void display_teacher_screen();
void display_parent_screen();

int main()
{
	int choice;
	fstream teacher_stream;
	fstream parent_stream;
	fstream student_stream;

	while (1)
	{
		cout << "School name: " << endl;
		cout << "Contact details: " << endl;
		cout << "Latest events or upcoming events details: " << endl;
		cout << "Term dates: " << endl;
		cout << "1.Teacher" << endl;
		cout << "2.Parent" << endl;
		cout << "3.Admin" << endl;
		cout << "4.Quit" << endl;
		cout << "Enter your choice:";
		cin >> choice;
		cin.ignore();
		switch (choice)
		{
		case 1:
			display_teacher_screen();
			break;
		case 2:
			//login parent
			display_parent_screen();
			break;
		case 3:
			display_admin_screen();
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


void display_teacher_screen()
{
	int choice;
	fstream teacher_stream;
	fstream student_stream;
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
			login_teacher(teacher_stream, student_stream );
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




void display_parent_screen()
{
	int choice;
	fstream parent_stream;
	fstream student_stream;
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
			register_parent(parent_stream);
		}
		else if (choice == 2)
		{
			login_parent(parent_stream,student_stream);
		}

		else if (choice == 3)
		{
			break;
		}
		else if (choice == 4)
		{
			cout << "q";
			
		}
		else
		{
			cout << "Enter a valid option" << endl;
		}
	}
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
