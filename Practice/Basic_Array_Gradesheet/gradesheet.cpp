
#include <iostream>

using namespace std;

int main(){
    string names[] = {"Abu Sayeed", "Mir Mughdo", "Ahad", "Jafor Iqbal", "Enayet Chowdhury"};
    int grades[] = {100,100,100,0,5};

    cout<<"***********************GRADESHEET 36th July 2024*************************"<<'\n';
    cout<<"***********************XXXXXXXXXXXXXXXXXXXXXXXXX*************************"<<'\n';
    cout<<'\n';

    for(int i = 0; i<(sizeof(names)/sizeof(names[0])); i++)
    {
        cout<<i+1<<") "<<names[i]<<": "<<grades[i]<<"%"<<'\n';
        cout<<'\n';
    }
    cout<<'\n';
    return 0;
}