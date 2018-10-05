#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
	fstream iofile("test.txt");
	vector<string> strs(20);
	int i=0;
	if(!iofile){
		cerr<<"open file failed"<<endl;
	}else{
		while(iofile>>strs[i++]);
	}
	for(int j=0;j<i-1;j++)
	{
		cout<<strs[j]<<endl;
	}
//	cout<<endl;
	cout<<"after sort"<<endl;
	cout<<*(strs.begin())<<endl;
	sort(strs.begin(),strs.begin()+i-1);
	cout<<"i:"<<i<<" "<<strs[1]<<endl;
	for(int j=0;j<i;j++)
        {
                cout<<strs[j]<<" ";
        }
	cout<<endl;
	return 0;
}
