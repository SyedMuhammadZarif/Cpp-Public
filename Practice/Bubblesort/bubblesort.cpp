#include <iostream>

using namespace std;
int main(){

    int array[]= {4,3,2,1,5,2,3,5,1,2,5};
    int size = sizeof(array)/sizeof(array[0]);
    for(int i=0; i<size-1;i++){
        for(int j=0; j<size-i-1; j++){
            
            if(array[j]>array[j+1]){
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
                
                
            }
        }
    }
    for(int x: array){
        cout<<x<<' ';
    }
    
    return 0;
}