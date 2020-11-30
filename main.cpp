#include <iostream>
#include "BST.h"
#include "Affiliate.h"
#include "Student.h"
#include "Faculty.h"
#include "GenLinkedList.h"
using namespace std;

int main(int argc, char ** argv){
  BST<int>* bstInstance = new BST<int>();

  bstInstance->insertNode(5);

  bstInstance->insertNode(18);

  bstInstance->insertNode(6);

  bstInstance->printTree();

  cout << "Max: " << bstInstance->getMax() << endl;

  cout << "Min: " << bstInstance->getMin() << endl;

  bstInstance->searchNode(5) ? cout << "BST contains 5" : cout << "BST does not contain 5";

  cout << endl;

  bstInstance->deleteNode(5);

  cout << "deleting node 5..." << endl;

  bstInstance->searchNode(5) ? cout << "BST contains 5" : cout << "BST does not contain 5";

  cout << endl;

  bstInstance->printTree();

  cout << "Max: " << bstInstance->getMax() << endl;

  cout << "Min: " << bstInstance->getMin() << endl;

  delete bstInstance;

  BST<char>* bstInstance2 = new BST<char>();

  bstInstance2->insertNode('a');

  bstInstance2->insertNode('c');

  bstInstance2->insertNode('b');

  bstInstance2->printTree();

  cout << "Max: " << bstInstance2->getMax() << endl;

  cout << "Min: " << bstInstance2->getMin() << endl;

  bstInstance2->searchNode('b') ? cout << "BST contains b" : cout << "BST does not contain b";

  cout << endl;

  bstInstance2->deleteNode('b');

  cout << "deleting node b..." << endl;

  bstInstance2->searchNode('b') ? cout << "BST contains b" : cout << "BST does not contain b";

  cout << endl;

  bstInstance2->printTree();

  cout << "Max: " << bstInstance2->getMax() << endl;

  cout << "Min: " << bstInstance2->getMin() << endl;

  delete bstInstance2;

  Affiliate* afInstance = new Affiliate(5, "bob", "freshman");

  cout << afInstance->toString();

  Affiliate* afInstance2 = new Affiliate(*afInstance);

  cout << afInstance2->toString();

  delete afInstance;
  delete afInstance2;

  Student* studentInstance = new Student(5, "bob", "freshman", "CS", 3.67, 42);

  cout << studentInstance->toString();

  Student* studentInstance2 = new Student(*studentInstance);

  cout << studentInstance2->toString();

  delete studentInstance;
  delete studentInstance2;

  Faculty* facultyInstance = new Faculty(5, "Rene", "Full Time Professor", "CS");

  cout << facultyInstance->toString();

  Faculty* facultyInstance2 = new Faculty(*facultyInstance);

  cout << facultyInstance2->toString();

  delete facultyInstance;
  delete facultyInstance2;

  GenLinkedList<int>* ll = new GenLinkedList<int>();
  cout << "SIZE " << ll->getSize() << endl;
  ll->insertBack(4);
  ll->insertBack(7);
  ll->insertFront(3);
  ll->insertFront(2);
  ll->insertFront(1);
  cout << "Find 3: " << to_string(ll->find(3)) << endl;
  cout << "SIZE " << ll->getSize() << endl;
  ll->printList(true);
  ll->removeFront();
  ll->printList(true);
  ll->removeBack();
  ll->printList(true);
  ll->deletePos(1);
  cout << "SIZE " << ll->getSize() << endl;
  ll->printList(true);
  delete ll;

  GenLinkedList<char>* ll2 = new GenLinkedList<char>();
  cout << "SIZE " << ll2->getSize() << endl;
  ll2->insertBack('a');
  ll2->insertBack('d');
  ll2->insertFront('b');
  ll2->insertFront('y');
  ll2->insertFront('g');
  cout << "Find y: " << to_string(ll2->find('y')) << endl;
  cout << "SIZE " << ll2->getSize() << endl;
  ll2->printList(true);
  ll2->removeFront();
  ll2->printList(true);
  ll2->removeBack();
  ll2->printList(true);
  ll2->deletePos(1);
  cout << "SIZE " << ll2->getSize() << endl;
  ll2->printList(true);
  delete ll2;

  return 0;
}
