#include<map>
#include<iostream>
#include<set>
#include<fstream>
#include<algorithm>
#include<string>
using namespace std;
int main(void)
{
    ifstream infile("words.txt");
    string removeWords[]={"a","an","or","the","and","but"};
    set<string> removeSet(removeWords,removeWords+6);
    string tempWord;
    map<string,int> mps;
    while(infile>>tempWord){
        if(!removeSet.count(tempWord)){
            mps[tempWord]++;
        }
    }
    cout<<"Please input the word that you want to search"<<endl;
    string serarchWord;
    cin>>serarchWord;
    if(mps.count(serarchWord)>0){
        cout<<"the word already exsit"<<endl;
    }else{
        cout<<"the word is not  exsit"<<endl;
    }
    for(map<string,int>::iterator it=mps.begin();it!=mps.end();it++){
        cout<<it->first<<"： "<<it->second<<endl;
    }
    return 0;
}