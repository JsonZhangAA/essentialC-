#include <iostream>
using namespace std;
int main()
{
	char * s[4]={"hehe","haha","wiqoqo","jdjkf"};
	int i;
	cin>>i;
	switch(i){
		case 0:cout<<s[0]<<endl;break;
		default:cout<<s[3]<<endl;break;
	}
	return 0;
}
