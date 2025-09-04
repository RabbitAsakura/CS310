#include <iostream>
#include <stdexcept>

using namespace std;

int main(int argc, char const *argv[])
{
    try
    {
        bool condition = true;
        int nums[] = {2,5,4,67,90};
        int i;

        std::cout << "Enter an index: ";
        std::cin >> i;

        if(i < 0 || i > 5)
        {
            throw out_of_range("Index out of bound!");
        }

        std::cout << "Num at index " << i << ": " << nums[i] << std::endl;

        if(condition)
        {
            throw runtime_error("Runtime error occurred!");
        }else{
            throw out_of_range("Index out of bound!");
        }
    }catch(const runtime_error& e)
    {
        std::cerr << "Runtime Error: "<< e.what() << "\n";
    }catch(const out_of_range& e)
    {
        std::cerr << "Out of Range Error: "<< e.what() << "\n";
    }catch(const exception& e)
    {
        std::cerr << "Error: "<< e.what() << "\n";
    }
    std::cout << "Execution continues..." << std::endl;
    return 0;
}