// #include "StudentTable.h"
// #include "FacultyTable.h"

#include "Student.h"
#include "Faculty.h"
#include "KVBST.h"

class Database{
  private:
    KVBST<Faculty*> *faculty;
    KVBST<Student*> *students;

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
    void deleteStudent(int id);
    void addFaculty(int id, string name, string level, string department);
    void changeAdvisor(int id);
    void removeAdvisee(int facultyId, int studentId);
    void rollback();
    void exit();
};
