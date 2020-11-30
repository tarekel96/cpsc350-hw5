#ifndef KVTREENODE_H
#define KVTREENODE_H
#include <iostream>
using namespace std;

template<class T>
class KVTreeNode{
  public:
    KVTreeNode();
    // KVTreeNode(T k); // passing in a key/value
    KVTreeNode(int k, T value);
    ~KVTreeNode();

    int key;
    T value;
     // data as well as the key; search and sort on the key not the value
    KVTreeNode* left;
    KVTreeNode* right;
};
template<class T>
KVTreeNode<T>::KVTreeNode(){
  left = NULL;
  right = NULL;
}
template<class T>
KVTreeNode<T>::KVTreeNode(int k, T v){
  left = NULL;
  right = NULL;
  key = k;
  value = v;
}
template<class T>
KVTreeNode<T>::~KVTreeNode(){
  if(left != NULL) delete left;
  if(right != NULL) delete right;
  left = NULL;
  right = NULL;
}
#endif
