// #include <iostream>
// #include "BST.h"
// #include "Affiliate.h"
// #include "Student.h"
// #include "Faculty.h"
// #include "GenLinkedList.h"
// using namespace std;
#include "Database.h"

int main(int argc, char ** argv){
  Database *db = new Database();
  db->addStudent(31, "krishna", "junior", "avfx/cs", 3.5, 22);
  db->addStudent(43, "tarek", "junior", "cs", 3.5, 3);
  db->addStudent(15, "zzzz", "junior", "avfx/cs", 3.5, 4);
  db->deleteStudent(31); //doesn't delete


  db->addFaculty(22, "rene", "prof", "cs");
  db->addFaculty(3, "moshier", "prof", "math");
  db->addFaculty(11, "harrison", "prof", "cs");
  db->addFaculty(91, "stevens", "prof", "math");
  db->deleteFaculty(11); // deletes the wrong node

  cout << "-------students-------" << endl;
  db->printStudents();
  cout << "--------------" << endl;
  db->printFaculty();
  cout << "-------faculty-------" << endl;

  delete db;

  return 0;
}
