#include <iostream>
#include <ctime>
#include <algorithm> // For std::transform
#include <cctype>    // For std::tolower



void scoreboard(int score, int cpu);
using str = std::string;
using namespace std;


int main(){
    srand(time(0));
    

    int user_score = 0;
    int computer_score= 0;
    int choice = 0;
    str start;
    cout<<"ROCK PAPER SCISSOR GAME!"<<'\n';
    cout<<"************************"<<'\n';
    cout<<"Do you wish to start?(y/n): "<<'\n';

    cin>>start;
    transform(start.begin(), start.end(), start.begin(),::tolower);

    
    if (start=="y"){
        do{
            
            cout<<"Select an option: "<<'\n';
            cout<<"#1 Rock"<<'\n'<<"#2 Paper"<<'\n'<<"#3 Scissor"<<'\n'<<"#4 Quit"<<'\n'<<"Choice: ";
            cin>>choice;
            int pc_choice = rand()%3+1;
            switch(choice){
                case 1:
                    if(pc_choice==1){
                        cout<<"Draw!"<<'\n';
                        scoreboard(user_score, computer_score);
                        break;
                    }
                    else if(pc_choice==2){
                        cout<<"You Lost!"<<'\n';
                        computer_score+= 1;
                        scoreboard(user_score, computer_score);
                        break;

                    }
                    else{
                        cout<<"You Won!"<<'\n';
                        user_score+= 1;
                        scoreboard(user_score, computer_score);
                        break;}
                case 2:
                    if (pc_choice==1){
                        cout<<"You Won!"<<'\n';
                        user_score+= 1;
                        scoreboard(user_score, computer_score);
                        break;
                    }
                    else if(pc_choice ==2){
                        cout<<"Draw!"<<'\n';
                        scoreboard(user_score, computer_score);
                        break;
                    }

                    else{
                        cout<<"You Lost!"<<'\n';
                        computer_score+= 1;
                        scoreboard(user_score, computer_score);
                        break;}
                case 3:
                    if (pc_choice==1){
                         cout<<"You Lost!"<<'\n';
                        computer_score+= 1;
                        scoreboard(user_score, computer_score);
                        break;
                    }
                    else if(pc_choice ==2){
                         cout<<"You Won!"<<'\n';
                        user_score+= 1;
                        scoreboard(user_score, computer_score);
                        break;
                    }
                    else{
                         cout<<"Draw!"<<'\n';
                        scoreboard(user_score, computer_score);
                        break;
                    }
                case 4:
                    scoreboard(user_score, computer_score);
                    break;
                default: cout<<"Invalid Option!"<<'\n';
                    cin>>choice;

            }
        }while (choice!=4);
    }
    else if(start=="n"||start =="N")
    {
        cout<<"See you soon!";
    }
    else{
        cout<<"Invalid Input!"<<'\n';
        cout<<"Please Restart!"<<'\n';
        main();
    }
 return 0;           
}

void scoreboard(int score, int cpu){
    cout<<'\n'<<'\n'<<"SCOREBOARD"<<'\n'<<"********************"<<'\n';
    cout<<"User: "<<score<<'\n';
    cout<<"Opponent: "<<cpu<<'\n'<<'\n'<<'\n'<<'\n';


}