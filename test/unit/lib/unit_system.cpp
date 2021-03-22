#include "unit_system.h"


void unit_System_Constructor()
{
    Model *model = Model::createModel();
    System *sys = model->createSystem();
    //Default Constructor
    assert(sys->getName() == "Default system");
    assert(sys->getValue() == 0.0);


    //Constructor(name, value)
    System *sys2 = model->createSystem("S1", 40.333);
    assert(sys2->getName() == "S1");
    assert(sys2->getValue() == 40.333);

    //Copy Constructor
    //System_Imp *sys3 = new System_Imp(*sys2);
    //assert(*sys3 == *sys2);
}
/*
void unit_System_assignmentOperator()
{

    System *s1 = new System_Imp("S1", 20);
    System *s2 = new System_Imp();

    s2 = s1;

    assert(s2 == s1);
}
*/
void unit_System_getName()
{
    Model *model = Model::createModel();
    System *sys = model->createSystem();

    assert(sys->getName().compare("Default system") == 0);

    sys->setName("S1");
    assert(sys->getName().compare("S1") == 0);

}

void unit_System_setName()
{
    Model *model = Model::createModel();
    System *sys = model->createSystem();

    sys->setName("S2");
    assert(sys->getName().compare("S2") == 0);
}

void unit_System_getValue()
{
    Model *model = Model::createModel();
    System *sys = model->createSystem();

    sys->setValue(100);
    assert(fabs(sys->getValue() - 100) <= 0.0001);
}

void unit_System_setValue()
{
    Model *model = Model::createModel();
    System *sys = model->createSystem();
    sys->setValue(100);
    assert(fabs(sys->getValue() - 100) <= 0.0001);
}

/*
void unit_System_equalityOperator()
{
    System_Imp *s1 = new System_Imp("s1", 10);
    System_Imp *s2 = new System_Imp("s1", 10);
    assert(*s1 == *s2);
}
*/
void run_unit_tests_System()
{
    unit_System_Constructor();
   // unit_System_equalityOperator();
    //unit_System_assignmentOperator();
    unit_System_setName();
    unit_System_setValue();
    unit_System_getName();
    unit_System_getValue();
}





