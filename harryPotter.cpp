#include <iostream>
#include <unistd.h>
#include <ctype.h>
#include <conio.h>

using namespace std;

int sortHouse();
int* printQuestions();

/* 16 options

4 = one house

if 4 belongs to one house = your house

slytherin 	= 	cunning, 	smart, 	powerful, 	ambitious
gryffindor 	= 	brave, 		daring, 	nerve, 		chivalry
ravenclaw 	= 	intelligence, 	wit, 		wisdom, 		learning
hufflepuff 	= 	patient, 		loyal, 	hardworking, just */

int main()
{
    string name;
    cout << "What's your name?\n";
    getline(cin, name);
    name[0] = toupper(name[0]);
    size_t space_pos = name.find(' ');
    if (space_pos != std::string::npos)
    {
        name[space_pos+1] = std::toupper(name[space_pos+1]);
        for (size_t i = space_pos+2; i < name.size(); i++)
        {
            name[i] = std::tolower(name[i]);
        }
    }
    system("cls");
    char choice;
    int house;
    string houseName;
    cout << "~HOGWARTS SCHOOL of WITCHCRAFT and WIZARDRY~\n";
    cout << "Dear "<< name << "," <<"\nWe are pleased to inform you that you have been accepted at Hogwarts School of Witchcraft and Wizardry.";
    do
    {
        //
        cout << "\nAre you ready to be sorted into your house? (Y/N)\n";
        cout << "Enter choice: ";
        cin >> choice;
        choice = toupper(choice);
        if (choice == 'Y')
        {
            house = sortHouse();
        }
        else if (choice == 'N')
        {
            system("cls");
            cout << "~You can always visit again~";
            sleep(3);
            break;
        }
        else
        {
            cout << "Oh no! That's not a correct answer. Let's try again shall we?\n";
            sleep(3);
        }
    } while (choice != 'Y' && choice != 'N');
    if (house == 1)
    {
        houseName = "Slytherin";
    }
    else if (house == 2)
    {
        houseName = "Gryffindor";
    }
    else if (house == 3)
    {
        houseName = "Ravenclaw";
    }
    else
    {
        houseName = "Hufflepuff";
    }
    system("cls");
    cout << name << " ~ " << houseName << endl;
    cout << "~Press any key to begin your new journey at Hogwarts~";
    getch();
    return 0;
}

int* printQuestions()
{
    int* choice = new int[5];
    string choiceDefined;
    string options[][4] =   {{"1. Cunning", "2. Brave", "3. Intelligence", "4. Patient"},
                            {"1. Smart", "2. Daring", "3. Wit", "4. Loyal"},
                            {"1. Powerful", "2. Nerve", "3. Wisdom", "4. Hardworking"},
                            {"1. Ambitious", "2. Chivalry", "3. Learning", "4. Just"}};

    for(int i = 0; i < 4; i++)
    {
        system("cls");
        sleep(2);
        cout << "Are you...?\n";
        sleep(1);
        for (int j = 0; j < 4; j++)
        {
            
            cout << options[i][j] << "\n";
        }
        cout << "\nEnter choice: ";
        cin >> choice[i];
        choiceDefined = options[i][choice[i] - 1].substr(3);
        cout << "You chose: " << choiceDefined;
        sleep(2);
    }
    return choice;
}

int sortHouse()
{
    int house = 0;
    string options[][4] =   {{"cunning", "brave", "intelligent", "patient"},
                            {"smart", "daring", "witty", "loyal"},
                            {"powerful", "full of nerves", "wise", "hardworking"},
                            {"ambitious", "full of chivalry", "loves to learn", "always just"}};

    string houses[4] = {{"Slytherin"},{"Gryffindor"},{"Ravenclaw"},{"Hufflepuff"}};
    
    system("cls");
    cout << "~Welcome to the Sorting Hat Ceremony~\n";
    sleep(2);
    cout << "You need to tell me about you to determine your house..\n";
    sleep(2);
    cout << "So";
    sleep(1);
    cout << ".";
    sleep(1);
    cout << ".";
    sleep(1);
    cout << ".";
    sleep(1);
    cout << "Let's begin!\n";
    sleep(2);
    
    int* personality = printQuestions();

    system("cls");
    cout << "Oh I see..\n";
    sleep(3);
    cout << "Hmm..\n";
    sleep(2);
    cout << "So you are "   << options[0][personality[0] - 1] << ", " 
                            << options[1][personality[1] - 1] << ", " 
                            << options[2][personality[2] - 1] << " and " 
                            << options[3][personality[3] - 1] << "!\n";
    sleep(2);
    cout << "Hmm...Interesting...\n";
    sleep(3);
    cout << "Let's sort you into...\n";
    sleep(5);

    //{{"Slytherin"},{"Gryffindor"},{"Ravenclaw"},{"Hufflepuff"}};

    int Slytherin = 1, Gryffindor = 2, Ravenclaw = 3, Hufflepuff = 4;
    int slytherinHouseScore = 0;
    int gryffindorHouseScore = 0;
    int ravenclawHouseScore = 0;
    int hufflepuffHouseScore = 0;

    for (int i = 0; i < 4; i++)
    {
        if (personality[i] == Slytherin)
        {
            slytherinHouseScore++;
        }
        if (personality[i] == Gryffindor)
        {
            gryffindorHouseScore++;
        }
        if (personality[i] == Ravenclaw)
        {
            ravenclawHouseScore++;
        }
        if (personality[i] == Hufflepuff)
        {
            hufflepuffHouseScore++;
        }
    }

    if (slytherinHouseScore >= gryffindorHouseScore && slytherinHouseScore >= ravenclawHouseScore && slytherinHouseScore >= hufflepuffHouseScore)
    {
        house = 1;
        system("color 02");
        cout << "~SLYTHERIN!~" << endl;
        sleep(5);
    }
    else if (gryffindorHouseScore >= slytherinHouseScore && gryffindorHouseScore >= ravenclawHouseScore && gryffindorHouseScore >= hufflepuffHouseScore)
    {
        house = 2;
        system("color 0C");
        cout << "~GRYFFINDOR!~" << endl;
        sleep(5);
    }
    else if (ravenclawHouseScore >= slytherinHouseScore && ravenclawHouseScore >= gryffindorHouseScore && ravenclawHouseScore >= hufflepuffHouseScore)
    {
        house = 3;
        system("color 03");
        cout << "~RAVENCLAW!~" << endl;
        sleep(5);
    }
    else
    {
        house = 4;
        system("color 06");
        cout << "~HUFFLEPUFF!~" << endl;
        sleep(5);
    }
    delete(personality);
    return house;
}