//! non premp priority
#include <iostream>
#include<bits/stdc++.h>

using namespace std;

struct Process {
    int id;
    int arrivalTime;
    int burstTime;
    int priority;
    int completionTime;
    int turnaroundTime;
    int waitingTime;
    
};

bool compareArrivalTime(const Process& p1, const Process& p2) {
    return p1.arrivalTime < p2.arrivalTime;
}

bool comparepriority(const Process& p1, const Process& p2) {
    return p1.priority < p2.priority;
}

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<Process> processes(n);

    cout << "Enter id, priority, arrival time and burst time of each process:\n";
    for (int i = 0; i < n; ++i) {
        cin>>processes[i].id>>processes[i].priority>>processes[i].arrivalTime>>processes[i].burstTime;
    }

    sort(processes.begin(), processes.end(), compareArrivalTime);
     
    int currentTime = 0;
    for (int i = 0; i < n; ++i) {
        currentTime = max(currentTime, processes[i].arrivalTime);
        int HPJobIndex = -1;
        int Highestpriority = INT_MAX;
        for (int j = i; j < n; ++j) {
            if (processes[j].arrivalTime <= currentTime && processes[j].priority < Highestpriority) {
                HPJobIndex = j;
                Highestpriority = processes[j].priority;
            }
        }
        if (HPJobIndex == -1) {
            break;
        }
        swap(processes[i], processes[HPJobIndex]);
        processes[i].completionTime = currentTime + processes[i].burstTime;
        processes[i].turnaroundTime = processes[i].completionTime - processes[i].arrivalTime;
        processes[i].waitingTime = processes[i].turnaroundTime - processes[i].burstTime;
        currentTime = processes[i].completionTime;
    }

    sort(processes.begin(), processes.end(), compareArrivalTime);
    
    cout << "\nProcess\tArrival Time\tBurst Time\t priority\tCompletion Time\tTurnaround Time\tWaiting Time\n";
    for (int i = 0; i < n; ++i) {
        cout << processes[i].id << "\t\t" << processes[i].arrivalTime << "\t\t" << processes[i].burstTime << "\t\t" <<processes[i].priority<<"\t\t"
             << processes[i].completionTime << "\t\t" << processes[i].turnaroundTime << "\t\t" << processes[i].waitingTime << endl;
    }

    return 0;
}
