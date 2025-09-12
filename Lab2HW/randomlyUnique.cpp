//Jakobe McPhail
//09/12/25
//Data Structures

#include "unsorted.h"
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    ItemType item;
    int randomNumber = rand() % 100;
    UnsortedType list;

    for(int i = 0; i < list.GetLength(); i++)
    {
        item.Initialize(randomNumber);
        ItemType foundItem;
        bool found = false;
        list.GetItem(item, found);
        if(found)
        {
            list.DeleteItem(item);
        }
        if(list.IsFull())
        {
            break;
        }
    }

    for(int i = 0; i < list.GetLength(); i++)
    {
        ItemType temp = list.GetNextItem();
        temp.Print(cout);
        cout << " ";
    }

}