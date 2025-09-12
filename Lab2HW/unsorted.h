#ifndef UNSORTED_H
#define UNSORTED_H
#include "ItemType.h" 
#include <iostream>
// File ItemType.h must be provided by the user of this class. 
//  ItemType.h must contain the following definitions: 
//  MAX_ITEMS:     the maximum number of items on the list 
//  ItemType:      the definition of the objects on the list 
//  RelationType:  {LESS, GREATER, EQUAL}
//  Member function ComparedTo(ItemType item) which returns 
//       LESS, if self "comes before" item 
//       GREATER, if self "comes after" item 
//       EQUAL, if self and item are the same 
using namespace std;

class UnsortedType 
{
public:
  UnsortedType(int MAX_ITEMS = 50)
  {
    capacity = MAX_ITEMS;
    info = new ItemType[MAX_ITEMS];
    length = 0;
    currentPos = -1;
  }
  // Constructor
  
  bool MakeEmpty()
  {
    return length == 0;
  }
  // Function: Returns the list to the empty state.
  // Post:  List is empty.
  
  bool IsFull() const
  {
    return length == capacity;
  }
  // Function:  Determines whether list is full.
  // Pre:  List has been initialized.
  // Post: Function value = (list is full)

  int GetLength() const
  {
    return length;
  }
  // Function: Determines the number of elements in list.
  // Pre:  List has been initialized.
  // Post: Function value = number of elements in list

  ItemType GetItem(ItemType item, bool& found)
  {
    found = false;
    for(int i = 0; i < length; i++){
      if(info[i].ComparedTo(item) == EQUAL)
      {
      found = true;
      return info[i];
      }
  }
    return item;
  }
  // Function: Retrieves list element whose key matches item's key (if
  //           present).
  // Pre:  List has been initialized.
  //       Key member of item is initialized.
  // Post: If there is an element someItem whose key matches
  //       item's key, then found = true and someItem is returned.
  // 	 otherwise found = false and item is returned.
  //       List is unchanged.

  void PutItem(ItemType item)
  {
    if(length < MAX_ITEMS)
    {
      info[length++] = item;
    }
  }
  // Function: Adds item to list.
  // Pre:  List has been initialized.
  //       List is not full.
  //       item is not in list.
  // Post: item is in list.

  void DeleteItem(ItemType item)
  {
    for(int i = 0; i < length; i++){
        if(info[i].ComparedTo(item) == 0)
        {
          for(int j = i; j < length-1; j++){
            info[j] = info[j+1];
          }
          length--;
          return;
        }
    }
  }
  // Function: Deletes the element whose key matches item's key.
  // Pre:  List has been initialized.
  //       Key member of item is initialized.
  //       One and only one element in list has a key matching item's key.
  // Post: No element in list has a key matching item's key.

  void ResetList()
  {
    currentPos = -1;
  }
  // Function: Initializes current position for an iteration through the list.
  // Pre:  List has been initialized.
  // Post: Current position is prior to list.

  ItemType GetNextItem()
  {
    currentPos++;
    return info[currentPos];
  }
  // Function: Gets the next element in list.
  // Pre:  List has been initialized and has not been changed since last call.
  //       Current position is defined.
  //       Element at current position is not last in list.
  //	     
  // Post: Current position is updated to next position.
  //       item is a copy of element at current position.

private:
  int length = 0;
  ItemType *info;
  int currentPos = -1;
  int capacity;
};

#endif
