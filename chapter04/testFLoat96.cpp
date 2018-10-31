#include <iostream>
using namespace std;
int main(){
    float * mtx=new float(96);
    delete [] mtx;
    mtx=new float(16);
    for(int i=0;i<96;i++){
        cout<<mtx[i]<<" ";
    }
    cout<<endl;
    return 0;
}