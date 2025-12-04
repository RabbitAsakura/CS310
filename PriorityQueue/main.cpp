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

}