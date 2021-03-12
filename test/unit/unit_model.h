#ifndef UNIT_MODEL_H
#define UNIT_MODEL_H
#include <assert.h>
#include <cmath>
#include <algorithm>
#include "../../src/model.h"
#include "../../src/model_impl.h"
#include "../../src/flow.h"
#include "../../src/flow_imp.h"
#include "../../src/exponentialflow.h"
#include "../../src/logisticflow.h"
#include "../../src/system_imp.h"


void unit_Model_getName();
void unit_Model_setName();
void unit_Model_Constructor();

void unit_Model_addFlow();
void unit_Model_addSystem();
void unit_Model_removeFlow();
void unit_Model_removeSystem();
void unit_Model_execute();
void run_unit_test_Model();

#endif // UNIT_MODEL_H
