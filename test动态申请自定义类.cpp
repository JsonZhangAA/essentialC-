#include <iostream>
using namespace std;
class testClass{
public:
	testClass(){
		i=0,j=0;
	}
	testClass(int _i,int _j):i(_i),j(_j){
	}
	void print(){
		cout<<"i: "<<i<<" j: "<<j<<endl;
	}
private:
		int i,j;
};
int main(){
	testClass * temp=new testClass[3];
	for(int i=0;i<3;i++){
		temp[i].print();
	} 
	return 0;
}
