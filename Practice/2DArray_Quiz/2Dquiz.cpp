#include <iostream>
using namespace std;

int main(){

//Initializing Array for questions
    string questions[]=
    {
        "1) What command is used to stage files for a commit in Git?", 
        "2) Which of the following commands will create a new branch in Git?",
        "3) What does the git status command do?",
        "4) Which Git command is used to apply changes from a remote repository to your local repository?"
    };
//Initializing Array for MC answers
    string option[][4] ={{
                        "A) git add",
                        "B) git commit",
                        "C) git push",
                        "D) git pull"},

                        {
                        "A) git checkout -b branch-name",
                        "B) git branch create branch-name",
                        "C) git new branch branch-name",
                        "D) git init branch-name"
                        },
                        
                        {
                        "A) Displays the current branch name",
                        "B) Shows changes between commits",
                        "C) Displays the state of the working directory and staging area",
                        "D) Commits changes to the repository"
                        },
                        
                        {
                        "A) git merge",
                        "B) git fetch",
                        "C) git pull",
                        "D) git clone"
                        }};
//array for answers
    char anskey[]= {'B','A','C','C'};

    int size = sizeof(questions)/sizeof(questions[0]);
    char guess;
    int score;

    for(int i =0; i<size, i++){
        cout<<questions[i]<<'\n';
    }

    return 0;
}