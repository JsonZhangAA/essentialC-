#include <iostream>
#include <string>
#include <vector>
using namespace std;
const vector<double> * pentagonal(int num);
template <typename T>
void showPentagonal(const vector<T> ves,string tName);
inline bool checkNum(int num){
    if(num>1024)
        return false;
    return true;
}
double returnValue(int pos,const vector<double> & ves);
int main(void)
{
    int num;
    cout<<"set the value of num:"<<endl;
    cin>>num;
    const vector<double> * vesP;
    while(num>0){
        vesP=pentagonal(num);
        double value=returnValue(num,*vesP);
        cout<<value<<endl;
        cin>>num;
        //showPentagonal(ves,"double");
    }
    return 0;
}
const vector<double> * pentagonal(int num)
{
    bool flag=checkNum(num);
    static vector<double> ves;
    if(!flag){
        cerr<<"num is two big!"<<endl;
        return NULL;
    }
    for(int i=ves.size();i<num;i++)
    {
        ves.push_back((i+1)*(3*(i+1)-1)/2);
    }
    return &ves;
}
template <typename T>
void showPentagonal(const vector<T> ves,string tName)
{
    if(ves.size()<=0)
        return;
    for(int i=0;i<ves.size();i++)
    {
        cout<<ves[i]<<"\t";
    }
    cout<<endl;
}
double returnValue(int pos,const vector<double> & ves)
{
    if(pos<=ves.size())
        return ves[pos-1];
    else   
        return -1;
}