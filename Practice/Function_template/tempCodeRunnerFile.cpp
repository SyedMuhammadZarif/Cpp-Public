#include <iostream>
using namespace std;
template <typename T>

T max(T x, T y)
{   
    return (x>y) ? x : y ;
}

int main()
{   
    cout<< max(12,123);
    return 0;
    
}