#include "Action.h"

Action::Action(){
  m_id = -1;
  m_type = Type::UNASSIGNED;
  m_affiliate = NULL;
}
Action::Action(Affiliate* affiliate, Type type){
  m_affiliate = affiliate;
  m_id = affiliate->getId();
  m_type = type;
}
Action::~Action(){

}
Affiliate* Action::getAffiliate(){
  return m_affiliate;
}
Type Action::getType(){
  return m_type;
}
string Action::toString(){
  string ret = "";
  ret += "Action ID#: ";
  ret += to_string(m_id);
  ret += "\nAction Type: ";
  ret += typeToString(m_type);
  ret += "\n";
  ret += m_affiliate->toString();
  return ret;
}
string Action::typeToString(Type type){
  string ret = "";
  
  switch (type) {
    case Type::CREATE:
      ret = "CREATE";
      break;
    case Type::READ:
      ret = "READ";
      break;
    case Type::UPDATE:
      ret = "UPDATE";
      break;
    case Type::DELETE:
      ret = "DELETE";
      break;
    default:
      ret = "UNASSIGNED";
      break;
  }

  return ret;
}
