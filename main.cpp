// #include <iostream>
// #include "BST.h"
// #include "Affiliate.h"
// #include "Student.h"
// #include "Faculty.h"
// #include "GenLinkedList.h"
// using namespace std;
#include "Database.h"
#include "KVBST.h"
using namespace std;

int main(int argc, char ** argv){

  // testing BST w/ numbers
  // KVBST<int>* bstNumbers = new KVBST<int>();
  //
  // cout << "Is Empty: " << bstNumbers->isEmpty() << endl;
  // cout << "Searching for 5: " << bstNumbers->searchNode(5) << endl;
  //
  // // tested insert ok
  // bstNumbers->insertNode(2,5);
  // bstNumbers->insertNode(1,2);
  // bstNumbers->insertNode(5,7);
  // bstNumbers->insertNode(3,8);
  // bstNumbers->insertNode(4,6);
  // bstNumbers->insertNode(6,7);
  // cout << "Printing Tree..." << endl;
  // bstNumbers->printTree();
  // cout << endl;
  //
  // // tested aux functions ok
  // cout << "Is Empty: " << bstNumbers->isEmpty() << endl;
  // cout << "Get Max " << bstNumbers->getMax() << endl;
  // cout << "Get Min " << bstNumbers->getMin() << endl;
  // cout << "Searching for 5: " << bstNumbers->searchNode(5) << endl;
  // // tested getNode ok
  // cout << "Get Node 5 value: " << bstNumbers->getNode(5) << endl;
  // // tested deleteNode ok
  // cout << "Deleting Node 4: "<< bstNumbers->deleteNode(4) << endl;
  //
  // cout << "Printing Tree..." << endl;
  // bstNumbers->printTree();
  // cout << endl;
  //
  // delete bstNumbers;

  Database *db = new Database();

  db->addFaculty(22, "rene", "prof", "cs");
  db->addFaculty(3, "moshier", "prof", "math");
  db->addFaculty(11, "harrison", "prof", "cs");
  db->addFaculty(91, "stevens", "prof", "math");
  db->deleteFaculty(11);

  db->addStudent(31, "krishna", "junior", "avfx/cs", 3.5, 22);
  db->addStudent(43, "tarek", "junior", "cs", 3.5, 3);
  db->addStudent(15, "zzzz", "junior", "avfx/cs", 3.5, 22);
  // db->deleteStudent(31);

  db->printFacultyAdvisees(22);
  db->removeAdvisee(22, 31);
  db->printFacultyAdvisees(22);
  // cout << "-------students-------" << endl;
  // db->printStudents();
  // cout << "-------faculty-------" << endl;
  // db->printFaculty();
  delete db;

  return 0;
}
