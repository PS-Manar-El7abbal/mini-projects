#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

class Log_in;
class Sign_up;
class Forget;
class Menu;

class Log_in
{
public:
    string user_name, u;
    string password, p;
   

    void menu_log()
    {
        cout << "------------------------\n";
        cout << "Enter your username : "; cin >> user_name;
        cout << "Enter your password : "; cin >> password;

        ifstream l("database.txt");
        bool found = false;
        while (l >> u >> p)
          {
            string dummyEmail; // to skip the email field
            l >> dummyEmail;
            if (u == user_name && p == password)
            {
                cout << "Logged In successfully\n";
                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "Invalid credentials, try again.\n";
        }
    }
};

class Sign_up
{
public:
    string user_name;
    string password;
    string email;
   

    void sign_menu()
    {
        cout << "----------------------------\n";
        cout << "Enter your username :"; cin >> user_name;
        cout << "Enter your password :"; cin >> password;
        cout << "Enter your email : "; cin >> email;
        cout << "----------------------------\n";

        ofstream s("database.txt", ios::app);
        s << user_name << " " << password << " " << email << endl;
    }
};

class Forget : public Sign_up
{
public:
    int ch;
    string search, usr_n;
    string pass, dummyEmail;

    void forget_what()
    {
        cout << "----------------------------\n";
        cout << "1. Search my id by username\n";
        cout << "2. Main menu\n";
        cout << "----------------------------\n";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Enter your username: "; cin >> search;
            {
                ifstream f("database.txt");
                bool found = false;
                while (f >> usr_n >> pass >> dummyEmail) // read all 3 fields
                {
                    if (search == usr_n)
                    {
                        cout << "Found! Your password is: " << pass << endl;
                        found = true;
                        break;
                    }
                }
                if (!found)
                {
                    cout << "Not found! Try again.\n";
                }
            }
            break;

        case 2:
            return;  // Return to main menu
            break;

        default:
            cout << "Invalid choice!\n";
            forget_what();
            break;
        }
    }
};

class Menu : public Forget, public Log_in
{
public:
    void menu()
    {
        while (true)
        {
           
            cout << setw(5) << "Menu\n";
            cout << "1. Sign Up\n";
            cout << "2. Log In\n";
            cout << "3. Forget username or password\n";
            cout << "4. Exit\n";
           

            int choice = 0; cin >> choice;
            switch (choice) 
            {
            case 1:
                sign_menu();
                break;
            case 2:
                menu_log();
                break;
            case 3:
                forget_what();
                break;
            case 4:
               
                exit(0);
                break;
            default:
                cout << "Invalid choice, try again.\n";
                break;
            }
        }
    }
};

int main()
{
    Menu m;
    m.menu();
    return 0;
}
