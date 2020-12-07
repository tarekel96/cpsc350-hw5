#include "Student.h"
//Student constructors
Student::Student():Affiliate(){
  m_major = "";
  m_gpa = -1.0;
  m_advisorId = -1;
}
//Student copy constructor
Student::Student(const Student& S):Affiliate(S){
  m_major = S.m_major;
  m_gpa = S.m_gpa;
  m_advisorId = S.m_advisorId;
}
//Student pointer copy constructor
Student::Student(const Student* S):Affiliate(S){
  m_major = S->m_major;
  m_gpa = S->m_gpa;
  m_advisorId = S->m_advisorId;
}
//student overloaded constructor
Student::Student(string name, string level, string major, double gpa, int advisorId):Affiliate(name, level){
  m_id = -1;
  m_major = major;
  m_gpa = gpa;
  m_advisorId = advisorId;
}
//student overloaded constructor
Student::Student(int id, string name, string level, string major, double gpa, int advisorId):Affiliate(id, name, level){
  m_major = major;
  m_gpa = gpa;
  m_advisorId = advisorId;
}
//student destructor
Student::~Student(){}
string Student::getMajor(){
  return m_major;
}
//get students GPA
double Student::getGpa(){
  return m_gpa;
}
//get students advisor
int Student::getAdvisorId(){
  return m_advisorId;
}
//get students major
void Student::setMajor(string major){
  m_major = major;
}
//set students gpa
void Student::setGpa(double gpa){
  m_gpa = gpa;
}
//set students avisor id
void Student::setAdvisorId(int advisorId){
  m_advisorId = advisorId;
}
//send student info to string
string Student::toString(){
  string ret = Affiliate::toString();
  ret += "Major: ";
  ret += m_major;
  ret += "\n";
  ret += "GPA: ";
  ret += to_string(m_gpa);
  ret += "\n";
  ret += "Advisor ID#: ";
  ret += to_string(m_advisorId);
  ret += "\n";
  return ret;
}
// ostream& operator<<(ostream& os, const Student& s)
// {
//     os << s.m_major << '/' << dt.da << '/' << dt.yr;
//     return os;
// }
