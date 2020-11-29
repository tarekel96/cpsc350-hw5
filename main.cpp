#include <iostream>
#include "BST.h"
#include "Affiliate.h"
#include "Student.h"
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

  return 0;
}
