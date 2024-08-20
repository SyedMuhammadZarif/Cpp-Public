#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int ToDec(int incoming, int base)
{
    string received = to_string(incoming);
    int size = received.size();
    int power = 0;
    int decnum = 0;
    
    for(int index = size-1; index>=0; index--)
    {   
        int temp = received[index] - '0';
        if(temp>=base){
            cout<<"Error in Input, range exceeded!";
            break;
        }
        decnum += (temp) * pow(base,power);
        power++;
        
    }
    cout<<decnum;

    return 0;
}

int main(){
    int number;
    int base;
    cout<<"Enter number"<<'\n';
    cin>>number;
    cout<<"Enter Base"<<'\n';
    cin>>base;

    ToDec(number, base);



    return 0;
}