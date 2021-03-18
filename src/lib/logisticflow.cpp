#include "logisticflow.h"

LogisticFlow::LogisticFlow(){}

LogisticFlow::LogisticFlow(string name) : Flow_Imp(name)
{

}

LogisticFlow::LogisticFlow(string name, System *source, System *target) :
    Flow_Imp(name, source, target)
{}

LogisticFlow::~LogisticFlow()
{

}

double LogisticFlow::execute()
{
    return getTarget()->getValue() * 0.01 * (1 - (getTarget()->getValue()/70));
}

ostream& operator<<(ostream &out, const LogisticFlow &f){
    out <<f.getName()<<": "<<f.getSource()<<", "<<f.getTarget()<<endl;
    return out;
}

