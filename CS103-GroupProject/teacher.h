#pragma once
#include<iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

void register_teacher(fstream& teacher_stream);

void login_teacher(fstream& teacher_stream);

bool checkUsername(fstream& teacher_stream, char* user_name);
