#include "Undo.h"

Undo::Undo(){
  ActionStack = new GenStack<Action*>(5);
  ObjectTypeStack = new GenStack<ObjectType>(5);
}
Undo::~Undo(){
  delete ActionStack;
  delete ObjectTypeStack;
}
void Undo::addAction(Action* action, ObjectType objectType){
  ActionStack->push(action);
  ObjectTypeStack->push(objectType);
}
const Action* Undo::getLastAction(){
  if(ActionStack->isEmpty() == false){
    return ActionStack->pop();
  }
}
void Undo::viewLastAction(){
  if(ActionStack->isEmpty()) cerr << "ERROR: Undo Stack is empty." << endl;
  else{
    cout << "Object Type: " << toStringObjectType(ObjectTypeStack->peek()) << endl;
    cout << ActionStack->peek()->toString();
  }
}
string Undo::toStringLastAction(){
  string ret = "";
  if(ActionStack->isEmpty())
    return "ERROR: Undo Stack is empty.";
  else{
    ret += ActionStack->peek()->toString();
  }
  return ret;
}
string Undo::toStringObjectType(ObjectType objectType){
  string ret = "";

  switch (objectType) {
    case ObjectType::STUDENT:
      ret = "STUDENT";
      break;
    case ObjectType::FACULTY:
      ret = "FACULTY";
      break;
    case ObjectType::BOTH:
      ret = "BOTH";
      break;
    default:
      ret = "UNASSIGNED";
      break;
  }

  return ret;
}
ActionType Undo::getLastActionType(){
  return (ActionStack->peek()->getActionType());
}
ObjectType Undo::getLastObjectType(){
  return (ObjectTypeStack->peek());
}
