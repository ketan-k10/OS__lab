//! correct one !!
#include <iostream>
#include<bits/stdc++.h>

using namespace std;

struct Process {
    int id;
    int arrivalTime;
    int burstTime;
    int completionTime;
    int turnaroundTime;
    int waitingTime;
};

bool compareArrivalTime(const Process& p1, const Process& p2) {
    return p1.arrivalTime < p2.arrivalTime;
}
bool compareId(const Process& p1, const Process& p2) {
    return p1.id < p2.id;
}

bool compareBurstTime(const Process& p1, const Process& p2) {
    return p1.burstTime < p2.burstTime;
}

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<Process> processes(n);

    cout << "Enter arrival time and burst time of each process:\n";
    for (int i = 0; i < n; ++i) {
        processes[i].id = i + 1;
        cout << "Process " << processes[i].id << ":\n";
        cout << "Arrival time: ";
        cin >> processes[i].arrivalTime;
        cout << "Burst time: ";
        cin >> processes[i].burstTime;
    }

    sort(processes.begin(), processes.end(), compareArrivalTime);
     
    int currentTime = 0;
    for (int i = 0; i < n; ++i) {
        currentTime = max(currentTime, processes[i].arrivalTime);
        int shortestJobIndex = -1;
        int shortestBurstTime = INT_MAX;
        for (int j = i; j < n; ++j) {
            if (processes[j].arrivalTime <= currentTime && processes[j].burstTime < shortestBurstTime) {
                shortestJobIndex = j;
                shortestBurstTime = processes[j].burstTime;
            }
        }
        if (shortestJobIndex == -1) {
            break;
        }
        swap(processes[i], processes[shortestJobIndex]);
        processes[i].completionTime = currentTime + processes[i].burstTime;
        processes[i].turnaroundTime = processes[i].completionTime - processes[i].arrivalTime;
        processes[i].waitingTime = processes[i].turnaroundTime - processes[i].burstTime;
        currentTime = processes[i].completionTime;
    }

      sort(processes.begin(), processes.end(), compareId);
    cout << "\nProcess\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n";
    for (int i = 0; i < n; ++i) {
        cout << processes[i].id << "\t\t" << processes[i].arrivalTime << "\t\t" << processes[i].burstTime << "\t\t"
             << processes[i].completionTime << "\t\t" << processes[i].turnaroundTime << "\t\t" << processes[i].waitingTime << endl;
    }

    return 0;
}