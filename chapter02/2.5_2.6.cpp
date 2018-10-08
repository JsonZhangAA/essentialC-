#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
template <typename T>
T imax(T  a,T  b);

template<typename T>
T imax(vector<T> a);

template<typename T>
T imax(const T *  ves,int len);
int main(void)
{
    int a=0,b=1;
    cout<<imax(a,b)<<endl;
    double a1=0.0,b1=0.2;
    cout<<imax(a1,b1)<<endl;
    string a2="hehe",b2="haha";
    cout<<imax(a2,b2)<<endl;
    vector<int> ves0(3);
    ves0[0]=1;ves0[1]=2,ves0[2]=3;
    cout<<imax(ves0)<<endl;
    vector<double> ves1(3);
    ves1[0]=1.0;ves1[1]=2.1,ves1[2]=3.1;
    cout<<imax(ves1)<<endl;
    vector<string> ves2(3);
    ves2[0]="I",ves2[1]="am",ves2[2]="zhang!";
    cout<<imax(ves2)<<endl;
    int arr0[3]={1,4,7};
    double arr1[3]={1.0,4.0,7.4};
    string arr2[3]={"I","am","Jsn"};
    cout<<imax(arr0,3)<<endl;
    cout<<imax(arr1,3)<<endl;
    cout<<imax(arr2,3)<<endl;
    return 0;
}

template<typename T>
T imax(T  a,T  b)
{
    return a>b?a:b;
}
template<typename T>
T imax(vector<T>  ves)
{
    return *max_element(ves.begin(),ves.end());
}
template<typename T>
T imax(const T *  ves,int len)
{
    return *max_element(ves,ves+len);
}