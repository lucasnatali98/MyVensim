#ifndef FLOW_IMP_H
#define FLOW_IMP_H
#include "flow.h"
#include <iostream>
/**
 * @brief The Flow_Imp class
 */
class Flow_Imp : public Flow
{

protected:
    string name;
    System *source;
    System *target;
public:

    /**
     * @brief Flow_Imp: Constructor
     */
    Flow_Imp();
    /**
     * @brief Flow_Imp: Constructor
     * @param name
     */
    Flow_Imp(string name);
    /**
     * @brief Flow_Imp: Constructor
     * @param name: flow name
     * @param source: source system
     * @param target: target system
     */
    Flow_Imp(string name, System *source, System *target);

    /**
     * @brief ~Flow_Imp: Destructor
     */
    virtual ~Flow_Imp();
    /**
     * @brief setSource
     * @param source: source system
     */
    void setSource(System *source);
    /**
     * @brief setTarget
     * @param target: target system
     */
    void setTarget(System *target);
    /**
     * @brief connect: connects a flow to two systems
     * @param s1: source system
     * @param s2: target system
     */
    void connect(System *s1, System *s2);

    /**
     * @brief execute
     * @return double
     */
    virtual double execute();

    /**
     * @brief getName
     * @return string
     */
    string getName() const;
    /**
     * @brief setName
     * @param value - type: string
     */
    void setName(const string &value);
    /**
     * @brief getSource
     * @return System*
     */
    System *getSource() const;
    /**
     * @brief getTarget
     * @return System*
     */
    System *getTarget() const;

    /**
     * @brief operator ==
     * @param rhs: type = Flow&
     * @return bool
     */
    bool operator==(const Flow &rhs) const ;

    /**
     * @brief Flow_Imp
     * @param f
     */
    Flow_Imp(const Flow_Imp& flow);
private:



    /**
     * @brief operator =
     * @param f
     * @return Flow_Imp
     */
    Flow_Imp &operator=(const Flow_Imp& flow);
};

#endif // FLOW_IMP_H
