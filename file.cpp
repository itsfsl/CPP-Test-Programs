#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    /* fstream myFile;
    myFile.open("wee.txt", ios::out);
    if(myFile.is_open())
    {
        myFile << "Hola!\n";
        myFile.close();
    } */

    fstream myFile;
    /* myFile.open("wee.txt", ios::app);
    if(myFile.is_open())
    {
        myFile << "Como tale tale woo!\n";
        myFile.close();
    } */
    string line;
    myFile.open("wee.txt", ios::in);
    while (getline(myFile, line))
    {
        cout << line << '\n';
    }
    myFile.close();
    return 0;
}