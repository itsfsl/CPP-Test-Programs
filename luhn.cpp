#include <iostream>

int sumEvenDigits(std::string cc);
int sumOddDigits(std::string cc);
int getDigit(int number);

int main()
{
    //6011000990139424
    std::string cc;
    int result = 0;

    std::cout << "Enter CC#: ";
    std::cin >> cc;

    result = sumEvenDigits(cc) + sumOddDigits(cc);

    if (result % 10 == 0)
    {
        std::cout << "Your CC# is valid.";
    }
    else
    {
        std::cout << "Your CC# is NOT valid.";
    }
    return 0;
}

int sumEvenDigits(std::string cc){
    int sum;

    for(int i = cc.size() - 2; i >= 0; i-=2)
    {
        sum += getDigit((cc[i] - '0' ) * 2);
    }

    return sum;
}

int sumOddDigits(std::string cc){
    int sum;

    for(int i = cc.size() - 1; i >= 0; i-=2)
    {
        sum += getDigit(cc[i] - '0' );
    }

    return sum;
}

int getDigit(int number)
{   //0.7 // 0.07
    return number % 10 + (number / 10 % 10);
}