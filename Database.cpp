#include "Database.h"
#include <fstream>
#include <string>

//database class contains two trees, one of faculty, one of students,
//as well as variables to track actions for the rollback function.

Database::Database(){
  faculty = new KVBST<Faculty*>();
  students = new KVBST<Student*>();
  undo = new Undo();
  deleteFacultyStudents = new GenStack<int>();
}

//database destrucctor

Database::~Database(){
  delete faculty;
  delete students;
  delete undo;
  delete deleteFacultyStudents;
}

//print the student tree
void Database::printStudents(){
  students->printTree(true);
}

//print the faculty tree
void Database::printFaculty(){
  faculty->printTree(true);
}

//put faculty data into string format for file out purposes
string Database::getFacultyData(){
  return faculty->getTreeToString();
  //return faculty->treeToString();
}

//put student data into string formart for file out purposes
string Database::getStudentData(){
  return students->getTreeToString();
  //return students->treeToString();
}

//print the data of a given student
void Database::findStudent(int id){
  if(students->searchNode(id)){
    cout << students->getNode(id)->toString() << endl;
  }else{
    cout << "student does not exist" << endl;
  }
}

//print data of a given faculty
void Database::findFaculty(int id){
  if(faculty->searchNode(id)){
    cout << faculty->getNode(id)->toString() << endl;
  }else{
    cout << "faculty does not exist" << endl;
  }
}

//print the info of a stuents advisor
void Database::printStudentAdvisor(int id){
  int advisorId = students->getNode(id)->getAdvisorId();
  findFaculty(advisorId);
}
// changes the advisor of the given id student to the provided the faculty member id
void Database::changeAdvisor(int studentId, int facultyId){
  // check student exists
  removedAdvisor = facultyId;
  Student* newStudent = new Student(students->getNode(studentId));
  Action* newAction = new Action(newStudent, ActionType::UPDATE);
  undo->addAction(newAction, ObjectType::STUDENT);
  if(students->searchNode(studentId)){
    // check faculty exists
    if(faculty->searchNode(facultyId)){
      // deletes the student id from list of student IDs
      removedAdvisor = students->getNode(studentId)->getAdvisorId();
      removeAdvisee(students->getNode(studentId)->getAdvisorId(), studentId, true, true);
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
  // Action* newAction = new Action(studentId, ActionType::CREATE);
  // undo->addAction(newAction, ObjectType::STUDENT);
}

//print the advisees of a faculty member by runing through there advisee list
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

//remove an advisee, replace if neccessary
void Database::removeAdvisee(int facultyId, int studentId, bool needReplaceAdvisor, bool addAction){
  removedId = studentId;
  if(addAction){
    //create a new action to put into the undo stack
    Faculty* newFaculty = new Faculty(faculty->getNode(facultyId));
    Action* newAction = new Action(newFaculty, ActionType::UPDATE);
    undo->addAction(newAction, ObjectType::FACULTY);
  }
  //make sure that reassigned students get valid ids
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

//replace  astudents advisor
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
  //
  faculty->getNode(newFacultyId)->addAdvisee(studentId);
}
//prompt for an integer id
int Database::promptIdNumber(bool student){
  int id = -1;
  student ? cout << "Enter the Student ID number: \n" : cout << "Enter the Faculty Member ID number: \n";
  id = IE.getIntegerInput(1);
  return id;
}
//make sure  av number is valid through if statements
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
//add student to the databse. input parameters for constructor
void Database::addStudent(int id, string name, string level, string major, double gpa, int advisorId){
  if(faculty->searchNode(advisorId)){
    Student* newStudent = new Student(id, name, level, major, gpa, advisorId);
    students->insertNode(id, newStudent);
    faculty->getNode(advisorId)->addAdvisee(id);
  }else{
    cout << "the student could not be entered into the system because of an invalid faculty advisor id" << endl;
  }
}
//add a student, bt make an action to add to undo stack
void Database::addStudent(int id, string name, string level, string major, double gpa, int advisorId, bool beginUndo){
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
//delete student, add action to undo stack
void Database::deleteStudent(int id, bool needReplaceAdvisor){
  if(students->searchNode(id)){
    Student* currStudent = new Student(students->getNode(id));
    Action* newAction = new Action(currStudent, ActionType::DELETE);
    cout << "before new action" << endl;
    cout << newAction->toString();
    undo->addAction(newAction, ObjectType::STUDENT);
    removeAdvisee(students->getNode(id)->getAdvisorId(), id, needReplaceAdvisor, false);
    students->deleteNode(id);
    // cout << "FINISHED DELETING" << endl;
    // cout << undo->toStringLastAction();
  }
}
//add a faculty memeber via parameters
void Database::addFaculty(int id, string name, string level, string department){
  Faculty* newFaculty = new Faculty(id, name, level, department);
  faculty->insertNode(id, newFaculty);
}
//add faculty memebr, add action to undo stack
void Database::addFaculty(int id, string name, string level, string department, bool beginUndo){
  Faculty* newFaculty = new Faculty(id, name, level, department);
  faculty->insertNode(id, newFaculty);
  // add new action to undo stack
  Action* newAction = new Action(newFaculty, ActionType::CREATE);
  undo->addAction(newAction, ObjectType::FACULTY);
}
//delete a faculty member, add action to undo stack
void Database::deleteFaculty(int id){
  Faculty* newFaculty = new Faculty(faculty->getNode(id));
  Action* newAction = new Action(newFaculty, ActionType::DELETE);
  undo->addAction(newAction, ObjectType::FACULTY);
  if(faculty->searchNode(id)){
    int newAdvisor = -1;
    int size = faculty->getNode(id)->getListSize();
    //for the students without an advisor after deletion, reassign
    for(int i = 0; i < size; ++i){
      deleteFacultyStudents->push(students->getNode(faculty->getNode(id)->getStudentId(i))->getId());
      replaceAdvisor(id, faculty->getNode(id)->getStudentId(i));
    }
    faculty->deleteNode(id);
  }
}
//check if the student database is empty
bool Database::studentDatabaseIsEmpty(){
  return (students->isEmpty());
}
//check if the faculty database is empty
bool Database::facultyDatabaseIsEmpty(){
  return (faculty->isEmpty());
}
//rollback function
void Database::rollback(){
  if(undo->isEmpty()){
    cout << "ERROR: No action has yet been performed to rollback from." << endl;
  }
  else{
    int id = -1;
    string msg = "SUCCESS - undid the previous action: \n";
    msg += undo->toStringLastAction();
    //work with last undo action
    Action* lastAction = undo->getLastAction();
    ObjectType objectType = undo->getLastObjectType();
    ActionType actionType = lastAction->getActionType();
    //undo creation by deleting student
    if(objectType == ObjectType::STUDENT){
      if(actionType == ActionType::CREATE){
        id = lastAction->m_id;
        deleteStudent(id, false);
        cout << msg;
      }
      // else if(actionType == ActionType::READ){
      //
      // }
      //undo updating student advisor
      else if(actionType == ActionType::UPDATE){
        id = lastAction->m_id;
        //remove advisee from current faculty id
        faculty->getNode(students->getNode(removedId)->getAdvisorId())->removeAdvisee(id);
        //add it to the original
        faculty->getNode(removedAdvisor)->addAdvisee(id);
        // update advisor field for the Student instance
        students->getNode(id)->setAdvisorId(removedAdvisor);
      }
      else if(actionType == ActionType::DELETE){
        id = lastAction->m_id;
        Affiliate* lastAffiliate = lastAction->getAffiliate();
        Student* lastStudent = (Student*)lastAffiliate;
        students->insertNode(id, lastStudent);
        undo->pop();
      }
      else if(actionType == ActionType::UNASSIGNED){}
      else{}
    }
    // if last action affected only faculty member
    else if(objectType == ObjectType::FACULTY){
      if(actionType == ActionType::CREATE){
        id = lastAction->m_id;
        deleteFaculty(id);
        cout << msg;
      }
      // else if(actionType == ActionType::READ){}
      else if(actionType == ActionType::UPDATE){
        id = lastAction->m_id;
        //remove the removed id from the "new" faculty member
        faculty->getNode(students->getNode(removedId)->getAdvisorId())->removeAdvisee(removedId);
        //add the advisee to the original faculty member that was deleted
        faculty->getNode(id)->addAdvisee(removedId);
        //change the faculty of the student id to match
        students->getNode(removedId)->setAdvisorId(id);
      }
      else if(actionType == ActionType::DELETE){
        id = lastAction->m_id;
        // cout << id << endl;
        //get the deleted faculty member back
        Affiliate* lastAffiliate = lastAction->getAffiliate();
        Faculty* lastFaculty = (Faculty*)lastAffiliate;
        //stick it back in the data base
        faculty->insertNode(id, lastFaculty);
        //run through the ids of the students that were originally held by that
        //faculty member, until stack is empty
        int currStudent;
        // cout << deleteFacultyStudents->getSize() << endl;
        while(!deleteFacultyStudents->isEmpty()){
          //pop an id off
          currStudent = deleteFacultyStudents->pop();
          faculty->getNode(students->getNode(currStudent)->getAdvisorId())->removeAdvisee(currStudent);
          //add that id back into the faculty list
          // faculty->getNode(id)->addAdvisee(currStudent);
          //set that students advisor back to the original faculty member
          students->getNode(currStudent)->setAdvisorId(id);
        }
        undo->pop();
      }
      else if(actionType == ActionType::UNASSIGNED){}
      else{}
    }
    // if last action affected both - student and faculty member
  }
}
//exit the program, save data to file
string Database::exit(){
  string ret = "";
  ret += getFacultyData();
  ret += getStudentData();
  return ret;
}
