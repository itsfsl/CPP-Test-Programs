#include <iostream>

template <typename f, typename s>

auto max(f x, s y){
    return (x > y) ? x : y;
}

int main()
{
    std::cout << max('a', 'A');
}