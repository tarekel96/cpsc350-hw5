#include <iostream>
#include "Database.h"
#include "KVBST.h"
#include "FileError.h"
#include "Driver.h"
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

  Driver* driver = new Driver(file);

  delete driver;
  // Database *db = new Database(file);
  //
  // db->processFile();
  //
  // db->printFacultyAdvisees(3);
  // db->deleteFaculty(22);
  // cout << "------------------------------------------" << endl;
  // db->printFacultyAdvisees(3);
  // cout << "------------------------------------------" << endl;
  // db->printFacultyAdvisees(91);
  // db->deleteStudent(44);
  // cout << "------------------------------------------" << endl;
  // db->printFacultyAdvisees(91);
  // delete db;

  return 0;
}
