//Jakobe McPhail
//10/21/25
#include <iostream>

template <typename T>
T max(T a, T b)
{
    return (a > b) ? a : b;
}

template <typename T, typename U>
T add(T a, U b)
{
    return a + b;
}

template <typename T1, typename T2>
class Pair
{
    private:
        T1 first;
        T2 second;
    public:
        Pair(T1 f, T2 s) : first(f), second(s) {}

        T1 getFirst()
        {
            return first;
        }

        T2 getSecond()
        {
            return second;
        }

};

template <typename T, int Size>
class FixedArray
{
    T data[Size]; 
};

template<>
const char* max<const char*>(const char* a, const char* b)
{
    return std::string(a) > std::string(b) ? a : b;
} 

template <typename... Args>
void print(Args... args)
{
    (std::cout << ... << args) << std::endl;
}

int main()
{
    int a = 10;
    int b = 20;
    int c = max(a, b);
    std::cout << c << std::endl;
    std::cout << max(4.5,3.2) << std::endl;
    std::cout << max('a', 'b') << std::endl;
    std::cout << max('a' , 'd') << std::endl;
    std::cout << max("Hello" , "Hi") << std::endl;
    //std::cout << max( 31, 30) << std::endl;

    std::cout << "==========================" << std::endl;
    std::cout << add(10, 20.5) << std::endl;
    std::cout << add(10.5, 20) << std::endl;
    std::cout << add(10, 'a') << std::endl;
    std::cout << add(std::string("Hello "), "World!") << std::endl;
    //std::cout << add(std::string("Hello "), 2.5) << std::endl;

    std::cout << "==========================" << std::endl;
    Pair<int, double> p1(10, 20.5);
    Pair<std::string, char> p2("Hello", '!');
    Pair<std::string, float> p3("Pi", 3.14);
    std::cout << p1.getFirst() << std::endl;
    std::cout << p1.getSecond() << std::endl;
    std::cout << p2.getFirst() << std::endl;
    std::cout << p2.getSecond() << std::endl;
    std::cout << p3.getFirst() << std::endl;
    std::cout << p3.getSecond() << std::endl;
    std::cout << "==========================" << std::endl;
    print(1, 2, 3, 4, 5);
    print("Hello", " ", "World", "!");
    print(3.14, " is Pi, ", 2.71, " is e");
    
}