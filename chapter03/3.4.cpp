#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <algorithm>
using namespace std;
bool myCompare(int n){
    if(n%2==0)
        return true;
    return false;
}
int main(void){
    istream_iterator<int> in_file(cin);
    istream_iterator<int> eof;
    vector<int> ves;
    copy(in_file,eof,back_inserter(ves));
    ofstream out_file1("Ji.txt");
    ofstream out_file2("Ou.txt");
    ostream_iterator<int> os1(out_file1," ");
    ostream_iterator<int> os2(out_file2,"\n\n");
    vector<int>::iterator divi=partition(ves.begin(),ves.end(),myCompare);
    copy(ves.begin(),divi,os1);
    copy(divi,ves.end(),os2);
    out_file1.close();
    out_file2.close();
    return 0;
}