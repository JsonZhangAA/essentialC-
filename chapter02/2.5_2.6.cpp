#include<iostream>
#include<vector>
using namespace std;
template <typename T>
void imax(T  a,T  b);

template<typename T>
void imax(vector<T> a);

template<typename T>
void imax(vector<T>  ves,int len);
int main(void)
{
    int a=0,b=1;
    imax(a,b);
    double a1=0.0,b1=0.2;
    imax(a1,b1);
    string a2="hehe",b2="haha";
    imax(a2,b2);
    vector<int> ves0(3);
    ves0[0]=1;ves0[1]=2,ves0[2]=3;
    imax(ves0);
    vector<double> ves1(3);
    ves1[0]=1.0;ves1[1]=2.1,ves1[2]=3.1;
    imax(ves1);
    vector<string> ves2(3);
    ves2[0]="I",ves2[1]="am",ves2[2]="zhang!";
    imax(ves2);
    imax(ves0,3);
    imax(ves1,3);
    imax(ves2,3);
    return 0;
}

template<typename T>
void imax(T  a,T  b)
{
    cout<<a<<"\t"<<b<<endl;
}
template<typename T>
void imax(vector<T>  ves)
{
    cout<<"type1"<<endl;
    for(int i=0;i<ves.size();i++)
    {
        cout<<ves[i]<<"\t";
    }
    cout<<endl;
}
template<typename T>
void imax(vector<T>  ves,int len)
{
    cout<<"type2"<<endl;
    for(int i=0;i<len;i++)
    {
        cout<<ves[i]<<"\t";
    }
    cout<<endl;
}