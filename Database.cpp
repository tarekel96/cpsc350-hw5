#include "Database.h"

Database::Database(){
  faculty = new BST<Faculty*>();
  students = new BST<Student*>();
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

void Database::findStudent(int id){

}

void Database::findFaculty(int id){

}

void Database::printStudentAdvisor(int id){

}

void Database::printFacultyAdvisees(int id){

}

void Database::addStudent(int id, string name, string level, string major, double gpa, int advisorId){

}

void Database::deleteStudent(int id){

}

void Database::addFaculty(int id, string name, string level, string department, List* advisees){

}

void Database::changeAdvisor(int id){

}

void Database::removeAdvisee(int facultyId, int studentId){

}

void Database::rollback(){

}

void Database::exit(){

}
