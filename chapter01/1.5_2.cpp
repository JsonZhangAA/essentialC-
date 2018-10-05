#include <string>
#include <iostream>
using namespace std;
int main(void)
{
	string name;
	cin>>name;
	if(name.size()<=2){
		cout<<"The name is too short"<<endl;	
	}else{
		cout<<"good name"<<endl;
	}
	return 0;
}
