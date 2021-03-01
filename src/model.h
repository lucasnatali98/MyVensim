#ifndef MODEL_H
#define MODEL_H
#include <vector>
#include <string>

#include "system.h"
#include <iostream>
#include <algorithm>
#include "exponentialflow.h"
#include "logisticflow.h"
using namespace std;

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

    virtual ~Model();

    void add(System *s);
    void add(Flow *f);

    bool remove(System *system);
    bool remove(Flow *flow);

    void printSystems();
    void printFlows();

    void results();
    void execute(double start, double final, double inc);

    vector<Flow *> getFlows() const;
    vector<System *> getSys() const;
    string getName() const;
    void setName(const string &value);



};

#endif // MODEL_H
