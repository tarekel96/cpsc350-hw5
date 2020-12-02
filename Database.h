#ifndef DATABASE_H
#define DATABASE_H
/*
  * @name Database - class that represents a the system database (consisting of students and faculty)
  * @author Tarek El-Hajjaoui & Krishna Narayan
*/
#include "Student.h"
#include "Faculty.h"
#include "KVBST.h"
class Database{
  private:
    KVBST<Faculty*> *faculty;
    KVBST<Student*> *students;
    string file;

  public:
    Database(string f);
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
    void deleteFaculty(int id);
    void changeAdvisor(int studentId, int facultyId);
    void removeAdvisee(int facultyId, int studentId);
    void processFile();
    void rollback();
    void exit();
};
#endif
