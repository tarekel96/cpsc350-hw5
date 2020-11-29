#include "Affiliate.h"

Affiliate::Affiliate(){
  m_id = -1;
  m_name = "";
  m_level = "";
}
Affiliate::Affiliate(Affiliate& A){
  m_id = A.m_id;
  m_name = A.m_name;
  m_level = A.m_level;
}
Affiliate::Affiliate(string name, string level){
  m_id = -1;
  m_name = name;
  m_level = level;
}
Affiliate::Affiliate(int id, string name, string level){
  m_id = id;
  m_name = name;
  m_level = level;
}
Affiliate::~Affiliate(){}
int Affiliate::getId(){
  return m_id;
}
string Affiliate::getName(){
  return m_name;
}
string Affiliate::getLevel(){
  return m_level;
}
void Affiliate::setId(int id){
  m_id = id;
}
void Affiliate::setName(string name){
  m_name = name;
}
void Affiliate::setLevel(string level){
  m_level = level;
}
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
