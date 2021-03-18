#ifndef FLOW_H
#define FLOW_H
#include "system.h"
#include <string>
using namespace std;
/**
 * @brief The Flow interface
 */
class Flow
{
public:

    /**
     * @brief ~Flow: Destructor
     */
    virtual ~Flow(){}

    /**
     * @brief setSource
     * @param source: source system
     */
    virtual void setSource(System *source)=0;

    /**
     * @brief setTarget
     * @param target: target system
     */
    virtual void setTarget(System *target)=0;

    /**
     * @brief connect: connects a stream to two systems
     * @param s1: source system
     * @param s2: target system
     */
    virtual void connect(System *s1, System *s2)=0;

    /**
     * @brief execute: performs the function associated with the flow
     * @return double
     */
    virtual double execute()=0;

    /**
     * @brief getName
     * @return string
     */
    virtual string getName() const = 0;

    /**
     * @brief setName: set flow name
     * @param value: flow name
     */
    virtual void setName(const string &value) = 0;

    /**
     * @brief getSource: return the source system
     * @return System*
     */
    virtual System *getSource() const = 0;

    /**
     * @brief getTarget: return the target system
     * @return System*
     */
    virtual System *getTarget() const = 0;


};

#endif // FLOW_H
