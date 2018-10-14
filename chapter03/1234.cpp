#include <iostream>
using namespace std;

class Virtualbase
{
public:
    virtual void Demon(){ cout << "this is Virtualbase class" << endl; };
    virtual void Base() { cout << "this is farther class" << endl; };
};


class SubVirtual :public Virtualbase
{
public:
    void Demon() {
        cout << " this is SubVirtual!" << endl;
    }


    void Base() {
        cout << "this is subclass Base" << endl;
    }
};


int  main()
{
    Virtualbase* inst = new SubVirtual();
    inst->Demon();
    inst->Base();
    return 0;
}