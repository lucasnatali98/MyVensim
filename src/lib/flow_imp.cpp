#include "flow_imp.h"

Flow_Imp::Flow_Imp()
{
    this->name = "Default";
    this->target = nullptr;
    this->source = nullptr;
}

Flow_Imp::Flow_Imp(string name)
{
    this->name = name;
}

Flow_Imp::Flow_Imp(string name, System *source, System *target)
{
    this->name = name;
    this->source = source;
    this->target = target;
}

Flow_Imp::~Flow_Imp(){}



void Flow_Imp::setSource(System *source)
{
    this->source = source;
}

void Flow_Imp::setTarget(System *target)
{
    this->target = target;
}

void Flow_Imp::connect(System *s1, System *s2)
{
    this->source = s1;
    this->target = s2;
}

double Flow_Imp::execute()
{

}



string Flow_Imp::getName() const
{
    return name;
}

void Flow_Imp::setName(const string &value)
{
    name = value;
}

System *Flow_Imp::getSource() const
{
    return source;
}

System *Flow_Imp::getTarget() const
{
    return target;
}

bool Flow_Imp::operator==(const Flow_Imp &rhs) const
{
    return this->name == rhs.getName() &&
            this->source == rhs.getSource() &&
            this->target == rhs.getTarget();
}


Flow_Imp::Flow_Imp(const Flow_Imp &f)
{
    this->name = f.getName();
    this->target = f.getTarget();
    this->source = f.getSource();
}


Flow_Imp &Flow_Imp::operator=(const Flow_Imp &f)
{
    if(&f == this){
        return *this;
    }
    this->name = f.name;
    this->target = f.target;
    this->source = f.source;

    return *this;
}

