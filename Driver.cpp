#include "Driver.h"

Driver::Driver(){
  m_file = "";
  DB = new Database();
}
Driver::Driver(string file){
  m_file = file;
  DB = new Database();
  processFile();
  int choice = -1;
  while(choice != 14){
    choice = promptChoice();
    handleChoice(choice);
  }
}
Driver::~Driver(){
  if(DB != NULL) delete DB;
}
void Driver::setFile(string file){
  m_file = file;
}
void Driver::processFile(){
  inFile.open(m_file);
  string line;
  cout << "Processing File..." << endl;
  if(inFile.is_open()){
    while(getline(inFile, line)){
      int id;
      string name;
      string level;
      string department;
      string major;
      double gpa;
      int advisorId;
      id = stoi(line.substr(5,line.length()));
      getline(inFile, line);
      name = line.substr(6, line.length());
      getline(inFile, line);
      level = line.substr(7, line.length());
      getline(inFile, line);
      if(line.at(0) == 'D'){
        department = line.substr(12, line.length());
        DB->addFaculty(id, name, level, department);
      }else{
        major = line.substr(7, line.length());
        getline(inFile, line);
        gpa = stod(line.substr(5,line.length()));
        getline(inFile, line);
        advisorId = stoi(line.substr(13, line.length()));
        DB->addStudent(id, name, level, major, gpa, advisorId);
      }
      getline(inFile, line);
    }
    inFile.close();
  }
  cout << "File Successfully Processed. The current Database is now populated." << endl;
}
void Driver::printDB(){
  if((DB->studentDatabaseIsEmpty()) && (DB->facultyDatabaseIsEmpty())){
    cout << "Database is empty. There are no students or faculty." << endl;
  }
  else {
    printStudents();
    printFaculty();
  }
}
void Driver::printStudents(){
  if(DB->studentDatabaseIsEmpty() == false) DB->printStudents();
  else cout << "Message: The database does not contain any students\n";
}
void Driver::printFaculty(){
  if(DB->facultyDatabaseIsEmpty() == false) DB->printFaculty();
  else cout << "Message: The database does not contain any faculty members\n";
}
int Driver::promptChoice(){
  int choice = -1;
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
  // TODO - InputException
  cin >> choice;
  return choice;
}
void Driver::handleChoice(int choice){
  switch (choice) {
  case 1:
    printStudents();
    break;
  case 2:
    printFaculty();
    break;
  case 3:
    DB->findStudent(promptIdNumber(true));
    break;
  case 4:
    DB->findFaculty(promptIdNumber(false));
    break;
  case 5:
    DB->printStudentAdvisor(promptIdNumber(true));
    break;
  case 6:
    DB->printFacultyAdvisees(promptIdNumber(false));
    break;
  case 7:
    promptNewStudentInfo();
    break;
  }
}
int Driver::promptIdNumber(bool student){
  int id = -1;
  student ? cout << "Enter the Student ID number: \n" : cout << "Enter the Faculty Member ID number: \n";
  cin >> id;
  return id;
}
void Driver::promptNewStudentInfo(){
  int id, advisorId = -1;
  string name, level, major = "";
  double gpa = -1.0;
  cout << "Enter the id number of the student: ";
  cin >> id;
  cout << endl;
  cout << "Enter the id number of the student's advisor: ";
  cin >> advisorId;
  cout << endl;
  cout << "Enter the name of the student: ";
  cin >> name;
  cout << endl;
  cout << "Enter the level of the student: ";
  cin >> level;
  cout << endl;
  cout << "Enter the major of the student: ";
  cin >> major;
  cout << endl;
  cout << "Enter the gpa of the student: ";
  cin >> gpa;
  cout << endl;
  DB->addStudent(id, name, level, major, gpa, advisorId);
}
