#include "Faculty.h"

Faculty::Faculty():Affiliate(){
  m_department = "";
  StudentIds = new GenLinkedList<int>();
}
Faculty::Faculty(const Faculty& F):Affiliate(F){
  m_department = F.m_department;
  StudentIds = F.StudentIds;
}
Faculty::Faculty(string name, string level, string department):Affiliate(name, level){
  m_department = department;
  StudentIds = new GenLinkedList<int>();
}
Faculty::Faculty(int id, string name, string level, string department):Affiliate(id, name, level){
  m_department = department;
  StudentIds = new GenLinkedList<int>();
}
Faculty::~Faculty(){}
string Faculty::getDepartment(){
  return m_department;
}
void Faculty::setDepartment(string department){
  m_department = department;
}
string Faculty::toString(){
  string ret = Affiliate::toString();
  ret += "Department: ";
  ret += m_department;
  ret += "\n";
  return ret;
}
// void Faculty::printStudentIds(){
//   StudentIds->printList(false);
// }
