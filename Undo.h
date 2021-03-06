#ifndef UNDO_H
#define UNDO_H
#include <iostream>
#include "Action.h"
#include "Affiliate.h"
#include "GenStack.h"
using namespace std;
enum class ObjectType {STUDENT, FACULTY, BOTH, UNASSIGNED};
/*
  * @name Undo - class that represents an action given by the user
  * @author Tarek El-Hajjaoui & Krishna Narayan
*/
class Undo{
  private:
    GenStack<Action*>* ActionStack;
    GenStack<ObjectType>* ObjectTypeStack;
  public:
    Undo();
    ~Undo();
    void pop();
    void addAction(Action* affiliate, ObjectType objectType);
    Action* getLastAction();
    void viewLastAction();
    string toStringLastAction();
    string toStringObjectType(ObjectType objectType);
    ActionType getLastActionType();
    ObjectType getLastObjectType();
    bool isEmpty();
};
#endif
