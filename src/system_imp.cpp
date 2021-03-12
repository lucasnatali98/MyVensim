#include "system_imp.h"


string System_Imp::getName() const
{
    return name;
}

void System_Imp::setName(const string &value)
{
    name = value;
}

double System_Imp::getValue() const
{
    return value;
}

void System_Imp::setValue(double value)
{
    this->value = value;
}

bool System_Imp::operator==(const System &rhs) const
{
    return this->name == rhs.getName() &&
            this->value == rhs.getValue();
}
System_Imp::System_Imp()
{
    this->name="Default system";
    this->value=0.0;
}


System_Imp::~System_Imp(){}

System_Imp::System_Imp(string name, double value)
{
    this->name = name;
    this->value = value;
}
ostream& operator<<(ostream &out, const System &s){
    out <<s.getName()<<", "<<s.getValue()<<endl;
    return out;
}
System_Imp &System_Imp::operator=(System_Imp &copy)
{
    if(&copy == this) return (*this);

    value = copy.value;
    name= copy.name;

    return (*this);
}
System_Imp::System_Imp(const System_Imp &sys)
{
    value = sys.value;
    name = sys.name;
}
