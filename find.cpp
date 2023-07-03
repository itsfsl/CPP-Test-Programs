#include <iostream>

int findNumber(int numbers[], int size, int element);

int main(){

    int numbers[] = {1, 2, 3, 4, 6, 7, 8};

    int size = sizeof(numbers)/sizeof(int);

    int element;

    int index;

    std::cout << "What number do you want to search for?: ";
    std::cin >> element;

    index = findNumber(numbers, size, element);
    
    if(index < 0){
        std::cout << "Couldn't find your number!";
    }
    else{
        std::cout << "Found your number at index " << index;
    }
    return 0;
}

int findNumber(int numbers[], int size, int element){
    for(int i = 0; i < size; i++){
        if (element == numbers[i]){
            return i;
        }
    }
    return -1;
}