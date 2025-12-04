//Jakobe McPhail
//12/04/25
//Data Structures
#include "HeapMaster.h"

struct SRTFTask
{
    int id;
    int remainingTime;
    int arrivalTime;
    bool operator<(const SRTFTask& other) const 
    {
        return remainingTime < other.remainingTime;
    }

};


int main()
{

    const int MAX_SIZE = 20;
    int array[MAX_SIZE] = {2,3,6,7,8,1,10,11,19,4,9,0,18,13,12,5,14,20,17};
    HeapMaster<int> maxHeap;
    
    std::cout << "Inital Array: ";
    for(int i = 0; i < 20; i++)
    {
        std::cout << array[i] << (i < 20 ?  ", " : ""); 
    }

    std::cout << std::endl;
    maxHeap.buildHeap(array, 20);

    std::cout << "Heap Master After Buld Heap:\n";
    maxHeap.printHeap();

    std::cout << "After popping 7 elements:\n";
    maxHeap.pop();
    maxHeap.pop();
    maxHeap.pop();
    maxHeap.pop();
    maxHeap.pop();
    maxHeap.pop();
    maxHeap.pop();
    maxHeap.printHeap();

    maxHeap.push(50);
    maxHeap.push(100);
    maxHeap.push(200);
    maxHeap.push(25);
    maxHeap.push(35);
    std::cout << "After pushing 5 elements:\n";
    maxHeap.printHeap();


    HeapMaster<SRTFTask, 1000, std::less<SRTFTask>> pq;

    pq.push({1, 10, 0});
    pq.push({2, 3, 1});
    pq.push({3, 5, 2});

    int time = 0;
    while(!pq.empty())
    {
        auto task = pq.top(); pq.pop();
        std::cout << "Time " << time << ": Running Task " << task.id
        << " (rem=" << task.remainingTime << ")\n";

        task.remainingTime -= 1;
        time++;

        if(task.remainingTime > 0)
        {
            pq.push(task);
        }
    }

    std::cout << std::endl;
}