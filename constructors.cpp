#include <iostream>

class Car
{
    public:
        std::string make;
        std::string model;
        int manufactureYear;
        std::string color;

    Car(std::string make, std::string model, int manufactureYear, std::string color)
    {
        this->make = make;
        this->model = model;
        this->manufactureYear = manufactureYear;
        this->color = color;
    }

    void accelerate()
    {
        std::cout << "Vroom Vroom!";
    }
};


int main()
{
    Car car1("Maruti Suzuki", "Wagon-R", 2018, "Pale Grey");
    Car car2("Maruti Suzuki", "Alto", 2021, "White");
    Car car3("Maruti Suzuki", "Ignis", 2019, "Blue");
    Car car4("Maruti Suzuki", "Celerio", 2022, "Orange");
    Car car5("Maruti Suzuki", "Omni", 2014, "White");
    
    std::cout << "A brand new " << car3.manufactureYear << ' ' << car3.color << ' ' << car3.make << ' ' << car3.model << ' ' << "just took off at full speed!\n";
    
    car3.accelerate();
    return 0;
}