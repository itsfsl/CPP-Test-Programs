#include <iostream>

double currencyConverter(int choice, double value, int choice2)
{
    double USD, INR, EUR, YEN, GBP;

    if (choice == 1)
    {
        INR = 82.466;
        GBP = 0.82002;
        USD = 1;
        EUR = 0.93296;
        YEN = 129.86;

        if (choice2 == 1)
        {
            return value * USD;
        }
        if (choice2 == 2)
        {
            return value * INR;
        }
        if (choice2 == 3)
        {
            return value * EUR;
        }
        if (choice2 == 4)
        {
            return value * YEN;
        }
        if (choice2 == 5)
        {
            return value * GBP;
        }
    }
    else if (choice == 2)
    {
        INR = 1;
        GBP = 0.0099306;
        USD = 0.012121;
        EUR = 0.011298;
        YEN = 1.5747;

        if (choice2 == 1)
        {
            return value * USD;
        }
        if (choice2 == 2)
        {
            return value * INR;
        }
        if (choice2 == 3)
        {
            return value * EUR;
        }
        if (choice2 == 4)
        {
            return value * YEN;
        }
        if (choice2 == 5)
        {
            return value * GBP;
        }
    }
    else if (choice == 3)
    {
        INR = 88.540;
        GBP = 0.87899;
        USD = 1.0732;
        EUR = 1;
        YEN = 139.43;

        if (choice2 == 1)
        {
            return value * USD;
        }
        if (choice2 == 2)
        {
            return value * INR;
        }
        if (choice2 == 3)
        {
            return value * EUR;
        }
        if (choice2 == 4)
        {
            return value * YEN;
        }
        if (choice2 == 5)
        {
            return value * GBP;
        }
    }
    else if (choice == 4)
    {
        INR = 0.0071722;
        GBP = 0.0063043;
        USD = 0.0076975;
        EUR = 0.0071722;
        YEN = 1;

        if (choice2 == 1)
        {
            return value * USD;
        }
        if (choice2 == 2)
        {
            return value * INR;
        }
        if (choice2 == 3)
        {
            return value * EUR;
        }
        if (choice2 == 4)
        {
            return value * YEN;
        }
        if (choice2 == 5)
        {
            return value * GBP;
        }
    }
    else if (choice == 5)
    {
        INR = 100.75;
        GBP = 1;
        USD = 1.2212;
        EUR = 1.1377;
        YEN = 158.68;

        if (choice2 == 1)
        {
            return value * USD;
        }
        if (choice2 == 2)
        {
            return value * INR;
        }
        if (choice2 == 3)
        {
            return value * EUR;
        }
        if (choice2 == 4)
        {
            return value * YEN;
        }
        if (choice2 == 5)
        {
            return value * GBP;
        }
    }
    else
    {
        std::cout << "Invalid choice!";
    }
    return 0;
}

int main()
{
    system("color 02");
    double value;
    int choice;
    int choice2;
    double newValue;
    char exit;
    std::string symbol;
    std::string fullname;
    std::string symbol2;
    std::string fullname2;

    do
    {
        std::cout << "What currency would you like to convert?\n";
        std::cout << "1. USD\n2. INR\n3. EURO\n4. YEN\n5. GREAT BRITISH POUND\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        if (choice <= 0 || choice > 5)
        {
            std::cout << "Error: Invalid value!";
            return 0;
        }
        else
        {
            switch (choice)
            {
                case 1: symbol = "$"; fullname = "US Dollar"; break;
                case 2: symbol = "Rs."; fullname = "Indian Rupees"; break;
                case 3: symbol = "EUR"; fullname = "Euro"; break;
                case 4: symbol = "YEN"; fullname = "Yen Dollar"; break;
                case 5: symbol = "GBP"; fullname = "Great British Pound"; break;
                default: break;
            }
        }
        std::cout << "\nYour choice: " << fullname << '\n';
        std::cout << "Enter value to convert: " << symbol << " ";
        std::cin >> value;
        if (value <= 0)
        {
            std::cout << "Error: Invalid value!";
            return 0;
        }
        else
        {
            std::cout << "\nConvert " << value << ' ' << fullname << ' ' << "to?\n";
            std::cout << "1. USD\n2. INR\n3. EURO\n4. YEN\n5. GREAT BRITISH POUND\n";
            std::cout << "Enter your choice: ";
            std::cin >> choice2;
            if (choice2 <= 0 || choice2 > 5)
            {
                std::cout << "Error: Invalid value!";
                return 0;
            }
            else
            {
                switch (choice2)
                {
                    case 1: symbol2 = "$"; fullname2 = "US Dollar"; break;
                    case 2: symbol2 = "Rs."; fullname2 = "Indian Rupees"; break;
                    case 3: symbol2 = "EUR"; fullname2 = "Euro"; break;
                    case 4: symbol2 = "YEN"; fullname2 = "Yen Dollar"; break;
                    case 5: symbol2 = "GBP"; fullname2 = "Great British Pound"; break;
                    default: break;
                }
            }
        }

        std::cout << "\nYour choice: " << fullname2 << '\n';
        
        newValue = currencyConverter(choice, value, choice2);

        std::cout << symbol << value << " is " << symbol2 << newValue << '\n';    
        
        std::cout << "\nWould you like to exit? Y/N: ";
        std::cin >> exit;
        exit = toupper(exit);
        std::cout << '\n';
    } while (exit != 'Y');
    return 0;
}