#include "funcional_tests.h"

void exponentialFuncionalTest()
{

    Model *model = new Model();
    System* s1 = new System("pop1", 100);
    System* s2 = new System("pop2", 0);
    Flow *flow = new ExponentialFlow();
    flow->setSource(s1);
    flow->setTarget(s2);
    flow->setName("ExpFlow");

    model->add(s1);
    model->add(s2);
    model->add(flow);

    model->execute(0, 100, 1);

    assert(fabs(s1->getValue() - 36.6032) < 0.0001);
    assert(fabs(s2->getValue() - 63.3968) < 0.0001);
    assert(fabs(flow->execute() - 0.366032) < 0.0001);


}

void logisticalFuncionalTest()
{

    System* s1 = new System("p1", 100);
    System* s2 = new System("p2", 10);
    Flow *flow = new LogisticFlow();
    Model *model = new Model();
    flow->setSource(s1);
    flow->setTarget(s2);
    flow->setName("LogFlow");
    model->add(s1);
    model->add(s2);
    model->add(flow);
    model->execute(0,100,1);
    assert(fabs(s1->getValue()-88.2167) < 0.0001);
    assert(fabs(s2->getValue()-21.7834) < 0.0001);
    assert(fabs(flow->execute()-0.150046) < 0.0001);

}

void complexFuncionalTest()
{

    Model *ComplexModel = new Model();
    System* q1 = new System("q1", 100);
    System* q2 = new System("q2", 0);
    System* q3 = new System("q3", 100);
    System* q4 = new System("q4", 0);
    System* q5 = new System("q5", 0);
    Flow* f = new ExponentialFlow("f", q1, q2);
    Flow* g = new ExponentialFlow("g", q1, q3);
    Flow* r = new ExponentialFlow("r", q2, q5);
    Flow* t = new ExponentialFlow("t", q2, q3);
    Flow* u = new ExponentialFlow("u", q3, q4);
    Flow* v = new ExponentialFlow("v", q4, q1);

    f->connect(q1,q2);
    t->connect(q2,q3);
    u->connect(q3,q4);
    v->connect(q4,q1);
    g->connect(q1,q3);
    r->connect(q2,q5);

    ComplexModel->add(q1);
    ComplexModel->add(q2);
    ComplexModel->add(q3);
    ComplexModel->add(q4);
    ComplexModel->add(q5);
    ComplexModel->add(f);
    ComplexModel->add(g);
    ComplexModel->add(r);
    ComplexModel->add(t);
    ComplexModel->add(u);
    ComplexModel->add(v);

    ComplexModel->execute(0, 100,1);


    assert(fabs(q1->getValue() - 31.8513) <= 0.0001);
    assert(fabs(q2->getValue() - 18.4003) <= 0.0001);
    assert(fabs(q3->getValue() - 77.1143) <= 0.0001);
    assert(fabs(q4->getValue() - 56.1728) <= 0.0001);
    assert(fabs(q5->getValue() - 16.4612) <= 0.0001);

}

