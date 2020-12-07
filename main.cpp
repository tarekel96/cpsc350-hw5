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
  Driver* driver;
  FileError* FE; /* used to check file input */
  if(argc > 1){  /* if console argument provided */
    FE = new FileError(argv[1]);

    if(FE->pass() == false){
      while(true){
        FE->setFile(FE->getFile());
        if(FE->pass()) break;
      }
    }
    string file = FE->getFileValue();
    driver = new Driver(file);
  }
  else { /* if no console argument provided */
    driver = new Driver();
  }

  delete FE;
  delete driver;

  return 0;
}
