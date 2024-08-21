#include <iostream>
#include <string>
#include <cmath>
using namespace std;



int luhn_cardchecker(long cardnumber){
    bool valid;
    string card_microchip;
    string temp = to_string(cardnumber);
    int temp2 = temp[0] - '0';
   
  
    if(temp.length()> 16)
    {
        cout<<"Invalid card number!";
        return 0;
    }

    if(temp2>6|temp2<3)
    {
        cout<<"Invalid card number!";
        return 0;
    }

    switch(temp2)
    {
        case 3:card_microchip="American Express";
                if(temp.length()>15)
                {
                    cout<<"Invalid number!"<<'\n';
                    return 0;
                }
        
        case 4: card_microchip="VISA";
                if(temp.length()<16)
                {
                    cout<<"Invalid number!"<<'\n';
                    return 0;
                }
        
        case 5: card_microchip="Mastercard";
                if(temp.length()<16)
                {
                    cout<<"Invalid number!"<<'\n';
                    return 0;
                }
        
        case 6: card_microchip="Discovery";
                
                if(temp.length()<16)
                {
                    cout<<"Invalid number!"<<'\n';
                    return 0;
                }

    }

    string temp3 = "";

    for(long index = temp.length()-2 ; index>=0; index-=2)
    {
        temp3+= temp[index];   
    }
    
   
    int temp4=0;
    int digitholder;
    string splitter;
//multiplication of digits
    for( int idx2 = 0; idx2<temp3.length(); idx2++)
    {
        digitholder = (temp3[idx2]-'0')*2;
        cout<<digitholder<<'\n';
        if(digitholder>9)
        {
            splitter = to_string(digitholder);
            temp4+= (splitter[0]-'0')+(splitter[1]-'0');
            cout<<temp4<<'\n';
        }
        else{
            temp4+=digitholder;
        }
        
    }
    
//odd numbered addition to previous step
    for(long index = temp.length()-1 ; index>=0; index-=2)
    {
        temp4+= (temp[index]-'0');
    }
    cout<<temp4;

    if(temp4%10==0)
    {
        valid=true;
        
    }
    else{
        valid = false;
        cout<<"Card is Invalid!";
        return 0;
    }
    



    cout<<"Card Type: "<<card_microchip<<'\n';
    cout<<"Card Number: "<<temp<<'\n';
    cout<<"Card is valid!";
    
    
    return 0;
}


int main()
{
    cout<<"Please enter card number: "<<'\n';
    long card;
    cin>>card;
    luhn_cardchecker(card);



    return 0;
}