#include <iostream>

int main()
{
    char* str = "ABCD";

    str[0] = *"F";

    std::cout << str[0];
    
    return 0;

}