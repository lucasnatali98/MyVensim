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
     * @param name: flow name
     */
    ExponentialFlow(string name);

    /**
     * @brief ExponentialFlow
     * @param name: flow name
     * @param source: source system
     * @param target: target system
     */
    ExponentialFlow(string name, System *source, System *target);
    /**
     * @brief ~ExponentialFlow: Destructor
     */
    virtual ~ExponentialFlow();

    /**
     * @brief operator << : override output operator
     * @param out
     * @param f
     * @return ostream
     */
    friend ostream &operator<<(ostream &out, const ExponentialFlow &f);

    /**
     * @brief execute: performs the function associated with the flow
     * @return double
     */
    double execute();


};

#endif // EXPONENTIALFLOW_H
