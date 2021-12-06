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

//struct for student
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

//struct for parent
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



void display_student_record_screen(fstream &student_stream)  //student record screen
{
	int choice;
	system("CLS");
	while (1)
	{
		system("CLS");

		cout << "\n1.Add student record"<<endl;
		cout << "2.Edit student record"<<endl;
		cout << "3.Delete student record" << endl;
		cout << "4.Update student record" << endl;
		cout << "5.View the records" << endl;
		cout << "6.Go back" << endl;
		cout << "Enter your choice:";
		cin >> choice;

		if (choice == 1)
		{
			add_student(student_stream);  //function to add student
		}
		else if (choice == 2)
		{
			edit_student(student_stream);  //function to edit student
		}
		else if (choice == 3)
		{
			delete_student(student_stream);  //function to delete student
		}
		else if (choice == 4)
		{
			update_student(student_stream);  //function to update student
		}
		else if (choice == 5)
		{
			view_student_record(student_stream);  //function to view student
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
  
void add_student(fstream& student_stream)  //function to add student
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
		student_stream.open("Room_1.dat", ios::out | ios::app | ios::binary);  //opening the classroom the student is in

		char classroom_number[SIZE] = "1";
		strcpy_s(s.classroom_num, classroom_number);

		//user input  student details
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
	else if (classroom == 2)  //if classroom is 2
	{

		Student s;
		student_stream.open("Room_2.dat", ios::out | ios::app | ios::binary);  //opening the classroom 2 file to add student

		char classroom_number[SIZE] = "2";
		strcpy_s(s.classroom_num, classroom_number);

		//user input student details
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

void delete_student(fstream& student_stream)  //function to delete student
{
	int flag = 0;
	Student s;
	char name[SIZE];
	int classroom_number;

	cout << "Enter the classroom number:";
	cin >> classroom_number;
	cin.ignore();


	if (classroom_number == 1)  //f classroom is 2
	{

		cout << "Name the student you want to delete?"; //entering the name of the studet whom you want to delete
		cin.getline(name, SIZE);
		student_stream.open("Room_1.dat", ios::in | ios::binary);  //opening the classroom 1 file

		ofstream ofs;
		ofs.open("temp.dat", ios::out | ios::binary);  //creating a temporary file

		while (!student_stream.eof()) {

			student_stream.read(reinterpret_cast<char*>(&s), sizeof(s));

			if (student_stream)
			{
				if (strcmp(name, s.name) == 0) //if the name to be deleted exist , print its going to be deleted
				{
					flag = 1;
					cout << s.name << " 's record is going to be deleted";
				}
				else  
				{
					ofs.write(reinterpret_cast<char*>(&s), sizeof(s));  //everything else except the details of the student who is deleted gets copied to the temporary file
				}
			}
		}
		ofs.close();
		student_stream.close();  //close file

		remove("Room_1.dat"); //removing the old file in which the deleted student is in 

		rename("temp.dat", "Room_1.dat"); //renaming the temporary file to that of the old file

		if (flag == 1)
		{
			cout << "\nrecord successfully deleted\n";
		}
		else
		{
			cout << "\nrecord not found\n";
		}
	}

	if (classroom_number == 2) //if classroom is 2
	{

		cout << "Name the student you want to delete?";
		cin.getline(name, SIZE);
		student_stream.open("Room_2.dat", ios::in | ios::binary); //opening the file for classroom 2

		ofstream ofs;
		ofs.open("temp.dat", ios::out | ios::binary);  //opening a temporary file

		while (!student_stream.eof()) {

			student_stream.read(reinterpret_cast<char*>(&s), sizeof(s));

			if (student_stream)
			{
				if (strcmp(name, s.name) == 0) //if the name the user want to delete is found in the file, then print its deleted
				{
					flag = 1;
					cout << s.name << " 's record is going to be deleted";
				}
				else
				{
					ofs.write(reinterpret_cast<char*>(&s), sizeof(s));  //copy everything else to the temporary file
				}
			}
		}
		ofs.close();
		student_stream.close();

		remove("Room_2.dat"); //delete the old file with the deleted student in it

		rename("temp.dat", "Room_2.dat"); //rename the new file with the nam of old file

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

void edit_student(fstream& student_stream)  //function to edit student
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
		cout << "Name the student you want to edit?";  //ask the user which student should be edited
		cin.getline(name, SIZE);

		student_stream.open("Room_1.dat", ios::in | ios::binary);  //opening the file for class1

		ofstream ofs;
		ofs.open("temp.dat", ios::out | ios::binary); //opening a temporary file

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

		remove("Room_1.dat"); //removing the old file with the student who needs to be edited

		rename("temp.dat", "Room_1.dat"); //renaming the new file to that of the old file

		if (flag == 1)
		{
			cout << "\nEnter new values\n";

			student_stream.open("Room_1.dat", ios::out | ios::app | ios::binary);

			char classroom_number[SIZE] = "1";
			strcpy_s(s.classroom_num, classroom_number);
			strcpy_s(s.name, name);  //copying the name of the student who is going to be edited to the file
			//entering other values
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

	else if (classroom_number == 2)  //if classroom is 2 
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

void update_student(fstream& student_stream)  //function to update the student record
{
	char progress[SIZE];

	int flag = 0;
	char name[SIZE];
	char gender[SIZE];
	int classroom_number;

	cout << "Enter the classroom number:";
	cin >> classroom_number;
	cin.ignore();

	if (classroom_number == 1)
	{

		Student s;
		cout << "Name the student you want to update?"; //enter the student you want to update
		cin.getline(name, SIZE);

		student_stream.open("Room_1.dat", ios::in | ios::binary);  //opening the file for the correct classroom


		while (!student_stream.eof()) {

			student_stream.read(reinterpret_cast<char*>(&s), sizeof(s));

			if (student_stream)
			{
				if (strcmp(name, s.name) == 0)  
				{
					flag = 1;
					cout << s.name << " 's record is going to be updated (Adding another term observation)"; 
					strcpy_s(gender, s.gender);
				}
			}
		}
		student_stream.close();

		if (flag == 1)
		{
			cout << "\nEnter updated values (values of another term) \n";  //entering the updated values

			student_stream.open("Room_1.dat", ios::out | ios::app | ios::binary);

			char classroom_number[SIZE] = "1";
			strcpy_s(s.classroom_num, classroom_number);
			strcpy_s(s.name, name);
			strcpy_s(s.gender, gender);

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

			cout << "\nUpdating student(adding another term observation) in the system....." << endl;
			student_stream.write(reinterpret_cast<char*>(&s), sizeof(s));
			cout << "Successfully updated student (added another term observations) in the system....." << endl;

			student_stream.close();

			system("pause");
			system("CLS");
		}
		else
		{
			cout << "\nrecord not found\n";
		}


	}

	else if (classroom_number == 2)  //if classroom 2
	{

	Student s;
	cout << "Name the student you want to update?"; //enter the student you want to update
	cin.getline(name, SIZE);

	student_stream.open("Room_2.dat", ios::in | ios::binary);  //opening the file for the correct classroom


	while (!student_stream.eof()) {

		student_stream.read(reinterpret_cast<char*>(&s), sizeof(s));

		if (student_stream)
		{
			if (strcmp(name, s.name) == 0)
			{
				flag = 1;
				cout << s.name << " 's record is going to be updated (Adding another term observation)";
				strcpy_s(gender, s.gender);
			}
		}
	}
	student_stream.close();

	if (flag == 1)
	{
		cout << "\nEnter updated values (values of another term) \n";  //entering the updated values

		student_stream.open("Room_1.dat", ios::out | ios::app | ios::binary);

		char classroom_number[SIZE] = "1";
		strcpy_s(s.classroom_num, classroom_number);
		strcpy_s(s.name, name);
		strcpy_s(s.gender, gender);

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

		cout << "\nUpdating student(adding another term observation) in the system....." << endl;
		student_stream.write(reinterpret_cast<char*>(&s), sizeof(s));
		cout << "Successfully updated student (added another term observations) in the system....." << endl;

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

	if (strcmp(progress,"Achieved")==0 || strcmp(progress, "Progressing") == 0|| strcmp(progress, "Need Help") == 0)
	{
		return true;
	}
	else
	{
		return false;
	}

	
}

void view_student_record(fstream& student_stream)   //function to view the student record
{
	Student s;
	char name[SIZE];
	int classroom_num;
	char reply;
	cout << "\nEnter classroom number";   //input the classroom number
	cin >> classroom_num;
	cin.ignore();
	do
	{
		if (classroom_num == 1)  //if classroom is 1
		{
			bool flag = false;
			student_stream.open("room_1.dat", ios::in | ios::binary); // room 1 is opened

			if (!student_stream)
			{
				cout << "File does not exist or there is a problem opening the file";
			}
			else 
			{
				cout << "Enter the name of the student whose details you want to see: "; //input name of the student
				cin.getline(name, SIZE);
				cout << "\n";

				student_stream.read(reinterpret_cast<char*>(&s), sizeof(s));
				while (!student_stream.eof()) 
				{
					if (strcmp(name, s.name) == 0) 

					{
						//diaplaying student records
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
			student_stream.close();//close file 
		}
		else if (classroom_num == 2) //if class is 2
		{
			bool flag = false;
			student_stream.open("room_2.dat", ios::in | ios::binary); //open room 2

			if (!student_stream)
			{
				cout << "File does not exist or there is a problem opening the file";
			}
			else
			{
				cout << "Enter the name of the student whose details you want to see: ";
				cin.getline(name, SIZE);  //input name of the student
				cout << "\n";

				student_stream.read(reinterpret_cast<char*>(&s), sizeof(s));
				while (!student_stream.eof())
				{
					if (strcmp(name, s.name) == 0)

					{
						//display student records
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
			student_stream.close(); //close file
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

void child_report(fstream& parent_stream, fstream& student_stream, char* parent_name) //view child report for parent
{
	Student s;
	Parent p;
	char name[SIZE];
	char child_name[SIZE];
	int classroom_number;
	cout << "\nPlease enter classroom number of your child:";  
	cin >> classroom_number;
	cin.ignore();
	cout << "\nPlease enter the name of your child:";
	cin.getline(child_name, SIZE);
	bool flag = false;

	

	cout << "\nReport of " << parent_name << " 's child" << endl;

	if (classroom_number == 1)
	{

			student_stream.open("Room_1.dat", ios::in | ios::binary);  //opening the classroom file to get the student details

			if (!student_stream)
			{
				cout << "File does not exist or there is a problem opening the file";  //error message if we dont find the file
			}
			else
			{

				student_stream.read(reinterpret_cast<char*>(&s), sizeof(s));  //reading the file
				while (!student_stream.eof())
				{
					if (strcmp(child_name, s.name) == 0)
					{
						//displaying student details
						cout << "Student Name: " << s.name << endl;
						cout << "Student Gender: " << s.gender << endl;
						cout << "Student Maths: " << s.maths << endl;
						cout << "Student Science: " << s.science << endl;
						cout << "Student Writing: " << s.writing << endl;
						cout << "Student Reading: " << s.reading << endl;
						cout << "Student Sports: " << s.sports << endl;
						cout << "Learning Progress: " << s.LearningProgress << endl<<endl;


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
			student_stream.close();  //closing the file to prevent memory leakage 
		
	
	}
	else if (classroom_number == 2)
	{

		
			student_stream.open("Room_2.dat", ios::in | ios::binary); //opening classroom 2 

			if (!student_stream)
			{
				cout << "File does not exist or there is a problem opening the file";
			}
			else
			{

				student_stream.read(reinterpret_cast<char*>(&s), sizeof(s));
				while (!student_stream.eof())
				{
					if (strcmp(child_name, s.name) == 0) //checking if the student names match
					{
						//displaying student details
						cout << "Student Name: " << s.name << endl;
						cout << "Student Gender: " << s.gender << endl;
						cout << "Student Maths: " << s.maths << endl;
						cout << "Student Science: " << s.science << endl;
						cout << "Student Writing: " << s.writing << endl;
						cout << "Student Reading: " << s.reading << endl;
						cout << "Student Sports: " << s.sports << endl;
						cout << "Learning Progress: " << s.LearningProgress << endl << endl;


						cout << "\n\n";
						flag = true;
					}
					student_stream.read(reinterpret_cast<char*>(&s), sizeof(s));
				}



				if (flag == false)
				{
					cout << "\n No records for the student/parent found\n";
				}



			}
			student_stream.close();  //closing the file
		
	}
	else
	{
	cout << "\nOnly two classrooms available!"<<endl;
    }
}