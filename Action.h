#ifndef ACTION_H
#define ACTION_H
#include <iostream>
#include <string>
#include "Affiliate.h"
using namespace std;
enum class Type {CREATE, READ, UPDATE, DELETE, UNASSIGNED};
class Action{
  private:
    int m_id;
    Type m_type;
    Affiliate* m_affiliate;
  public:
    Action();
    Action(Affiliate* affiliate, Type type);
    ~Action();

    Affiliate* getAffiliate();
    Type getType();
    string typeToString(Type type);
    string toString();
};
#endif
/*
cout << "Please pick from one of the following integer options (1-14): " << endl;
cout << "1) ************* View all Students (and their info) from Database" << endl;
cout << "2) ************* View all Faculty (and their info) from Database" << endl;
cout << "3) ************* Find Student by ID (and display their info) from Database" << endl;
cout << "4) ************* Find Faculty by ID (and display their info) from Database" << endl;
cout << "5) ************* Given a Student’s ID, print the name and info of their Faculty advisor" << endl;
cout << "6) ************* Given a Faculty ID, print ALL the names and info of his/her advisees." << endl;
cout << "7) ************* Add a new Student" << endl;
cout << "8) ************* Delete a Student by ID" << endl;
cout << "9) ************* Add a new Faculty member" << endl;
cout << "10) ************ Delete a Faculty member given the ID" << endl;
cout << "11) ************ Change a Student's advisor given the Student ID and the new Faculty ID" << endl;
cout << "12) ************ Remove an advisee from a Faculty member given the IDs" << endl;
cout << "13) ************ Rollback" << endl;
cout << "14) ************ Exit" << endl;
*/
