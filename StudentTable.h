#include "BST.h"

class StudentTable{

  private:
    BST<Student> *studentTree;

  public:
    FacultyTable();
    ~FacultyTable();
    void print();
    void find(int id);
    void getAdvisor(int id);
    void addStudent(int id, string name, string level, string major, double gpa, int advisorId);
    void deleteStudent(int id);
    void changeAdvisor(int id);
}
