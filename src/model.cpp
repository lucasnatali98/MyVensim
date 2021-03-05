#include "model.h"


bool Model::remove(System *system)
{
    if(system != nullptr){
        vector<System*>::iterator itSystem;
        itSystem = find(sys.begin(), sys.end(), system);
        sys.erase(itSystem);
        return true;
    }
    return false;
}

bool Model::remove(Flow *flow)
{
    if(flow != nullptr){
        vector<Flow*>::iterator itFlow;
        itFlow = find(flows.begin(), flows.end(), flow);
        flows.erase(itFlow);
        return true;
    }

    return false;

}

void Model::printSystems()
{
    for(auto it : sys){
        cout<<*it<<endl;
    }
}

void Model::printFlows()
{

    for(vector<Flow*>::iterator it = flows.begin(); it != flows.end(); it++){
        ExponentialFlow *ef = dynamic_cast<ExponentialFlow*>(*it);
        LogisticFlow *lf = dynamic_cast<LogisticFlow*>(*it);

        if(ef != nullptr){
            cout<<*ef<<endl;
        }
        if(lf != nullptr){
            cout<<*lf<<endl;
        }
    }

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



void Model::results(){
    for(auto it : sys){
        cout<<*it<<endl;
    }
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


    for(vector<System*>::iterator it= sys.begin(); it!=sys.end(); it++)
    {
        delete *it;
    }

    this->sys.clear();

    for(vector<Flow*>::iterator it=flows.begin(); it!=flows.end(); it++)
    {
        delete *it;
    }
    this->flows.clear();


    System* saux;
    for(vector<System*>::iterator it = copy.sys.begin(); it != copy.sys.end(); ++it){
        saux = (*it);
        this->add(saux);
    }
    Flow* faux;
    for(vector<Flow*>::iterator it = copy.flows.begin(); it != copy.flows.end(); ++it){
        faux = (*it);
        this->add(faux);
    }


    return (*this);
}

Model::Model(const Model &copy)
{
    this->setName(copy.getName());

    System* saux;
    for(vector<System*>::const_iterator it = copy.sys.begin(); it != copy.sys.end(); ++it){
        saux = (*it);
        this->add(saux);
    }

    Flow* faux;
    for(vector<Flow*>::const_iterator it = copy.flows.begin(); it != copy.flows.end(); ++it){
        faux = (*it);
        this->add(faux);
    }

}
