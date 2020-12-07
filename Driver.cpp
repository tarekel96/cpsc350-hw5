#include "Driver.h"

//constructs a driver
Driver::Driver(){
  m_file = "";
  DB = new Database();
  cout << "Enter the name of file where the Database will be saved to: ";
  string file = IE.getStringInput();
  setFile(file);
  int choice = -1;
  while(choice != 14){
    choice = promptChoice();
    handleChoice(choice);
  }
}
//driver with a new file in it
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
//process a file based on substrings
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
//print the database in its entirety
void Driver::printDB(){
  if((DB->studentDatabaseIsEmpty()) && (DB->facultyDatabaseIsEmpty())){
    cout << "Database is empty. There are no students or faculty." << endl;
  }
  else {
    printStudents();
    printFaculty();
  }
}
//print students
void Driver::printStudents(){
  if(DB->studentDatabaseIsEmpty() == false) DB->printStudents();
  else cout << "Message: The database does not contain any students\n";
}
//print faculty
void Driver::printFaculty(){
  if(DB->facultyDatabaseIsEmpty() == false) DB->printFaculty();
  else cout << "Message: The database does not contain any faculty members\n";
}
//print choices
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
  choice = IE.getIntegerInput(1);
  return choice;
}
//switch case to act on upon choice given
void Driver::handleChoice(int choice){
  switch (choice) {
  case 1:
    printStudents();
    break;
  case 2:
    printFaculty();
    break;
  case 3:
    DB->findStudent(promptValidIdNumber(true));
    break;
  case 4:
    DB->findFaculty(promptValidIdNumber(false));
    break;
  case 5:
    DB->printStudentAdvisor(promptValidIdNumber(true));
    break;
  case 6:
    DB->printFacultyAdvisees(promptValidIdNumber(false));
    break;
  case 7:
    promptNewStudentInfo();
    break;
  case 8:
    DB->deleteStudent(promptValidIdNumber(true), false);
    break;
  case 9:
    promptNewFacultyMemberInfo();
    break;
  case 10:
    DB->deleteFaculty(promptValidIdNumber(false));
    break;
  case 11:
    DB->changeAdvisor(promptValidIdNumber(true), promptValidIdNumber(false));
    break;
  case 12:
    DB->removeAdvisee(DB->promptValidIdNumber(false), DB->promptValidIdNumber(true), true);
    break;
  case 13:
    DB->rollback();
    break;
  case 14:
    exitAndSave();
    break;
  default:
    cout << "ERROR: Input did not match any of the choices. Please follow directions." << endl;
    break;
  }
}
//get  a new id number
int Driver::promptNewIdNumber(bool student){
  int id = -1;
  student ? cout << "Enter the Student ID number: \n" : cout << "Enter the Faculty Member ID number: \n";
  while(true){
    id = IE.getIntegerInput(1);
    if(student){
      if(DB->students->searchNode(id) == true){
        cerr << "ERROR: Invalid ID. ID#: " << to_string(id) << " is already taken\nPlease enter a unique ID." << endl;
        continue;
      }
    }
    else{
      if(DB->faculty->searchNode(id) == true){
        cerr << "ERROR: Invalid ID. ID#: " << to_string(id) << " is already taken\nPlease enter a unique ID." << endl;
        continue;
      }
    }
    break;
  }
  return id;
}
//get a valid id number
int Driver::promptValidIdNumber(bool student){
  int id = -1;
  student ? cout << "Enter the Student ID number: \n" : cout << "Enter the Faculty Member ID number: \n";
  while(true){
    id = IE.getIntegerInput(1);
    if(student){
      if(DB->students->searchNode(id) == false) {
        cerr << "ERROR: Invalid ID, student does not exist." << endl;
        continue;
      }
    }
    else{
      if(DB->faculty->searchNode(id) == false) {
        cerr << "ERROR: Invalid ID, faculty member does not exist." << endl;
        continue;
      }
    }
    break;
  }
  return id;
}
//prompt info if a new student is going to be input
void Driver::promptNewStudentInfo(){
  if(DB->faculty->isEmpty()){
    cout << "ERROR: There are no faculty members in DB so cannot create student yet." << endl;
    cout << "Please create a faculty member first. Thank you." << endl;
  }
  else{
    int id, advisorId = -1;
    string name, level, major = "";
    double gpa = -1.0;
    cout << "New student needs a unique id number. ";
    id = promptNewIdNumber(true);
    cout << endl;
    cout << "New student needs a valid advisor id number. ";
    advisorId = promptValidIdNumber(false);
    cout << endl;
    cout << "Enter the name of the student: ";
    name = IE.getStringInput();
    cout << endl;
    cout << "Enter the level of the student: ";
    level = IE.getStringInput();
    cout << endl;
    cout << "Enter the major of the student: ";
    major = IE.getStringInput();
    cout << endl;
    cout << "Enter the gpa of the student: ";
    gpa = IE.getDoubleInput(0.0, 4.0);
    cout << endl;
    DB->addStudent(id, name, level, major, gpa, advisorId, true);
  }
}
//prompt for a new faculty memeber
void Driver::promptNewFacultyMemberInfo(){
  int id = -1;
  string name, level, department = "";
  double gpa = -1.0;
  cout << "New faculty member needs a unique id number. ";
  id = promptNewIdNumber(false);
  cout << endl;
  cout << "Enter the name of the faculty member: ";
  name = IE.getStringInput();
  cout << endl;
  cout << "Enter the level of the faculty member: ";
  level = IE.getStringInput();
  cout << endl;
  cout << "Enter the department of the faculty member: ";
  department = IE.getStringInput();
  cout << endl;
  DB->addFaculty(id, name, level, department, true);
}
//exit the driver
void Driver::exitAndSave(){
  outFile.open(m_file);
  outFile << DB->exit();
  outFile.close();
  cout << "SUCCESS: Program has been terminated and the Database has been saved in " << m_file << endl;
  exit(EXIT_SUCCESS);
}
