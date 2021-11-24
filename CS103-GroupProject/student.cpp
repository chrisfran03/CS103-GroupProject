#include<iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <map>
#include <stdlib.h>
#include "student.h"

using namespace std;

void StudentRecordProcess()
{
	cout << "1.Add student" << endl;
	cout << "2.Edit student record" << endl;
	cout << "3.Delete student record" << endl;
	cout << "4.Update record " << endl;
	cout << "5.View Records" << endl;

	int choice = 0;
	cout << "give me your choice:"; cin >> choice;
	cin.ignore();

	map<string, string> student;
	switch (choice)
	{
	case 1:
	{
		cout << "name:";
		getline(cin, student["name"]);
		cout << "gender:";
		getline(cin, student["gender"]);
		cout << "maths:";
		getline(cin, student["maths"]);
		cout << "science:";
		getline(cin, student["science"]);
		cout << "writing:";
		getline(cin, student["writing"]);
		cout << "reading:";
		getline(cin, student["reading"]);
		cout << "sports:";
		getline(cin, student["sports"]);
		cout << "learning_progress:";
		getline(cin, student["learning_progress"]);

		string classRoomName;
		cout << "class room:";
		getline(cin, classRoomName);
		fstream classRoom(classRoomName + ".txt", fstream::app | fstream::binary);
		for (auto& it : student)
		{
			char field[64] = { '\0' };
			strcpy_s(field, it.second.c_str());
			classRoom.write(field, sizeof(field));
		}
		break;
	}
	case 4:
	case 2:
	{
		map<string, map<string, string>> students;

		string name;
		cout << "student name:";
		getline(cin, name);

		string classRoomName;
		cout << "Classroom:";
		getline(cin, classRoomName);

		fstream classRoom(classRoomName + ".txt", fstream::in | fstream::out | fstream::binary);
		while (!classRoom.eof())
		{
			char field[64] = { '\0' };
			classRoom.read(field, sizeof(field));
			student["name"] = field;

			memset(field, 0, sizeof(field));
			classRoom.read(field, sizeof(field));
			student["gender"] = field;

			memset(field, 0, sizeof(field));
			classRoom.read(field, sizeof(field));
			student["maths"] = field;

			memset(field, 0, sizeof(field));
			classRoom.read(field, sizeof(field));
			student["science"] = field;

			memset(field, 0, sizeof(field));
			classRoom.read(field, sizeof(field));
			student["writing"] = field;

			memset(field, 0, sizeof(field));
			classRoom.read(field, sizeof(field));
			student["reading"] = field;

			memset(field, 0, sizeof(field));
			classRoom.read(field, sizeof(field));
			student["sports"] = field;

			memset(field, 0, sizeof(field));
			classRoom.read(field, sizeof(field));
			student["learning_progress"] = field;

			students[student["name"]] = student;
		}

		string editedStudentName;
		cout << "who will be edited?";
		getline(cin, editedStudentName);

		string fieldName;
		cout << "field name:";
		getline(cin, fieldName);

		string newValue;
		cout << "new value:";
		getline(cin, newValue);

		students[editedStudentName][fieldName] = newValue;
		classRoom.close();
		classRoom.open(classRoomName + ".txt", fstream::out | fstream::trunc | fstream::binary);

		for (auto& i : students)
		{
			for (auto& it : i.second)
			{
				char field[64] = { '\0' };
				strcpy_s(field, it.second.c_str());
				classRoom.write(field, sizeof(field));
			}
		}

		break;
	}
	case 3:
	{
		map<string, map<string, string>> students;

		string name;
		cout << "student name:";
		getline(cin, name);

		string classRoomName;
		cout << "Classroom:";
		getline(cin, classRoomName);

		fstream classRoom(classRoomName + ".txt", fstream::in | fstream::out | fstream::binary);
		while (!classRoom.eof())
		{
			char field[64] = { '\0' };
			classRoom.read(field, sizeof(field));
			student["name"] = field;

			memset(field, 0, sizeof(field));
			classRoom.read(field, sizeof(field));
			student["gender"] = field;

			memset(field, 0, sizeof(field));
			classRoom.read(field, sizeof(field));
			student["maths"] = field;

			memset(field, 0, sizeof(field));
			classRoom.read(field, sizeof(field));
			student["science"] = field;

			memset(field, 0, sizeof(field));
			classRoom.read(field, sizeof(field));
			student["writing"] = field;

			memset(field, 0, sizeof(field));
			classRoom.read(field, sizeof(field));
			student["reading"] = field;

			memset(field, 0, sizeof(field));
			classRoom.read(field, sizeof(field));
			student["sports"] = field;

			memset(field, 0, sizeof(field));
			classRoom.read(field, sizeof(field));
			student["learning_progress"] = field;

			students[student["name"]] = student;
		}

		string delStudentName;
		cout << "who will be delete?";
		getline(cin, delStudentName);

		students.erase(delStudentName);
		classRoom.close();
		classRoom.open(classRoomName + ".txt", fstream::out | fstream::trunc | fstream::binary);
		for (auto& i : students)
		{
			for (auto& it : i.second)
			{
				char field[64] = { '\0' };
				strcpy_s(field, it.second.c_str());
				classRoom.write(field, sizeof(field));
			}
		}
		break;
	}
	case 5:
	{
		map<string, map<string, string>> students;

		string name;
		cout << "student name:";
		getline(cin, name);

		string classRoomName;
		cout << "Classroom:";
		getline(cin, classRoomName);

		fstream classRoom(classRoomName + ".txt", fstream::in | fstream::out | fstream::binary);
		while (!classRoom.eof())
		{
			char field[64] = { '\0' };
			classRoom.read(field, sizeof(field));
			student["name"] = field;

			memset(field, 0, sizeof(field));
			classRoom.read(field, sizeof(field));
			student["gender"] = field;

			memset(field, 0, sizeof(field));
			classRoom.read(field, sizeof(field));
			student["maths"] = field;

			memset(field, 0, sizeof(field));
			classRoom.read(field, sizeof(field));
			student["science"] = field;

			memset(field, 0, sizeof(field));
			classRoom.read(field, sizeof(field));
			student["writing"] = field;

			memset(field, 0, sizeof(field));
			classRoom.read(field, sizeof(field));
			student["reading"] = field;

			memset(field, 0, sizeof(field));
			classRoom.read(field, sizeof(field));
			student["sports"] = field;

			memset(field, 0, sizeof(field));
			classRoom.read(field, sizeof(field));
			student["learning_progress"] = field;

			students[student["name"]] = student;
		}

		string viewedStudentName;
		cout << "who will be view?";
		getline(cin, viewedStudentName);

		for (auto& it : students[viewedStudentName])
		{
			cout << it.second << endl;
		}
		break;
	}
	default:
		break;
	}

}