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
  students->printTree();
}

void Database::printFaculty(){
  faculty->printTree();
}

// void Database::findStudent(int id){
//
// }
//
// void Database::findFaculty(int id){
//
// }

void Database::printStudentAdvisor(int id){

}

void Database::printFacultyAdvisees(int id){

}

void Database::addStudent(int id, string name, string level, string major, double gpa, int advisorId){
  students->insertNode(id, new Student(id, name, level, major, gpa, advisorId));
}

void Database::deleteStudent(int id){
  students->deleteNode(id);
}

void Database::addFaculty(int id, string name, string level, string department){
  faculty->insertNode(id, new Faculty(id, name, level, department));
}

void Database::changeAdvisor(int id){

}

void Database::removeAdvisee(int facultyId, int studentId){

}

void Database::rollback(){

}

void Database::exit(){

}
