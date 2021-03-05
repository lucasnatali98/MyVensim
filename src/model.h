#ifndef MODEL_H
#define MODEL_H
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

#include "system.h"
#include "exponentialflow.h"
#include "logisticflow.h"
using namespace std;
/**
 * @brief The Model class
 */
class Model
{
protected:
    vector<Flow*> flows;
    vector<System*> sys;
    string name;

private:
    Model &operator=(Model&);
    Model(const Model &copy);
public:
    Model();
    Model(string name);
    typedef typename vector<Flow*>::iterator itFlow;
    typedef typename vector<System*>::iterator itSystem;
    virtual ~Model();

    void add(System *s);
    void add(Flow *f);

    bool remove(System *system);
    bool remove(Flow *flow);

    void printSystems();
    void printFlows();

    void results();
    void execute(double start, double final, double inc);


    string getName() const;
    void setName(const string &value);



};

#endif // MODEL_H
