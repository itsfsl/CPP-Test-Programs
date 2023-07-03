#include <iostream>

int main(){

    int size = 99;
    std::string foods[size];

    fill(foods, foods + size/3, "pizza");
    fill(foods + size/3, foods + (size/3)*2, "burger");
    fill(foods + (size/3)*2, foods + size, "french fries");

    for(std::string food : foods){
        std::cout << food << '\n';
    }
}