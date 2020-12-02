#ifndef INPUTEXCEPTION_H
#define INPUTEXCEPTION_H
#include <exception>
#include <iostream>
using namespace std;
class InputException: public exception{
  private:
    string message;
  public:
    InputException();
    ~InputException();
    int getIntegerInput();
};
#endif
