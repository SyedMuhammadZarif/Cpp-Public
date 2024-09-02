#include <iostream>

using namespace std;

int main(){
    char *pGrades = NULL;
    int size;
    cout<<"Enter how many grades need to be recorded: "<<'\n';
    cin>>size;
    pGrades = new char[size];

    for(int i=0; i<size; i++)
    {   
        cout<<"Enter Grade #"<< i+1<<": "<<'\n';
        cin>>pGrades[i];
    }

    for(int i=0; i<size; i++)
    {
        cout<<pGrades[i]<<',';
    }
    return 0;
}