#include <iostream>
#include <stdexcept>

using namespace std;

void divide(int a, int b)
{
    if(b == 0)
    {
        throw invalid_argument("Division by zero is invalid!");
    }
    std::cout << " Result: " << a / b << std::endl;
}

int main()
{
    string user_input = "y";
    int a, b;

    while(user_input == "y"){
       try
         {
        std::cout << "Enter two numbers: ";
        std::cin >> a >> b;
        divide(a, b);
        }
        catch(const std::exception& e)
        {
        std::cerr << "Caught: "<< e.what() << '\n';
        }
        catch(const exception& e)
        {
            std::cerr << "General Error: "<< e.what() << '\n';
        }
        std::cout<< "Do you want to continue? (y/n): ";
        std::cin >> user_input;
    }
}