#include <iostream>
#include <iomanip>

double deposit();
double withdraw(double balance);
void showBalance(double balance);

int main(){
    int choice = 0;
    double balance = 0;

    std::cout << "***FSL BANK***\n";

    do
    {
        std::cout << "1. Deposit\n";
        std::cout << "2. Withdraw\n";
        std::cout << "3. Balance\n";
        std::cout << "4. Exit\n";
        std::cout << "Select an option: ";
        std::cin >> choice;
        std::cin.clear();
        fflush(stdin);

        switch(choice){
        case 1: balance += deposit(); showBalance(balance); break;
        case 2: balance -= withdraw(balance); showBalance(balance); break;
        case 3: showBalance(balance); break;
        case 4: break;
        default: std::cout << "Enter a valid choice!\n"; break;
        }

    } while (choice!= 4);

    std::cout << "***Thanks for using the ATM***";

    return 0;    
}

double deposit(){
    double amount;
    std::cout << "Enter amount to deposit: ";
    std::cin >> amount;

    if (amount < 0){
        std::cout << "Error: Invalid amount!\n";
        return 0;
    }
    else{
        return amount;
    }
}

double withdraw(double balance){
    double amount;
    std::cout << "Enter amount to withdraw: ";
    std::cin >> amount;

    if (amount > balance){
        std::cout << "Error: Insufficient funds!\n";
        return 0;
    }
    else if (amount < 0){
        std::cout << "Error: Invalid amount!\n";
        return 0;
    }
    else{
        return amount;
    }
}

void showBalance(double balance){
    std::cout << "Your balance is: $" << std::setprecision(2) << std::fixed << balance << "\n";
}