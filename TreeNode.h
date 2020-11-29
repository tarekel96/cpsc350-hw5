#ifndef TREENODE_H
#define TREENODE_H
#include <iostream>
using namespace std;

template<class T>
class TreeNode{
  public:
    TreeNode();
    TreeNode(T k); // passing in a key/value
    // TreeNode(int k, string value) another way to do it
    ~TreeNode();

    T key; // data as well as the key; search and sort on the key not the value
    TreeNode* left;
    TreeNode* right;
};
template<class T>
TreeNode<T>::TreeNode(){
  left = NULL;
  right = NULL;
}
template<class T>
TreeNode<T>::TreeNode(T k){
  left = NULL;
  right = NULL;
  key = k;
}
template<class T>
TreeNode<T>::~TreeNode(){
  if(left != NULL) delete left;
  if(right != NULL) delete right;
  left = NULL;
  right = NULL;
}
#endif
