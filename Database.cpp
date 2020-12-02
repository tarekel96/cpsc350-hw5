#include "Database.h"
#include <fstream>
#include <string>

Database::Database(){
  faculty = new KVBST<Faculty*>();
  students = new KVBST<Student*>();
}
Database::Database(string f){
  faculty = new KVBST<Faculty*>();
  students = new KVBST<Student*>();
  file = f;
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
      removeAdvisee(students->getNode(studentId)->getAdvisorId(), studentId);
      faculty->getNode(facultyId)->addAdvisee(studentId);
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
void Database::removeAdvisee(int facultyId, int studentId){
  if(faculty->searchNode(facultyId)){
    //remove student id from faculty member list
    faculty->getNode(facultyId)->removeAdvisee(studentId);
    //print ids
  }else{
    cout << "faculty does not exist" << endl;
  }
}

void Database::addStudent(int id, string name, string level, string major, double gpa, int advisorId){
  // TODO - make sure the id entered is not already taken
  if(faculty->searchNode(advisorId)){
    students->insertNode(id, new Student(id, name, level, major, gpa, advisorId));
    faculty->getNode(advisorId)->addAdvisee(id);
  }else{
    cout << "the student could not be entered into the system because of an invalid faculty advisor id" << endl;
  }
}

void Database::deleteStudent(int id){
  if(students->searchNode(id)){
    removeAdvisee(students->getNode(id)->getAdvisorId(), id);
    students->deleteNode(id);
  }
}

void Database::addFaculty(int id, string name, string level, string department){
  faculty->insertNode(id, new Faculty(id, name, level, department));
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

void Database::processFile(){
  ifstream myfile (file);
  string line;
  if(myfile.is_open()){
    while(getline(myfile, line)){
      int id;
      string name;
      string level;
      string department;
      string major;
      double gpa;
      int advisorId;
      id = stoi(line.substr(5,line.length()));
      getline(myfile, line);
      name = line.substr(6, line.length());
      getline(myfile, line);
      level = line.substr(7, line.length());
      getline(myfile, line);
      if(line.at(0) == 'D'){
        department = line.substr(12, line.length());
        addFaculty(id, name, level, department);
      }else{
        major = line.substr(7, line.length());
        getline(myfile, line);
        gpa = stod(line.substr(5,line.length()));
        getline(myfile, line);
        advisorId = stoi(line.substr(13, line.length()));
        addStudent(id, name, level, major, gpa, advisorId);
      }
      getline(myfile, line);
    }
    myfile.close();
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
}
