#include "Database.h"
#include <fstream>
#include <string>

Database::Database(){
  faculty = new KVBST<Faculty*>();
  students = new KVBST<Student*>();
  undo = new Undo();
}

Database::~Database(){
  delete faculty;
  delete students;
  delete undo;
}

void Database::printStudents(){
  students->printTree(true);
}

void Database::printFaculty(){
  faculty->printTree(true);
}

void Database::findStudent(int id){
  if(students->searchNode(id)){
    cout << students->getNode(id)->toString() << endl;
  }else{
    cout << "student does not exist" << endl;
  }
}

void Database::findFaculty(int id){
  if(faculty->searchNode(id)){
    cout << faculty->getNode(id)->toString() << endl;
  }else{
    cout << "faculty does not exist" << endl;
  }
}

void Database::printStudentAdvisor(int id){
  int advisorId = students->getNode(id)->getAdvisorId();
  findFaculty(advisorId);
}
// changes the advisor of the given id student to the provided the faculty member id
void Database::changeAdvisor(int studentId, int facultyId){
  // check student exists
  if(students->searchNode(studentId)){
    // check faculty exists
    if(faculty->searchNode(facultyId)){
      // deletes the student id from list of student IDs
      removeAdvisee(students->getNode(studentId)->getAdvisorId(), studentId, true);
      // find the new advisor and add the student to their list of student IDs
      faculty->getNode(facultyId)->addAdvisee(studentId);
      // update advisor field for the Student instance
      students->getNode(studentId)->setAdvisorId(facultyId);
    }else{
      cout << "faculty does not exist" << endl;
    }
  }else{
    cout << "student does not exist" << endl;
  }
}

void Database::printFacultyAdvisees(int id){
  //loop through the faculty advisee list and print using findStudent
  if(faculty->searchNode(id)){
    for(int i = 0; i < faculty->getNode(id)->getListSize(); ++i){
      cout << students->getNode(faculty->getNode(id)->getStudentId(i))->toString() << endl;
    }
  }else{
    cout << "faculty does not exist" << endl;
  }
}

//
void Database::removeAdvisee(int facultyId, int studentId, bool needReplaceAdvisor){
  bool facultyHasStudent = faculty->getNode(facultyId)->hasAdvisee(studentId);
  if(facultyHasStudent == false){
        cerr << "ERROR: Faculty ID#: " << to_string(facultyId) << " does not have the student ID#: " << to_string(studentId) << endl;
        cout << "Please enter a valid student ID to remove from Faculty Member ID# " << to_string(facultyId) << ": ";
  }
  while(facultyHasStudent == false){
    studentId = promptValidIdNumber(true);
    facultyHasStudent = faculty->getNode(facultyId)->hasAdvisee(studentId);
    if(facultyHasStudent == false){
      cerr << "ERROR: Faculty ID#: " << to_string(facultyId) << " does not have the student ID#: " << to_string(studentId) << endl;
      cout << "Please enter a valid student ID to remove from Faculty Member ID# " << to_string(facultyId) << endl;
    }
    else break;
  }
  if(faculty->searchNode(facultyId)){
    //remove student id from faculty member list  - deletes the student id from list of student IDs
    faculty->getNode(facultyId)->removeAdvisee(studentId);
    // remove faculty member from student from advisor field
    //changeAdvisor(studentId, facultyId);
    if(needReplaceAdvisor){
      replaceAdvisor(facultyId, studentId);
    }
  }else{
    cout << "faculty does not exist" << endl;
  }
}
void Database::replaceAdvisor(int facultyId, int studentId){
  int newFacultyId = -1;
  cout << "Student ID#: " << to_string(studentId) << " needs a new advisor..." << endl;
  while(true){
    newFacultyId = promptValidIdNumber(false);
    if(newFacultyId == facultyId){
      cout << "ERROR: Advisor cannot be the same previous advisor id: " << to_string(facultyId) << endl;
    }
    else break;
  }
  // assign advisor id to advisor field of the student
  students->getNode(studentId)->setAdvisorId(newFacultyId);
}
int Database::promptIdNumber(bool student){
  int id = -1;
  student ? cout << "Enter the Student ID number: \n" : cout << "Enter the Faculty Member ID number: \n";
  id = IE.getIntegerInput(1);
  return id;
}
int Database::promptValidIdNumber(bool student){
  int id = -1;
  student ? cout << "Enter the Student ID number: \n" : cout << "Enter the Faculty Member ID number: \n";
  while(true){
    id = IE.getIntegerInput(1);
    if(student){
      if(students->searchNode(id) == false) {
        cerr << "ERROR: Invalid ID, student does not exist." << endl;
        continue;
      }
    }
    else{
      if(faculty->searchNode(id) == false) {
        cerr << "ERROR: Invalid ID, faculty member does not exist." << endl;
        continue;
      }
    }
    break;
  }
  return id;
}
void Database::addStudent(int id, string name, string level, string major, double gpa, int advisorId){
  if(faculty->searchNode(advisorId)){
    Student* newStudent = new Student(id, name, level, major, gpa, advisorId);
    students->insertNode(id, newStudent);
    faculty->getNode(advisorId)->addAdvisee(id);
    // add new action to undo stack
    Action* newAction = new Action(newStudent, ActionType::CREATE);
    undo->addAction(newAction, ObjectType::STUDENT);
  }else{
    cout << "the student could not be entered into the system because of an invalid faculty advisor id" << endl;
  }
}

void Database::deleteStudent(int id, bool needReplaceAdvisor){
  if(students->searchNode(id)){
    removeAdvisee(students->getNode(id)->getAdvisorId(), id, needReplaceAdvisor);
    students->deleteNode(id);
  }
}

void Database::addFaculty(int id, string name, string level, string department){
  Faculty* newFaculty = new Faculty(id, name, level, department);
  faculty->insertNode(id, newFaculty);
  // add new action to undo stack
  Action* newAction = new Action(newFaculty, ActionType::CREATE);
  undo->addAction(newAction, ObjectType::FACULTY);
}

void Database::deleteFaculty(int id){
  if(faculty->searchNode(id)){
    int newAdvisor = -1;
    int size = faculty->getNode(id)->getListSize();
    for(int i = 0; i < size; ++i){
      // cout << "count: " << i << endl;
      // cout << faculty->getNode(id)->toString() << endl;
      // cout << faculty->getNode(id)->getStudentId(i) << endl;
      // faculty->getNode(id)->printStudentIds();
      cout << "the following student requires a new advisor: " << endl;
      cout << students->getNode(faculty->getNode(id)->getStudentId(0))->toString() << endl;
      cout << "entire id of new advisor: ";
      // TODO - add try catch exception
      cin >> newAdvisor;
      cout << endl;
      if(faculty->searchNode(newAdvisor)){
        changeAdvisor(faculty->getNode(id)->getStudentId(0), newAdvisor);
      }else{
        while(!faculty->searchNode(newAdvisor)){
          cout << "please enter a valid faculty id" << endl;
          cin >> newAdvisor;
        }
        changeAdvisor(faculty->getNode(id)->getStudentId(0), newAdvisor);
        cout << "" << endl;
      }
    }
    faculty->deleteNode(id);
  }
}
bool Database::studentDatabaseIsEmpty(){
  return (students->isEmpty());
}
bool Database::facultyDatabaseIsEmpty(){
  return (faculty->isEmpty());
}
void Database::rollback(){
  // TODO
  int id = -1;
  string msg = "SUCCESS - undid the previous action: \n";
  msg += undo->toStringLastAction();

  const Action* lastAction = undo->getLastAction();
  ObjectType objectType = undo->getLastObjectType();
  ActionType actionType = undo->getLastActionType();

  // if last action affected only student
  if(objectType == ObjectType::STUDENT){
    if(actionType == ActionType::CREATE){
      id = lastAction->m_id;
      deleteStudent(id, false);
      cout << msg;
    }
  }
  // if last action affected only faculty member
  else if(objectType == ObjectType::FACULTY){
    if(actionType == ActionType::CREATE){
      id = lastAction->m_id;
      deleteFaculty(id);
      cout << msg;
    }
  }
  // if last action affected both - student and faculty member

}
