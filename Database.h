#include "StudentTable.h"
#include "FacultyTable.h"

class Database{
  private:
    FacultyTable *faculty;
    StudentTable *students;

  public:
    Database();
    ~Database();
    void printStudents();
    void printFaculty();
    void findStudent(int id);
    void findFaculty(int id);
    void printStudentAdvisor(int id);
    void printFacultyAdvisees(int id);
    void addStudent(int id, string name, string level, string major, double gpa, int advisorId);

}
