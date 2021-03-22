#include "unit_model.h"



void unit_Model_Constructor()
{
    Model* model1 = Model::createModel();
    Model* model2 = Model::createModel("model2");
    //Model* model3 = Model::createModel(*model2);

    assert(model1->getName() == "Default");

    assert(model2->getName() == "model2");

    //assert(*model3 == *model2);

    //delete model3;
    delete model2;
    delete model1;
}

void unit_Model_getName()
{
    Model* model = Model::createModel();
    model->setName("model");
    assert(model->getName() == "model");
    delete model;
}

void unit_Model_setName()
{
    Model* model = Model::createModel();

    model->setName("model_test");
    assert(model->getName() == "model_test");
}

void unit_Model_addFlow()
{
    Model* model = Model::createModel();
    Flow *flow = model->createFlow<ExponentialFlow>("ExpFlow");
    Flow *flow2 = model->createFlow<LogisticFlow>("LogFlow");


    auto it = find(model->flowIteratorBegin(),
                   model->flowIteratorEnd(), flow);


    assert(it != model->flowIteratorEnd());

    delete flow;
    delete flow2;
    delete model;

}

void unit_Model_addSystem()
{
    Model* model = Model::createModel();
    System *sys = model->createSystem("S1", 10);


    auto it = find(model->systemIteratorBegin(),
                   model->systemIteratorEnd(), sys);

    assert(it != model->systemIteratorEnd());

    delete sys;
    delete model;
}

void unit_Model_removeFlow()
{
    Model* model = Model::createModel();
    Flow *flow = model->createFlow<ExponentialFlow>();
    Flow *flow2 = model->createFlow<LogisticFlow>();

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
    Model* model = Model::createModel();
    System *sys = model->createSystem("S1", 10);
    System *sys2 = model->createSystem("S2", 20);

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
