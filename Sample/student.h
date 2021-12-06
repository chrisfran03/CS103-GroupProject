#pragma once
#include<iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

void display_student_record_screen(fstream& student_stream);  //function to display student record screen

void add_student(fstream& student_stream); //function to add student

void delete_student(fstream& student_stream); //function to delete student from the record

void edit_student(fstream& student_stream);  //function to edit a student in the record

void update_student(fstream& student_stream); //function to update the student record

bool enter_learning_progress(char *progress);  //function to check for the user input for learning progress

void view_student_record(fstream& student_stream);  //function to view the student record

void child_report(fstream& parent_stream, fstream& student_stream, char* parent_name);  //function to view the child report for parent