#ifndef LOGISTICFLOW_H
#define LOGISTICFLOW_H
#include <iostream>
#include "flow_imp.h"
using namespace std;
/**
 * @brief The LogisticFlow class
 */
class LogisticFlow : public Flow_Imp
{
public:
    /**
     * @brief LogisticFlow: Constructor
     */
    LogisticFlow();


    /**
     * @brief LogisticFlow: Constructor
     * @param name: flow name
     */
    LogisticFlow(string name);


    /**
     * @brief LogisticFlow: Constructor
     * @param name: flow name
     * @param source: source system
     * @param target: target system
     */
    LogisticFlow(string name, System *source, System *target);

    /**
     * @brief ~LogisticFlow: Destructor
     */
    virtual ~LogisticFlow();

    /**
     * @brief operator <<: override output operator
     * @param out
     * @param f
     * @return ostream
     */
    friend ostream &operator<<(ostream &out, const LogisticFlow &f);

    /**
     * @brief execute: performs the function associated with the flow
     * @return double
     */
    double execute();
};

#endif // LOGISTICFLOW_H
