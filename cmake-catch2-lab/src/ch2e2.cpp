#include <iostream>
#include <string>
using namespace std;

class Person
{
    protected:
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

class Employee: public Person
{
    private:
         double salary;
    public:
        Employee(string n, int a): Person(n,a), salary(0){}
        void work() const{ cout << "Performs tasks!" << endl;};
        
        void display()
        {
            Person::display(); 
            std::cout << ".\t Salary: " << salary << std::endl;
        }
};

int main()
{
    //Example1
    Person employee("Alice",27);
    employee.display();
    employee.setName("Alicia");
    cout << " Employee's new name is: " << employee.getName() << endl;

    //Example 2
    Employee emp1("John Smith", 24);
    emp1.setName("Alice");
    emp1.display();
    return 0;
}