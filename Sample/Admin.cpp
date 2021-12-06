#include<iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "teacher.h"
#include "student.h"
#include "admin.h"

using namespace std;
const int SIZE = 100;

struct Student  //struct of student
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
struct Parent  //struct of parent
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
struct Teacher  //struct of teacher
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

void display_admin_screen()   //function to display admin screen
{
	string username, password;
	int choice;

	fstream student_stream;
	fstream parent_stream;
	fstream teacher_stream;

	system("CLS");

		cout << "Username:";
		cin >> username;
		cout << "Password:";
		cin >> password;

		if (username == "username" && password == "password")  //checking for username and password for admin login
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
					display_class_records(student_stream);  //function to display class records
				}
				else if (choice == 2)
				{
					display_parent_records(parent_stream);  //function to display parent records

				}
				else if (choice == 3)
				{
					report_need_help(student_stream, parent_stream, teacher_stream);  //function to display the report of students who need help

				}
				else if (choice == 4)
				{
					report_progressing(student_stream, parent_stream, teacher_stream);  //functions to display report of students who are progressing
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
					cout << "\nEnter a valid option:" << endl;
				}
			}
		}
		else
		{
			cout << "Username or Password is incorrect. Please try after some time" << endl;  //notification for wrong username or password
			system("pause");
			system("CLS");

		}
		
}

void display_class_records(fstream& student_stream)  //function to display class records
{

	system("CLS");

	int class_num;
	cout << "Enter the classroom number:";
	cin >> class_num;
	cin.ignore();

	if (class_num == 1)
	{
		Student s;

		student_stream.open("Room_1.dat", ios::in | ios::binary);  //checking in the class file

		if (!student_stream)
		{
			cout << "File does not exist or there is a problem opening the file";
		}
		else
		{
			student_stream.read(reinterpret_cast<char*>(&s), sizeof(s));
			while (!student_stream.eof())
			{
				//printing the records of students
				cout << "Student Name: " << s.name << endl;
				cout << "Student Gender: " << s.gender << endl;
				cout << "Student Maths: " << s.maths << endl;
				cout << "Student Science: " << s.science << endl;
				cout << "Student Writing: " << s.writing << endl;
				cout << "Student Reading: " << s.reading << endl;
				cout << "Student Sports: " << s.sports << endl;
				cout << "Learning Progress: " << s.LearningProgress << endl<<endl;
				student_stream.read(reinterpret_cast<char*>(&s), sizeof(s));

		     }
		}
		student_stream.close(); //close the file to prevent memory leakage
	}

	else if (class_num == 2)
	{
		Student s;

		student_stream.open("Room_2.dat", ios::in | ios::binary);  //checking in the class file
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
				  //printing records of students
					cout << "Student Name: " << s.name << endl;
					cout << "Student Gender: " << s.gender << endl;
					cout << "Student Maths: " << s.maths << endl;
					cout << "Student Science: " << s.science << endl;
					cout << "Student Writing: " << s.writing << endl;
					cout << "Student Reading: " << s.reading << endl;
					cout << "Student Sports: " << s.sports << endl;
					cout << "Learning Progress: " << s.LearningProgress << endl<<endl;
					student_stream.read(reinterpret_cast<char*>(&s), sizeof(s));

			}
		}
		student_stream.close(); //closing the file to prevent memory leakage
	}

	else
	{

		cout << "Only 2 classrooms are available";  //message to show that only two classrooms are availbale

	}

	system("pause");
	system("CLS");
}

void display_parent_records(fstream& parent_stream)  //function to display parent records
{
	system("CLS");

	Parent p;

	parent_stream.open("parent_registration.dat", ios::in | ios::binary);  //opening parent_registration file

	if (!parent_stream)
	{
		cout << "File does not exist or there is a problem opening the file";
	}
	else
	{
		parent_stream.read(reinterpret_cast<char*>(&p), sizeof(p));
		while (!parent_stream.eof())
		{		
			//printing the parent records
				cout << "Full Name: " << p.name << endl;
				cout << "Gender: " << p.gender << endl;
				cout << "Email: " << p.email << endl;
				cout << "Contact number: " << p.contact_num << endl;
				cout << "Child full name: " << p.child_full_name << endl;
				cout << "Child classroom number: " <<p.child_classroom_num<< endl;
				cout << "Child parent/caregiver full name: " << p.child_guardian_name << endl;
				cout << "Emergency contact number: " << p.emergency_contact_num << endl<<endl;
				parent_stream.read(reinterpret_cast<char*>(&p), sizeof(p));

		}
	}
	parent_stream.close();  //closing the file to prevent memory leakage 
	system("pause");
	system("CLS");
}

void report_need_help(fstream& student_stream, fstream& parent_stream, fstream& teacher_stream)  //report of the students who need help
{
	system("CLS");
	int classroom_number;
	cout << "Please enter the classroom number:";
	cin >> classroom_number;
	cin.ignore();
	if (classroom_number == 1)
	{
		Student s;
		char name[SIZE] = "Need Help";
		bool flag = false;
		bool flag2 = false;
		bool flag3 = false;

		student_stream.open("Room_1.dat", ios::in | ios::binary);  //checking the classroom 1
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
					//printing records of students who need help
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
					get_teacher_name(teacher_stream, 1);

					get_parent_number(parent_stream, s.name);

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
	else if (classroom_number == 2)  //checking classroom 2
	{
		Student s;
		char name[SIZE] = "Need Help";
		bool flag = false;
		

		student_stream.open("Room_2.dat", ios::in | ios::binary);  //opening the file of classroom 2
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
					//printing the records of students who need help
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

					get_teacher_name(teacher_stream, 2); //printing the names of teachers of their class

					get_parent_number(parent_stream, s.name); //printing the contact number of parent

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

void report_progressing(fstream& student_stream, fstream& parent_stream, fstream& teacher_stream)  //report of studenrs who are progressing
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
		

		student_stream.open("Room_1.dat", ios::in | ios::binary);  //checking in classroom 1

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
					//printing the records of students who are progressing
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

					get_teacher_name(teacher_stream, 1); //printing the names of teachers of their class

					get_parent_number(parent_stream, s.name); //printing the contact number of parent
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
	else if (classroom_number == 2)  //if classroom is 2
	{
		Student s;
		char name[SIZE] = "Progressing";
		bool flag = false;
		

		student_stream.open("Room_2.dat", ios::in | ios::binary);//opening the file of classroom 2

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
					//printing the records of students who are progressing
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

					get_teacher_name(teacher_stream, 2); //printing the names of teachers of their class


					get_parent_number(parent_stream, s.name); //printing the contact number of parent
			
				}
				student_stream.read(reinterpret_cast<char*>(&s), sizeof(s));
			}

			if (flag == false)
			{
				cout << "\n No records for the student found\n";
			}
		}
		student_stream.close(); //closing the file to prevent memory leakage
	}

	else
	{
		cout << "Only 2 classrooms are availabale";
	}
	system("pause");
	system("CLS");
}

void get_teacher_name(fstream& teacher_stream, int class_num)
{
	char classroom_number[SIZE]; 
	if (class_num == 1)
	{
		strcpy_s(classroom_number, "1");
	}
	else if (class_num == 2)
	{
		strcpy_s(classroom_number, "2");
	}
	
	bool flag = false;
	// printing the names of teachers of classroom
	Teacher t;
	teacher_stream.open("teacher_registration.dat", ios::in | ios::binary);
	if (!teacher_stream)
	{
		cout << "File does not exist or there is a problem opening the file";
	}
	else
	{

		teacher_stream.read(reinterpret_cast<char*>(&t), sizeof(t));
		while (!teacher_stream.eof())
		{
			if (strcmp(classroom_number, t.class_num) == 0)
			{
				cout << "Teacher name: " << t.name << endl;
				flag = true;
			}
			teacher_stream.read(reinterpret_cast<char*>(&t), sizeof(t));
		}
	}
	if (flag == false)
	{
		cout << "\nNo records of the teacher found\n";
	}
	teacher_stream.close();
}

void get_parent_number(fstream& parent_stream,  char*child_name)
{
	 //printing the contact number of the parent
	bool flag = false;
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
				if (strcmp(child_name, p.child_full_name) == 0)
			    {
				  cout << "Parent Contact number: " << p.contact_num << endl << endl;
				  flag = true;
				}
				    parent_stream.read(reinterpret_cast<char*>(&p), sizeof(p));
			}
		}
		if (flag == false)
		{
			cout << "No records of the parent found!\n";
		}
		parent_stream.close();
					   
}