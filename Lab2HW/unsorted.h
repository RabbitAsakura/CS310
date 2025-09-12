#ifndef UNSORTED_H
#define UNSORTED_H

#include "ItemType.h"

class UnsortedType 
{
public:
  UnsortedType();
  bool IsFull() const;
  int GetLength() const;
  ItemType GetItem(ItemType item, bool& found);
  bool MakeEmpty();
  void PutItem(ItemType item);
  void DeleteItem(ItemType item);
  void ResetList();
  ItemType GetNextItem();

private:
  int length;
  ItemType info[MAX_ITEMS];
  int currentPos;
};

#endif