#include <iostream>
using namespace std;
template<typename type1>
class example{
    public:
        example(type1 & min,type1 & max);
        example(const type1 * array,type2 size);
        type1 & operator[](type2 index);
        bool operator==(const example1 &) const;
        bool insert(const type1 *,int);
        bool insert(const type1 &);
        type1 min() const{ return _min;}
        type1 max() const{ return _max;}
        void min(const type1 &);
        void max(const type1 &);
        type2 count(const type1 & value ) const;
    private:
        int size;
        type1 *parray;
        type1 _min;
        type1 _max;
};
int main(){
    return 0;
}