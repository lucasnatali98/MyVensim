#include "exponentialflow.h"

ExponentialFlow::ExponentialFlow(){}

ExponentialFlow::ExponentialFlow(string name) : Flow_Imp(name)
{

}

ExponentialFlow::ExponentialFlow(string name, System *source, System *target) :
    Flow_Imp(name, source, target)
{}

ExponentialFlow::~ExponentialFlow()
{

}

double ExponentialFlow::execute()
{
    return getSource()->getValue() * 0.01;
}

ostream& operator<<(ostream &out, const ExponentialFlow &f){
    out <<f.getName()<<": "<<f.getSource()<<", "<<f.getTarget()<<endl;
    return out;
}

