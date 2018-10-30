#include <iostream>
using namespace std;


template<typename elemType>
class Matrix{
    public:
        Matrix(int m,int n);
       // Matrix(elemType *);;
        Matrix(const Matrix & _value);

        Matrix<elemType>  operator+(const Matrix<elemType> & another);
        Matrix<elemType>  operator*(const Matrix<elemType> & another);
        void operator+=(const Matrix<elemType> & another);
        void operator=(const Matrix<elemType> & another);
        elemType & operator()(int i,int j);
        ostream & print(ostream & os);

        inline elemType get_mtx(int i) const{
            if(i<0||i>=16) return -1;
            return mtx[i/4][i%4];
        }
        inline void set_mtx(int i,int j,elemType value){
            mtx[i][j]=value;
        }
    private:
        int x,y;
        elemType * mtx;
};
template<typename elemType>
Matrix<elemType>::Matrix(int m,int n){
    mtx=new elemType(m*n);
    x=m,y=n;
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++){
            mtx[i*n+j]=0.0;
        }
}
/*template<typename elemType>
Matrix<elemType>::Matrix(elemType * _value){
    for(int i=0;i<16;i++)
        mtx[i*4+j]=_value[i];
}*/
template <typename elemType>
Matrix<elemType>::Matrix(const Matrix<elemType> & _value){
    this->x=_value.x;
    this->y=_value.y;
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            mtx[i*y+j]=_value.mtx[i*y+j];
        }
    }
}

template<typename elemType>
elemType & Matrix<elemType>::operator()(int i,int j){
    return mtx[i*y+j];
}

template<typename elemType>
Matrix<elemType>  Matrix<elemType>::operator+(const Matrix<elemType> & another){
    Matrix<elemType> temp(*this);
    temp+=another;
    return temp;
}

template<typename elemType>
Matrix<elemType> Matrix<elemType>::operator*(const Matrix<elemType> & another){
    Matrix temp(*this);
    for(int i=0;i<temp.x;i++){
        for(int j=0;j<temp.y;j++){
            for(int k=0;k<temp.y;k++){
                temp.mtx[i*y+j]+=(temp.mtx[i*y+k])*(another.mtx[j+k*x]);
            }
        }
    }
    return temp;
}
template<typename elemType>
void Matrix<elemType>::operator+=(const Matrix<elemType> & another){
    for(int i=0;i<another.x;i++){
        for(int j=0;j<another.y;j++){
                this->mtx[i*y+j]+=another.mtx[i*y+j];
        }
    }
}
template <typename elemType>
ostream & operator<<(ostream & os,Matrix<elemType> & other){
    cout<<"hehe"<<endl;
    return other.print(os);
    //return os;
}

template<typename elemType>
ostream & Matrix<elemType>::print(ostream & os){
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            cout<<"i*y+j: "<<(i*y+j)<<endl;
            os<<mtx[i*y+j]<<" ";
        }
        if(i==1) cout<<endl;
    } 
    return os;
}
int main()
{
    Matrix<float> identity(4,4);
    cout<<identity<<endl;
    float ar[16]={1.0,0.0,0.0,0.0,
                  0.0,1.0,0.0,0.0,
                  0.0,0.0,1.0,0.0,
                  0.0,0.0,0.0,1.0};
    for(int i=0,k=0;i<4;++i)
        for(int j=0;j<4;++j)
            identity(i,j)=ar[k++];
    cout<<"identity after set: "<<identity<<endl;
    Matrix<float> m(identity);
    cout<<"m: memberwise initialized: "<<m<<endl;
    Matrix<float> m2(8,12);
    cout<<"m2: 8x12: "<<m2<<endl;
    /*m2=m;
    cout<<"m2 after memberwise assigned to m: "<<m2<<endl;*/
    float ar2[16]={1.3,0.4,2.6,8.2,6.2,1.7,1.3,8.3,
                 4.2,7.4,2.7,1.9,6.3,8.1,5.6,6.6};
    Matrix<float> m3(4,4);
    for(int ix=0,kx=0;ix<4;++ix)
        for(int j=0;j<4;++j)
            m3(ix,j)=ar2[kx++];
    cout<<"m3: assigned random values: "<<m3<<endl;
    Matrix<float> m4=m3*identity;cout<<m4<<endl;
    Matrix<float> m5=m3+m4;cout<<m5<<endl;
    m3+=m4;cout<<m3<<endl;
    return 0;
}