#ifndef DRIVER_H
#define DRIVER_H
#include <iostream>
#include <fstream>
#include <string>
#include "Database.h"
using namespace std;
class Driver{
  private:
    string m_file;
    Database* DB;
    ifstream inFile;
    ofstream outFile;
  public:
    Driver();
    Driver(string file);
    ~Driver();

    void setFile(string file);

    void processFile(); /* populates DB field with info - if file is provided */
    void printDB(); /* prints out the students BST and the faculty BST within DB */
    void printStudents();
    void printFaculty();
    int promptChoice();
    void handleChoice(int choice);
    int promptIdNumber(bool student);
    void promptNewStudentInfo();
    void promptNewFacultyMemberInfo();
};
#endif
