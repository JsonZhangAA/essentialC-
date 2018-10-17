#include <string>
#include <vector>
#include <iostream>
#include <cstring>
using namespace std;
class Stack{
public:
    bool push(const string &);
    bool pop(string &elem);
    bool peek(string & elem);
    bool empty(){
        return _stack.empty();
    }
    bool full();
    int size(){
        return _stack.size();
    }
    bool find(const string str);
    int count(const string str);
private:
    vector<string> _stack;
};