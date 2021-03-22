#include "funcional_tests.h"

void exponentialFuncionalTest()
{

    Model *model = Model::createModel("Model");
    System* s1 = model->createSystem("pop1", 100);
    System* s2 = model->createSystem("pop2", 0);
    Flow *flow = model->createFlow<ExponentialFlow>("ExpFlow", s1,s2);


    model->execute(0, 100, 1);

    assert(fabs(s1->getValue() - 36.6032) < 0.0001);
    assert(fabs(s2->getValue() - 63.3968) < 0.0001);
    assert(fabs(flow->execute() - 0.366032) < 0.0001);

    delete model;
    delete s1;
    delete s2;
    delete flow;

}

void logisticalFuncionalTest()
{
    Model *model = Model::createModel("Model");
    System* s1 = model->createSystem("p1", 100);
    System* s2 = model->createSystem("p2", 10);
    Flow *flow = model->createFlow<LogisticFlow>("LogFlow",s1,s2);

    /*
    flow->setSource(s1);
    flow->setTarget(s2);
    flow->setName("LogFlow");
    model->add(s1);
    model->add(s2);
    model->add(flow);
    */

    model->execute(0,100,1);
    assert(fabs(s1->getValue()-88.2167) < 0.0001);
    assert(fabs(s2->getValue()-21.7834) < 0.0001);
    assert(fabs(flow->execute()-0.150046) < 0.0001);


    delete model;
    delete s1;
    delete s2;
    delete flow;
}

void complexFuncionalTest()
{

    Model *model = Model::createModel("Model");
    System* q1 = model->createSystem("q1", 100);
    System* q2 = model->createSystem("q2", 0);
    System* q3 = model->createSystem("q3", 100);
    System* q4 = model->createSystem("q4", 0);
    System* q5 = model->createSystem("q5", 0);
    Flow* f = model->createFlow<ExponentialFlow>("f", q1, q2);
    Flow* g = model->createFlow<ExponentialFlow>("g", q1, q3);
    Flow* r = model->createFlow<ExponentialFlow>("r", q2, q5);
    Flow* t = model->createFlow<ExponentialFlow>("t", q2, q3);
    Flow* u = model->createFlow<ExponentialFlow>("u", q3, q4);
    Flow* v = model->createFlow<ExponentialFlow>("v", q4, q1);


    model->execute(0, 100,1);

    assert(fabs(q1->getValue() - 31.8513) < 0.0001);
    assert(fabs(q2->getValue() - 18.4003) < 0.0001);
    assert(fabs(q3->getValue() - 77.1143) < 0.0001);
    assert(fabs(q4->getValue() - 56.1728) < 0.0001);
    assert(fabs(q5->getValue() - 16.4612) < 0.0001);

    delete  model;
    delete q1;
    delete q2;
    delete q3;
    delete q4;
    delete q5;
    delete f;
    delete g;
    delete t;
    delete r;
    delete u;
    delete v;
}

