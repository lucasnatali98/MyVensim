#ifndef LOGISTICFLOW_H
#define LOGISTICFLOW_H
#include <iostream>
#include "flow.h"
using namespace std;
/**
 * @brief The LogisticFlow class
 */
class LogisticFlow : public Flow
{
public:
    LogisticFlow();
    LogisticFlow(string name, System *source, System *target);
    friend ostream &operator<<(ostream &out, const LogisticFlow &f);
    float execute();
};

#endif // LOGISTICFLOW_H
