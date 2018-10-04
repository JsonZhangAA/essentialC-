#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int main(void)
{
	char s[100];
	cin>>s;
	if(strlen(s)>2){
		cout<<"good name"<<endl;
	}else{
		cout<<"name is too short"<<endl;
	}
	return 0;
}
