#ifndef UNDO_H
#define UNDO_H
#include <iostream>
#include "Action.h"
#include "Affiliate.h"
#include "GenStack.h"
using namespace std;
enum class ObjectType {STUDENT, FACULTY, BOTH, UNASSIGNED};
class Undo{
  private:
    GenStack<Action*>* UndoStack;
    GenStack<ObjectType>* ObjectTypeStack;
  public:
    Undo();
    ~Undo();

    void addAction(Action* affiliate, ObjectType objectType);
    const Action* getLastAction();
    void viewLastAction();
    string toStringLastAction();
    string toStringObjectType(ObjectType objectType);
    ActionType getLastActionType();
    ObjectType getLastObjectType();
};
#endif
