#include "flow.h"

Flow::Flow()
{
    this->name = "Default";
    this->target = nullptr;
    this->source = nullptr;
}

Flow::Flow(string name, System *source, System *target)
{
    this->name = name;
    this->source = source;
    this->target = target;
}

Flow::~Flow(){}

void Flow::setSource(System *source)
{
    this->source = source;
}

void Flow::setTarget(System *target)
{
    this->target = target;
}

void Flow::connect(System *s1, System *s2)
{
    this->source = s1;
    this->target = s2;
}



string Flow::getName() const
{
    return name;
}

void Flow::setName(const string &value)
{
    name = value;
}

System *Flow::getSource() const
{
    return source;
}

System *Flow::getTarget() const
{
    return target;
}

Flow::Flow(const Flow &f)
{
    this->name = f.getName();
    this->target = f.getTarget();
    this->source = f.getSource();
}


Flow &Flow::operator=(const Flow &f)
{
    if(&f == this){
        return *this;
    }
    this->name = f.name;
    this->target = f.target;
    this->source = f.source;

    return *this;
}

