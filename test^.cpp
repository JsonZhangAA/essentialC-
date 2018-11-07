#include <iostream>
using namespace std;
int main(){
    int flag=0;
    for(int i=0;i<5;i++){
        cout<<"i: "<<i<<" "<<flag<<endl;
        flag^=1;
    }
    return 0;
}