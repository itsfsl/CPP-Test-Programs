#include <iostream>
#include <cstring>

struct Person
{
    char name[64];
    int age;
};

void updateStruct(struct Person *p, const char* name, int age)
{
    strcpy(p->name, name);
    p->age = age;
}

int main()
{
    struct Person fsl;

    updateStruct(&fsl, "fslsssss", 200);
    
    std::cout << fsl.name << '\n';
    std::cout << fsl.age << '\n';
}