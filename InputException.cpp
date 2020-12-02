#include "InputException.h"

InputException::InputException(){}
InputException::~InputException(){}
int InputException::getIntegerInput(){
  int response = -1;
  while(true){
    if(cin.fail()){
      cerr << "ERROR: INVALID INPUT - PLEASE FOLLOW DIRECTIONS" << endl;
      cin.clear();
      cin.ignore(10000,'\n');
      continue;
    }
    else{
      cin >> response;
      break;
    }
  }
  return response;
}
string InputException::getStringInput(){
  string response = "";
  while(true){
    if(cin.fail()){
      cerr << "ERROR: INVALID INPUT - PLEASE FOLLOW DIRECTIONS" << endl;
      cin.clear();
      cin.ignore(10000,'\n');
      continue;
    }
     else{
       cin >> response;
       break;
    }
  }
  return response;
}
double InputException::getDoubleInput(){
  double response = -1.0;
  while(true){
    if(cin.fail()){
      cerr << "ERROR: INVALID INPUT - PLEASE FOLLOW DIRECTIONS" << endl;
      cin.clear();
      cin.ignore(10000,'\n');
      continue;
    }
    else{
      cin >> response;
      break;
    }
  }
  return response;
}
