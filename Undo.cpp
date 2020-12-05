#include "Undo.h"

Undo::Undo(){
  UndoStack = new GenStack<Action*>(5);
  ObjectTypeStack = new GenStack<ObjectType>(5);
}
Undo::~Undo(){
  delete UndoStack;
  delete ObjectTypeStack;
}
void Undo::addAction(Action* action, ObjectType objectType){
  UndoStack->push(action);
  ObjectTypeStack->push(objectType);
}
const Action* Undo::getLastAction(){
  if(UndoStack->isEmpty() == false){
    return UndoStack->pop();
  }
}
void Undo::viewLastAction(){
  if(UndoStack->isEmpty()) cerr << "ERROR: Undo Stack is empty." << endl;
  else{
    cout << "Object Type: " << toStringObjectType(ObjectTypeStack->peek()) << endl;
    cout << UndoStack->peek()->toString();
  }
}
string Undo::toStringLastAction(){
  string ret = "";
  if(UndoStack->isEmpty())
    return "ERROR: Undo Stack is empty.";
  else{
    ret += UndoStack->peek()->toString();
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
  return (UndoStack->peek()->getActionType());
}
ObjectType Undo::getLastObjectType(){
  return (ObjectTypeStack->peek());
}
