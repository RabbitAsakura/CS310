//Jakobe McPhail
//12/04/25
//Data Structures

#ifndef HEAPMASTER_HPP
#define HEAPMASTER_HPP
#include "HeapMaster.h"

template<typename T, int MAX_SIZE, typename Compare>
void HeapMaster<T, MAX_SIZE, Compare>::heapifyUp(int i)
{
    while(i > 0)
    {
        int p = parent(i);
        if(comp(data[p], data[i]))
        {
            std::swap(data[p], data[i]);
            i = p;
        }
        else
        {
            break;
        }
    }
}

template<typename T, int MAX_SIZE, typename Compare>
void HeapMaster<T, MAX_SIZE, Compare>::heapifyDown(int i)
{
    while(true)
    {
        int best = i;
        int l = left(i);
        int r = right(i);

        if(l < sz && comp(data[best], data[l])) best = l;
        if(r < sz && comp(data[best], data[r])) best = r;

        if(best != i)
        {
            std::swap(data[i], data[best]);
            i = best;
        }
        else
        {
            break;
        }
    }
}

template<typename T, int MAX_SIZE, typename Compare>
bool HeapMaster<T, MAX_SIZE, Compare>::decreaseKey(int idx, const T& newVal)
{
    if(idx < 0 || idx >= sz) return false;
    
    if constexpr(std::is_same_v<Compare, std::less<T>>)
    {
        if(comp(newVal, data[idx]))
        {
            return false;
        }
    }
    else
    {
        if(comp(data[idx], newVal))
        {
            data[idx] = newVal;
            heapifyDown(idx);
            return true;
        }
    }

    data[idx] = newVal;
    heapifyUp(idx);
    return true;
}

template<typename T, int MAX_SIZE, typename Compare>
bool HeapMaster<T, MAX_SIZE, Compare>::increaseKey(int idx, const T& newVal)
{
    if(idx < 0 || idx >= sz) return false;

    if constexpr(std::is_same_v<Compare, std::less<T>>)
    {
        if(comp(newVal, data[idx]))
        {
            return false;
        }
    }
    else
    {
        if(comp(data[idx], newVal))
        {
            return false;
        }
    }

    data[idx] = newVal;
    heapifyDown(idx);
    return true;
}

template<typename T, int MAX_SIZE, typename Compare>
const T& HeapMaster<T, MAX_SIZE, Compare>::top() const
{
    if(sz == 0) throw std::out_of_range("Heap is empty");
    return data[0];
}

template<typename T, int MAX_SIZE, typename Compare>
void HeapMaster<T, MAX_SIZE, Compare>::push(const T& val)
{
    if(sz >= MAX_SIZE) throw std::overflow_error("Heap full");

    data[sz] = val;
    heapifyUp(sz);
    sz++;
}

template<typename T, int MAX_SIZE, typename Compare>
void HeapMaster<T, MAX_SIZE, Compare>::pop()
{
    if(sz == 0) throw std::underflow_error("Heap empty");

    data[0] = data[--sz];
    heapifyDown(0);
}

#endif