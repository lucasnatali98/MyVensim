#ifndef MODEL_H
#define MODEL_H

#include "system.h"
#include "flow.h"
#include <vector>

using namespace std;

/**
 * @brief The Model interface
 */
class Model
{
protected:
    typedef vector<System*>::iterator SystemIterator;
    typedef vector<Flow*>::iterator FlowIterator;

public:
    /**
     * @brief ~Model: Destructor
     */
    virtual ~Model(){}

    //Factory

    static Model* createModel(string model_name);
    static Model* createModel();

    virtual System* createSystem(string, double)=0;
    virtual System* createSystem()=0;

    template<typename FLOW_IMP>
    Flow* createFlow(string flow_name = "", System* source=nullptr, System* target=nullptr)
    {
       Flow* flow = new FLOW_IMP(flow_name, source, target);
       add(flow);
       return flow;
    }
    /**
     * @brief add: add a system in the model
     * @param system
     */
    virtual void add(System *system)=0;

    /**
     * @brief add: add a flow in the model
     * @param flow
     */
    virtual void add(Flow *flow)=0;


    /**
     * @brief remove: remove a system
     * @param system
     * @return bool
     */
    virtual bool remove(System *system)=0;

    /**
     * @brief remove: remove a flow
     * @param flow
     * @return bool
     */
    virtual bool remove(Flow *flow)=0;

    /**
     * @brief systemIteratorBegin: return an object vector<System*> to the first position
     * @return SystemIterator
     */
    virtual SystemIterator systemIteratorBegin()=0;

    /**
     * @brief systemIteratorEnd: return an object vector<System*> to the last position
     * @return SystemIterator
     */
    virtual SystemIterator systemIteratorEnd()=0;

    /**
     * @brief flowIteratorBegin: return an object vector<Flow*> to the first position
     * @return FlowIterator
     */
    virtual FlowIterator flowIteratorBegin()=0;

    /**
     * @brief flowIteratorEnd: return an object vector<Flow*> to the last position
     * @return FlowIterator
     */
    virtual FlowIterator flowIteratorEnd()=0;

    /**
     * @brief printSystems: print all systems
     */
    virtual void printSystems()=0;

    /**
     * @brief printFlows: print all flows
     */
    virtual void printFlows()=0;

    /**
     * @brief results: results after model execution
     */
    virtual void results()=0;

    /**
     * @brief execute: runs the model
     * @param start: initial time
     * @param final: final time
     * @param inc: increment
     */
    virtual void execute(double start, double final, double inc)=0;

    /**
     * @brief getName
     * @return string
     */
    virtual string getName() const = 0;

    /**
     * @brief setName
     * @param value
     */
    virtual void setName(const string &value)=0;
};

#endif // MODEL_H
