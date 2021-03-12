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
     * @param name: type = string
     * @param source: type = System*
     * @param target: type = System*
     */

    /**
     * @brief LogisticFlow
     * @param name: type = string
     */
    LogisticFlow(string name);


    /**
     * @brief LogisticFlow
     * @param name: type = string
     * @param source: type = System*
     * @param target: type = System*
     */
    LogisticFlow(string name, System *source, System *target);

    /**
     * @brief ~LogisticFlow: Destructor
     */
    virtual ~LogisticFlow();

    /**
     * @brief operator <<: override output operator
     * @param out: type = ostream&
     * @param f: type = LogisticFlow&
     * @return ostream
     */
    friend ostream &operator<<(ostream &out, const LogisticFlow &f);

    /**
     * @brief execute
     * @return double
     */
    double execute();
};

#endif // LOGISTICFLOW_H
