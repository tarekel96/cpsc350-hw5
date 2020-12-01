#include "Database.h"

Database::Database(){
  faculty = new KVBST<Faculty*>();
  students = new KVBST<Student*>();
}

Database::~Database(){
  delete faculty;
  delete students;
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

void Database::changeAdvisor(int studentId, int facultyId){
  if(students->searchNode(studentId)){
    if(faculty->searchNode(facultyId)){
      students->getNode(studentId)->setAdvisorId(facultyId);
    }else{
      cout << "faculty does not exist" << endl;
    }
  }else{
    cout << "student does not exist" << endl;
  }
}

// void Database::printFacultyAdvisees(int id){
//   //loop through the faculty advisee list and print using findStudent
// }

//
// void Database::removeAdvisee(int facultyId, int studentId){
//
// }

void Database::addStudent(int id, string name, string level, string major, double gpa, int advisorId){
  if(faculty->searchNode(advisorId)){
    students->insertNode(id, new Student(id, name, level, major, gpa, advisorId));
  }else{
    cout << "the student could not be entered into the system because of an invalid faculty advisor id" << endl;
  }
}

void Database::deleteStudent(int id){
  students->deleteNode(id);
}

void Database::addFaculty(int id, string name, string level, string department){
  faculty->insertNode(id, new Faculty(id, name, level, department));
}

void Database::deleteFaculty(int id){
  faculty->deleteNode(id);
}

//
// void Database::rollback(){
//
// }
//
// void Database::exit(){
//
// }
