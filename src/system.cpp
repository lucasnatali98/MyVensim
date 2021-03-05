#include "system.h"

string System::getName() const
{
    return name;
}

void System::setName(const string &value)
{
    name = value;
}

double System::getValue() const
{
    return value;
}

void System::setValue(double value)
{
    this->value = value;
}

System::System()
{
    this->name="Default system";
    this->value=0.0;
}

System::System(string name, double value)
{
    this->name = name;
    this->value = value;
}
ostream& operator<<(ostream &out, const System &s){
    out <<s.getName()<<", "<<s.getValue()<<endl;
    return out;
}
System &System::operator=(System &copy)
{
    if(&copy == this) return (*this);

    value = copy.value;
    name= copy.name;

    return (*this);
}

System::System(const System &sys)
{
    value = sys.value;
    name = sys.name;
}

System::~System(){}
