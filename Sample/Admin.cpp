#include<iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "teacher.h"
#include "student.h"
#include "admin.h"

using namespace std;
const int SIZE = 100;

struct Student
{
	char name[SIZE];
	char gender[SIZE];
	char maths[SIZE];
	char science[SIZE];
	char writing[SIZE];
	char reading[SIZE];
	char sports[SIZE];
	char LearningProgress[SIZE];
	char classroom_num[SIZE];
};
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

void display_admin_screen()
{
	string username, password;
	int choice;

	fstream student_stream;
	fstream parent_stream;

	system("CLS");

		cout << "Username:";
		cin >> username;
		cout << "Password:";
		cin >> password;

		if (username == "username" && password == "password")
		{
			system("CLS");

			while (1)
			{
			cout << "WELCOME ADMIN" << endl;
			cout << "1.See class records" << endl;
			cout << "2.See parents records" << endl;
			cout << "3.Report of students who need help" << endl;
			cout << "4.Report of students who are progressing" << endl;
			cout << "5.Log out" << endl;

			cout << "Enter you choice:";
			cin >> choice;
			cin.ignore();

			
				if (choice == 1)
				{
					display_class_records(student_stream);
				}
				else if (choice == 2)
				{
					display_parent_records(parent_stream);

				}
				else if (choice == 3)
				{
					report_need_help(student_stream);

				}
				else if (choice == 4)
				{
					report_progressing(student_stream);
				}
				else if (choice == 5)
				{
					cout << "\nLogging out..." << endl;
					system("pause");
					system("CLS");
					break;
				}
				else
				{
					cout << "\nEnter a valid option" << endl;
				}
			}
		}
		else
		{
			cout << "Username or Password is incorrect. Please try after some time" << endl;
			system("pause");
			system("CLS");

		}
		
}

void display_class_records(fstream& student_stream)
{

	system("CLS");

	int class_num;
	cout << "Enter the classroom number:";
	cin >> class_num;
	cin.ignore();

	if (class_num == 1)
	{
		Student s;

		student_stream.open("Room_1.dat", ios::in | ios::binary);

		if (!student_stream)
		{
			cout << "File does not exist or there is a problem opening the file";
		}
		else
		{
			student_stream.read(reinterpret_cast<char*>(&s), sizeof(s));
			while (!student_stream.eof())
			{
				
				cout << "Student Name: " << s.name << endl;
				cout << "Student Gender: " << s.gender << endl;
				cout << "Student Maths: " << s.maths << endl;
				cout << "Student Science: " << s.science << endl;
				cout << "Student Writing: " << s.writing << endl;
				cout << "Student Reading: " << s.reading << endl;
				cout << "Student Sports: " << s.sports << endl;
				cout << "Learning Progress: " << s.LearningProgress << endl;
				student_stream.read(reinterpret_cast<char*>(&s), sizeof(s));

		     }
		}
		student_stream.close();
	}

	else if (class_num == 2)
	{
		Student s;

		student_stream.open("Room_2.dat", ios::in | ios::binary);
		string student_data;


		if (!student_stream)
		{
			cout << "File does not exist or there is a problem opening the file";
		}
		else
		{
			student_stream.read(reinterpret_cast<char*>(&s), sizeof(s));
			while (!student_stream.eof())
			{
				
					cout << "Student Name: " << s.name << endl;
					cout << "Student Gender: " << s.gender << endl;
					cout << "Student Maths: " << s.maths << endl;
					cout << "Student Science: " << s.science << endl;
					cout << "Student Writing: " << s.writing << endl;
					cout << "Student Reading: " << s.reading << endl;
					cout << "Student Sports: " << s.sports << endl;
					cout << "Learning Progress: " << s.LearningProgress << endl;
					student_stream.read(reinterpret_cast<char*>(&s), sizeof(s));

			}
		}
		student_stream.close();
	}

	else
	{

		cout << "Only 2 classrooms are available";

	}

	system("pause");
	system("CLS");
}

void display_parent_records(fstream& parent_stream)
{
	system("CLS");

	Parent p;

	parent_stream.open("parent_registration.dat", ios::in | ios::binary);

	if (!parent_stream)
	{
		cout << "File does not exist or there is a problem opening the file";
	}
	else
	{
		parent_stream.read(reinterpret_cast<char*>(&p), sizeof(p));
		while (!parent_stream.eof())
		{		
				cout << "Full Name: " << p.name << endl;
				cout << "Gender: " << p.gender << endl;
				cout << "Email: " << p.email << endl;
				cout << "Contact number: " << p.contact_num << endl;
				cout << "Child full name: " << p.child_full_name << endl;
				cout << "Child classroom number: " <<p.child_classroom_num<< endl;
				cout << "Child parent/caregiver full name: " << p.child_guardian_name << endl;
				cout << "Emergency contact number: " << p.emergency_contact_num << endl;
				parent_stream.read(reinterpret_cast<char*>(&p), sizeof(p));

		}
	}
	parent_stream.close();
	system("pause");
	system("CLS");
}

void report_need_help(fstream & student_stream)
{
	system("CLS");
	int classroom_number;
	cout << "Please enter the classroom number:";
	cin >> classroom_number;
	cin.ignore();
	if (classroom_number == 1)
	{
		Student s;
		char name[SIZE] = "NeedHelp";
		bool flag = false;

		student_stream.open("Room_1.dat", ios::in | ios::binary);
		string student_data;


		if (!student_stream)
		{
			cout << "File does not exist or there is a problem opening the file";
		}
		else
		{

			student_stream.read(reinterpret_cast<char*>(&s), sizeof(s));
			while (!student_stream.eof())
			{
				if (strcmp(name, s.LearningProgress) == 0)
				{
					cout << "Student Classroom number:" << s.classroom_num << endl;
					cout << "Student Name: " << s.name << endl;
					cout << "Student Gender: " << s.gender << endl;
					cout << "Student Maths: " << s.maths << endl;
					cout << "Student Science: " << s.science << endl;
					cout << "Student Writing: " << s.writing << endl;
					cout << "Student Reading: " << s.reading << endl;
					cout << "Student Sports: " << s.sports << endl;
					cout << "Learning Progress: " << s.LearningProgress << endl;
					flag = true;
				}
				student_stream.read(reinterpret_cast<char*>(&s), sizeof(s));
			}

			if (flag == false)
			{
				cout << "\n No records for the student found\n";
			}
		}
		student_stream.close();
	}
	else if (classroom_number == 2)
	{
		Student s;
		char name[SIZE] = "NeedHelp";
		bool flag = false;

		student_stream.open("Room_2.dat", ios::in | ios::binary);
		string student_data;


		if (!student_stream)
		{
			cout << "File does not exist or there is a problem opening the file";
		}
		else
		{

			student_stream.read(reinterpret_cast<char*>(&s), sizeof(s));
			while (!student_stream.eof())
			{
				if (strcmp(name, s.LearningProgress) == 0)
				{
					cout << "Student Classroom number:" << s.classroom_num << endl;
					cout << "Student Name: " << s.name << endl;
					cout << "Student Gender: " << s.gender << endl;
					cout << "Student Maths: " << s.maths << endl;
					cout << "Student Science: " << s.science << endl;
					cout << "Student Writing: " << s.writing << endl;
					cout << "Student Reading: " << s.reading << endl;
					cout << "Student Sports: " << s.sports << endl;
					cout << "Learning Progress: " << s.LearningProgress << endl;
					flag = true;
				}
				student_stream.read(reinterpret_cast<char*>(&s), sizeof(s));
			}

			if (flag == false)
			{
				cout << "\n No records for the student found\n";
			}
		}
		student_stream.close();
	}

	else
	{
		cout << "Only 2 classrooms are availabale";
	}
	system("pause");
	system("CLS");
}

void report_progressing(fstream& student_stream)
{
	system("CLS");
	int classroom_number;
	cout << "Please enter the classroom number:";
	cin >> classroom_number;
	cin.ignore();
	if (classroom_number == 1)
	{
		Student s;
		char name[SIZE] = "Progressing";
		bool flag = false;

		student_stream.open("Room_1.dat", ios::in | ios::binary);
		string student_data;


		if (!student_stream)
		{
			cout << "File does not exist or there is a problem opening the file";
		}
		else
		{

			student_stream.read(reinterpret_cast<char*>(&s), sizeof(s));
			while (!student_stream.eof())
			{
				if (strcmp(name, s.LearningProgress) == 0)
				{
					cout << "Student Classroom number:" << s.classroom_num << endl;
					cout << "Student Name: " << s.name << endl;
					cout << "Student Gender: " << s.gender << endl;
					cout << "Student Maths: " << s.maths << endl;
					cout << "Student Science: " << s.science << endl;
					cout << "Student Writing: " << s.writing << endl;
					cout << "Student Reading: " << s.reading << endl;
					cout << "Student Sports: " << s.sports << endl;
					cout << "Learning Progress: " << s.LearningProgress << endl;
					flag = true;
				}
				student_stream.read(reinterpret_cast<char*>(&s), sizeof(s));
			}

			if (flag == false)
			{
				cout << "\n No records for the student found\n";
			}
		}
		student_stream.close();
	}
	else if (classroom_number == 2)
	{
		Student s;
		char name[SIZE] = "Progressing";
		bool flag = false;

		student_stream.open("Room_2.dat", ios::in | ios::binary);
		string student_data;


		if (!student_stream)
		{
			cout << "File does not exist or there is a problem opening the file";
		}
		else
		{

			student_stream.read(reinterpret_cast<char*>(&s), sizeof(s));
			while (!student_stream.eof())
			{
				if (strcmp(name, s.LearningProgress) == 0)
				{
					cout << "Student Classroom number:" << s.classroom_num << endl;
					cout << "Student Name: " << s.name << endl;
					cout << "Student Gender: " << s.gender << endl;
					cout << "Student Maths: " << s.maths << endl;
					cout << "Student Science: " << s.science << endl;
					cout << "Student Writing: " << s.writing << endl;
					cout << "Student Reading: " << s.reading << endl;
					cout << "Student Sports: " << s.sports << endl;
					cout << "Learning Progress: " << s.LearningProgress << endl;
					flag = true;
				}
				student_stream.read(reinterpret_cast<char*>(&s), sizeof(s));
			}

			if (flag == false)
			{
				cout << "\n No records for the student found\n";
			}
		}
		student_stream.close();
	}

	else
	{
		cout << "Only 2 classrooms are availabale";
	}
	system("pause");
	system("CLS");
}