#include "Action.h"

//construct an action
Action::Action(){
  m_id = -1;
  m_type = ActionType::UNASSIGNED;
  m_affiliate = NULL;
}
//overloaded construct of an action
Action::Action(Affiliate* affiliate, ActionType type){
  m_affiliate = affiliate;
  m_id = affiliate->getId();
  m_type = type;
}
//copy an action
Action::Action(const Action* A){
  m_type = A->m_type;
  m_affiliate = A->m_affiliate;
  m_id = A->m_id;
}
//delete action
Action::~Action(){
  delete m_affiliate;
}
//get action id
const int Action::getId(){
  return m_id;
}
//get affiliate
Affiliate* Action::getAffiliate(){
  return m_affiliate;
}
//get the type of action
ActionType Action::getActionType(){
  return m_type;
}
//print ot the action data
string Action::toString(){
  string ret = "";
  ret += "Action ID#: ";
  ret += to_string(m_id);
  ret += "\nActionType: ";
  ret += typeToString(m_type);
  ret += "\n";
  ret += m_affiliate->toString();
  return ret;
}
//send action data to string for output
string Action::typeToString(ActionType type){
  string ret = "";

  switch (type) {
    case ActionType::CREATE:
      ret = "CREATE";
      break;
    case ActionType::READ:
      ret = "READ";
      break;
    case ActionType::UPDATE:
      ret = "UPDATE";
      break;
    case ActionType::DELETE:
      ret = "DELETE";
      break;
    default:
      ret = "UNASSIGNED";
      break;
  }

  return ret;
}
