#pragma once
#include <iostream>

using namespace std;

class keyDoesNotExistException : public exception{
private:
    string message = "Key Does Not Exist:";
public:
    keyDoesNotExistException(unsigned int Key);
    keyDoesNotExistException(const string msg);
    const char* what();
};

keyDoesNotExistException::keyDoesNotExistException(unsigned int Key){
    string msg = to_string(Key);
    this->message += msg;
}

keyDoesNotExistException::keyDoesNotExistException(const string msg = ""){
    this->message += msg;
}

const char* keyDoesNotExistException::what(){
    return (this->message).c_str();
}
