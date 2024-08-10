#include <iostream>
#include <iomanip>
using str = std::string;
using namespace std;


void showBalance(double amount);
double deposit();
double withdraw(double amount);

int main(){

    double balance = 0.00;
    int choice = 0;
    while(choice!=4){
        cout<<"Welcome to the State Bank!"<<'\n';
        cout<<"****************************"<<'\n';
        cout<<"1. Show Balance"<<'\n';
        cout<<"2. Make a Deposit"<<'\n';
        cout<<"3. Withdraw Cash"<<'\n';
        cout<<"4. Quit"<<'\n';

        cin>>choice;
        cin.clear();
        fflush(stdin);

        switch(choice){

            case 1: showBalance(balance);
                    break;

            case 2: balance+=deposit();
                    showBalance(balance);
                    break;

            case 3: balance -= (withdraw(balance));
                    showBalance(balance);
                    break;

            case 4: cout<<"Thank you for banking with us!";
                    break;

            default: cout<<"Invalid Input!";}}

    return 0;
}

void showBalance(double balance){
    cout<<"Your balance is: $" << std::setprecision(2)<<std::fixed<< balance<<'\n';
}

double deposit(){
    double amount = 0; 
    cout<<"Enter amount to deposit: ";
    cin>> amount;

    if(amount<1)
    { 
        cout<<"Invalid amount!";
        return(0);}

    else{
    cout<<"Deposit of $"<< amount<<"Successful";
    return(amount);
}}

double withdraw(double balance)
{
    int amount = 0;
    cout<<"Enter amount to withdraw: $";
    cin>>amount;
    if (amount>balance){
        cout<<"Insufficient Funds!";
        return(0);
    }
    else if (amount<=0){
        cout<<"Invalid Amount";
        return(0);
    }
    else{
        return(amount);
    }
}
