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
    Flow_Imp *f1 = new Flow_Imp();
    Flow_Imp *f2 = new Flow_Imp("flow2");
    Flow_Imp *f3 = new Flow_Imp("flow3", s1, s2);

    Flow_Imp *f4 = new Flow_Imp(*f3);

    //Empty constructor
    assert(f1->getName() == "Default");
    assert(f1->getSource() == nullptr);
    assert(f1->getTarget() == nullptr);

    //Constructor(name)
    assert(f2->getName() == "flow2");
    assert(f2->getSource() == nullptr);
    assert(f2->getTarget() == nullptr);

    //Constructor(name, source, target)
    assert(f3->getName() == "flow3");
    assert(f3->getSource() == s1);
    assert(f3->getTarget() == s2);

    //Copy Constructor
    assert(*f4 == *f3);


    delete s1;
    delete s2;
    delete f1;
    delete f2;
    delete f3;
    delete f4;
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

    delete expF1;
    delete logF1;
    delete expF2;
    delete logF2;
    delete s1;
    delete s2;
    delete s3;
    delete s4;

}
void unit_Flow_assignmentOperator()
{

    System_Imp *s1 = new System_Imp("S1", 10);
    System_Imp *s2 = new System_Imp("S2", 30);
    Flow_Imp *f1 = new ExponentialFlow("F1", s1, s2);
    Flow_Imp *f2 = new ExponentialFlow("F2", s1, s2);
    Flow_Imp *f3 = new LogisticFlow("F3", s1, s2);
    Flow_Imp *f4 = new LogisticFlow("F4", s1 , s2);


    f2 = f1;
    f4 = f3;

    assert(*f2 == *f1);
    assert(*f4 == *f3);


}

void unit_Flow_equalityOperator()
{
    System *s1 = new System_Imp("S1", 10);
    System *s2 = new System_Imp("S2", 40);
    Flow_Imp *f1 = new ExponentialFlow("expFlow", s1, s2);
    Flow_Imp *f2 = new ExponentialFlow("expFlow", s1, s2);

    Flow_Imp *f3 = new LogisticFlow("logFlow", s1, s2);
    Flow_Imp *f4 = new LogisticFlow("logFlow", s1, s2);

    assert(*f1 == *f2);
    assert(*f3 == *f4);


    delete f1;
    delete f2;
    delete f3;
    delete f4;
    delete s1;
    delete s2;
}

void run_unit_tests_Flow()
{
    unit_Flow_Constructor();
    unit_Flow_equalityOperator();
    unit_Flow_assignmentOperator();
    unit_Flow_setName();
    unit_Flow_getName();
    unit_Flow_setTarget();
    unit_Flow_getTarget();
    unit_Flow_setSource();
    unit_Flow_getSource();
    unit_Flow_connect();
    unit_Flow_execute();

}



