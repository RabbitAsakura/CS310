//Jakobe McPhail
//09/12/25
//Data Structures

#include "unsorted.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    UnsortedType list;
    ItemType item;

    while(!list.IsFull())
    {
        int num = rand() % 100;
        item.Initialize(num);
        bool found;
        list.GetItem(item, found);
        if(!found)
        {
            list.PutItem(item);
        }
    }

    list.ResetList();
    for(int i = 0; i < list.GetLength(); i++)
    {
        ItemType temp = list.GetNextItem();
        temp.Print(cout);
        cout << " ";

    if((i+1) % 10 == 0)
    {
        std::cout << std::endl;
    }
}

    if(list.GetLength() % 10 != 0)
    {
        std::cout << std::endl;
    }
}