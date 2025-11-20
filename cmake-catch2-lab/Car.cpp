#include <string>

using namespace std;

class Car
{
    private:
        int speed;
        string vin;
        string make;
        std::string model;
    public:
        Car(int speed, string vin, string make, string model);
        Car(Car* car)
        {
            speed = car->speed;
            vin = car->vin;
            make = car->make;
            model = car->model;
        }
        Car CarCopy(Car* car)
        {
            Car newCar = new Car(car);
        }
};