// #include "StudentTable.h"
//
// StudentTable::StudentTable(){
//   studentTree = new BST<Student>();
// }
//
// StudentTable::~StudentTable(){
//     delete studentTree;
// }
//
// void StudentTable::print(){
//   studentTree->printTree();
// }
//
// // void StudentTable::find(int id){
// //
// // }
// //
// // void StudentTable::getAdvisor(int id){
// //
// // }
//
// void StudentTable::addStudent(int id, string name, string level, string major, double gpa, int advisorId){
//   // if(studentTree->searchNode(id)){
//   //   cout << "a student with the given id already exists." << endl;
//   // }else{
//   //   Student s(id, name, level, major, gpa, advisorId);
//   //   studentTree->insertNode(s);
//   // }
//   Student s(id, name, level, major, gpa, advisorId);
//   studentTree->insertNode(s);
// }
//
// // void StudentTable::removeStudent(int id){
// //   if(studentTree->searchNode(id)){
// //     studentTree->deleteNode(id);
// //   }else{
// //     cout << "there does not exist a student with the given id" << endl;
// //   }
// // }
//
// // void StudentTable::changeAdvisor(int id){
// //
// // }
