#include "Stack.h"

int main(void){
    Stack stc;
    string str;
    cin>>str;
    while(strcmp(str.c_str(),"q"))  {
        stc.push(str);
        cin>>str;
    }
    cout<<"hehe"<<endl;
    stc.peek(str);
    cout<<"最后一个string为："<<str<<endl;
    stc.pop(str);
    stc.peek(str);
    cout<<"pop一个string后，此时最后一个string为"<<str<<endl;
    cout<<"Stack size is "<<stc.size()<<endl;
    cout<<"最后一个元素存在否： "<<stc.find(str)<<endl;
    cout<<"存在"<<stc.count(str)<<"次"<<endl;
    return 0;
}