#include <iostream>
#include <chrono>
#include <conio.h>

using namespace std;

int main()
{
    char choice;

    do
    {
        //char key;
        choice = ' ';
        int laps = 0;

        cout << "How many laps do you want to record?: ";
        cin >> laps;
        if(cin.fail())
        {
            cout << "Error: Invalid input! Please enter an integer value.\n";
            break;
        }
        cin.ignore();
        cout << "Enter any key to begin!\n";
        getch();
        auto start = std::chrono::steady_clock::now();
        cout << "Stopwatch started!\n";
        cout << "Enter any key to take a lap!\n";
        for (int i = 0; i < laps; i++)
        {
            getch();
            auto end = std::chrono::steady_clock::now();
            std::chrono::duration<double> elapsed_seconds = end - start;
            cout << "Lap #" << i + 1 << ": " << elapsed_seconds.count() << " secs\n";
        }
        cout << "\nWould you like to reset the stopwatch or exit?\n";
        cout << "R to Reset / E to exit\n";
        cin >> choice;
        choice = toupper(choice);
        while (choice != 'R' && choice != 'E')
        {
            cout << "Error: R to Reset & E to exit: ";
            cin >> choice;
            choice = toupper(choice);
        }
    } while (choice != 'E');
    cout << "Thanks for using the stopwatch!";
    return 0;
}