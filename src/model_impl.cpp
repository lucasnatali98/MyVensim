#include "model_impl.h"

Model_Impl::Model_Impl()
{
    this->name = "Default";
}

Model_Impl::Model_Impl(string name)
{
    this->name = name;
}

Model_Impl::~Model_Impl()
{

}
void Model_Impl::add(System *system)
{
    sys.push_back(system);
}
void Model_Impl::add(Flow *flow)
{
    flows.push_back(flow);
}
string Model_Impl::getName() const
{
    return name;
}

void Model_Impl::setName(const string &value)
{
    name = value;
}


Model_Impl &Model_Impl::operator=(Model_Impl &copy)
{
    if(&copy == this) return (*this);


    for(vector<System*>::iterator it = systemIteratorBegin(); it!= systemIteratorEnd(); it++)
    {
        delete *it;
    }

    this->sys.clear();

    for(vector<Flow*>::iterator it=flowIteratorBegin(); it!=flowIteratorEnd(); it++)
    {
        delete *it;
    }
    this->flows.clear();


    System* saux;
    for(vector<System*>::iterator it = copy.systemIteratorBegin(); it != copy.systemIteratorEnd(); ++it)
    {
        saux = (*it);
        this->add(saux);
    }
    Flow* faux;
    for(vector<Flow*>::iterator it = copy.flowIteratorBegin(); it != copy.flowIteratorEnd(); ++it){
        faux = (*it);
        this->add(faux);
    }


    return (*this);
}

Model_Impl::Model_Impl(const Model_Impl &copy)
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

Model_Impl::SystemIterator Model_Impl::systemIteratorBegin()
{
    return sys.begin();
}

Model_Impl::SystemIterator Model_Impl::systemIteratorEnd()
{
    return sys.end();
}

Model_Impl::FlowIterator Model_Impl::flowIteratorBegin()
{
    return flows.begin();
}

Model_Impl::FlowIterator Model_Impl::flowIteratorEnd()
{
    return flows.end();
}



void Model_Impl::results(){
    for(auto it : sys){
        cout<<it->getName()<<endl;
    }
}

bool Model_Impl::operator==(const Model &rhs) const
{

}

void Model_Impl::execute(double start, double final, double inc)
{
    vector<double> values;
    System *source;
    System *target;
    int k=0;
    for (int i = start; i < final; i+=inc) {
        for (int j=0; j<flows.size(); j++) {
            values.push_back(flows[j]->execute());
        }
        for (vector<Flow*>::iterator it = flowIteratorBegin(); it != flowIteratorEnd(); ++it) {
            source = (*it)->getSource();
            source->setValue(source->getValue() - values[k]);
            target = (*it)->getTarget();
            target->setValue(target->getValue() + values[k]);
            k++;
        }
    }
}

bool Model_Impl::remove(System *system)
{
    if(system != nullptr){
        vector<System*>::iterator itSystem;
        itSystem = find(sys.begin(), sys.end(), system);
        sys.erase(itSystem);
        return true;
    }
    return false;
}


bool Model_Impl::remove(Flow *flow)
{
    if(flow != nullptr){
        vector<Flow*>::iterator itFlow;
        itFlow = find(flows.begin(), flows.end(), flow);
        flows.erase(itFlow);
        return true;
    }

    return false;

}

void Model_Impl::printSystems()
{

    for(auto it : sys){
        cout<<it->getName()<<endl;
    }
}

void Model_Impl::printFlows()
{
    for(vector<Flow*>::iterator it = flowIteratorBegin(); it != flowIteratorEnd(); it++){
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
