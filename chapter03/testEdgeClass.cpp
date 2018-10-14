#include <iostream>
#include <stdint.h>
#include <stdlib.h>
using namespace std;
typedef uint32_t V_IDX;
class Edges{
    public:
        virtual void display(){
            cout<<"this is base class"<<endl;
        }
};
class EdgesType1:public Edges{
    public:
        int src,dst;
        EdgesType1(int src_,int dst_):src(src_),dst(dst_){}
        void display(){
            cout<<"EdgeType1 display"<<endl;
            //cout<<src<<" "<<dst<<endl;
        }
};
class EdgesType2:public Edges{
    public:
        int src,dst;
        float weight;
        EdgesType2(int src_,int dst_,float weight_):src(src_),dst(dst_),weight(weight_){}
        void display(){
            cout<<src<<" "<<dst<<":"<<weight<<endl;
        }
};
class EdgesType1B:public Edges{
    public:
        V_IDX src,dst;
        EdgesType1B(V_IDX src_,V_IDX dst_):src(src_),dst(dst_){}
        void display(){
            cout<<src<<" "<<dst<<endl;
        }
};
class EdgesType2B:public Edges{
    public:
        V_IDX src,dst;
        float weight;
        EdgesType2B(V_IDX src_,V_IDX dst_,float weight_):src(src_),dst(dst_),weight(weight_){}
        void display(){
            cout<<src<<" "<<dst<<":"<<weight<<endl;
        }
};
int main(int argc,char * * argv)
{
    Edges * edges;
    int mode=atoi(argv[1]);
    switch(mode){
        case 0:edges=new EdgesType1(1,2);break;
        case 2:edges=new EdgesType2(1,2,3.0);break;
        case 1:edges=new EdgesType1B(4,5);break;
        case 3:edges=new EdgesType2B(4,5,6.0);break;
    }
    edges->display();
    return 0;
}