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
     * @brief ~Flow
     */
    virtual ~Flow(){}

    /**
     * @brief setSource
     * @param source: type = System*
     */
    virtual void setSource(System *source)=0;

    /**
     * @brief setTarget
     * @param target: type = System*
     */
    virtual void setTarget(System *target)=0;

    /**
     * @brief connect
     * @param s1: type=System*
     * @param s2: type=System*
     */
    virtual void connect(System *s1, System *s2)=0;

    /**
     * @brief execute
     * @return double
     */
    virtual double execute()=0;

    /**
     * @brief getName
     * @return string
     */
    virtual string getName() const = 0;

    /**
     * @brief setName
     * @param value: type = string
     */
    virtual void setName(const string &value) = 0;

    /**
     * @brief getSource
     * @return System*
     */
    virtual System *getSource() const = 0;

    /**
     * @brief getTarget
     * @return System*
     */
    virtual System *getTarget() const = 0;


private:

   // Flow &operator=(const Flow& f);
};

#endif // FLOW_H
