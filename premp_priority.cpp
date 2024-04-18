//! premptive priority!!

#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;

struct process
{
    int id;
    int arrivalTime;
    int burstTime;
    int completionTime;
    int turnaroundTime;
    int waitingTime;
    int priority;
};

bool compareArrival(const process& a, const process& b) {
    return a.arrivalTime < b.arrivalTime;
}

bool compareID(const process& a, const process& b) {
    return a.id < b.id;
}

bool comparePriority(const process& a, const process& b) {
    return a.priority < b.priority;
}

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;
    vector<process> arr(n);

    map<int,int> temp_burst_time;
    cout << "Enter id,  arrivalTime, burstTime and priority of each process:- "<<endl;

    for (int i = 0; i < n; i++) {
       
        cin >> arr[i].id >> arr[i].arrivalTime >> arr[i].burstTime >> arr[i].priority;
        arr[i].completionTime = 0;
        arr[i].turnaroundTime = 0;
        arr[i].waitingTime = 0;
        temp_burst_time[arr[i].id] = arr[i].burstTime;
    }

    sort(arr.begin(), arr.end(), compareArrival);

    int time = arr[0].arrivalTime;
    int count = 0;
    int j;
    while (count < n) {
        time += 1;
        if (arr[count].arrivalTime < time) {
            arr[count].burstTime--;
        }
        if (arr[count].burstTime == 0) {
            arr[count].completionTime = time;
            count++;
        }
        j = count;
        for (int i = count + 1; i < n; i++) {
            if (time >= arr[i].arrivalTime) {
                j++;
            }
        }
        if (j != count) {
            sort(arr.begin() + count, arr.begin() + j + 1, comparePriority);
        }
    }

    for (int i = 0; i < n; i++) {
        arr[i].turnaroundTime = arr[i].completionTime - arr[i].arrivalTime;
        arr[i].waitingTime = arr[i].turnaroundTime - temp_burst_time[arr[i].id];
    }

    sort(arr.begin(), arr.end(), compareID);

    cout << "Process\tArrival Time\tBurst Time\tPriority\tCompletion Time\tTurnaround Time\tWaiting Time" << endl;
    for (int i = 0; i < n; i++) {
        cout << "P" << arr[i].id << "\t\t" << arr[i].arrivalTime << "\t\t" << temp_burst_time[arr[i].id] << "\t\t" << arr[i].priority << "\t\t" << arr[i].completionTime << "\t\t" << arr[i].turnaroundTime << "\t\t" << arr[i].waitingTime << endl;
    }
    return 0;
}
