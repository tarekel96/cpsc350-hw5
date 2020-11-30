#ifndef KVBST_H
#define KVBST_H
#include "KVTreeNode.h"

template<class T>
class KVBST{
  private:
    /* FIELD */
    KVTreeNode<T>* root;
  public:
    KVBST();  /* Default Constructor */
    ~KVBST(); /* Destructor */
    /* CORE FUNCTIONS */
    void insertNode(int k, T value);
    bool searchNode(int k);
    bool deleteNode(int k);
    /* plays a role when deleting a node, *d represents the node to be deleted. */
    KVTreeNode<T>* getSuccessor(KVTreeNode<T> *d);
    /* AUXILIARY FUNCTIONS */
    bool isEmpty();
    T getMax();
    T getMin();
    T getNode(int k);
    /* PRINT FUNCTIONS */
    void recPrint(KVTreeNode<T>* node); // recursive print
    void printTree();
};
template<class T>
KVBST<T>::KVBST(){
  root = NULL; // empty tree
}
template<class T>
KVBST<T>::~KVBST(){
  // iterate and delete, this O(n)- cannot delete from top down
  if(root != NULL) delete root;
  root = NULL;
}
template<class T>
bool KVBST<T>::isEmpty(){
  return (root == NULL);
}
template<class T>
void KVBST<T>::recPrint(KVTreeNode<T>* node){
  if(node != NULL){
    recPrint(node->left);
    cout << node->value->toString() << endl;
    recPrint(node->right);
  }
}
template<class T>
void KVBST<T>::printTree(){
  recPrint(root);
}
template<class T>
T KVBST<T>::getMax(){
  if(isEmpty()) runtime_error("ERROR: Tree is empty, cannot getMax");

  KVTreeNode<T>* current = root;
  while(current->right != NULL){
    current = current->right;
  }

  return current->key;
}
template<class T>
T KVBST<T>::getMin(){
  if(isEmpty()) runtime_error("ERROR: Tree is empty, cannot getMin");

  KVTreeNode<T>* current = root;
  while(current->left != NULL){
    current = current->left;
  }

  return current->key;
}

template<class T>
T KVBST<T>::getNode(int k){
  if(isEmpty()) runtime_error("ERROR: Tree is empty, cannot get node");
  else{
    // tree is not empty
    KVTreeNode<T>* current = root;
    while(current->key != k){
      if(k < current->key)
        current = current->left;
      else
        current = current->right;
    }
    return current->value;
  }
}

template<class T>
void KVBST<T>::insertNode(int k, T value){

  KVTreeNode<T>* node = new KVTreeNode<T>(k, value);
  if(isEmpty()) root = node;
  else{
    // it is not an empty tree, need to find the insertion point
    KVTreeNode<T>* current = root;
    KVTreeNode<T>* parent = NULL;

    while(true){
      // iterate to find correct insertion point
      parent = current;

      if(k < current->key){
        // go left
        current = current->left;

        if(current == NULL){
          // we found the location AKA insertion point
          parent->left = node;
          break;
        }
      }
      else{
        // we go right
        current = current->right;

        if(current == NULL){
          parent->right = node;
          break;
        }
      }
    }
  }
}
template<class T>
bool KVBST<T>::searchNode(int k){
  if(isEmpty()) return false;
  else{
    // tree is not empty
    KVTreeNode<T>* current = root;
    while(current->key != k){
      if(k < current->key)
        current = current->left;
      else
        current = current->right;
      if(current == NULL)
        return false;
    }
  }
  return true;
}
template<class T>
bool KVBST<T>::deleteNode(int k){
  if(isEmpty()) return false; // root == NULL

  // invoke search to determine whether exist or not
  KVTreeNode<T>* parent = NULL;
  KVTreeNode<T>* current = root;
  bool isLeftNode = true;

  cout << "key to match -> " << k << endl;
  cout << "current k -> " << current->key << endl;
  while(current->key != k){
    cout << "current k -> " << current->key << endl;

    parent = current;

    // if(value < current->left){ // TODO
    if(k < current->key){
      isLeftNode = true;
      current = current->left;
    }
    else{
      isLeftNode = false;
      current = current->right;
    }
    if(current == NULL) return false; // value does not exist

    // at this point, we have found our key/value, now let's proceed to delete this node

    // case: node to be deleted does not have children, AKA a leaf node
    if(current->left == NULL && current->right == NULL){
      if(current == root){
        root = NULL;
      }
      else if(isLeftNode){
        parent->left = NULL;
      }
      else{
        parent->right = NULL;
      }
    }
    // case: node to be deleted has one child. need to determine whether descendant is left or right
    else if(current->right == NULL){
      // does not have a right child, must have left
      if(current == root){
        root = current->left;
      }
      else if(isLeftNode){
        parent->left = current->left;
      }
      else{
        parent->right = current->left;
      }
    }
    else if(current->left == NULL){
      // does not have a left child, must have right
      if(current == root){
        root = current->right;
      }
      else if(isLeftNode){
        parent->left = current->right;
      }
      else{
        parent->right = current->right;
      }
    }
    else{
      // the node to be deleted has two children
      // we have to find the successor

      KVTreeNode<T>* successor = getSuccessor(current); // current is the node to be deleted
      if(current == root) root = successor;
      else if(isLeftNode) parent->left = successor;
      else                parent->right = successor;

      successor->left = current->left;
    }
  }
  // cout << "current key " << current->key << endl;
  // delete (garbage collect) in this function or do we something special in the destructor
  return true;
}
template<class T>
KVTreeNode<T>* KVBST<T>::getSuccessor(KVTreeNode<T>* d){
  KVTreeNode<T>* sp = d; // successor parent
  KVTreeNode<T>* successor = d;
  KVTreeNode<T>* current = d->right;

  while(current != NULL){
    sp = successor;
    successor = current;
    current = current->left;
  }

  if(successor != d->right){
    sp->left = successor->right;
    successor->right = d->right;
  }
  return successor;
}
#endif
