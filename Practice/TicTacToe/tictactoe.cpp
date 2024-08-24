#include <iostream>
#include <ctime>
#include <algorithm>

void drawboard(char *spaces);
void playerMove(char *spaces, char player);
void computerMove(char *spaces, char computer);
bool checkTie(char *scenario, char *spaces);
bool checkWinner(char *spaces, char player, char computer);

using namespace std;
char *scenario = nullptr;

int main()
{
    srand(time(0));
    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player = 'X';
    char computer = 'O';
    bool running = true;
    drawboard(spaces);

    while (running)
    {
        playerMove(spaces, player);
        drawboard(spaces);
        if (checkWinner(spaces, player, computer))
        {
            running = false;
            break;
        }
        else if (checkTie(scenario, spaces))
        {
            running = false;
            break;
        }

        computerMove(spaces, computer);
        drawboard(spaces);
        if (checkWinner(spaces, player, computer))
        {
            running = false;
            break;
        }
        else if (checkTie(scenario, spaces))
        {
            running = false;
            break;
        }
    }

    return 0;
}

void drawboard(char *spaces)
{
    cout << '\n';
    cout << "     |     |     " << '\n';
    cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "   " << '\n';
    cout << "_____|_____|_____" << '\n';
    cout << "     |     |     " << '\n';
    cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "   " << '\n';
    cout << "_____|_____|_____" << '\n';
    cout << "     |     |     " << '\n';
    cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "   " << '\n';
    cout << "     |     |     " << '\n';
    cout << '\n';
}

void playerMove(char *spaces, char player)
{
    int number;
    do
    {
        cout << "Make your move (1-9): ";
        cin >> number;
        number--;
        if (number >= 0 && number < 9 && spaces[number] == ' ')
        {
            spaces[number] = player;
            break;
        }
    } while (true);
}

void computerMove(char *spaces, char computer)
{
    int computernumber;
    do
    {
        computernumber = rand() % 9;
        if (spaces[computernumber] == ' ')
        {
            spaces[computernumber] = computer;
            break;
        }
    } while (true);
}

bool checkWinner(char *spaces, char player, char computer)
{
    // Check rows
    for (int i = 0; i < 9; i += 3)
    {
        if (spaces[i] == spaces[i + 1] && spaces[i + 1] == spaces[i + 2] && spaces[i] != ' ')
        {
            scenario = &spaces[i];
            cout << (spaces[i] == player ? "Player" : "Computer") << " wins!" << endl;
            return true;
        }
    }

    // Check columns
    for (int i = 0; i < 3; i++)
    {
        if (spaces[i] == spaces[i + 3] && spaces[i + 3] == spaces[i + 6] && spaces[i] != ' ')
        {
            scenario = &spaces[i];
            cout << (spaces[i] == player ? "Player" : "Computer") << " wins!" << endl;
            return true;
        }
    }

    // Check diagonals
    if (spaces[0] == spaces[4] && spaces[4] == spaces[8] && spaces[0] != ' ')
    {
        scenario = &spaces[0];
        cout << (spaces[0] == player ? "Player" : "Computer") << " wins!" << endl;
        return true;
    }
    if (spaces[2] == spaces[4] && spaces[4] == spaces[6] && spaces[2] != ' ')
    {
        scenario = &spaces[2];
        cout << (spaces[2] == player ? "Player" : "Computer") << " wins!" << endl;
        return true;
    }

    return false;
}

bool checkTie(char *scenario, char *spaces)
{
    if (scenario == nullptr)
    {
        if (find(spaces, spaces + 9, ' ') == spaces + 9)
        {
            cout << "It's a draw!" << std::endl;
            return true;
        }
    }
    return false;
}
