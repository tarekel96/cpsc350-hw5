// #include "StudentTable.h"
// #include "FacultyTable.h"

class Database{
  private:
    BST<Faculty> *faculty;
    BST<Student> *students;

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
    void addFaculty(int id, string name, string level, string department, List* advisees);
    void changeAdvisor(int id);
    void removeAdvisee(int facultyId, int studentId);
    void rollback();
    void exit();
}
