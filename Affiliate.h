#ifndef AFFILIATE_H
#define AFFILIATE_H
/*
  * @name Affiliate - abstract class that represents an affiliate of the university
  * @author Tarek El-Hajjaoui & Krishna Narayan
*/
#include <string>
using namespace std;
class Affiliate{
  protected:
    /* FIELDS */
    int m_id;
    string m_name;
    string m_level;
  public:
    Affiliate();  /* Default Constructor */
    Affiliate(const Affiliate& A); /* Copy Constructor */
    Affiliate(string name, string level); /* Overloaded Constructor */
    Affiliate(int id, string name, string level); /* Overloaded Constructor */
    ~Affiliate(); /* Destructor */
    /* ACCESSORS */
    int getId();
    string getName();
    string getLevel();
    /* MUTATORS */
    void setId(int id);
    void setName(string name);
    void setLevel(string level);
    /* PRINT FUNCTION */
    string toString();
};
#endif
