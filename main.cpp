#include <iostream>
#include "Database.h"
#include "KVBST.h"
#include "FileError.h"
using namespace std;

int main(int argc, char ** argv){


  FileError* FE; /* used to check file input */
  if(argc > 1){  /* if console argument provided */
    FE = new FileError(argv[1]);

    if(FE->pass() == false){
      while(true){
        FE->setFile(FE->getFile());
        if(FE->pass()) break;
      }
    }
  }
  else { /* if no console argument provided - get file name */
    FE = new FileError();

    if(FE->pass() == false){
      while(true){
        FE->setFile(FE->getFile());
        if(FE->pass()) break;
      }
    }
  }
  /* at this point, the user inputted file is valid */
  string file = FE->getFileValue();

  Database *db = new Database(file);

  db->processFile();

  // db->addFaculty(22, "rene", "prof", "cs");
  // db->addFaculty(3, "moshier", "prof", "math");
  // db->addFaculty(11, "harrison", "prof", "cs");
  // db->addFaculty(91, "stevens", "prof", "math");
  // db->deleteFaculty(11);
  //
  // db->addStudent(31, "krishna", "junior", "avfx/cs", 3.5, 22);
  // db->addStudent(43, "tarek", "junior", "cs", 3.5, 3);
  // db->addStudent(15, "zzzz", "junior", "avfx/cs", 3.5, 22);
  // db->printFacultyAdvisees(22);
  // db->deleteStudent(31);
  // db->deleteFaculty(22);
  db->removeAdvisee(22, 31);

  // db->printFacultyAdvisees(22);
  // db->removeAdvisee(22, 31);
  // db->printFacultyAdvisees(22);
  cout << "------------------------------------------" << endl;
  db->printFaculty();
  cout << "------------------------------------------" << endl;
  db->printStudents();
  cout << "------------------------------------------" << endl;
  // cout << "-------students-------" << endl;
  // db->printStudents();
  // cout << "-------faculty-------" << endl;
  // db->printFaculty();
  delete db;

  return 0;
}
