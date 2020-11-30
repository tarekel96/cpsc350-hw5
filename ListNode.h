#ifndef LISTNODE_H
#define LISTNODE_H
/*
  * @name ListNode - represents a Single Linked List Node
  * @author Tarek El-Hajjaoui & Krishna Narayan
*/
template<class T>
class ListNode{
    public:
        ListNode(); /* Default Constructor */
        ListNode(T d); /* Overloaded Constructor */
        ~ListNode(); /* Destructor */
        /* FIELDS */
        T data;
        ListNode *next; /* Next Pointer */
};
/* Default Constructor - NULL out fields */
template<class T>
ListNode<T>::ListNode(){
    data = NULL;
    next = NULL;
}
/* Default Constructor - set data and NULL out other fields */
template<class T>
ListNode<T>::ListNode(T d){
    data = d;
    next = NULL;
}
/* Destructor - delete next if exits and NULL out fields */
template<class T>
ListNode<T>::~ListNode(){
    next = NULL;
}
#endif
