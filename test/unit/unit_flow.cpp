#include "unit_flow.h"


void unit_Flow_setName()
{
    Flow_Imp f1;
    f1.setName("F1");
    assert(f1.getName() == "F1");
}

void unit_Flow_getName()
{
    Flow_Imp f1;
    f1.setName("F1");
    assert(f1.getName() == "F1");
}

void unit_Flow_getSource()
{
    System *s1 = new System_Imp("S1", 10);
    Flow *f1 = new Flow_Imp("f1");
    f1->setSource(s1);
    assert(f1->getSource() == s1);

    delete s1;
    delete f1;

}

void unit_Flow_setSource()
{
    System *s1 = new System_Imp("S1", 10);
    Flow *f1 = new Flow_Imp("f1");
    f1->setSource(s1);
    assert(f1->getSource() == s1);

    delete s1;
    delete f1;
}

void unit_Flow_setTarget()
{
    System *s1 = new System_Imp("S1", 10);
    Flow *f1 = new Flow_Imp("f1");
    f1->setTarget(s1);
    assert(f1->getTarget() == s1);

    delete s1;
    delete f1;
}

void unit_Flow_getTarget()
{
    System *s1 = new System_Imp("S1", 10);
    Flow *f1 = new Flow_Imp("f1");
    f1->setTarget(s1);
    assert(f1->getTarget() == s1);

    delete s1;
    delete f1;
}

void unit_Flow_connect()
{
    System *s1 = new System_Imp("S1", 10);
    System *s2 = new System_Imp("S2", 20);
    Flow *f1 = new Flow_Imp("f1");
    f1->setSource(s1);
    f1->setTarget(s2);
    assert(f1->getSource() == s1);
    assert(f1->getTarget() == s2);

    delete s1;
    delete s2;
    delete f1;
}
void unit_Flow_Constructor()
{
    System *s1 = new System_Imp("S1", 10);
    System *s2 = new System_Imp("S2", 15);
    Flow *f1 = new Flow_Imp();
    Flow *f2 = new Flow_Imp("flow2");
    Flow *f3 = new Flow_Imp("flow3", s1, s2);

    assert(f1->getName() == "Default");
    assert(f1->getSource() == nullptr);
    assert(f1->getTarget() == nullptr);
    assert(f2->getName() == "flow2");
    assert(f3->getName() == "flow3");
    assert(f3->getSource() == s1);
    assert(f3->getTarget() == s2);

    delete s1;
    delete s2;
    delete f1;
    delete f2;
    delete f3;
}

void unit_Flow_execute()
{
    Flow *expF1 = new ExponentialFlow("ExpFlow");
    Flow *logF1 = new LogisticFlow("LogisticFlow");
    Flow *expF2 = new ExponentialFlow("ExpFlow2");
    Flow *logF2 = new LogisticFlow("LogisticFlow2");

    System *s1 = new System_Imp("S1", 100);
    System *s2 = new System_Imp("S2", 0);
    System *s3 = new System_Imp("S3", 100);
    System *s4 = new System_Imp("S4", 10);

    expF1->connect(s1,s2);
    logF1->connect(s3, s4);

    expF2->connect(s1,s2);
    logF2->connect(s3,s4);


    assert(expF1->execute() != logF1->execute());
    assert(expF1->execute() == expF2->execute());
    assert(logF1->execute() == logF2->execute());

}

void run_unit_tests_Flow()
{
    unit_Flow_Constructor();
    unit_Flow_setName();
    unit_Flow_getName();
    unit_Flow_setTarget();
    unit_Flow_getTarget();
    unit_Flow_setSource();
    unit_Flow_getSource();
    unit_Flow_connect();
    unit_Flow_execute();

}

