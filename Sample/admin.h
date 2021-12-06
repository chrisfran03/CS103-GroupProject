#pragma once
#include<iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

void display_admin_screen();

void display_class_records(fstream&  student_stream);

void display_parent_records(fstream& parent_stream);

void report_need_help(fstream& student_stream);

void report_progressing(fstream& student_stream);