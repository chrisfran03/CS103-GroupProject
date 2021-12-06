#pragma once
#include<iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

void display_admin_screen();  //function to display admin screen 

void display_class_records(fstream&  student_stream); //function to display class records

void display_parent_records(fstream& parent_stream);  //function to display parent record

void report_need_help(fstream& student_stream, fstream& parent_stream, fstream& teacher_stream);  //function to display the record of students who need help

void report_progressing(fstream& student_stream, fstream& parent_stream ,fstream& teacher_stream);  //function to display the record of students who are progressing

void get_teacher_name(fstream& teacher_stream,int class_num);  //function to get the teacher name in the admin report for students who need help and who are progressing

void get_parent_number(fstream& parent_stream, char *child_name);