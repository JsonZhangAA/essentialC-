#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <cstring>
using namespace std;
int main(void){
    map<string,vector<string> > mps;
    ifstream fin("name.txt",ios_base::in);
    string tempStr;
    while(getline(fin,tempStr)){
        string firstName;
        vector<string> tempVes;
        int pre_pos=0;
        int pos;
        int readLen;
        while((pos=tempStr.find_first_of(' ',pre_pos))!=string::npos)
        {
            readLen=pos-pre_pos;
            if(pre_pos==0){
                firstName=tempStr.substr(pre_pos,readLen);
            }else{
                tempVes.push_back(tempStr.substr(pre_pos,readLen));
            }
            pre_pos=++pos;
        }
        if(pre_pos==0){
            firstName=tempStr.substr(pre_pos,readLen);
        }else{
             tempVes.push_back(tempStr.substr(pre_pos,readLen));
        }
        mps[firstName]=tempVes;
    }
    string querString;
    cout<<"请输入想要查询的姓氏：(quit结束)"<<endl;
    while(cin>>querString){
        if(strcmp(querString.c_str(),"quit")==0){
            cout<<"quit!"<<endl;
            break;
        }
        if(mps.count(querString)!=0){
            if(mps[querString].size()==0){
                cout<<"this family no member";
            }
            for(int j=0;j<mps[querString].size();j++){
                cout<<mps[querString][j]<<" ";
            }
        }else{
            cout<<"no such family";
        }
        cout<<endl;
        
    }
   /* for(map<string,vector<string> >::iterator i=mps.begin();i!=mps.end();i++){
        cout<<i->first<<":";
        for(int j=0;j<i->second.size();j++){
            cout<<i->second[j]<<" ";
        }
        cout<<endl;
    }*/
    return 0;
}