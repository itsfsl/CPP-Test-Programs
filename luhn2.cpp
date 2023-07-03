#include <iostream>

int sumOddNumbers(std::string cc);
int sumEvenNumbers(std::string cc);
int getDigit(int sum);

int main()
{
    std::string cc;
    int result;

    std::cout << "Enter CC#:"; //6011000990139424
    std::cin >> cc;

    result = sumOddNumbers(cc) + sumEvenNumbers(cc);

    if (result % 10 == 0)
    {
        std::cout << "Valid CC!";
    }
    else
    {
        std::cout << "Invalid CC!";
    }
    return 0;
}

int sumOddNumbers(std::string cc)
{
    int sum;

    for (int i = cc.size() - 2; i >= 0; i-=2)
    {
        sum += getDigit((cc[i] - '0') * 2);
    }

    return sum;
}
int sumEvenNumbers(std::string cc)
{
    int sum;

    for (int i = cc.size() - 1; i >= 0; i-=2)
    {
        sum += getDigit(cc[i] - '0');
    }
    return sum;
}
int getDigit(int number)
{
    return number = number % 10 + (number / 10 % 10);
}