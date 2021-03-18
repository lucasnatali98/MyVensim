#ifndef UNIT_MODEL_H
#define UNIT_MODEL_H
#include <assert.h>
#include <cmath>
#include <algorithm>
#include "../../src/lib/model.h"
#include "../../src/lib/model_impl.h"
#include "../../src/lib/flow.h"
#include "../../src/lib/flow_imp.h"
#include "../../src/lib/exponentialflow.h"
#include "../../src/lib/logisticflow.h"
#include "../../src/lib/system_imp.h"


void unit_Model_getName();
void unit_Model_setName();
void unit_Model_Constructor();
//void unit_Model_assignmentOperator();
void unit_Model_addFlow();
void unit_Model_addSystem();
void unit_Model_removeFlow();
void unit_Model_removeSystem();
void unit_Model_execute();
void run_unit_test_Model();

#endif // UNIT_MODEL_H
