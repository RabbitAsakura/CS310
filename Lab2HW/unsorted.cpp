#include "unsorted.h"

UnsortedType::UnsortedType(int MAX_ITEMS) {
    capacity = MAX_ITEMS;
    info = new ItemType[capacity];
    length = 0;
    currentPos = -1;
}

bool UnsortedType::MakeEmpty() {
    length = 0;
    return true;
}

bool UnsortedType::IsFull() const {
    return length == capacity;
}

int UnsortedType::GetLength() const {
    return length;
}

ItemType UnsortedType::GetItem(ItemType item, bool& found) {
    found = false;
    for (int i = 0; i < length; i++) {
        if (info[i].ComparedTo(item) == EQUAL) {
            found = true;
            return info[i];
        }
    }
    return item;
}

void UnsortedType::PutItem(ItemType item) {
    if (length < capacity) {
        info[length++] = item;
    }
}

void UnsortedType::DeleteItem(ItemType item) {
    for (int i = 0; i < length; i++) {
        if (info[i].ComparedTo(item) == EQUAL) {
            for (int j = i; j < length - 1; j++) {
                info[j] = info[j + 1];
            }
            length--;
            return;
        }
    }
}

void UnsortedType::ResetList() {
    currentPos = -1;
}

ItemType UnsortedType::GetNextItem() {
    currentPos++;
    return info[currentPos];
}
