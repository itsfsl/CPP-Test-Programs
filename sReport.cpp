#include <iostream>
#include <fstream>
#include <conio.h>
#include <cstring>

using namespace std;

void teacherSection();
void studentSection();
void adminSection();
bool newRegistration(string callingFunction);
bool login(string accountType);
void logOut();

struct Student
{
    char username[20];
    char password[20];
    char name[25];
    int rollno;
    int englishMarks;
    int scienceMarks;
    int computerMarks;
    int mathMarks;
    int grade;
};

struct Teacher
{
    char username[20];
    char password[20];
    char name[25];
};

struct Student currentStudent;

struct Teacher currentTeacher;

bool isAdmin, isTeacher, isStudent, isLoggedIn = false;

int main()
{
       
    int choice1;
    int totalGrade = 300;

    string currentLoggedInAs;

    do
    {
        system("cls");
        if (isLoggedIn && isAdmin)
        {
            currentLoggedInAs = "Administrator\n";
        }
        else if (isLoggedIn && isTeacher)
        {
            currentLoggedInAs = "Teacher\n";
        }
        else if (isLoggedIn && isStudent)
        {
            currentLoggedInAs = "Student\n";
        }
        else
        {
            currentLoggedInAs = "Logged Out\n";
        }
        system("cls");
        cout << "====================================" << endl;
        cout << "  ~Imaginary International School~\n";
        cout << "====================================" << endl;
        cout << "1. Teacher's Section\n";
        cout << "2. Student's Section\n";
        cout << "3. Admin Section\n";
        cout << "4. Log Out\n";
        cout << "5. Exit\n";
        cout << "====================================" << endl;
        cout << "Logged in as: " << currentLoggedInAs;
        cout << "====================================" << endl;
        cout << "Enter your choice: ";
        cin >> choice1;

        switch (choice1)
        {
        case 1: teacherSection(); break;
        case 2: studentSection(); break;
        case 3: adminSection(); break;
        case 4: logOut(); break;
        case 5: break;
        default: 
            cout << "====================================" << endl;
            cout << "ERROR: Invalid choice!" << endl;
            cout << "Press any key to continue" << endl;
            cout << "====================================" << endl;
            getch();
            break;
        }
    } while (choice1 != 5);
    return 0;
}

void teacherSection()
{
    if (isLoggedIn && isTeacher)
    {
        int choice1;
        int rollno;
        char studentName[25];
        char grade;
        bool studentFound;

        FILE *fp;

        do
        {
            system("cls");
            cout << "====================================" << endl;
            cout << "~Welcome Mr. " << currentTeacher.name << " to the Teacher's Section~" << endl;;
            cout << "====================================" << endl;
            cout << "1. Search a student by rollno   " << endl;
            cout << "2. Search a student by name     " << endl;
            cout << "3. Log out & back to main menu  " << endl;
            cout << "====================================" << endl;
            cout << "Enter your choice: ";
            cin >> choice1;

            switch (choice1)
            {
                case 1:
                    cout << "====================================" << endl;
                    cout << "Enter Roll No: ";
                    cin >> rollno;

                    fp = fopen("studentsnew.txt", "rb+");
                    while(fread(&currentStudent, sizeof(currentStudent), 1, fp))
                    {
                        if (rollno == currentStudent.rollno)
                        {
                            currentStudent.grade = (currentStudent.englishMarks + currentStudent.computerMarks + currentStudent.scienceMarks + currentStudent.mathMarks / 400) * 100;
                            
                            if (currentStudent.grade >= 80 && currentStudent.grade <= 100)
                            {
                                grade = 'A';
                            }
                            else if (currentStudent.grade >= 70 && currentStudent.grade < 80)
                            {
                                grade = 'B';
                            }
                            else if (currentStudent.grade >= 60 && currentStudent.grade < 70)
                            {
                                grade = 'C';
                            }
                            else
                            {
                                grade = 'D';
                            }

                            int exitChoice;
                            do
                            {
                                int newMarks;
                                int choice2;
                                int choiceSub;
                                system("cls");
                                cout << "====================================" << endl;
                                cout << "Student found!" << endl;
                                cout << "====================================" << endl;
                                cout << "Roll No: " << currentStudent.rollno << endl;
                                cout << "Student Name: " << currentStudent.name << endl;
                                cout << "English Marks: " << currentStudent.englishMarks << endl;
                                cout << "Computer Marks: " << currentStudent.computerMarks << endl;
                                cout << "Science Marks: " << currentStudent.scienceMarks << endl;
                                cout << "Math Marks: " << currentStudent.mathMarks << endl;
                                cout << "Grade: " << grade << endl;
                                cout << "====================================" << endl;
                                cout << "1. Update Marks\t2. Exit" << endl;
                                cout << "====================================" << endl;
                                cout << "Enter Choice: ";
                                cin >> choice2;

                                switch (choice2)
                                {
                                    case 1:
                                        cout << "====================================" << endl;
                                        cout << "1. English\t2. Computer" << endl;
                                        cout << "3. Science\t4. Math" << endl;
                                        cout << "====================================" << endl;
                                        cout << "Select Subject: ";
                                        cin >> choiceSub;

                                        switch (choiceSub)
                                        {
                                            case 1:
                                                cout << "====================================" << endl;
                                                cout << "Enter new marks for English: ";
                                                cin >> newMarks;
                                                currentStudent.englishMarks = newMarks;
                                                newMarks = 0;
                                                cout << "====================================" << endl;
                                                cout << "Marks updated successfully!" << endl;
                                                break;
                                            case 2:
                                                cout << "====================================" << endl;
                                                cout << "Enter new marks for Computer: ";
                                                cin >> newMarks;
                                                currentStudent.computerMarks = newMarks;
                                                newMarks = 0;
                                                cout << "====================================" << endl;
                                                cout << "Marks updated successfully!" << endl;
                                                break;
                                            case 3:
                                                cout << "====================================" << endl;
                                                cout << "Enter new marks for Science: ";
                                                cin >> newMarks;
                                                currentStudent.scienceMarks = newMarks;
                                                newMarks = 0;
                                                cout << "====================================" << endl;
                                                cout << "Marks updated successfully!" << endl;
                                                break;
                                            case 4:
                                                cout << "====================================" << endl;
                                                cout << "Enter new marks for Math: ";
                                                cin >> newMarks;
                                                currentStudent.mathMarks = newMarks;
                                                newMarks = 0;
                                                cout << "====================================" << endl;
                                                cout << "Marks updated successfully!" << endl;
                                                break;
                                            default: 
                                                cout << "====================================" << endl;
                                                cout << "ERROR: Invalid choice!" << endl;
                                                cout << "Press any key to continue" << endl;
                                                cout << "====================================" << endl;
                                                getch();
                                                break;
                                        }
                                        break;
                                    case 2: 
                                        exitChoice = 1;
                                        break;

                                    default: 
                                        cout << "====================================" << endl;
                                        cout << "ERROR: Invalid choice!" << endl;
                                        cout << "Press any key to continue" << endl;
                                        cout << "====================================" << endl;
                                        getch();
                                        break;
                                }
                            } while (exitChoice != 1);
                            studentFound = true;
                            fseek(fp, -(long int)sizeof(currentStudent), SEEK_CUR);
                            fwrite(&currentStudent, sizeof(currentStudent), 1, fp);
                            break;
                        }
                    }
                    fclose(fp);
                    if (!studentFound)
                    {
                        cout << "=====================" << endl;
                        cout << "        ERROR        " << endl;
                        cout << "=====================" << endl;
                        cout << "  Student not found! " << endl;
                        cout << "=====================" << endl;
                        cout << "Press any key to go back to the teacher menu";
                        getch();
                    }
                    break;
                case 2:
                    cout << "====================================" << endl;
                    cout << "Enter Student Name: ";
                    cin >> studentName;

                    fp = fopen("studentsnew.txt", "rb");
                    while(fread(&currentStudent,sizeof(currentStudent), 1, fp))
                    {
                        if (strcmp(studentName, currentStudent.name) == 0)
                        {
                            currentStudent.grade = (currentStudent.englishMarks + currentStudent.computerMarks + currentStudent.scienceMarks + currentStudent.mathMarks / 400) * 100;
                            
                            if (currentStudent.grade >= 80 && currentStudent.grade <= 100)
                            {
                                grade = 'A';
                            }
                            else if (currentStudent.grade >= 70 && currentStudent.grade < 80)
                            {
                                grade = 'B';
                            }
                            else if (currentStudent.grade >= 60 && currentStudent.grade < 70)
                            {
                                grade = 'C';
                            }
                            else
                            {
                                grade = 'D';
                            }

                            int exitChoice;
                            do
                            {
                                int newMarks;
                                int choice2;
                                int choiceSub;
                                system("cls");
                                cout << "====================================" << endl;
                                cout << "Student found!" << endl;
                                cout << "====================================" << endl;
                                cout << "Roll No: " << currentStudent.rollno << endl;
                                cout << "Student Name: " << currentStudent.name << endl;
                                cout << "English Marks: " << currentStudent.englishMarks << endl;
                                cout << "Computer Marks: " << currentStudent.computerMarks << endl;
                                cout << "Science Marks: " << currentStudent.scienceMarks << endl;
                                cout << "Math Marks: " << currentStudent.mathMarks << endl;
                                cout << "Grade: " << grade << endl;
                                cout << "====================================" << endl;
                                cout << "1. Update Marks\t2. Exit" << endl;
                                cout << "====================================" << endl;
                                cout << "Enter Choice: ";
                                cin >> choice2;

                                switch (choice2)
                                {
                                    case 1:
                                        cout << "====================================" << endl;
                                        cout << "1. English\t2. Computer" << endl;
                                        cout << "3. Science\t4. Math" << endl;
                                        cout << "====================================" << endl;
                                        cout << "Select Subject: ";
                                        cin >> choiceSub;

                                        switch (choiceSub)
                                        {
                                            case 1:
                                                cout << "====================================" << endl;
                                                cout << "Enter new marks for English: ";
                                                cin >> newMarks;
                                                currentStudent.englishMarks = newMarks;
                                                newMarks = 0;
                                                cout << "====================================" << endl;
                                                cout << "Marks updated successfully!" << endl;
                                                break;
                                            case 2:
                                                cout << "====================================" << endl;
                                                cout << "Enter new marks for Computer: ";
                                                cin >> newMarks;
                                                currentStudent.computerMarks = newMarks;
                                                newMarks = 0;
                                                cout << "====================================" << endl;
                                                cout << "Marks updated successfully!" << endl;
                                                break;
                                            case 3:
                                                cout << "====================================" << endl;
                                                cout << "Enter new marks for Science: ";
                                                cin >> newMarks;
                                                currentStudent.scienceMarks = newMarks;
                                                newMarks = 0;
                                                cout << "====================================" << endl;
                                                cout << "Marks updated successfully!" << endl;
                                                break;
                                            case 4:
                                                cout << "====================================" << endl;
                                                cout << "Enter new marks for Math: ";
                                                cin >> newMarks;
                                                currentStudent.mathMarks = newMarks;
                                                newMarks = 0;
                                                cout << "====================================" << endl;
                                                cout << "Marks updated successfully!" << endl;
                                                break;
                                            default: 
                                                cout << "====================================" << endl;
                                                cout << "ERROR: Invalid choice!" << endl;
                                                cout << "Press any key to continue" << endl;
                                                cout << "====================================" << endl;
                                                getch();
                                                break;
                                        }
                                        break;
                                    case 2: 
                                        exitChoice = 1;
                                        break;

                                    default: 
                                        cout << "====================================" << endl;
                                        cout << "ERROR: Invalid choice!" << endl;
                                        cout << "Press any key to continue" << endl;
                                        cout << "====================================" << endl;
                                        getch();
                                        break;
                                }
                            } while (exitChoice != 1);
                            studentFound = true;
                            fseek(fp, -(long int)sizeof(currentStudent), SEEK_CUR);
                            fwrite(&currentStudent, sizeof(currentStudent), 1, fp);
                            break;
                        }
                    }
                    fclose(fp);
                    if (!studentFound)
                    {
                        cout << "=====================" << endl;
                        cout << "        ERROR        " << endl;
                        cout << "=====================" << endl;
                        cout << "  Student not found! " << endl;
                        cout << "=====================" << endl;
                        cout << "Press any key to go back to the teacher menu";
                        getch();
                    }
                    break;
                case 3: logOut(); break;
                default: 
                    cout << "====================================" << endl;
                    cout << "ERROR: Invalid choice!" << endl;
                    cout << "Press any key to continue" << endl;
                    cout << "====================================" << endl;
                    getch();
                    cin.clear();
                    cin.ignore();
                    break;
            }
        } while (isLoggedIn && isTeacher);
    }
    else
    {
        int choice;
        do
        {
            system("cls");
            cout << "====================================" << endl;
            cout << " ~Welcome to the Teacher's Section~\n";
            cout << "====================================" << endl;
            cout << "1. Login\n2. Register a new teacher\n3. Back to main menu\n";
            cout << "====================================" << endl;
            cout << "Your choice: ";
            cin >> choice;

            switch (choice)
            {
                case 1: if(login("teacher")) choice = 3; break;
                case 2: if(newRegistration("teacher")) choice = 3; break;
                case 3: break;
                default: 
                    cout << "====================================" << endl;
                    cout << "ERROR: Invalid choice!" << endl;
                    cout << "Press any key to continue" << endl;
                    cout << "====================================" << endl;
                    getch();
                    break;
            }
        } while (choice != 3);
    }
}

void studentSection()
{
    int choice;
    char grade;

    if (isLoggedIn && isStudent)
    {
        int choice;
        do
        {
            currentStudent.grade = (currentStudent.englishMarks + currentStudent.computerMarks + currentStudent.scienceMarks + currentStudent.mathMarks / 400) * 100;
                            
            if (currentStudent.grade >= 80 && currentStudent.grade <= 100)
            {
                grade = 'A';
            }
            else if (currentStudent.grade >= 70 && currentStudent.grade < 80)
            {
                grade = 'B';
            }
            else if (currentStudent.grade >= 60 && currentStudent.grade < 70)
            {
                grade = 'C';
            }
            else
            {
                grade = 'D';
            }

            system("cls");
            cout << "====================================" << endl;
            cout << "~Welcome " << currentStudent.name << " to the Student's Section~" << endl;
            cout << "====================================" << endl;
            cout << "Here are your details: " << endl;
            cout << "====================================" << endl;
            cout << "Roll No: " << currentStudent.rollno << endl;
            cout << "English Marks: " << currentStudent.englishMarks << endl;
            cout << "Computer Marks: " << currentStudent.computerMarks << endl;
            cout << "Math Marks: " << currentStudent.mathMarks << endl;
            cout << "Science Marks: " << currentStudent.scienceMarks << endl;
            cout << "Grade: " << grade << endl;
            cout << "====================================" << endl;
            cout << "1. Log out & back to main menu\n";
            cout << "====================================" << endl;
            cout << "Your choice: ";
            cin >> choice;
            switch (choice)
            {
                case 1: logOut(); break;
                default: 
                    cout << "====================================" << endl;
                    cout << "ERROR: Invalid choice!" << endl;
                    cout << "Press any key to continue" << endl;
                    cout << "====================================" << endl;
                    getch();
                    break;
            }
        } while (isLoggedIn && isStudent);
    }
    else
    {
        do
        {
            system("cls");
            cout << "====================================" << endl;
            cout << " ~Welcome to the Student's Section~\n";
            cout << "====================================" << endl;
            cout << "1. Login\n2. Register yourself as a new student\n3. Back to main menu\n";
            cout << "====================================" << endl;
            cout << "Your choice: ";
            cin >> choice;

            switch (choice)
            {
                case 1: if(login("student")) choice = 3; break;
                case 2: if(newRegistration("student")) choice = 3; break;
                case 3: break;
                default: 
                    cout << "====================================" << endl;
                    cout << "ERROR: Invalid choice!" << endl;
                    cout << "Press any key to continue" << endl;
                    cout << "====================================" << endl;
                    getch();
                    break;
            }
        }while (choice != 3);
    }
}

void adminSection()
{
    int choice;
    do
    {
        system("cls");
        cout << "====================================" << endl;
        cout << "   ~Welcome to the Admin Section~   " << endl;
        cout << "====================================" << endl;
        cout << "1. Login\n2. Register a new admin\n3. Back to main menu\n";
        cout << "====================================" << endl;
        cout << "Your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1: if(login("admin")) choice = 3; break;
            case 2: if(newRegistration("admin")) choice = 3; break;
            case 3: break;
            default: 
                cout << "====================================" << endl;
                cout << "ERROR: Invalid choice!" << endl;
                cout << "Press any key to continue" << endl;
                cout << "====================================" << endl;
                getch();
                break;
        }
    } while (choice != 3);
}

bool newRegistration(string accountType)
{
    system("cls");
    FILE *fp;
    if (accountType == "teacher" && isAdmin)
    {
        fp = fopen("teachersnew.txt", "ab");
        cout << "====================================" << endl;
        cout << "~New Teacher Registration~\n";
        cout << "====================================" << endl;
        cout << "Username: ";
        cin >> currentTeacher.username;
        fflush(stdin);
        cout << "Enter your password: ";
        cin >> currentTeacher.password;
        fflush(stdin);
        cout << "Enter your name: ";
        cin >> currentTeacher.name;

        for (int i = 1; i < sizeof(currentTeacher.name); i++)
        {
            currentTeacher.name[i] = tolower(currentTeacher.name[i]);
        }
        currentTeacher.name[0] = toupper(currentTeacher.name[0]);

        fwrite(&currentTeacher, sizeof(currentTeacher), 1, fp);
        fflush(stdin);
        cout << "============================" << endl;
        cout << "          SUCCESS           " << endl;
        cout << "============================" << endl;
        cout << "  Teacher account created!  " << endl;
        cout << "============================" << endl;
        cout << "Press any key to go back to the admin menu";
        getch();
        fclose(fp);
        return true;
    }
    else if (accountType == "teacher" && !isAdmin)
    {
        cout << "=================================" << endl;
        cout << "              ERROR              " << endl;
        cout << "=================================" << endl;
        cout << "Need an admin account to do this!" << endl;
        cout << "=================================" << endl;
        cout << "Press any key to go back to the teacher menu";
        getch();
        return false;
    }
    else if (accountType == "student")
    {
        fp = fopen("studentsnew.txt", "ab");
        cout << "~New Student Registration~\n";
        cout << "Username: ";
        cin >> currentStudent.username;
        fflush(stdin);
        cout << "Enter your password: ";
        cin >> currentStudent.password;
        fflush(stdin);
        cout << "Enter your name: ";
        cin >> currentStudent.name;
        
        for (int i = 1; i < sizeof(currentStudent.name); i++)
        {
            currentStudent.name[i] = tolower(currentStudent.name[i]);
        }
        currentStudent.name[0] = toupper(currentStudent.name[0]);
        
        fflush(stdin);
        cout << "Enter your roll no: ";
        cin >> currentStudent.rollno;
        fflush(stdin);
        currentStudent.computerMarks, currentStudent.englishMarks,
        currentStudent.mathMarks, currentStudent.scienceMarks = 0;
        fwrite(&currentStudent,sizeof(currentStudent), 1, fp);
        fflush(stdin);
        cout << "==========================" << endl;
        cout << "          SUCCESS         " << endl;
        cout << "==========================" << endl;
        cout << " Student account created! " << endl;
        cout << "==========================" << endl;
        cout << "Press any key to go back to the admin menu";
        getch();
        fclose(fp);
        return true;
    }
    else
    {
        if(isLoggedIn && isAdmin)
        {
            string username;
            string password;
            cout << "~New Admin Registration~\n";
            cout << "Username: ";
            cin >> username;
            cout << "Enter your password: ";
            cin >> password;
            ofstream write("admins.txt", ios::app);
            write << username << ' ' << password << endl;
            write.close();
            cout << "==========================" << endl;
            cout << "          SUCCESS         " << endl;
            cout << "==========================" << endl;
            cout << "  Admin account created!  " << endl;
            cout << "==========================" << endl;
            cout << "Press any key to go back to the admin menu";
            getch();
            return true;
        }
        else
        {
            cout << "=================================" << endl;
            cout << "              ERROR              " << endl;
            cout << "=================================" << endl;
            cout << "Need an admin account to do this!" << endl;
            cout << "=================================" << endl;
            cout << "Press any key to go back to the admin menu";
            getch();
            return false;
        }
    }
}

bool login(string accountType)
{
    system("cls");
    bool accountFound;
    FILE *fp;

    if (accountType == "admin" && !isLoggedIn)
    {
        string username, password, un, pw;
        cout << "~Administrator Login~\n";
        cout << "Username: ";
        cin >> username;
        ifstream read("admins.txt");
        while(read >> un >> pw)
        {
            if (un == username)
            {
                accountFound = true;

                cout << "Enter your password: ";
                cin >> password;
                
                if (pw == password)
                {
                    cout << "===================" << endl;
                    cout << "      SUCCESS      " << endl;
                    cout << "===================" << endl;
                    cout << "     Logged in!    " << endl;
                    cout << "===================" << endl;
                    cout << "Press any key to go back to the main menu";
                    getch();
                    isLoggedIn = true;
                    isAdmin = true;
                    read.close();
                    return true;
                }
                else
                {
                    cout << "===================" << endl;
                    cout << "       ERROR       " << endl;
                    cout << "===================" << endl;
                    cout << "Incorrect Password!" << endl;
                    cout << "===================" << endl;
                    cout << "Press any key to go back to the admin menu";
                    getch();
                    break;
                }
            }
        }
        read.close();
        if(!accountFound)
        {
            cout << "===================" << endl;
            cout << "       ERROR       " << endl;
            cout << "===================" << endl;
            cout << "Account Not Found!" << endl;
            cout << "===================" << endl;
            cout << "Press any key to go back to the admin menu";
            getch();
        }
        return false;
    }

    else if (accountType == "student" && !isLoggedIn)
    {
        string username;
        string password;
        cout << "~Student Login~\n";
        cin.ignore();
        cout << "Username: ";
        getline(cin, username);
        fp = fopen("studentsnew.txt","rb");
        while(fread(&currentStudent,sizeof(currentStudent),1,fp))
        {
            if (username == currentStudent.username)
            {
                accountFound = true;
                cout << "Enter your password: ";
                getline(cin, password);
                if (password == currentStudent.password)
                {
                    isLoggedIn = true;
                    isStudent = true;
                    cout << "===================" << endl;
                    cout << "      SUCCESS      " << endl;
                    cout << "===================" << endl;
                    cout << "     Logged in!    " << endl;
                    cout << "===================" << endl;
                    cout << "Press any key to go back to the main menu";
                    getch();
                    fclose(fp);
                    return true;
                }
                else
                {
                    cout << "===================" << endl;
                    cout << "       ERROR       " << endl;
                    cout << "===================" << endl;
                    cout << "Incorrect Password!" << endl;
                    cout << "===================" << endl;
                    cout << "Press any key to go back to the student menu";
                    getch();
                    break;
                }
                break;
            }
        }
        fclose(fp);
        if(!accountFound)
        {
            cout << "===================" << endl;
            cout << "       ERROR       " << endl;
            cout << "===================" << endl;
            cout << "Account Not Found!" << endl;
            cout << "===================" << endl;
            cout << "Press any key to go back to the student menu";
            getch();
        }
        return false;
    }

    else if (accountType == "teacher" && !isLoggedIn)
    {
        string username;
        string password;
        cout << "~Teacher Login~\n";
        cin.ignore();
        cout << "Username: ";
        getline(cin, username);
        fp=fopen("teachersnew.txt","rb");
        while(fread(&currentTeacher,sizeof(currentTeacher),1,fp))
        {
            if (username == currentTeacher.username)
            {
                accountFound = true;
                cout << "Enter your password: ";
                getline(cin, password);
                if (password == currentTeacher.password)
                {
                    cout << "===================" << endl;
                    cout << "      SUCCESS      " << endl;
                    cout << "===================" << endl;
                    cout << "     Logged in!    " << endl;
                    cout << "===================" << endl;
                    cout << "Press any key to go back to the main menu";
                    getch();
                    isLoggedIn = true;
                    isTeacher = true;
                    fclose(fp);
                    return true;
                }
                else
                {
                    cout << "===================" << endl;
                    cout << "       ERROR       " << endl;
                    cout << "===================" << endl;
                    cout << "Incorrect Password!" << endl;
                    cout << "===================" << endl;
                    cout << "Press any key to go back to the teacher menu";
                    getch();
                    break;
                }
                break;
            }
        }
        fclose(fp);
        if(!accountFound)
        {
            cout << "===================" << endl;
            cout << "       ERROR       " << endl;
            cout << "===================" << endl;
            cout << "Account Not Found!" << endl;
            cout << "===================" << endl;
            cout << "Press any key to go back to the teacher menu";
            getch();
        }
        return false;
    }
    
    else
    {
        if (isAdmin)
        {
            cout << "====================================" << endl;
            cout << "               ERROR               " << endl;
            cout << "====================================" << endl;
            cout << "Already logged in as administrator!" << endl;
            cout << "====================================" << endl;
            cout << "Press any key to go back to the main menu";
            getch();
        }
        else if (isTeacher)
        {
            cout << "====================================" << endl;
            cout << "               ERROR               " << endl;
            cout << "====================================" << endl;
            cout << "   Already logged in as teacher!   " << endl;
            cout << "====================================" << endl;
            cout << "Press any key to go back to the main menu";
            getch();
        }
        else
        {
            cout << "====================================" << endl;
            cout << "               ERROR               " << endl;
            cout << "====================================" << endl;
            cout << "   Already logged in as student!   " << endl;
            cout << "====================================" << endl;
            cout << "Press any key to go back to the main menu";
            getch();
        }
    }
    return false;
}

void logOut()
{
    system("cls");
    if (isLoggedIn)
    {
        isAdmin = false;
        isTeacher = false;
        isStudent = false;
        isLoggedIn = false;
        cout << "===================" << endl;
        cout << "      SUCCESS      " << endl;
        cout << "===================" << endl;
        cout << "     Logged out!    " << endl;
        cout << "===================" << endl;
        cout << "Press any key to go back to the main menu";
        getch();
    }
    else
    {
        cout << "===================" << endl;
        cout << "       ERROR       " << endl;
        cout << "===================" << endl;
        cout << "   Not logged in!  " << endl;
        cout << "===================" << endl;
        cout << "Press any key to go back to the main menu";
        getch();
    }
}