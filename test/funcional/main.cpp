#include "funcional_tests.h"
#include "../../src/flow.h"
#include "../../src/system.h"
#include "../../src/model.h"
#include "../../src/exponentialflow.h"
#include "../../src/logisticflow.h"


int valor(int a,int b){
    return a+b;
}
int main(){
    exponentialFuncionalTest();
    logisticalFuncionalTest();
    complexFuncionalTest();
    //System *s1 = new System("S1", 19);


    return 0;
}
