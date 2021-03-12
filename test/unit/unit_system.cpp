#include "unit_system.h"



void unit_System_getName()
{
    System_Imp sys;
    assert(sys.getName().compare("Default system") == 0);

    sys.setName("S1");
    assert(sys.getName().compare("S1") == 0);

}

void unit_System_setName()
{
    System_Imp sys;
    sys.setName("S2");
    assert(sys.getName().compare("S2") == 0);
}

void unit_System_getValue()
{
    System_Imp sys;
    sys.setValue(100);
    assert(fabs(sys.getValue() - 100) <= 0.0001);
}

void unit_System_setValue()
{
    System_Imp sys;
    sys.setValue(100);
    assert(fabs(sys.getValue() - 100) <= 0.0001);
}
void unit_System_Constructor()
{
    System_Imp sys;
    assert(sys.getName() == "Default system");
    assert(sys.getValue() == 0.0);
}


void run_unit_tests_System()
{
    unit_System_Constructor();
    unit_System_setName();
    unit_System_setValue();
    unit_System_getName();
    unit_System_getValue();
}

