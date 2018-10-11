#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
bool myCompare(string s1,string s2){
    if(s1.length()<s2.length())
        return true;
    else
        return false;
}
int main(int argc,char * * argv)
{

    ifstream ifd(argv[1],ios_base::in);
    if(!ifd.is_open()){
        cout<<"open file"<<argv[1]<<endl;
    }
    vector<string> vecs;
    string tempStr;
    while(ifd>>tempStr){
        vecs.push_back(tempStr);
    }
    cout<<"before sort:"<<endl;
    for(vector<string>::iterator it=vecs.begin();it!=vecs.end();it++){
        cout<<*it<<"\t";
    }
    cout<<endl;
    sort(vecs.begin(),vecs.end(),myCompare);
    cout<<"after sort"<<endl;
    for(vector<string>::iterator it=vecs.begin();it!=vecs.end();it++){
        cout<<*it<<"\t";
    }
    cout<<endl;
    return 0;
}