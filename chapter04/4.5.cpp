#include <iostream>
using namespace std;


typedef double elemType;
class Matrix{
    public:
        Matrix();
        Matrix(elemType *);;
        Matrix(const Matrix & _value);

        friend Matrix  operator+(const Matrix & other,const Matrix & another);
        friend Matrix  operator*(const Matrix & other,const Matrix & another);
        friend void operator+=(Matrix & other,const Matrix & another);

        inline elemType get_mtx(int i) const{
            if(i<0||i>=16) return -1;
            return mtx[i/4][i%4];
        }
        inline void set_mtx(int i,int j,double value){
            mtx[i][j]=value;
        }
    private:
        double mtx[4][4];
};
Matrix::Matrix(){
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            mtx[i][j]=0.0;
}
Matrix::Matrix(elemType * _value){
    for(int i=0;i<16;i++)
        mtx[i/4][i%4]=_value[i];
}
Matrix::Matrix(const Matrix & _value){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            mtx[i][j]=_value.get_mtx(i*4+j);
        }
    }
}

Matrix  operator+(const Matrix & other,const Matrix & another){
    Matrix temp(other);
    temp+=another;
    return temp;
}
Matrix operator*(const Matrix & other,const Matrix & another){
    Matrix temp;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            double tempValue=0.0;
            for(int k=0;k<4;k++){
                tempValue+=other.get_mtx(i*4+k)*another.get_mtx(j+k*4);
                //temp.set_mtx(i,j,other.get_mtx(i*4+k)*another.get_mtx(j+k*4));
            }
            temp.set_mtx(i,j,tempValue);
        }
    }
    return temp;
}
void operator+=(Matrix & other,const Matrix & another){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            other.set_mtx(i,j,another.get_mtx(i*4+j)+other.get_mtx(i*4+j));
        }
    }
}

ostream & operator<<(ostream & os,Matrix m){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            os<<m.get_mtx(i*4+j)<<" ";
        }
        if(i==1) cout<<endl;
    } 
    return os;
}
int main()
{
    Matrix m;
    cout<<m<<endl;

    elemType ar[16]={
        1,0,0,0,0,1,0,0,
        0,0,1,0,0,0,0,1
    };
    Matrix identity(ar);
    cout<<identity<<endl;

    Matrix m2(identity);
    m=identity;
    cout<<m2<<endl;
    cout<<m<<endl;

    elemType ar2[16]={
        1.3,0.4,2.6,8.2,6.2,1.7,1.3,8.3,
        4.2,7.4,2.7,1.9,6.3,8.1,5.6,6.6
    };
    Matrix m3(ar2);
    cout<<m3<<endl;
    Matrix m4=m3*identity;
    cout<<m4<<endl;
    Matrix m5=m3+m4;
    cout<<m5<<endl;
    m3+=m4;
    cout<<m3<<endl;
    return 0;
}