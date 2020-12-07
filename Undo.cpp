#include "Undo.h"
//create undo instance
Undo::Undo(){
  ActionStack = new GenStack<Action*>(5);
  ObjectTypeStack = new GenStack<ObjectType>(5);
}
//delete undo
Undo::~Undo(){
  delete ActionStack;
  delete ObjectTypeStack;
}
//pop an object from undo stack
void Undo::pop(){
  ObjectTypeStack->pop();
}
//add an action to the stack
void Undo::addAction(Action* action, ObjectType objectType){
  ActionStack->push(action);
  ObjectTypeStack->push(objectType);
}
//get the last action given
Action* Undo::getLastAction(){
  if(ActionStack->isEmpty() == false){
    return ActionStack->pop();
  }
}
//view what the last action is
void Undo::viewLastAction(){
  if(ActionStack->isEmpty()) cerr << "ERROR: Undo Stack is empty." << endl;
  else{
    cout << "Object Type: " << toStringObjectType(ObjectTypeStack->peek()) << endl;
    cout << ActionStack->peek()->toString();
  }
}
//send last action data to string
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
//determine type of last action
ActionType Undo::getLastActionType(){
  return (ActionStack->peek()->getActionType());
}
//determine object of last action
ObjectType Undo::getLastObjectType(){
  return (ObjectTypeStack->peek());
}
//determine if stack is empty
bool Undo::isEmpty(){
  return (ActionStack->isEmpty());
}
