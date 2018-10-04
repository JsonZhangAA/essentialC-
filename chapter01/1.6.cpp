#include <iostream>
#include <vector>
using namespace std;
int main(void)
{	
	int array0[5];
	cout<<"请输入5个整数"<<endl;
	for(int i=0;i<5;i++)
	{
		int temp;
		cin>>temp;
		array0[i]=temp;
	}
	vector<int> array1(array0,array0+5);
	float max0=0,avera0=0,max1=0,avera1=0;
	for(int i=0;i<5;i++)
	{
		max0+=array0[i];
		max1+=array1[i];
	}
	avera0=max0/5;
	avera1=max1/5;
	cout<<"array max:"<<max0<<" avera:"<<avera0<<endl;
	cout<<"vector max:"<<max1<<" avera:"<<avera1<<endl;
	return 0;
}
