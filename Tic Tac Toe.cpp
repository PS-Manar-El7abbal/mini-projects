#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

//colors
const string RESET = "\033[0m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";
const string M = "\033[35m";
const string b = "\033[97m";

//global variables
char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
int p1, p2;

void printWithColor(const string& text, const string& color)
{
    cout << color << text << RESET;
}

void draw_the_table()
{
    for (int i = 0; i < 3; ++i)
    {
        printWithColor("+---+---+---+\n", BLUE);
        for (int j = 0; j < 3; ++j)
        {
            printWithColor("| " + string(1, board[i][j]) + " ", M);
        }
        printWithColor("|\n", M);
    }

    printWithColor("+---+---+---+\n", BLUE);
}


bool who_win()
{
    // Check rows and columns
    for (int i = 0; i < 3; ++i)
    {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') ||
            (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' '))
        {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' '))
    {
        return true;
    }
    return false;
}

bool is_board_full()
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

void insert_character(int p1, int p2, char c)
{
    if (p1 >= 0 && p1 < 3 && p2 >= 0 && p2 < 3 && board[p1][p2] == ' ')
    {
        board[p1][p2] = c;
    }
    else
    {
        printWithColor("Invalid position, choose another one\n", RED);
    }
}

void multiple_player()
{
    draw_the_table();
    cout << "You are X and Your Friend is O:\n";
    for (int i = 0; i < 9; ++i)
    {
        if (who_win())
        {
            printWithColor("WINNER!\n", GREEN);
            return;
        }

        if (is_board_full())
        {
            printWithColor("It's a draw!\n", RED);
            return;
        }

        cout << "Enter Move position [row column]: ";
        cin >> p1 >> p2;
        char c = (i % 2 == 0) ? 'X' : 'O'; // X goes on odd turns, O on even turns
        insert_character(p1, p2, c);
        draw_the_table();
    }
}

char chooseRandomCharacter()
{
    return (rand() % 2 == 0) ? 'X' : 'O';
}

void computer_move(char computer)
{
    int p1, p2;
    do
    {
        p1 = rand() % 3;
        p2 = rand() % 3;
    } while (board[p1][p2] != ' ');

    insert_character(p1, p2, computer);
}

void play_with_computer()
{
    draw_the_table();
    srand(time(0));
    char player = chooseRandomCharacter();
    char computer = (player == 'X') ? 'O' : 'X';
    cout << "You are " << player << " and the computer is " << computer << endl;

    for (int i = 0; i < 9; ++i)
    {
        if (who_win())
        {
            printWithColor(string(1, (i % 2 == 0) ? computer : player) + " WINS!\n", GREEN);
            return;
        }

        if (is_board_full())
        {
            printWithColor("It's a draw!\n", RED);
            return;
        }

        if (i % 2 == 0) // Player's turn
        {
            cout << "Enter Move position [row column]: ";
            cin >> p1 >> p2;
            insert_character(p1, p2, player);
        }
        else // Computer's turn
        {
            computer_move(computer);
        }
        draw_the_table();
    }

    printWithColor("It's a draw!\n", RED);
}


void game_menu()
{
    printWithColor("-------------------------------------- \n", BLUE);
    printWithColor("Tic Tac Toe \n", b);
    printWithColor("[1] Multiple Players\n", b);
    printWithColor("[2] Play With Computer\n", b);
    printWithColor("-------------------------------------- \n", BLUE);

    short choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        multiple_player();
        break;

    case 2:
        play_with_computer();
        break;

    default:
        printWithColor("Invalid choice, try again\n", RED);
        game_menu();
        break;
    }
}

int main()
{
    game_menu();
    return 0;
}
