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
    for(map<string,int>::iterator it=mps.begin();it!=mps.end();it++){
        cout<<it->first<<"： "<<it->second<<endl;
    }
    return 0;
}