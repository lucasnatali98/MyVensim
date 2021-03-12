#ifndef FLOW_IMP_H
#define FLOW_IMP_H
#include "flow.h"
#include <iostream>
class Flow_Imp : public Flow
{
protected:
    string name;
    System *source;
    System *target;
public:
    Flow_Imp();
    /**
     * @brief Flow_Imp
     * @param name - type: String
     */
    Flow_Imp(string name);
    /**
     * @brief Flow_Imp
     * @param name
     * @param source
     * @param target
     */
    Flow_Imp(string name, System *source, System *target);

    /**
     * @brief ~Flow_Imp
     */
    virtual ~Flow_Imp();
    /**
     * @brief setSource
     * @param source : pointer to System
     */
    void setSource(System *source);
    /**
     * @brief setTarget
     * @param target : pointer to System
     */
    void setTarget(System *target);
    /**
     * @brief connect
     * @param s1 : pointer to System
     * @param s2 : pointer to System
     */
    void connect(System *s1, System *s2);

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

    bool operator==(const Flow &rhs) const ;

private:
    Flow_Imp(const Flow_Imp& f);
    /**
     * @brief operator =
     * @param f : type = Flow_Imp&
     * @return Flow_Imp
     */
    Flow_Imp &operator=(const Flow_Imp& f);
};

#endif // FLOW_IMP_H
