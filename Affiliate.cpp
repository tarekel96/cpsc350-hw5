#include "Affiliate.h"
//affiliate constructor
Affiliate::Affiliate(){
  m_id = -1;
  m_name = "";
  m_level = "";
}
//affiliate copy constructor
Affiliate::Affiliate(const Affiliate& A){
  m_id = A.m_id;
  m_name = A.m_name;
  m_level = A.m_level;
}
//affiliate pointer copy constructor
Affiliate::Affiliate(const Affiliate* A){
  m_id = A->m_id;
  m_name = A->m_name;
  m_level = A->m_level;
}
//affiliate overloaded constructor
Affiliate::Affiliate(string name, string level){
  m_id = -1;
  m_name = name;
  m_level = level;
}
//affiliate overloaded constructor
Affiliate::Affiliate(int id, string name, string level){
  m_id = id;
  m_name = name;
  m_level = level;
}
//affiliate destructor
Affiliate::~Affiliate(){}
//get affiliate id
int Affiliate::getId(){
  return m_id;
}
//get affiliate name
string Affiliate::getName(){
  return m_name;
}
//get affiliate level
string Affiliate::getLevel(){
  return m_level;
}
//set affiliate id
void Affiliate::setId(int id){
  m_id = id;
}
//set affiliate name
void Affiliate::setName(string name){
  m_name = name;
}
//set affiliate level
void Affiliate::setLevel(string level){
  m_level = level;
}
//send affiliate details to string
string Affiliate::toString(){
  string ret = "";
  ret += "ID#: ";
  ret += to_string(m_id);
  ret += "\n";
  ret += "Name: ";
  ret += m_name;
  ret += "\n";
  ret += "Level: ";
  ret += m_level;
  ret += "\n";
  return ret;
}
