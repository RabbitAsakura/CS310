//Jakobe McPhail
//11/22/25
#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include <iostream>

class Customer
{
    private:
        std::string firstName;
        std::string lastName;
        int assignedNumber;
        int nameLength;
    public:
        Customer() : firstName(""), lastName(""), assignedNumber(0), nameLength(0) {}
        Customer(std::string first, std::string last, int number)
        {
            firstName = first;
            lastName = last;
            assignedNumber = number;
            nameLength = firstName.length() + lastName.length() + 1;
        }
        std::string getName() const {return firstName + " " + lastName;}
        int getNumber() const {return assignedNumber;}
        int getNameLength() const {return nameLength;}

        bool operator<(const Customer& other) const
        {
            return nameLength < other.nameLength;
        }

        bool operator>(const Customer& other) const
        {
            return nameLength > other.nameLength;
        }

        bool operator<=(const Customer& other) const
        {
            return nameLength <= other.nameLength;
        }
};




#endif