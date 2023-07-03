#include <iostream>

int main()
{
    int num1 = 1;
    int num2 = 4;
    int *pNum1 = &num1;
    int *pNum2 = &num2;

    std::cout << *pNum1 << '\n';
    std::cout << *pNum2;
}