#ifndef EXPONENTIALFLOW_H
#define EXPONENTIALFLOW_H
#include "flow_imp.h"
#include <iostream>
using namespace std;
/**
 * @brief The ExponentialFlow class
 */
class ExponentialFlow : public Flow_Imp
{
public:
    /**
     * @brief ExponentialFlow: Constructor
     */
    ExponentialFlow();

    /**
     * @brief ExponentialFlow
     * @param name: type = string
     */
    ExponentialFlow(string name);

    /**
     * @brief ExponentialFlow
     * @param name: type = string
     * @param source: type = System*
     * @param target: type = System*
     */
    ExponentialFlow(string name, System *source, System *target);
    /**
     * @brief ~ExponentialFlow: Destructor
     */
    virtual ~ExponentialFlow();

    /**
     * @brief operator << : override output operator
     * @param out: type = ostream&
     * @param f: type = ExponentialFlow&
     * @return ostream
     */
    friend ostream &operator<<(ostream &out, const ExponentialFlow &f);

    /**
     * @brief execute
     * @return double
     */
    double execute();
};

#endif // EXPONENTIALFLOW_H
