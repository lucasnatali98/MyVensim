#ifndef MODEL_H
#define MODEL_H
#include <vector>
#include <string>
#include "flow.h"
#include "system.h"
#include <iostream>
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
    void results();
    void execute(double start, double final, double inc);
    void add(System *s);
    void add(Flow *f);
    vector<Flow *> getFlows() const;
    vector<System *> getSys() const;
    void remove();
    void update();
    string getName() const;
    void setName(const string &value);
};

#endif // MODEL_H
