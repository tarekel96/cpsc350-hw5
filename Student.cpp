#include "Student.h"

Student::Student():Affiliate(){
  m_major = "";
  m_gpa = -1.0;
  m_advisorId = -1;
}
Student::Student(const Student& S):Affiliate(S){
  m_major = S.m_major;
  m_gpa = S.m_gpa;
  m_advisorId = S.m_advisorId;
}
Student::Student(string name, string level, string major, double gpa, int advisorId):Affiliate(name, level){
  m_id = -1;
  m_major = major;
  m_gpa = gpa;
  m_advisorId = advisorId;
}
Student::Student(int id, string name, string level, string major, double gpa, int advisorId):Affiliate(id, name, level){
  m_major = major;
  m_gpa = gpa;
  m_advisorId = advisorId;
}
Student::~Student(){}
string Student::getMajor(){
  return m_major;
}
double Student::getGpa(){
  return m_gpa;
}
int Student::getAdvisorId(){
  return m_advisorId;
}
void Student::setMajor(string major){
  m_major = major;
}
void Student::setGpa(double gpa){
  m_gpa = gpa;
}
void Student::setAdvisorId(int advisorId){
  m_advisorId = advisorId;
}
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
