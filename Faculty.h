#ifndef FACULTY_H
#define FACULTY_H
#include "Affiliate.h"
using namespace std;
/*
  * @name Faculty - class that represents a faculty member of the university
  * @author Tarek El-Hajjaoui & Krishna Narayan
*/
class Faculty: public Affiliate{
  private:
    /* FIELDS */
    string m_department;
    // TODO List StudentIdNumbers;
  public:
    Faculty();  /* Default Constructor */
    Faculty(const Faculty &F);  /* Copy Constructor */
    Faculty(string name, string level, string department); /* Overloaded Constructor */
    Faculty(int id, string name, string level, string department); /* Overloaded Constructor */
    ~Faculty(); /* Destructor */
    /* ACCESSORS */
    string getDepartment();
    /* MUTATORS */
    void setDepartment(string department);
    /* PRINT FUNCTION */
    string toString();
};
#endif
