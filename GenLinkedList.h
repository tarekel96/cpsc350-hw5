#ifndef GENLINKEDLIST_H
#define GENLINKEDLIST_H
#include <iostream>
#include "ListNode.h"
using namespace std;
template<class T>
class GenLinkedList{
  private:
    ListNode<T>* front;
    ListNode<T>* back;
    unsigned int size;
  public:
    GenLinkedList();
    ~GenLinkedList();
    void insertFront(T d);
    void insertBack(T d);
    T removeFront();
    T removeBack();
    int find(T value); // search
    T deletePos(int pos);
    void printList();
    bool isEmpty();
    unsigned int getSize();
};
template<class T>
GenLinkedList<T>::GenLinkedList(){
  size = 0;
  front = NULL;
  back = NULL;
}
template<class T>
GenLinkedList<T>::~GenLinkedList(){
  ListNode<T>* curr = front;
  ListNode<T>* next = front;
  while(curr != NULL){
    next = curr->next;
    delete curr;
    curr = next;
  }
}
template<class T>
void GenLinkedList<T>::insertFront(T d){
  ListNode<T>* node = new ListNode<T>(d);
  if(size == 0){
    back = node;
  }
  node->next = front;
  front = node;
  ++size;
}
template<class T>
void GenLinkedList<T>::insertBack(T d){
  ListNode<T>* node = new ListNode<T>(d);
  if(size == 0){
      front = node;
  }
  else{
     back->next = node;
  }
  back = node;
  ++size;
}
template<class T>
void GenLinkedList<T>::printList(){
  ListNode<T>* curr = front;
  while(curr != NULL){
    cout << curr->data << " ";
    curr = curr->next;
  }
  cout << endl;
}
template<class T>
bool GenLinkedList<T>::isEmpty(){
  return (size == 0);
}
template<class T>
unsigned int GenLinkedList<T>::getSize(){
  return size;
}
template<class T>
T GenLinkedList<T>::removeFront(){
  T temp = front->data;
  ListNode<T>* ft = front;
  front = front->next;
  ft->next = NULL;
  --size;
  delete ft;
  return temp;
}
template<class T>
T GenLinkedList<T>::removeBack(){
  T temp;
  ListNode<T>* nodeToDelete = back;
  if(!isEmpty()){
    ListNode<T>* curr = front;
    ListNode<T>* prev = curr;
    while(curr->next != NULL){
      prev = curr;
      curr = curr->next;
    }
    back = prev;
    temp = back->data;
    back->next = NULL;
    nodeToDelete->next = NULL;
    size--;
  }
  else {
    runtime_error("ERROR: cannot removeBack");
  }
  delete nodeToDelete;
  return temp;
}
template<class T>
int GenLinkedList<T>::find(T val){
  int pos = -1;
  ListNode<T>* curr = front;
  while(curr != NULL){
    ++pos;
    if(curr->data == val){
      break;
    }
    curr = curr->next;
  }
  if(curr == NULL){
    pos = -1;
  }
  return pos;
}
template<class T>
T GenLinkedList<T>::deletePos(int pos){
  int p = 0; // position
  ListNode<T>* curr = front;
  ListNode<T>* prev = front;

  while(p != pos){
    prev = curr;
    curr = curr->next;
    p++;
  }

  prev->next = curr->next;
  curr->next = NULL;
  int temp = curr->data;
  size--;

  delete curr;
  return temp;
}
#endif
