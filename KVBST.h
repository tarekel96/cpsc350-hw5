#ifndef BST_H
#define BST_H
#include "TreeNode.h"

template<class T>
class BST{
  private:
    /* FIELD */
    TreeNode<T>* root;
  public:
    BST();  /* Default Constructor */
    ~BST(); /* Destructor */
    /* CORE FUNCTIONS */
    void insertNode(int k, T value);
    bool searchNode(int k);
    bool deleteNode(int k);
    /* plays a role when deleting a node, *d represents the node to be deleted. */
    TreeNode<T>* getSuccessor(TreeNode<T> *d);
    /* AUXILIARY FUNCTIONS */
    bool isEmpty();
    T getMax();
    T getMin();
    /* PRINT FUNCTIONS */
    void recPrint(TreeNode<T>* node); // recursive print
    void printTree();
};
template<class T>
BST<T>::BST(){
  root = NULL; // empty tree
}
template<class T>
BST<T>::~BST(){
  // iterate and delete, this O(n)- cannot delete from top down
  if(root != NULL) delete root;
  root = NULL;
}
template<class T>
bool BST<T>::isEmpty(){
  return (root == NULL);
}
template<class T>
void BST<T>::recPrint(TreeNode<T>* node){
  if(node != NULL){
    recPrint(node->left);
    cout << node->key << endl;
    recPrint(node->right);
  }
}
template<class T>
void BST<T>::printTree(){
  recPrint(root);
}
template<class T>
T BST<T>::getMax(){
  if(isEmpty()) runtime_error("ERROR: Tree is empty, cannot getMax");

  TreeNode<T>* current = root;
  while(current->right != NULL){
    current = current->right;
  }

  return current->key;
}
template<class T>
T BST<T>::getMin(){
  if(isEmpty()) runtime_error("ERROR: Tree is empty, cannot getMin");

  TreeNode<T>* current = root;
  while(current->left != NULL){
    current = current->left;
  }

  return current->key;
}
template<class T>
void BST<T>::insertNode(int k, T value){

  TreeNode<T>* node = new TreeNode<T>(value);
  if(isEmpty()) root = node;
  else{
    // it is not an empty tree, need to find the insertion point
    TreeNode<T>* current = root;
    TreeNode<T>* parent = NULL;

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
bool BST<T>::searchNode(int k){
  if(isEmpty()) return false;
  else{
    // tree is not empty
    TreeNode<T>* current = root;
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
bool BST<T>::deleteNode(int k){
  if(isEmpty()) return false; // root == NULL

  // invoke search to determine whether exist or not
  TreeNode<T>* parent = NULL;
  TreeNode<T>* current = root;
  bool isLeftNode = true;

  while(current->key != k){
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

      TreeNode<T>* successor = getSuccessor(current); // current is the node to be deleted
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
TreeNode<T>* BST<T>::getSuccessor(TreeNode<T>* d){
  TreeNode<T>* sp = d; // successor parent
  TreeNode<T>* successor = d;
  TreeNode<T>* current = d->right;

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
