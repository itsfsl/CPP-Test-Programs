#include <iostream>

void sort(int array[], int size){

    int temp;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j] < array[j+1])
            {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

int main(){
    int numbers[] = {4,6,3,8,1,9,0,2,5,7};
    int temp;

    int totalSize = sizeof(numbers)/sizeof(int);

    sort(numbers, totalSize);

    for(int element : numbers){
        std::cout << element << '\n';
    }
    return 0;
}