#include "Faculty.h"
//faculty constructor
Faculty::Faculty():Affiliate(){
  m_department = "";
  m_StudentIds = new GenLinkedList<int>();
}
//faculty copy constructor
Faculty::Faculty(const Faculty& F):Affiliate(F){
  m_department = F.m_department;
  m_StudentIds = F.m_StudentIds;
}
//faculty copy constructor
Faculty::Faculty(const Faculty* F):Affiliate(F){
  m_department = F->m_department;
  m_StudentIds = F->m_StudentIds;
}
//faculty overloaded constructor
Faculty::Faculty(string name, string level, string department):Affiliate(name, level){
  m_department = department;
  m_StudentIds = new GenLinkedList<int>();
}
//faculty overloaded constructor
Faculty::Faculty(int id, string name, string level, string department):Affiliate(id, name, level){
  m_department = department;
  m_StudentIds = new GenLinkedList<int>();
}
//faculty overloaed constructor
Faculty::Faculty(int id, string name, string level, string department, GenLinkedList<int>* StudentIds):Affiliate(id, name, level){
  m_department = department;
  m_StudentIds = StudentIds;
}
//faculty destructor
Faculty::~Faculty(){}
string Faculty::getDepartment(){
  return m_department;
}
//set faculty department
void Faculty::setDepartment(string department){
  m_department = department;
}
//send faculty to string
string Faculty::toString(){
  string ret = Affiliate::toString();
  ret += "Department: ";
  ret += m_department;
  ret += "\n";
  return ret;
}
//print student ids
void Faculty::printStudentIds(){
  m_StudentIds->printList();
}
//get list size of faculty array
int Faculty::getListSize(){
  return m_StudentIds->getSize();
}
//get id from faculty id list
int Faculty::getStudentId(int pos){
  return m_StudentIds->getPos(pos);
}
//add an advisee to faculty
void Faculty::addAdvisee(int id){
  m_StudentIds->insertFront(id);
}
//remove advisee from faculty
void Faculty::removeAdvisee(int id){
  int pos = m_StudentIds->find(id);
  if(pos == 0){
    m_StudentIds->removeFront();
  }else{
    m_StudentIds->deletePos(pos);
  }
}
//determine if faculty has an advisee
bool Faculty::hasAdvisee(int id){
  return (m_StudentIds->find(id) != -1);
}
