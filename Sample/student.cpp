#include<iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "teacher.h"
#include "student.h"
#include "admin.h"
#include "parent.h"


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



void display_student_record_screen(fstream &student_stream)
{
	int choice;
	system("CLS");
	while (1)
	{
		cout << "1.Add student record"<<endl;
		cout << "2.Edit student record"<<endl;
		cout << "3.Delete student record" << endl;
		cout << "4.Update student record" << endl;
		cout << "5.View the records" << endl;
		cout << "6.Go back" << endl;
		cout << "Enter your choice";
		cin >> choice;

		if (choice == 1)
		{
			add_student(student_stream);
		}
		else if (choice == 2)
		{
			edit_student(student_stream);
		}
		else if (choice == 3)
		{
			delete_student(student_stream);
		}
		else if (choice == 4)
		{
			update_student(student_stream);
		}
		else if (choice == 5)
		{
			view_student_record(student_stream);
		}
		else if (choice == 6)
		{
			break;
		}
		else
		{
			cout << "\nEnter a valid option!!!"<<endl;
		}
	}
	system("CLS");
}

void add_student(fstream& student_stream)
{
	char progress[SIZE];
	int classroom;
	system("CLS");
	cout << "Enter classroom:";
	cin >> classroom;
	cin.ignore();
	if (classroom == 1)
	{
		Student s;
		student_stream.open("Room_1.dat", ios::out | ios::app | ios::binary);

		char classroom_number[SIZE] = "1";
		strcpy_s(s.classroom_num, classroom_number);

		cout << "Enter your name:";
		cin.getline(s.name, SIZE);
		cout << "Enter your gender:";
		cin.getline(s.gender, SIZE);
		cout << "Maths(Achieved,Progressing,Need Help):";
		cin.getline(progress,SIZE);
		while (enter_learning_progress(progress) == false)
		{
			cout << "\nType in these options only(Achieved,Progressing,Need Help).\nTry again:";
			cin.getline(progress, SIZE);
		}
		strcpy_s(s.maths,progress);

		cout << "Science(Achieved,Progressing,Need Help):";
		cin.getline(progress, SIZE);
		while (enter_learning_progress(progress) == false)
		{
			cout << "\nType in these options only(Achieved,Progressing,Need Help).\nTry again:";
			cin.getline(progress, SIZE);
		}
		strcpy_s(s.science, progress);

		cout << "Writing(Achieved,Progressing,Need Help):";
		cin.getline(progress, SIZE);
		while (enter_learning_progress(progress) == false)
		{
			cout << "\nType in these options only(Achieved,Progressing,Need Help).\nTry again:";
			cin.getline(progress, SIZE);
		}
		strcpy_s(s.writing, progress);

		cout << "Reading(Achieved,Progressing,Need Help):";
		cin.getline(progress, SIZE);
		while (enter_learning_progress(progress) == false)
		{
			cout << "\nType in these options only(Achieved,Progressing,Need Help).\nTry again:";
			cin.getline(progress, SIZE);
		}
		strcpy_s(s.reading, progress);

		cout << "Sports(Achieved,Progressing,Need Help):";
		cin.getline(progress, SIZE);
		while (enter_learning_progress(progress) == false)
		{
			cout << "\nType in these options only(Achieved,Progressing,Need Help).\nTry again:";
			cin.getline(progress, SIZE);
		}
		strcpy_s(s.sports, progress);

		cout << "Learning Progress(Achieved,Progressing,Need Help):";
		cin.getline(progress, SIZE);
		while (enter_learning_progress(progress) == false)
		{
			cout << "\nType in these options only(Achieved,Progressing,Need Help).\nTry again:";
			cin.getline(progress, SIZE);
		}
		strcpy_s(s.LearningProgress, progress);
		system("CLS");

		cout << "\nAdding student to the system....." << endl;
		student_stream.write(reinterpret_cast<char*>(&s), sizeof(s));
		cout << "Successfully added student to the system....." << endl;

		student_stream.close();
		system("pause");
		system("CLS");
	}
	else if (classroom == 2)
	{

		Student s;
		student_stream.open("Room_2.dat", ios::out | ios::app | ios::binary);

		char classroom_number[SIZE] = "2";
		strcpy_s(s.classroom_num, classroom_number);

		cout << "Enter your name:";
		cin.getline(s.name, SIZE);
		cout << "Enter your gender:";
		cin.getline(s.gender, SIZE);
		cout << "Maths(Achieved,Progressing,Need Help):";
		cin.getline(progress, SIZE);
		while (enter_learning_progress(progress) == false)
		{
			cout << "\nType in these options only(Achieved,Progressing,Need Help).\nTry again:";
			cin.getline(progress, SIZE);
		}
		strcpy_s(s.maths, progress);

		cout << "Science(Achieved,Progressing,Need Help):";
		cin.getline(progress, SIZE);
		while (enter_learning_progress(progress) == false)
		{
			cout << "\nType in these options only(Achieved,Progressing,Need Help).\nTry again:";
			cin.getline(progress, SIZE);
		}
		strcpy_s(s.science, progress);

		cout << "Writing(Achieved,Progressing,Need Help):";
		cin.getline(progress, SIZE);
		while (enter_learning_progress(progress) == false)
		{
			cout << "\nType in these options only(Achieved,Progressing,Need Help).\nTry again:";
			cin.getline(progress, SIZE);
		}
		strcpy_s(s.writing, progress);

		cout << "Reading(Achieved,Progressing,Need Help):";
		cin.getline(progress, SIZE);
		while (enter_learning_progress(progress) == false)
		{
			cout << "\nType in these options only(Achieved,Progressing,Need Help).\nTry again:";
			cin.getline(progress, SIZE);
		}
		strcpy_s(s.reading, progress);

		cout << "Sports(Achieved,Progressing,Need Help):";
		cin.getline(progress, SIZE);
		while (enter_learning_progress(progress) == false)
		{
			cout << "\nType in these options only(Achieved,Progressing,Need Help).\nTry again:";
			cin.getline(progress, SIZE);
		}
		strcpy_s(s.sports, progress);

		cout << "Learning Progress(Achieved,Progressing,Need Help):";
		cin.getline(progress, SIZE);
		while (enter_learning_progress(progress) == false)
		{
			cout << "\nType in these options only(Achieved,Progressing,Need Help).\nTry again:";
			cin.getline(progress, SIZE);
		}
		strcpy_s(s.LearningProgress, progress);
		system("CLS");

		cout << "\nAdding student to the system....." << endl;
		student_stream.write(reinterpret_cast<char*>(&s), sizeof(s));
		cout << "Successfully added student to the system....." << endl;

		student_stream.close();
		system("pause");
		system("CLS");
	}
	else
	{
	cout << "\nOnly two classrooms available" << endl;
	system("pause");
	system("CLS");
    }
}

void delete_student(fstream& student_stream)
{
	int flag = 0;
	Student s;
	char name[SIZE];
	int classroom_number;

	cout << "Enter the classroom number:";
	cin >> classroom_number;
	cin.ignore();


	if (classroom_number == 1)
	{

		cout << "Name the student you want to delete?";
		cin >> name;

		student_stream.open("Room_1.dat", ios::in | ios::binary);

		ofstream ofs;
		ofs.open("temp.dat", ios::out | ios::binary);

		while (!student_stream.eof()) {

			student_stream.read(reinterpret_cast<char*>(&s), sizeof(s));

			if (student_stream)
			{
				if (strcmp(name, s.name) == 0)
				{
					flag = 1;
					cout << s.name << " 's record is going to be deleted";
				}
				else
				{
					ofs.write(reinterpret_cast<char*>(&s), sizeof(s));
				}
			}
		}
		ofs.close();
		student_stream.close();

		remove("Room_1.dat");

		rename("temp.dat", "Room_1.dat");

		if (flag == 1)
		{
			cout << "\nrecord successfully deleted\n";
		}
		else
		{
			cout << "\nrecord not found\n";
		}
	}

	if (classroom_number == 2)
	{

		cout << "Name the student you want to delete?";
		cin >> name;

		student_stream.open("Room_2.dat", ios::in | ios::binary);

		ofstream ofs;
		ofs.open("temp.dat", ios::out | ios::binary);

		while (!student_stream.eof()) {

			student_stream.read(reinterpret_cast<char*>(&s), sizeof(s));

			if (student_stream)
			{
				if (strcmp(name, s.name) == 0)
				{
					flag = 1;
					cout << s.name << " 's record is going to be deleted";
				}
				else
				{
					ofs.write(reinterpret_cast<char*>(&s), sizeof(s));
				}
			}
		}
		ofs.close();
		student_stream.close();

		remove("Room_2.dat");

		rename("temp.dat", "Room_2.dat");

		if (flag == 1)
		{
			cout << "\nrecord successfully deleted\n";
		}
		else
		{
			cout << "\nrecord not found\n";
		}
	}
}

void edit_student(fstream& student_stream)
{
	char progress[SIZE];

	int flag = 0;
	char name[SIZE];
	int classroom_number;

	cout << "Enter the classroom number:";
	cin >> classroom_number;
	cin.ignore();

	if (classroom_number == 1)
	{

		Student s;
		cout << "Name the student you want to edit?";
		cin.getline(name, SIZE);

		student_stream.open("Room_1.dat", ios::in | ios::binary);

		ofstream ofs;
		ofs.open("temp.dat", ios::out | ios::binary);

		while (!student_stream.eof()) {

			student_stream.read(reinterpret_cast<char*>(&s), sizeof(s));

			if (student_stream)
			{
				if (strcmp(name, s.name) == 0)
				{
					flag = 1;
					cout << s.name << " 's record is going to be edited";
				}
				else
				{
					ofs.write(reinterpret_cast<char*>(&s), sizeof(s));
				}
			}
		}
		ofs.close();
		student_stream.close();

		remove("Room_1.dat");

		rename("temp.dat", "Room_1.dat");

		if (flag == 1)
		{
			cout << "\nEnter new values\n";

			student_stream.open("Room_1.dat", ios::out | ios::app | ios::binary);

			char classroom_number[SIZE] = "1";
			strcpy_s(s.classroom_num, classroom_number);
			strcpy_s(s.name, name);

			cout << "Enter your gender:";
			cin.getline(s.gender, SIZE);
			cout << "Maths(Achieved,Progressing,Need Help):";
			cin.getline(progress, SIZE);
			while (enter_learning_progress(progress) == false)
			{
				cout << "\nType in these options only(Achieved,Progressing,Need Help).\nTry again:";
				cin.getline(progress, SIZE);
			}
			strcpy_s(s.maths, progress);

			cout << "Science(Achieved,Progressing,Need Help):";
			cin.getline(progress, SIZE);
			while (enter_learning_progress(progress) == false)
			{
				cout << "\nType in these options only(Achieved,Progressing,Need Help).\nTry again:";
				cin.getline(progress, SIZE);
			}
			strcpy_s(s.science, progress);

			cout << "Writing(Achieved,Progressing,Need Help):";
			cin.getline(progress, SIZE);
			while (enter_learning_progress(progress) == false)
			{
				cout << "\nType in these options only(Achieved,Progressing,Need Help).\nTry again:";
				cin.getline(progress, SIZE);
			}
			strcpy_s(s.writing, progress);

			cout << "Reading(Achieved,Progressing,Need Help):";
			cin.getline(progress, SIZE);
			while (enter_learning_progress(progress) == false)
			{
				cout << "\nType in these options only(Achieved,Progressing,Need Help).\nTry again:";
				cin.getline(progress, SIZE);
			}
			strcpy_s(s.reading, progress);

			cout << "Sports(Achieved,Progressing,Need Help):";
			cin.getline(progress, SIZE);
			while (enter_learning_progress(progress) == false)
			{
				cout << "\nType in these options only(Achieved,Progressing,Need Help).\nTry again:";
				cin.getline(progress, SIZE);
			}
			strcpy_s(s.sports, progress);

			cout << "Learning Progress(Achieved,Progressing,Need Help):";
			cin.getline(progress, SIZE);
			while (enter_learning_progress(progress) == false)
			{
				cout << "\nType in these options only(Achieved,Progressing,Need Help).\nTry again:";
				cin.getline(progress, SIZE);
			}
			strcpy_s(s.LearningProgress, progress);
			system("CLS");

			cout << "\nEditing student system....." << endl;
			student_stream.write(reinterpret_cast<char*>(&s), sizeof(s));
			cout << "Successfully edited student in the system....." << endl;

			student_stream.close();

			system("pause");
			system("CLS");
		}
		else
		{
			cout << "\nrecord not found\n";
		}

		
	}

	else if (classroom_number == 2)
	{

		Student s;
		cout << "Name the student you want to edit?";
		cin.getline(name, SIZE);

		student_stream.open("Room_2.dat", ios::in | ios::binary);

		ofstream ofs;
		ofs.open("temp.dat", ios::out | ios::binary);

		while (!student_stream.eof()) {

			student_stream.read(reinterpret_cast<char*>(&s), sizeof(s));

			if (student_stream)
			{
				if (strcmp(name, s.name) == 0)
				{
					flag = 1;
					cout << s.name << " 's record is going to be edited";
				}
				else
				{
					ofs.write(reinterpret_cast<char*>(&s), sizeof(s));
				}
			}
		}
		ofs.close();
		student_stream.close();

		remove("Room_2.dat");

		rename("temp.dat", "Room_2.dat");

		if (flag == 1)
		{
			cout << "\nEnter new values\n";

			student_stream.open("Room_2.dat", ios::out | ios::app | ios::binary);

			char classroom_number[SIZE] = "2";
			strcpy_s(s.classroom_num, classroom_number);
			strcpy_s(s.name, name);

			cout << "Enter your gender:";
			cin.getline(s.gender, SIZE);
			cout << "Maths(Achieved,Progressing,Need Help):";
			cin.getline(progress, SIZE);
			while (enter_learning_progress(progress) == false)
			{
				cout << "\nType in these options only(Achieved,Progressing,Need Help).\nTry again:";
				cin.getline(progress, SIZE);
			}
			strcpy_s(s.maths, progress);

			cout << "Science(Achieved,Progressing,Need Help):";
			cin.getline(progress, SIZE);
			while (enter_learning_progress(progress) == false)
			{
				cout << "\nType in these options only(Achieved,Progressing,Need Help).\nTry again:";
				cin.getline(progress, SIZE);
			}
			strcpy_s(s.science, progress);

			cout << "Writing(Achieved,Progressing,Need Help):";
			cin.getline(progress, SIZE);
			while (enter_learning_progress(progress) == false)
			{
				cout << "\nType in these options only(Achieved,Progressing,Need Help).\nTry again:";
				cin.getline(progress, SIZE);
			}
			strcpy_s(s.writing, progress);

			cout << "Reading(Achieved,Progressing,Need Help):";
			cin.getline(progress, SIZE);
			while (enter_learning_progress(progress) == false)
			{
				cout << "\nType in these options only(Achieved,Progressing,Need Help).\nTry again:";
				cin.getline(progress, SIZE);
			}
			strcpy_s(s.reading, progress);

			cout << "Sports(Achieved,Progressing,Need Help):";
			cin.getline(progress, SIZE);
			while (enter_learning_progress(progress) == false)
			{
				cout << "\nType in these options only(Achieved,Progressing,Need Help).\nTry again:";
				cin.getline(progress, SIZE);
			}
			strcpy_s(s.sports, progress);

			cout << "Learning Progress(Achieved,Progressing,Need Help):";
			cin.getline(progress, SIZE);
			while (enter_learning_progress(progress) == false)
			{
				cout << "\nType in these options only(Achieved,Progressing,Need Help).\nTry again:";
				cin.getline(progress, SIZE);
			}
			strcpy_s(s.LearningProgress, progress);
			system("CLS");

			cout << "\nEditing student system....." << endl;
			student_stream.write(reinterpret_cast<char*>(&s), sizeof(s));
			cout << "Successfully edited student in the system....." << endl;

			student_stream.close();

			system("pause");
			system("CLS");
		}
		else
		{
			cout << "\nrecord not found\n";
		}

		
	}

	else
	{
	cout << "\nOnly two classrroms available\n";
    }
}

void update_student(fstream& student_stream)
{
	char progress[SIZE];

	int flag = 0;
	char name[SIZE];
	int classroom_number;

	cout << "Enter the classroom number:";
	cin >> classroom_number;
	cin.ignore();

	if (classroom_number == 1)
	{

		Student s;
		cout << "Name the student you want to update?";
		cin.getline(name, SIZE);

		student_stream.open("Room_1.dat", ios::in | ios::binary);

		ofstream ofs;
		ofs.open("temp.dat", ios::out | ios::binary);

		while (!student_stream.eof()) {

			student_stream.read(reinterpret_cast<char*>(&s), sizeof(s));

			if (student_stream)
			{
				if (strcmp(name, s.name) == 0)
				{
					flag = 1;
					cout << s.name << " 's record is going to be updated";
				}
				else
				{
					ofs.write(reinterpret_cast<char*>(&s), sizeof(s));
				}
			}
		}
		ofs.close();
		student_stream.close();

		remove("Room_1.dat");

		rename("temp.dat", "Room_1.dat");

		if (flag == 1)
		{
			cout << "\nEnter updated values\n";

			student_stream.open("Room_1.dat", ios::out | ios::app | ios::binary);

			char classroom_number[SIZE] = "1";
			strcpy_s(s.classroom_num, classroom_number);
			strcpy_s(s.name, name);

			cout << "Enter your gender:";
			cin.getline(s.gender, SIZE);
			cout << "Maths(Achieved,Progressing,Need Help):";
			cin.getline(progress, SIZE);
			while (enter_learning_progress(progress) == false)
			{
				cout << "\nType in these options only(Achieved,Progressing,Need Help).\nTry again:";
				cin.getline(progress, SIZE);
			}
			strcpy_s(s.maths, progress);

			cout << "Science(Achieved,Progressing,Need Help):";
			cin.getline(progress, SIZE);
			while (enter_learning_progress(progress) == false)
			{
				cout << "\nType in these options only(Achieved,Progressing,Need Help).\nTry again:";
				cin.getline(progress, SIZE);
			}
			strcpy_s(s.science, progress);

			cout << "Writing(Achieved,Progressing,Need Help):";
			cin.getline(progress, SIZE);
			while (enter_learning_progress(progress) == false)
			{
				cout << "\nType in these options only(Achieved,Progressing,Need Help).\nTry again:";
				cin.getline(progress, SIZE);
			}
			strcpy_s(s.writing, progress);

			cout << "Reading(Achieved,Progressing,Need Help):";
			cin.getline(progress, SIZE);
			while (enter_learning_progress(progress) == false)
			{
				cout << "\nType in these options only(Achieved,Progressing,Need Help).\nTry again:";
				cin.getline(progress, SIZE);
			}
			strcpy_s(s.reading, progress);

			cout << "Sports(Achieved,Progressing,Need Help):";
			cin.getline(progress, SIZE);
			while (enter_learning_progress(progress) == false)
			{
				cout << "\nType in these options only(Achieved,Progressing,Need Help).\nTry again:";
				cin.getline(progress, SIZE);
			}
			strcpy_s(s.sports, progress);

			cout << "Learning Progress(Achieved,Progressing,Need Help):";
			cin.getline(progress, SIZE);
			while (enter_learning_progress(progress) == false)
			{
				cout << "\nType in these options only(Achieved,Progressing,Need Help).\nTry again:";
				cin.getline(progress, SIZE);
			}
			strcpy_s(s.LearningProgress, progress);
			system("CLS");

			cout << "\nUpdating student in the system....." << endl;
			student_stream.write(reinterpret_cast<char*>(&s), sizeof(s));
			cout << "Successfully updated student in the system....." << endl;

			student_stream.close();

			system("pause");
			system("CLS");
		}
		else
		{
			cout << "\nrecord not found\n";
		}


	}

	else if (classroom_number == 2)
	{

		Student s;
		cout << "Name the student you want to update?";
		cin.getline(name, SIZE);

		student_stream.open("Room_2.dat", ios::in | ios::binary);

		ofstream ofs;
		ofs.open("temp.dat", ios::out | ios::binary);

		while (!student_stream.eof()) {

			student_stream.read(reinterpret_cast<char*>(&s), sizeof(s));

			if (student_stream)
			{
				if (strcmp(name, s.name) == 0)
				{
					flag = 1;
					cout << s.name << " 's record is going to be edited";
				}
				else
				{
					ofs.write(reinterpret_cast<char*>(&s), sizeof(s));
				}
			}
		}
		ofs.close();
		student_stream.close();

		remove("Room_2.dat");

		rename("temp.dat", "Room_2.dat");

		if (flag == 1)
		{
			cout << "\nEnter updated values\n";

			student_stream.open("Room_2.dat", ios::out | ios::app | ios::binary);

			char classroom_number[SIZE] = "2";
			strcpy_s(s.classroom_num, classroom_number);
			strcpy_s(s.name, name);

			cout << "Enter your gender:";
			cin.getline(s.gender, SIZE);
			cout << "Maths(Achieved,Progressing,Need Help):";
			cin.getline(progress, SIZE);
			while (enter_learning_progress(progress) == false)
			{
				cout << "\nType in these options only(Achieved,Progressing,Need Help).\nTry again:";
				cin.getline(progress, SIZE);
			}
			strcpy_s(s.maths, progress);

			cout << "Science(Achieved,Progressing,Need Help):";
			cin.getline(progress, SIZE);
			while (enter_learning_progress(progress) == false)
			{
				cout << "\nType in these options only(Achieved,Progressing,Need Help).\nTry again:";
				cin.getline(progress, SIZE);
			}
			strcpy_s(s.science, progress);

			cout << "Writing(Achieved,Progressing,Need Help):";
			cin.getline(progress, SIZE);
			while (enter_learning_progress(progress) == false)
			{
				cout << "\nType in these options only(Achieved,Progressing,Need Help).\nTry again:";
				cin.getline(progress, SIZE);
			}
			strcpy_s(s.writing, progress);

			cout << "Reading(Achieved,Progressing,Need Help):";
			cin.getline(progress, SIZE);
			while (enter_learning_progress(progress) == false)
			{
				cout << "\nType in these options only(Achieved,Progressing,Need Help).\nTry again:";
				cin.getline(progress, SIZE);
			}
			strcpy_s(s.reading, progress);

			cout << "Sports(Achieved,Progressing,Need Help):";
			cin.getline(progress, SIZE);
			while (enter_learning_progress(progress) == false)
			{
				cout << "\nType in these options only(Achieved,Progressing,Need Help).\nTry again:";
				cin.getline(progress, SIZE);
			}
			strcpy_s(s.sports, progress);

			cout << "Learning Progress(Achieved,Progressing,Need Help):";
			cin.getline(progress, SIZE);
			while (enter_learning_progress(progress) == false)
			{
				cout << "\nType in these options only(Achieved,Progressing,Need Help).\nTry again:";
				cin.getline(progress, SIZE);
			}
			strcpy_s(s.LearningProgress, progress);
			system("CLS");

			cout << "\nUpdating student system....." << endl;
			student_stream.write(reinterpret_cast<char*>(&s), sizeof(s));
			cout << "Successfully updated student in the system....." << endl;

			student_stream.close();

			system("pause");
			system("CLS");
		}
		else
		{
			cout << "\nrecord not found\n";
		}


	}

	else
	{
		cout << "\nOnly two classrroms available\n";
	}
}



bool enter_learning_progress(char *progress)
{

	/*if (progress == "Achieved" || progress == "Progressing" || progress == "Need Help")
	{
		return true;
	}
	else
	{
		return false;
	}*/
	return true;
	
}

void view_student_record(fstream& student_stream)
{
	Student s;
	char name[SIZE];
	int classroom_num;
	char reply;
	cout << "\nEnter classroom number";
	cin >> classroom_num;
	cin.ignore();
	do
	{
		if (classroom_num == 1)
		{
			bool flag = false;
			student_stream.open("room_1.dat", ios::in | ios::binary);

			if (!student_stream)
			{
				cout << "File does not exist or there is a problem opening the file";
			}
			else 
			{
				cout << "Enter the name of the student whose details you want to see: ";
				cin.getline(name, SIZE);
				cout << "\n";

				student_stream.read(reinterpret_cast<char*>(&s), sizeof(s));
				while (!student_stream.eof()) 
				{
					if (strcmp(name, s.name) == 0) 

					{
						cout << "Student Name: " << s.name << endl;
						cout << "Student Gender: " << s.gender << endl;
						cout << "Student Maths: " << s.maths << endl;
						cout << "Student Science: " << s.science << endl;
						cout << "Student Writing: " << s.writing << endl;
						cout << "Student Reading: " << s.reading << endl;
						cout << "Student Sports: " << s.sports << endl;
						cout << "Learning Progress: " << s.LearningProgress << endl;

						cout << "\n\n";
						flag = true; //Update flag is true
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
		else if (classroom_num == 2)
		{
			bool flag = false;
			student_stream.open("room_2.dat", ios::in | ios::binary);

			if (!student_stream)
			{
				cout << "File does not exist or there is a problem opening the file";
			}
			else
			{
				cout << "Enter the name of the student whose details you want to see: ";
				cin.getline(name, SIZE);
				cout << "\n";

				student_stream.read(reinterpret_cast<char*>(&s), sizeof(s));
				while (!student_stream.eof())
				{
					if (strcmp(name, s.name) == 0)

					{
						cout << "Student Name: " << s.name << endl;
						cout << "Student Gender: " << s.gender << endl;
						cout << "Student Maths: " << s.maths << endl;
						cout << "Student Science: " << s.science << endl;
						cout << "Student Writing: " << s.writing << endl;
						cout << "Student Reading: " << s.reading << endl;
						cout << "Student Sports: " << s.sports << endl;
						cout << "Learning Progress: " << s.LearningProgress << endl;

						cout << "\n\n";
						flag = true; //Update flag is true
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
			cout << "\nEnter correct value";
		}

		cout << "Do you want to view another record(y/n):";
		cin >> reply;
		cin.ignore();
	} while (reply == 'Y' || reply == 'y');


}

void child_report(fstream& parent_stream, fstream& student_stream, char* parent_name)
{
	Student s;
	char name[SIZE];
	int classroom_number;
	cout << "\nPlease enter classroom number of your child:";
	cin >> classroom_number;
	cin.ignore();
	cout << "Please enter the name of your child:";
	cin.getline(name,SIZE);
	

	bool flag = false;

	cout << "\nReport of " << parent_name << " 's child" << endl;

	if (classroom_number == 1)
	{

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
				if (strcmp(name, s.name) == 0) 
				{
					cout << "Student Name: " << s.name << endl;
						cout << "Student Gender: " << s.gender << endl;
						cout << "Student Maths: " << s.maths << endl;
						cout << "Student Science: " << s.science << endl;
						cout << "Student Writing: " << s.writing << endl;
						cout << "Student Reading: " << s.reading << endl;
						cout << "Student Sports: " << s.sports << endl;
						cout << "Learning Progress: " << s.LearningProgress << endl;


					cout << "\n\n";
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
	if (classroom_number == 2)
	{

		student_stream.open("Room_2.dat", ios::in | ios::binary);

		if (!student_stream)
		{
			cout << "File does not exist or there is a problem opening the file";
		}
		else
		{


			student_stream.read(reinterpret_cast<char*>(&s), sizeof(s));
			while (!student_stream.eof())
			{
				if (strcmp(name, s.name) == 0)
				{
					cout << "Student Name: " << s.name << endl;
					cout << "Maths: " << s.maths << endl;
					cout << "Science: " << s.science << endl;
					cout << "Reading: " << s.reading << endl;
					cout << "Writing: " << s.writing << endl;
					cout << "Sports: " << s.sports << endl;
					cout << "Learning Progress: " << s.LearningProgress << endl;

					cout << "\n\n";
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
}