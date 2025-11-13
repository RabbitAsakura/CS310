//Jakobe McPhail
//11/11/25
//Data Structures

#ifndef SORTEDLINKEDLIST_H
#define SORTEDLINKEDLIST_H
#include "LinkedList.h"


class SortedLinkedList : public LinkedList
{
    public:
        void insertSorted(int val);
};
#endif