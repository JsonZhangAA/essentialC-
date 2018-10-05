#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(void)
{
	vector<string> strs(3);
	strs[0]="hello";
	strs[1]="ajd";
	strs[2]=" ";
	cout<<"sort before"<<endl;
	for(int i=0;i<3;i++)
	{
		cout<<strs[i]<<" ";
	}
	cout<<endl;
	sort(strs.begin(),strs.end());
	cout<<"sort after"<<endl;
	for(int i=0;i<3;i++)
	{
		cout<<strs[i]<<" ";
	}
	cout<<endl;
	return 0;
}
