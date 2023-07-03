#include <iostream>

void walk(int steps)
{
    /* for (int i = 0; i < steps; i++)
    {
        std::cout << "You took one step!\n";
    } */
    if(steps > 0)
    {
        std::cout << "You took one step!\n";
        walk(steps - 1);
    }
}

int main()
{
    walk(3);
}