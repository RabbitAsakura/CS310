//Jakobe McPhail
//09/12/25
//Data Structures

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "unsorted.h"
using namespace std;

int main()
{
    
    UnsortedType list;
    ItemType item;
    
    // Keep generating until we have 50 unique numbers
    int attempts = 0;
    while(list.GetLength() < 50 && !list.IsFull())
    {
        int number = rand() % 100;  
        item.Initialize(number);
        bool found = false;
        
        // Note: GetItem for linked list takes ItemType& (reference)
        ItemType searchItem = item; 
        list.GetItem(searchItem, found);
        
        if(!found) {
            list.PutItem(item);     // Add only if not found
            cout << "Added: " << number << " (List size: " << list.GetLength() << ")" << endl;
        }
        
        attempts++;
        // Prevent infinite loop in case of bad luck
        if(attempts > 10000) {
            cout << "Too many attempts, stopping with " << list.GetLength() << " numbers." << endl;
            break;
        }
    }
    
    cout << "\nFinal list of " << list.GetLength() << " unique numbers:" << endl;
    cout << "Displayed in rows of 10:" << endl;
    
    // Display the list in rows of 10
    list.ResetList();
    for(int i = 0; i < list.GetLength(); i++)
    {
        ItemType temp = list.GetNextItem();
        temp.Print(cout);
        cout << " ";
        
        // Print newline after every 10 numbers
        if((i + 1) % 10 == 0) {
            cout << endl;
        }
    }
    
    // Print final newline if the last row isn't complete
    if(list.GetLength() % 10 != 0) {
        cout << endl;
    }
    
    return 0;
}