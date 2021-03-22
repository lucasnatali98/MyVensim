#ifndef MODEL_IMPL_H
#define MODEL_IMPL_H
#include "model.h"
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include "system_imp.h"
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
    static vector<Model*> models;
public:

    /**
     * @brief Model_Impl: Constructor
     */
    Model_Impl();

    /**
     * @brief Model_Impl: Constructor
     * @param name: string
     */
    Model_Impl(string name);

    virtual ~Model_Impl();

    //factory
    static Model* createModel(string model_name);
    static Model* createModel();
    System* createSystem(string, double);
    System* createSystem();

    /**
     * @brief getName
     * @return string
     */
    string getName() const;

    /**
     * @brief setName
     * @param value: string
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
     * @brief execute
     * @param start: initial time - type: double
     * @param final: final time - type: double
     * @param inc: increment time - type: double
     */
    void execute(double start, double final, double inc);

    /**
     * @brief printSystems: print all systems in the model
     */
    void printSystems();
    /**
     * @brief printFlows: print all flows in the model
     */
    void printFlows();

    /**
     * @brief results: results after model execution
     */
    void results();

    /**
     * @brief operator == : equality operator overload
     * @param rhs: Model&
     * @return
     */

    /**
     * @brief operator = : overload of the assignment operator
     * @return Model_Impl
     */
    Model_Impl &operator=(Model_Impl&);

    /**
     * @brief Model_Impl: constructor of copy
     * @param copy: Model_Impl&
     */
    Model_Impl(const Model_Impl &copy);


    bool operator==(const Model_Impl &rhs) const ;
protected:
    /**
     * @brief add: add a system in the model
     * @param system: System*
     */
    void add(System *system);

    /**
     * @brief add: add a flow in the model
     * @param flow: Flow*
     */
    void add(Flow *flow);

    /**
     * @brief remove: remove a System
     * @param system: System*
     * @return bool
     */
    bool remove(System *system);

    /**
     * @brief remove: remove a flow
     * @param flow: Flow*
     * @return bool
     */
    bool remove(Flow *flow);


};

#endif // MODEL_IMPL_H
