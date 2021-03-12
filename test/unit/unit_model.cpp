#include "unit_model.h"



void unit_Model_Constructor()
{
    Model* model1 = new Model_Impl();
    Model* model2 = new Model_Impl("model2");
   // Model* model3 = new Model_Impl(model2);

    assert(model1->getName() == "Default");
    assert(model2->getName() == "model2");
    //assert(model3 == model2);

   // delete model3;
    delete model2;
    delete model1;
}

void unit_Model_getName()
{
    Model* model = new Model_Impl();
    model->setName("model");
    assert(model->getName() == "model");
    delete model;
}

void unit_Model_setName()
{
    Model_Impl m1;
    m1.setName("model_test");
    assert(m1.getName() == "model_test");
}

void unit_Model_addFlow()
{
    Model* model = new Model_Impl();
    Flow *flow = new ExponentialFlow("ExpFlow");
    Flow *flow2 = new LogisticFlow("LogFlow");
    model->add(flow);
    model->add(flow2);

    auto it = find(model->flowIteratorBegin(),
                   model->flowIteratorEnd(), flow);


    assert(it != model->flowIteratorEnd());

    delete flow;
    delete flow2;
    delete model;

}

void unit_Model_addSystem()
{
    Model* model = new Model_Impl();
    System *sys = new System_Imp("S1", 10);
    model->add(sys);

    auto it = find(model->systemIteratorBegin(),
                   model->systemIteratorEnd(), sys);

    assert(it != model->systemIteratorEnd());

    delete sys;
    delete model;
}

void unit_Model_removeFlow()
{
    Model* model = new Model_Impl();
    Flow *flow = new ExponentialFlow();
    Flow *flow2 = new LogisticFlow();
    model->add(flow);
    model->add(flow2);
    model->remove(flow);

    auto it = find(model->flowIteratorBegin(),
                   model->flowIteratorEnd(), flow);


    assert(it == model->flowIteratorEnd());

    delete flow;
    delete flow2;
    delete model;
}

void unit_Model_removeSystem()
{
    Model* model = new Model_Impl();
    System *sys = new System_Imp("S1", 10);
    System *sys2 = new System_Imp("S2", 20);
    model->add(sys);
    model->add(sys2);
    model->remove(sys);

    auto it = find(model->systemIteratorBegin(),
                   model->systemIteratorEnd(), sys);


    assert(it == model->systemIteratorEnd());

    delete sys;
    delete model;
}


void unit_Model_execute()
{

}

void run_unit_test_Model()
{
    unit_Model_Constructor();
    unit_Model_addFlow();
    unit_Model_addSystem();
    unit_Model_removeFlow();
    unit_Model_removeSystem();
    unit_Model_getName();
    unit_Model_setName();
    unit_Model_execute();
}
