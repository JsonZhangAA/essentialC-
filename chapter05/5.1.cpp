#include <iostream>
#include <vector>
#include <string>
#include <exception>
using namespace std;
#define maxLength 5
class Stack_Exception:public exception{
public:
    Stack_Exception(const char * _msg):msg(_msg){
    }
    const char * what(){
        return msg.c_str();
    }
private:
    string msg;
};
class PushOnFull:public Stack_Exception{
public:
    PushOnFull():Stack_Exception("Push on Full"){}
};
class PullOnEmpty:public Stack_Exception{
public:
    PullOnEmpty():Stack_Exception("pull on empty"){}
};

class stack{
    public:
        stack(){
        }
        virtual ~stack(){
            cout<<"stack 析构"<<endl;
        }
        virtual bool pop(string & temp)=0;
        virtual void push(string temp)=0;
        //virtual string peek(const stack & st,int size)=0;
        virtual string peekHelp(int size)=0;
        virtual void print() const=0;
        vector<string> sta;
        inline int size(){
            return sta.size();
        }
        inline bool empty(){
            return sta.size()==0;
        }
        inline bool full(){
            return sta.size()==maxLength;
        }
};
class LIFO_Stack:public stack{
    public:
        LIFO_Stack(){

        }
        ~LIFO_Stack(){
            cout<<"LIFO_Stack析构"<<endl;
        }
        bool pop(string & temp);
        void push(string temp);
        //virtual string peek(const stack & st,int size);
        virtual string peekHelp(int size);
        virtual void print() const;
};
string LIFO_Stack::peekHelp(int size){
    return " ";
}
bool LIFO_Stack::pop(string & temp){
    if(sta.size()==0)
        return false;
    temp=sta[sta.size()-1];
    sta.pop_back();
    return true;
}
void LIFO_Stack::push(string temp){
    if(sta.size()==maxLength){
        throw PushOnFull();
    }
    sta.push_back(temp);
}
void peek(stack & st,int size){
    if(st.peekHelp(size)!=" ")
        cout<<"peek: "<<st.peekHelp(size)<<endl;
    else    
        cout<<"peek failed!"<<endl;
}
void LIFO_Stack::print() const{
    for(int i=sta.size()-1;i>=0;i--){
        cout<<sta[i]<<" "<<endl;
    }
    cout<<endl;
}
class Peekback_Stack:public LIFO_Stack{
    public:
        string peekHelp(int size);
        //void print();
};
/*void Peekback_Stack::print(){
    for(int i=0;i<sta.size();i++){
        cout<<sta[i]<<endl;
    }
    cout<<endl;
}*/
string Peekback_Stack::peekHelp(int size){
    if(size>=sta.size()){
        return " ";
    }else{
        return sta[size];
    }
}
ostream & operator<<(ostream & os,stack & st){
    st.print();
    return os;
}
int main(){
    try{
        LIFO_Stack st;
        string str;
        while(cin>>str&&str!="quit")
            st.push(str);
        cout<<"\n"<<"About to call peek() with LIFO_Stack"<<endl;
        peek(st,st.size()-1);
        cout<<st;

        Peekback_Stack pst;
        while(!st.empty()){
            string t;
            if(st.pop(t))
                pst.push(t);
        }
        cout<<"About to call peek() with Peekback_Stack"<<endl;
        peek(pst,pst.size()-1);
        cout<<pst;
    }
    catch(PushOnFull & msg){
        cout<<msg.what();
        cout<<endl;
    }
    return 0;
}