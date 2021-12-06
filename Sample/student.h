#pragma once
#include<iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

void display_student_record_screen(fstream& student_stream);

void add_student(fstream& student_stream);

void delete_student(fstream& student_stream);

void edit_student(fstream& student_stream);

void update_student(fstream& student_stream);

bool enter_learning_progress(char *progress);

void view_student_record(fstream& student_stream);

void child_report(fstream& parent_stream, fstream& student_stream, char* parent_name);