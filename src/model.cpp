#include "model.h"


vector<Flow *> Model::getFlows() const
{
    return flows;
}

vector<System *> Model::getSys() const
{
    return sys;
}

Model::Model()
{
    this->name = "Default";

}

Model::Model(string name)
{
    this->name = name;
}

Model::~Model(){}



void Model::results()
{

}

void Model::execute(double start, double final, double inc)
{
    vector<double> values;
    System *source;
    System *target;
    int k=0;
    for (int i = start; i < final; i+=inc) {
        for (int j=0; j<flows.size(); j++) {
            values.push_back(flows[j]->execute());
        }
        for (vector<Flow*>::iterator it = flows.begin(); it != flows.end(); ++it) {
            source = (*it)->getSource();
            source->setValue(source->getValue() - values[k]);
            target = (*it)->getTarget();
            target->setValue(target->getValue() + values[k]);
            k++;
        }
    }

}

void Model::add(System *system)
{
    sys.push_back(system);
}
void Model::add(Flow *flow)
{
    flows.push_back(flow);
}

string Model::getName() const
{
    return name;
}

void Model::setName(const string &value)
{
    name = value;
}

Model &Model::operator=(Model &copy)
{
    if(&copy == this) return (*this);

    for (auto&& item : flows) {
        delete item;
    }
    for (auto&& item : sys){
        delete item;
    }

    System* aux;
    for(vector<System*>::iterator it = copy.getSys().begin(); it != copy.getSys().end(); ++it){
        aux = (*it);
        add(aux);
    }
    Flow* bux;
    for(vector<Flow*>::iterator it = copy.getFlows().begin(); it != copy.getFlows().end(); ++it){
        bux = (*it);
        this->add(bux);
    }

    return (*this);
}

Model::Model(const Model &copy)
{
    this->setName(copy.getName());

    System* saux;
    for(vector<System*>::iterator it = copy.getSys().begin(); it != copy.getSys().end(); ++it){
        saux = (*it);
        add(saux);
    }

    Flow* faux;
    for(vector<Flow*>::iterator it = copy.getFlows().begin(); it != copy.getFlows().end(); ++it){
        faux = (*it);
        this->add(faux);
    }

}
