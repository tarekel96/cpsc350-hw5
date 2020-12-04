#ifndef UNDO_H
#define UNDO_H
#include <iostream>
#include "Action.h"
#include "Affiliate.h"
#include "GenStack.h"
using namespace std;

class Undo{
  private:
    GenStack<Action*>* UndoStack;
    GenStack<Type>* TypeStack;
  public:
    Undo();
    ~Undo();

    void addAction(Action* affiliate);
    const Action* getLastAction();
    void viewLastAction();
};
#endif
