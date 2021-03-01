#ifndef SYSTEM_H
#define SYSTEM_H
#include <string>
#include <iostream>
using namespace std;

class System
{
protected:
    string name;
    double value;
private:
    System &operator=(System&);
    System(const System& sys);
public:
    System();
    System(string name, double value);
    virtual ~System();
    string getName() const;
    void setName(const string &value);
    double getValue() const;
    void setValue(double value);
    friend ostream &operator<<(ostream &out, const System &s);

};

#endif // SYSTEM_H
