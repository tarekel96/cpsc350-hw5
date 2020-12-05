#ifndef DATABASE_H
#define DATABASE_H
/*
  * @name Database - class that represents a the system database (consisting of students and faculty)
  * @author Tarek El-Hajjaoui & Krishna Narayan
*/
#include <string>
#include "Undo.h"
#include "Student.h"
#include "Faculty.h"
#include "KVBST.h"
#include "InputException.h"
#include "Action.h"
class Database{
  private:
    InputException IE;
    Undo* undo;
  public:
    KVBST<Faculty*> *faculty;
    KVBST<Student*> *students;
    Database();
    ~Database();
    void printStudents();
    void printFaculty();
    void findStudent(int id);
    void findFaculty(int id);
    void printStudentAdvisor(int id);
    void printFacultyAdvisees(int id);
    void addStudent(int id, string name, string level, string major, double gpa, int advisorId);
    void addStudent(int id, string name, string level, string major, double gpa, int advisorId, bool beginUndo);
    void deleteStudent(int id, bool needReplaceAdvisor);
    void addFaculty(int id, string name, string level, string department);
    void addFaculty(int id, string name, string level, string department, bool beginUndo);
    void deleteFaculty(int id);
    void changeAdvisor(int studentId, int facultyId);
    void removeAdvisee(int facultyId, int studentId, bool needReplaceAdvisor);
    void replaceAdvisor(int facultyId, int studentId);
    int promptIdNumber(bool student);
    int promptValidIdNumber(bool student);
    void rollback();
    void exit();

    bool studentDatabaseIsEmpty();
    bool facultyDatabaseIsEmpty();
};
#endif
