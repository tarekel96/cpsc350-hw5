#ifndef STUDENT_H
#define STUDENT_H
#include "Affiliate.h"
using namespace std;
/*
  * @name Student - class that represents a student of the university
  * @author Tarek El-Hajjaoui & Krishna Narayan
*/
class Student: public Affiliate{
  private:
    /* FIELDS */
    string m_major;
    double m_gpa;
    int m_advisorId;
  public:
    Student();  /* Default Constructor */
    Student(const Student &S);  /* Copy Constructor */
    Student(string name, string level, string major, double gpa, int advisorId); /* Overloaded Constructor */
    Student(int id, string name, string level, string major, double gpa, int advisorId); /* Overloaded Constructor */
    ~Student(); /* Destructor */
    /* ACCESSORS */
    string getMajor();
    double getGpa();
    int getAdvisorId();
    /* MUTATORS */
    void setMajor(string major);
    void setGpa(double gpa);
    void setAdvisorId(int advisorId);
    /* PRINT FUNCTION */
    string toString();
};
#endif
