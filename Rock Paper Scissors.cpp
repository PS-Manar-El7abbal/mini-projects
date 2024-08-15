#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;


const string RESET = "\033[0m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";

// Function forward declarations
void game();
void who_win(int choice, const string& choose);
void play_again();

void printWithColor(const string& text, const string& color)
{
    cout << color << text << RESET << endl;
}


void who_win(int choice, const string& choose)
{
    // First condition
    if (choice == 1 && choose == "Rock")
    {
        printWithColor("You Win", GREEN);
    }
    else if (choice == 1 && choose == "Paper")
    {
        printWithColor("Tie", YELLOW);
    }
    else if (choice == 1 && choose == "Scissors")
    {
        printWithColor("Computers Wins", RED);
    }
    // Second condition
    else if (choice == 2 && choose == "Paper")
    {
        printWithColor("Computers Wins", RED);
    }
    else if (choice == 2 && choose == "Rock")
    {
        printWithColor("Tie", YELLOW);
       
    }
    else if (choice == 2 && choose == "Scissors")
    {
        printWithColor("You Win", GREEN);
    
    }
    // Third condition
    else if (choice == 3 && choose == "Paper")
    {
        printWithColor("You Win", GREEN);
    }
    else if (choice == 3 && choose == "Rock")
    {
        printWithColor("Computers Wins", RED);
    }
    else if (choice == 3 && choose == "Scissors")
    {
        printWithColor("Tie", YELLOW);
        
    }
}

void play_again()
{
    cout << "Do you want to play again (t/f)? ";
    char c;
    cin >> c;
    if (c == 't')
    {
        game();
    }
    else
    {
        cout << "Game Over\n";
    }
}

void game()
{
   
    cout << "------------------------------\n";
    cout << "[1] Paper\n";
    cout << "[2] Rock\n";
    cout << "[3] Scissors\n";
    cout << "------------------------------\n";

    int choice = -1;
    cout << "Enter your move number: ";
    cin >> choice;

    if (choice > 3 || choice < 1)
    {
        printWithColor("Invalid move, try again", RED);
        cout << "Invalid move, try again\n";
        game();  // Restart the game if invalid input
        return;
    }

    string playerChoice;
    if (choice == 1) playerChoice = "Paper";
    else if (choice == 2) playerChoice = "Rock";
    else if (choice == 3) playerChoice = "Scissors";

    printWithColor("Your choice: " + playerChoice, GREEN);

    srand(time(0));
    int move = (rand() % 3) + 1;
    string computer_choice;

    if (move == 1) computer_choice = "Paper";
    else if (move == 2) computer_choice = "Rock";
    else computer_choice = "Scissors";

    printWithColor("Computer choice: " + computer_choice, BLUE);

    who_win(choice, computer_choice);
    play_again();
}

int main()
{
    game();
    return 0;
}
