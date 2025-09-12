//Jakobe McPhail
//09/12/25
//Data Structures

#include "unsorted.h"
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    UnsortedType list;
    ItemType item;

    while(!list.IsFull())
    {
        int number = rand() % 100;
        item.Initialize(number);
        bool found = false;
        list.GetItem(item, found);
        if(!found){
            list.PutItem(item);
        }
    }
    list.ResetList();
    for(int i = 0; i < list.GetLength(); i++)
    {
        ItemType temp = list.GetNextItem();
        temp.Print(cout);
        cout << " ";
    }
}