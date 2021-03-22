#include <iostream>
#include "lib/unit_system.h"
#include "lib/unit_flow.h"

#include "lib/unit_model.h"
using namespace std;

int main()
{
    run_unit_tests_Flow();
    run_unit_tests_System();
    run_unit_test_Model();
    return 0;
}
