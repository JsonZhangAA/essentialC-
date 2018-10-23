#include <iostream>
#include <string>
using namespace std;
class Data{
    public:
        static const string program_name=new string("Tim");
        const string version_stamp="4.34";
        static const int version_number=5;
        static const int tests_run=4;
        static const int tests_passed=4;
        int id=9;
};
int main(void){
    cout<<"Data::program_name "<<Data::program_name<<endl;
    cout<<"Data::version_stamp "<<Data::version_stamp<<endl;
    cout<<"Data::version_number "<<Data::version_number<<endl;
    cout<<"Data::tests_run "<<Data::tests_run<<endl;
    cout<<"Data::tests_passed "<<Data::tests_passed<<endl;
    return 0;
}