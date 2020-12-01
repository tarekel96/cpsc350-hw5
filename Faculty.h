#ifndef FACULTY_H
#define FACULTY_H
/*
  * @name Faculty - class that represents a faculty member of the university
  * @author Tarek El-Hajjaoui & Krishna Narayan
*/
#include "Affiliate.h"
#include "GenLinkedList.h"
using namespace std;
class Faculty: public Affiliate{
  private:
    /* FIELDS */
    string m_department;
    GenLinkedList<int>* m_StudentIds; /* list of integers corresponding to all of the faculty member’s advisees’ ids */
  public:
    Faculty();  /* Default Constructor */
    Faculty(const Faculty &F);  /* Copy Constructor */
    Faculty(string name, string level, string department); /* Overloaded Constructor */
    Faculty(int id, string name, string level, string department); /* Overloaded Constructor */
    Faculty(int id, string name, string level, string department, GenLinkedList<int>* StudentIds); /* Overloaded Constructor */
    ~Faculty(); /* Destructor */
    /* ACCESSORS */
    string getDepartment();
    /* MUTATORS */
    void setDepartment(string department);
    /* PRINT FUNCTIONS */
    string toString();
    void printStudentIds();
    void addAdvisee(int id);
    void removeAdvisee(int id);
};
#endif
