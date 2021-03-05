#ifndef EXPONENTIALFLOW_H
#define EXPONENTIALFLOW_H
#include "flow.h"
#include <iostream>
using namespace std;
/**
 * @brief The ExponentialFlow class
 */
class ExponentialFlow : public Flow
{
public:
    ExponentialFlow();
    ExponentialFlow(string name, System *source, System *target);
    friend ostream &operator<<(ostream &out, const ExponentialFlow &f);
    float execute();
};

#endif // EXPONENTIALFLOW_H
