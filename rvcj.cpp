#include <iostream>
#include <string>
#include <cstring>
#include <conio.h>

using namespace std;

void displayLeaders(string leaders[])
{
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << ". " << leaders[i] << endl;
    }
}

void displayOtherMembers(string otherMembers[])
{
    for (int i = 0; i < 4; i++)
    {
        cout << i + 1 << ". " << otherMembers[i] << endl;
    }
}

void displaySupportMembers(string supportMembers[])
{
    for (int i = 0; i < 4; i++)
    {
        cout << i + 5 << ". " << supportMembers[i] << endl;
    }
}

int main()
{
    int balance = 20;
    int choiceLeader;
    string leaders[5] = {"Aquaman ($5)", "Iron Man ($4)", "Captain America ($3)", "Wonder Woman ($1)", "Batman ($2)"};
    string otherMembers[4] = {"Hulk ($3)", "Wolverine ($5)", "Gamora ($5)", "Flash ($4)"};
    string supportMembers[4] = {"Thor ($3)", "Spider-Man ($5)", "Black Widow ($2)", "Deadpool ($1)"};
    string myTeam[9];
    int teamSize = 0;
    
    cout << "You have $20 to make a team that will protect you during the end of the world" << endl;
    cout << "Choose wisely!" << endl;

    do
    {
        cout << "Select any one leader from the following: "<<endl;
        displayLeaders(leaders);
        cout << "Enter your choice: ";
        cin >> choiceLeader;
        cin.clear();
        cin.ignore();
        switch (choiceLeader)
        {
            case 1: balance -= 5; myTeam[0] = leaders[0]; break;
            case 2: balance -= 4; myTeam[0] = leaders[1]; break;
            case 3: balance -= 3; myTeam[0] = leaders[2]; break;
            case 4: balance -= 1; myTeam[0] = leaders[3]; break;
            case 5: balance -= 3; myTeam[0] = leaders[4]; break;
            default : cout << "Invalid choice!" << endl; break;
        }
    } while (myTeam[0].empty());
    
    system("cls");

    int i = 1;

    bool selected[8] = {false};
    int choice = 0;

    do
    {
        system("cls");
        displayOtherMembers(otherMembers);
        displaySupportMembers(supportMembers);
        cout << endl;
        cout << "Current Team: " << endl;
        for (int j = 0; j < teamSize + 1; j++)
        {
            int index = myTeam[j].find(" ($");
            string newTeamList = myTeam[j].substr(0, index);
            cout << " * " << newTeamList << endl;
        }
        cout << endl;
        cout << "Balance: $" << balance << endl;
        cout << endl;
        cout << "Select the rest of the members (69 to exit): ";
        cin >> choice;
        cin.clear();
        cin.ignore();

        if (choice == 69)
        {
            balance = 0;
            continue;
        }

        if (choice >= 9 || choice <= 0)
        {
            cout << "Invalid choice!" << endl;
            getch();
            continue;
        }

        if (selected[choice - 1])
        {
            cout << endl;
            cout << "ERROR: Cannot select a character more than once, select another!!" << endl;
            getch();
            continue;
        }

        switch (choice)
        {
        case 1:
            if (balance < 3)
            {
                cout << "Insufficient Balance! Select another character." << endl;
                getch();
                break;
            }
            /* else if (lastChoice == choice)
            {
                cout << "Cannot select a character more than once, select another!" << endl;
                break;
            } */
            else
            {
                balance -= 3; myTeam[i] = otherMembers[0];
                //cout << "You added: " << myTeam[i] << endl;
                i++;
                teamSize++;
                selected[0] = true;
                break;
            }
        case 2: 
            if (balance < 5)
            {
                cout << "Insufficient Balance! Select another character." << endl;
                getch();
                break;
            }
            else
            {
                balance -= 5; myTeam[i] = otherMembers[1];
                i++;
                teamSize++;
                selected[1] = true;
                break;
            }
        case 3:
            if (balance < 5)
            {
                cout << "Insufficient Balance! Select another character." << endl;
                getch();
                break;
            }
            else
            {
                balance -= 5; myTeam[i] = otherMembers[2];
                i++;
                teamSize++;
                selected[2] = true;
                break;
            }
        case 4:
            if (balance < 4)
            {
                cout << "Insufficient Balance! Select another character." << endl;
                getch();
                break;
            }
            else
            {
                balance -= 4; myTeam[i] = otherMembers[3];
                i++;
                teamSize++;
                selected[3] = true;
                break;
            }
        case 5:
            if (balance < 3)
            {
                cout << "Insufficient Balance! Select another character." << endl;
                getch();
                break;
            }
            else
            {
                balance -= 3; myTeam[i] = supportMembers[0];
                i++;
                teamSize++;
                selected[4] = true;
                break;
            }
        case 6:
            if (balance < 5)
            {
                cout << "Insufficient Balance! Select another character." << endl;
                getch();
                break;
            }
            else
            {
                balance -= 5; myTeam[i] = supportMembers[1];
                i++;
                teamSize++;
                selected[5] = true;
                break;
            }
        case 7:
            if (balance < 2)
            {
                cout << "Insufficient Balance! Select another character." << endl;
                getch();
                break;
            }
            else
            {
                balance -= 2; myTeam[i] = supportMembers[2];
                i++;
                teamSize++;
                selected[6] = true;
                break;
            }
        case 8:
            if (balance < 1)
            {
                cout << "Insufficient Balance! Select another character." << endl;
                getch();
                break;
            }
            else
            {
                balance -= 1; myTeam[i] = supportMembers[3];
                i++;
                teamSize++;
                selected[7] = true;
                break;
            }
        default : break;
        }
    } while (balance > 0);
    
    system("cls");
    
    cout << "Here is your final team: " << endl;
    
    int index = myTeam[0].find(" ($");
        string newTeamList = myTeam[0].substr(0, index);
        //cout << myTeam[i] << endl;
        cout << " * " << newTeamList << " (Leader)" << endl;

    for (int i = 1; i < teamSize + 1; i++)
    {
        int index = myTeam[i].find(" ($");
        string newTeamList = myTeam[i].substr(0, index);
        //cout << myTeam[i] << endl;
        cout << " * " << newTeamList << endl;
    }
    cout << "Press any key to exit.";
    getch();
    return 0;
}