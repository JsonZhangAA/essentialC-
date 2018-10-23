#include <iostream>
#include <cstring>
#include <sstream>
#include <map>
#include <string>
using namespace std;
class UserProfile{
    public:
        enum Rank{
            cainiao,
            putong,
            jinjie,
            gaowang
        };

        UserProfile(int _loginRecord,string _userName,int _submit,int _accepted,Rank _rank);
        UserProfile(Rank _rank);
        UserProfile(const char * _userName,Rank _rank);

        inline void set_loginRecord(int value){
            loginRecord=value;
        }
        inline void set_userName(string value){
            userName=value;
        }
        inline void set_submit(int value){
            submit=value;
        }
        inline void set_accepted(int value){
            accepted=value;
        }
        inline void set_Rank(Rank value){
            rank=value;
        }

        bool operator==(UserProfile & others){
            if(loginRecord==others.loginRecord&&!strcmp(userName.c_str(),others.userName.c_str()))
                return true;
            else
                return false;
        }
        bool operator!=(UserProfile & others){
            return !(*this==others);
        }

        int   get_loginRecord() const{
            return loginRecord;
        }
        string  get_userName() const{
            return userName;
        }
        int  get_submit() const{
            return submit;
        }
        const int  get_accepted() const{
            return accepted;
        }
        string  get_rank() const{
            static string tbl[]={
                "cainiao","putong","jinjie","gaowang"
            };
            return tbl[rank];
        }
        float get_correct() const{
            if(accepted==0||submit==0)
                return 0;
            float temp=(float)accepted/submit;
            //float temp=0.0;
            return temp; 
        }

        void bump_guess_count(int value){
            submit=value;
        }
        void bump_guess_correct(int value){
            accepted=value;
        }
        void bump_login_count(int value=1){
            loginRecord+=value;
        }
        
        static Rank find_mps(string _value);
    private:
        static map<string,Rank> mps;
        int loginRecord;//登陆次数
        string userName;//用户名
        int submit;//提交次数
        int accepted;//回答正确次数
        Rank rank;//等级
        static void init_mps();
};
map<string,UserProfile::Rank> UserProfile::mps;
UserProfile::Rank UserProfile::find_mps(string _value){
    map<string,Rank>::iterator it;
    it=mps.find(_value);
    if(it!=mps.end())
        return it->second;
    else    
        return UserProfile::cainiao;
}
//map<string,UserProfile::Rank> UserProfile::mps;
void UserProfile::init_mps(){
    /*enum Rank{
            cainiao,
            putong,
            jinjie,
            gaowang
        };*/
    mps["cainiao"]=cainiao;
    mps["putong"]=putong;
    mps["jinjie"]=jinjie;
    mps["gaowang"]=gaowang;
}

UserProfile::UserProfile(UserProfile::Rank _rank=cainiao){
    static int count=0;//用于默认的guest用户命名。
    stringstream ss;
    ss<<count;
    count++;
    string tempStr=ss.str();
    userName="guest"+tempStr;
    loginRecord=1;
    submit=0;
    accepted=0;
    rank=_rank;
}

UserProfile::UserProfile(int _loginRecord,string _userName,int _submit,int _accepted,UserProfile::Rank _rank):loginRecord(_loginRecord),
userName(_userName),submit(_submit),accepted(_accepted),rank(_rank){
}

UserProfile::UserProfile(const char * _userName,Rank _rank):userName(_userName),rank(_rank){
    UserProfile::init_mps();
	loginRecord=1;
    submit=0;
    accepted=0;
}

ostream & operator<<(ostream & os,const UserProfile users){
    os<<users.get_userName()<<" "<<users.get_loginRecord()<<" "<<users.get_submit()<<" "<<users.get_accepted()<<" "<<users.get_rank()<<endl;
    cout<<"正确率："<<users.get_correct()<<endl;
    return os;
}
istream & operator>>(istream & is,UserProfile & users){
    string tempUN;
    int tempL,tempS,tempA;
    string tempRank;
    is>>tempUN>>tempL>>tempS>>tempA>>tempRank;
    users.set_loginRecord(tempL);
    users.set_userName(tempUN);
    users.set_submit(tempS);
    users.set_accepted(tempA);
    users.set_Rank(UserProfile::find_mps(tempRank));
    return is;
}
int main()
{
    UserProfile anon;
    cout<<anon;

    UserProfile anon_too(UserProfile::jinjie);
    cout<<anon_too;

    UserProfile anna("AnnaL",UserProfile::gaowang);
    cout<<anna;

    anna.bump_guess_count(27);
    anna.bump_guess_correct(25);
    anna.bump_login_count();
    cout<<anna;

    cin>>anon;
    cout<<anon;
}
