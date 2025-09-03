#include <iostream>
#include <string>
using namespace std;

class Person
{
    private:
        int age;
        string name;
    public:
        Person(string name, int age): name(name), age(age){};
        void setName(string n)
        {
            name = n;
        }
        string getName() const
        {
            return name;
        }
        void display() const 
        {
            cout << "Name: " << name << ", Age: " << age << endl;
        }
};

class Employee: private Person
{
    public:
        Employee(string n, int a):
        {
            name = n;
            age = a;
        }
        void work() const{ cout << "Performs tasks!" << endl;};
};

int main()
{
    //Example1
    Person employee("Alice",27);
    employee.display();
    employee.setName("Alicia");
    cout << " Employee's new name is: " << employee.getName() << endl;

    //Example 2
    Employee emp1 = new Employee();
    emp1.setName("Alice");
    return 0;
}