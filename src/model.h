#ifndef MODEL_H
#define MODEL_H



#include "system.h"
#include "exponentialflow.h"
#include "logisticflow.h"
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


    /**
     * @brief add
     * @param s: type = System*
     */
    virtual void add(System *s)=0;

    /**
     * @brief add
     * @param f: type = Flow*
     */
    virtual void add(Flow *f)=0;

    /**
     * @brief remove
     * @param system: type = System*
     * @return bool
     */
    virtual bool remove(System *system)=0;

    /**
     * @brief remove
     * @param flow: type = Flow*
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
     * @brief printSystems
     */
    virtual void printSystems()=0;

    /**
     * @brief printFlows
     */
    virtual void printFlows()=0;

    /**
     * @brief results
     */
    virtual void results()=0;

    /**
     * @brief execute
     * @param start: type = double
     * @param final: type = double
     * @param inc: type = double
     */
    virtual void execute(double start, double final, double inc)=0;

    /**
     * @brief getName
     * @return string
     */
    virtual string getName() const = 0;

    /**
     * @brief setName
     * @param value: type = string
     */
    virtual void setName(const string &value)=0;
};

#endif // MODEL_H
