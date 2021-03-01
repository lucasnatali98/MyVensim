#ifndef FLOW_H
#define FLOW_H
#include "system.h"
#include <string>
using namespace std;
class Flow
{
protected:
    string name;
    System *source;
    System *target;
public:
    Flow();
    Flow(string name, System *source, System *target);
    virtual ~Flow();
    void setSource(System *source);
    void setTarget(System *target);
    void connect(System *s1, System *s2);
    virtual float execute()=0;
    string getName() const;
    void setName(const string &value);
    System *getSource() const;
    System *getTarget() const;

private:
    Flow(const Flow& f);
    Flow &operator=(const Flow& f);

};

#endif // FLOW_H
