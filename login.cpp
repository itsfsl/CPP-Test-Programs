#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;

bool checkAccount(string username)
{
    string un, pw;
    ifstream read("accounts.txt");
    while (getline(read, un))
    {
        getline(read, pw);
        if(un == username)
        {
            read.close();
            return true;
        }
    }
    read.close();
    return false;
}

bool isLoggedIn(string username)
{
    string password, un, pw;
    bool login = false;

    while(!login)
    {
        cout << "Enter your password: ";
        cin >> password;
        ifstream read("accounts.txt");
        while(getline(read, un))
        {
            getline(read, pw);
            if(un == username && pw == password)
            {
                cout << "Logged In!\n";
                login = true;
                read.close();
                break;
            }
        }
        read.close();
        if(!login)
        {
            cout << "Incorrect password!\n";
        }
    }
    return true;
}

void newRegistration(string username)
{
    string password;
    cout << "~New Registration~\n";
    cout << "Username: " << username << endl;
    cout << "Enter your password: ";
    cin >> password;
    ofstream write("accounts.txt", ios::app);
    write << username << endl;
    write << password << endl;
    write.close();
    cout << "Account successfully created!\n";
}

int main()
{
    system("color 06");
    string username, password;
    
    cout << "~Login System 1.0~\n";
    cout << "Enter your username: ";
    cin >> username;
    if(checkAccount(username))
    {
        cout << "Account already exists!\n";
        cout << "Please login to continue!\n";
        while(isLoggedIn(username))
        {
            break;
        }
    }
    else
    {
        newRegistration(username);
    }

    cout << "Welcome brother!";
    getch();

    return 0;
}