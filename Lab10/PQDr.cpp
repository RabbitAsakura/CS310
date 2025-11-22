//Jakobe McPhail
//11/22/25
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
typedef int ItemType;
#include "PQType.h"
#include "customer.h"

using namespace std;

void Roster(vector<pair<string, string>>& names)
{
    ifstream roster("roster.txt");
    string first, last;

    if (!roster.is_open())
    {
        std::cout << "Error: Could not open roster.txt. Using dummy names." << endl;
        for (int i = 0; i < 30; ++i) {
            names.push_back({("First" + to_string(i)), ("Last" + to_string(i))});
        }
        return;
    }
    int count = 0;
    while (roster >> first >> last && count < 30)
    {
        names.push_back({first, last});
        count++;
    }
    roster.close();
    if (names.size() < 30) 
    {
        cerr << "Warning: Only read " << names.size() << " names from roster.txt. Should have 30." << endl;
    }
}

int main()
{
    ofstream outFile("pq_wait_times.txt");
    outFile << "--- Priority Queue Wait Time Simulation Results ---" << endl;

    const int MAX_QUEUE_SIZE = 100;
    const int PRE_OPEN_CUSTOMERS = 10;
    const int MAX_SERVICES = 200; 
    
    srand(time(0)); 

    PQType<Customer> queue(MAX_QUEUE_SIZE);
    vector<pair<string, string>> rosterNames;
    vector<pair<string, int>> waitTimes; 
    int currentCount = 0;
    int servicesCompleted = 0;
    
    Roster(rosterNames);

    if (rosterNames.empty()) {
        outFile << "FATAL ERROR: Roster is empty. Simulation aborted." << endl;
        outFile.close();
        return 1;
    }

    outFile << "\n--- Pre-Store Opening: 10 Initial Customers ---\n" << endl;
    for (int i = 0; i < PRE_OPEN_CUSTOMERS; ++i)
    {
        int randomIndex = rand() % rosterNames.size();
        string first = rosterNames[randomIndex].first;
        string last = rosterNames[randomIndex].second;
        
        currentCount++; 
        Customer newCustomer(first, last, currentCount);

        try
        {
            queue.Enqueue(newCustomer);
            outFile << "P" << newCustomer.getNameLength() << ": " << newCustomer.getName() 
                    << " (Assigned #" << newCustomer.getNumber() << ") enqueued." << endl;
        }
        catch (FullPQ)
        {
            outFile << "FullQueue exception thrown during pre-opening." << endl;
            break;
        }
    }
    
    outFile << "\n--- Main Simulation: Serving up to " << MAX_SERVICES << " Customers ---\n" << endl;
    while (servicesCompleted < MAX_SERVICES && (!queue.IsEmpty() || currentCount < 1000)) 
    {
        int randomEvent = rand() % 100;
        if (randomEvent < 60) 
        {
            if (!queue.IsFull())
            {
                int randomIndex = rand() % rosterNames.size();
                string first = rosterNames[randomIndex].first;
                string last = rosterNames[randomIndex].second;
                
                currentCount++; 
                Customer newCustomer(first, last, currentCount);

                try {
                   queue.Enqueue(newCustomer);
                } catch (FullPQ) {
                    outFile << "FullQueue exception thrown." << endl;
                }
            }
        }
        else 
        {
            if (!queue.IsEmpty())
            {
                Customer servedCustomer;
                try {
                   queue.Dequeue(servedCustomer); 
                   servicesCompleted++;
                   int waitTime = currentCount - servedCustomer.getNumber();
                   waitTimes.push_back({servedCustomer.getName(), waitTime});
                   
                   outFile << "DEQUEUED: " << servedCustomer.getName() 
                           << " (P" << servedCustomer.getNameLength() 
                           << ", Assigned #" << servedCustomer.getNumber()
                           << ") Wait Time: " << waitTime << endl;

                } catch (EmptyPQ) {
                    outFile << "EmtpyQueue exception thrown." << endl;
                }
            }
        }
    }
    outFile << "\n--- FINAL PURCHASERS AND WAIT TIMES ---\n" << endl;
    outFile << "Total services completed: " << servicesCompleted << endl;
    outFile << "Name\t\t\tWait Time" << endl;
    outFile << "---------------------------------------" << endl;
    
    for (const auto& entry : waitTimes)
    {
        outFile << entry.first << "\t\t" << entry.second << endl;
    }
    cout << "Testing completed. Results written to pq_wait_times.txt."  << endl;
    outFile.close();
    return 0;
}