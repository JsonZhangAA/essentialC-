#include "Stack.h"
bool Stack::push(const string & tempStr){
    if(!full())
        _stack.push_back(tempStr);
    else    
        cout<<"stack is full!"<<endl;
}
bool Stack::pop(string & elem){
    if(!empty()){
        elem=_stack.back();
        _stack.pop_back();
        return true;
    }else{
        cout<<"stack is empty!"<<endl;
        return false;
    }
}
bool Stack::peek(string & elem){
    if(!empty()){
        elem=_stack.back();
        return true;
    }else{
        cout<<"stack is empty!"<<endl;
        return false;
    }
}
bool Stack::full(){
    return _stack.size()==_stack.max_size();
}
bool Stack::find(const string str){
    for(vector<string>::iterator it=_stack.begin();it!=_stack.end();it++){
        if(strcmp((*it).c_str(),str.c_str())==0){
            return true;
        }
    }
    return false;
}
int Stack::count(const string str){
    int count=0;
    for(vector<string>::iterator it=_stack.begin();it!=_stack.end();it++){
        if(strcmp((*it).c_str(),str.c_str())==0){
            count++;
        }
    }
    return count;
}