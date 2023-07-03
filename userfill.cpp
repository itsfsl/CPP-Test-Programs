#include <iostream>

int main()
{ 
    const int SIZE = 5;
    std::string foodList[SIZE];
    std::string temp;

    for (int i = 0; i < SIZE; i++)
    { 
        std::cout << "Enter some food name or 'q' to quit #" << i + 1 << ":";
        std::getline(std::cin, temp);
        if (temp == "q")
        {
            break;
        }
        else
        {
            foodList[i] = temp;
        }
    }

    std::cout << "Here are the foods you like:\n";

    for (int i = 0;!foodList[i].empty(); i++)
    {
        std::cout << foodList[i] << '\n';
    }
    
    return 0;
}