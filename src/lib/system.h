#ifndef SYSTEM_H
#define SYSTEM_H
#include <string>
#include <iostream>


using namespace std;
/**
 * @brief The System interface
 */

class System
{
public:
    /**
     * @brief ~System
     */
    virtual ~System(){}

    /**
     * @brief getName
     * @return string
     */
    virtual string getName() const = 0;

    /**
     * @brief setName
     * @param value
     */
    virtual void setName(const string &value) = 0;

    /**
     * @brief getValue
     * @return double
     */
    virtual double getValue() const = 0;

    /**
     * @brief setValue
     * @param value
     */
    virtual void setValue(double value) = 0;

};

#endif // SYSTEM_H
