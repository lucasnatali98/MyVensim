#ifndef SYSTEM_IMP_H
#define SYSTEM_IMP_H
#include "system.h"
#include <string>
/**
 * @brief The System_Imp class
 */
class System_Imp : public System
{
protected:
    string name;
    double value;
public:
    /**
     * @brief System_Imp: Constructor
     */
    System_Imp();

    /**
     * @brief ~System_Imp: Destructor
     */
    virtual ~System_Imp();

    /**
     * @brief System_Imp
     * @param name - type:string
     * @param value - type: double
     */
    System_Imp(string name, double value);

    /**
     * @brief getName
     * @return string
     */
    string getName() const;

    /**
     * @brief setName
     * @param value - type: string
     */
    void setName(const string &value);

    /**
     * @brief getValue
     * @return double
     */
    double getValue() const;

    /**
     * @brief setValue
     * @param value - type: double
     */
    void setValue(double value);


    /**
     * @brief operator <<
     * @param out: type: ostream&
     * @param s : type: System&
     * @return ostream
     */
    friend ostream &operator<<(ostream &out, const System &s);

    bool operator==(const System &rhs) const ;


private:

    System_Imp(const System_Imp& sys);
    /**
     * @brief operator =
     * @return System_Imp
     */
    System_Imp &operator=(System_Imp&);

};

#endif // SYSTEM_IMP_H
