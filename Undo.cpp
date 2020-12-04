#include "Undo.h"

Undo::Undo(){
  UndoStack = new GenStack<Action*>(5);
  TypeStack = new GenStack<Type>(5);
}
Undo::~Undo(){
  if(UndoStack != NULL) delete UndoStack;
  if(TypeStack != NULL) delete TypeStack;
}
void Undo::addAction(Action* action){
  UndoStack->push(action);
  TypeStack->push(action->getType());
}
const Action* Undo::getLastAction(){
  if(UndoStack->isEmpty() == false){
    return UndoStack->pop();
  }
}
void Undo::viewLastAction(){
  if(UndoStack->isEmpty()) cerr << "ERROR: Undo Stack is empty." << endl;
  else{
    cout << UndoStack->peek()->toString();
  }
}
