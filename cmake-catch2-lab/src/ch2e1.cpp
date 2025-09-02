#include <iostream>
using namespace std;

class Integer
{
    private:
    int value;
    
    public:
    Integer(int v): value(v){};
    int getValue() const {return value;};
    ~Integer();
};

class Counter
{
    private:
        int count;

    public:
        Counter()
        {
            count = 0;
        }
        void increment()
        {
            count++;
        }
        void decrement()
        {
           (count == 0)? 0: count--;
        }
        int getCount() const {return count;}
};

class Library
{
    private:
        bool available;
    public:
        Library() : available(true){};
        void checkOut()
        {
            if(available)
            {
                available = false;
            }
        }

        void checkIn()
        {
            available = true;
        }

        bool isAvailable() const
        {
            return available;
        }
};

struct Point
{
    int x,y;
};

int main()
{
    //Example 1
    Integer n(40);
    n = 102;
    cout << "Value: " << n.getValue() << endl;
    
    //Example 2
    Counter c;
    c.increment();
    cout << "Count: " << c.getCount() << endl;
    
    //Example 3
    Library book;
    book.checkOut();
    cout << " Book Availibility: " << (book.isAvailable() ? "Yes":"No") << endl;
    
    //Example 4
    Point points[2] = {{0,0}, {2,2}};
    for(int i = 0; i < 2; i++)
    {
        cout << "Point" <<(i+1) << ": [" << points[i].x << "," << points[i].y << "]\n";
    }
    return 0; 
}