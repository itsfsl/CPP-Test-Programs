#include <iostream>
#include <unistd.h>

int main()
{
    std::cout << "Let's wait 5 secs!\n";
    for (int i = 5; i > 0; i--)
    {
        std::cout << i << '\n';
        sleep(1);
    }
    std::cout << "Bye!";
    return 0;
}