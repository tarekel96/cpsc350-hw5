#include "BST.h"

class FacultyTable{

  private:
    BST<Faculty> *facultyTree;

  public:
    FacultyTable();
    ~FacultyTable();
    void print();
    void find(int id);
    void getAdvisees(int id);
    void addFaculty(int id, string name, string level, string department, List* advisees);
    void deleteFaculty(int id);
    void removeAdvisee(int facultyId, int studentId);
}
