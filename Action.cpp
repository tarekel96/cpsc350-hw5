#include "Action.h"

Action::Action(){
  m_id = -1;
  m_type = ActionType::UNASSIGNED;
  m_affiliate = NULL;
}
Action::Action(Affiliate* affiliate, ActionType type){
  m_affiliate = affiliate;
  m_id = affiliate->getId();
  m_type = type;
}
Action::Action(const Action* A){
  m_type = A->m_type;
  m_affiliate = A->m_affiliate;
  m_id = A->m_id;
}
Action::~Action(){
  delete m_affiliate;
}
const int Action::getId(){
  return m_id;
}
Affiliate* Action::getAffiliate(){
  return m_affiliate;
}
ActionType Action::getActionType(){
  return m_type;
}
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
