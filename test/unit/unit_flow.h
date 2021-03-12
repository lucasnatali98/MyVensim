#ifndef UNIT_FLOW_H
#define UNIT_FLOW_H
#include "../../src/flow.h"
#include "../../src/flow_imp.h"
#include "../../src/exponentialflow.h"
#include "../../src/logisticflow.h"
#include "../../src/system_imp.h"
#include <assert.h>
#include <cmath>

void unit_Flow_Constructor();
void unit_Flow_setName();
void unit_Flow_getName();
void unit_Flow_getSource();
void unit_Flow_setSource();
void unit_Flow_setTarget();
void unit_Flow_getTarget();
void unit_Flow_connect();
void unit_Flow_execute();
void run_unit_tests_Flow();

#endif // UNIT_FLOW_H
