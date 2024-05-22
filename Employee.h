#pragma once
#include <iostream>

using namespace std;

class Employee{
private:
    string name;
public:
    string position;
    unsigned int age;
    Employee();
    Employee(string givenName, string givenPosition, unsigned int givenge);
    friend ostream& operator<< (ostream& o, const Employee& emp);
};

Employee::Employee(){
    name = "N/A";
    position = "N/A";
    age = 0;
}

Employee::Employee(string givenName, string givenPosition, unsigned int givenAge){
    name = givenName;
    position = givenPosition;
    age = givenAge;
}

ostream& operator<<(ostream& o, const Employee& emp){
    o << emp.name << " ";
    o << emp.position << " ";
    o << emp.age;
    return o;
}

