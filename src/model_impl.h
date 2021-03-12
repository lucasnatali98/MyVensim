#ifndef MODEL_IMPL_H
#define MODEL_IMPL_H
#include "model.h"
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include "exponentialflow.h"
#include "logisticflow.h"

/**
 * @brief The Model_Impl class
 */

class Model_Impl : public Model
{
protected:

    vector<Flow*> flows;
    vector<System*> sys;
    string name;
public:

    Model_Impl();

    /**
     * @brief Model_Impl
     * @param name - type: string
     */
    Model_Impl(string name);

    virtual ~Model_Impl();
    /**
     * @brief getName
     * @return string
     */
    string getName() const;

    /**
     * @brief setName
     * @param value
     */
    void setName(const string &value);

    /**
     * @brief systemIteratorBegin: return an object vector<System*> to the first position
     * @return SystemIterator
     */
    SystemIterator systemIteratorBegin();

    /**
     * @brief systemIteratorEnd: return an object vector<System*> to the last position
     * @return SystemIterator
     */
    SystemIterator systemIteratorEnd();

    /**
     * @brief flowIteratorBegin: return an object vector<Flow*> to the first position
     * @return FlowIterator
     */
    FlowIterator flowIteratorBegin();

    /**
     * @brief flowIteratorEnd: return an object vector<Flow*> to the last position
     * @return FlowIterator
     */
    FlowIterator flowIteratorEnd();

    /**
     * @brief add
     * @param system : pointer to System
     */
    void add(System *system);

    /**
     * @brief add
     * @param flow : pointer to Flow
     */
    void add(Flow *flow);

    /**
     * @brief remove
     * @param system : pointer to System
     * @return bool
     */
    bool remove(System *system);

    /**
     * @brief remove
     * @param flow : pointer to Flow
     * @return bool
     */
    bool remove(Flow *flow);
    /**
     * @brief execute
     * @param start: initial time - type: double
     * @param final: final time - type: double
     * @param inc: increment time - type: double
     */
    void execute(double start, double final, double inc);

    /**
     * @brief printSystems
     */
    void printSystems();
    /**
     * @brief printFlows: list all flows in the model
     */
    void printFlows();
    /**
     * @brief results
     */
    void results();

    bool operator==(const Model &rhs) const ;
private:

    /**
     * @brief operator =
     * @return Model_Impl
     */
    Model_Impl &operator=(Model_Impl&);

    /**
     * @brief Model_Impl
     * @param copy: Model_Impl&
     */
    Model_Impl(const Model_Impl &copy);
};

#endif // MODEL_IMPL_H
