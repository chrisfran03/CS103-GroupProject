#pragma once
#include<iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

void register_parent(fstream& parent_stream);

void login_parent(fstream& parent_stream, fstream& student_stream);

bool checkUsernameParent(fstream& parent_stream, char* user_name);
