#include <iostream>
#include "KVBST.h"
#include "FileError.h"
#include "Driver.h"
#include "Undo.h"
#include "Action.h"
#include "Student.h"
#include "Faculty.h"
#include "Affiliate.h"
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

  return 0;
}
