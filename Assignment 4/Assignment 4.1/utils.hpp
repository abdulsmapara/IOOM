#ifndef UTILS_HPP_INCLUDED
#define UTILS_HPP_INCLUDED
#include "defines.hpp"
#include <iostream>
#include <string>
std::string i_to_dept(Department dept); 
void display_dept();
void assign_dept(Department& dept,int val);
std::string i_to_type(Type type);
void assign_type(Type& type,int val);
void display_types();
#endif