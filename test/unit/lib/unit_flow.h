#ifndef UNIT_FLOW_H
#define UNIT_FLOW_H

#include "../../../src/lib/exponentialflow.h"
#include "../../../src/lib/logisticflow.h"
#include "../../../src/lib/flow_imp.h"

#include "../../../src/lib/model.h"
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
void unit_Flow_equalityOperator();
//void unit_Flow_assignmentOperator();

void run_unit_tests_Flow();

#endif // UNIT_FLOW_H
