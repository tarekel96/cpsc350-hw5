#include <iostream>
using namespace std;
#include <fstream>
#include <string>

class FileProcessor{
  private:
    string file;

  public:
    FileProcessor();
    ~FileProcessor();
};

FileProcessor::FileProcessor(string f){
  file = f;
}

FileProcessor::~FileProcessor(){}

void FileProcessor::process(KVBST* faculty, KVBST* students){

}
