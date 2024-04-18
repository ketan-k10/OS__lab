//! correct one Round robin!!
#include <bits/stdc++.h>
using namespace std;
struct process
{
    int id;
    int arivaltime;
    int bursttime;
    int compeltiontime;
    int turnaroundtime;
    int waitingtime;
};

bool compare(process a, process b)
{
    return a.arivaltime < b.arivaltime;
}

int main()
{
    int n;
    cout << "enter the no of process :";
    cin >> n;
    process arr[n];
    map<int, int> temp_burst_time;
    cout<<"Enter id, aarival time and burst time of each process:- "<<endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].id >> arr[i].arivaltime >> arr[i].bursttime;
        temp_burst_time[arr[i].id] = arr[i].bursttime;
    }
    int tq;
    cout << "enter time quantom: ";
    cin >> tq;
    sort(arr, arr + n, compare);
    int time = arr[0].arivaltime;
    int count = 0;
    int j = 1;
    queue<int> q;
    q.push(0);
    while (count < n)
    {
        if (!q.empty())
        {
            bool flag=false;
            int i = q.front();
            q.pop();
            if (arr[i].bursttime <= tq)
            {
                time += arr[i].bursttime;
                arr[i].compeltiontime = time;
                arr[i].bursttime = 0;
                count++;
                flag =true;
            }
            else
            {
                arr[i].bursttime -= tq;
                time += tq;
            }
            for (int k = j; k < n; k++)
            {
                if (arr[k].arivaltime <= time && arr[k].arivaltime >= time - tq)
                {
                    q.push(k);
                    j++;
                }
                else break;
            }
            if(!flag){
               q.push(i);
            }
        }
        else
        {
            time += tq;
            for (int k = j; k < n; k++)
            {
                if (arr[k].arivaltime <= time && arr[k].arivaltime >= time - tq)
                {
                    q.push(j);
                    j++;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        arr[i].turnaroundtime = arr[i].compeltiontime - arr[i].arivaltime;
        arr[i].waitingtime = arr[i].turnaroundtime - temp_burst_time[arr[i].id];
    }
    sort(arr, arr + n, compare);
    cout << "process\t arival tiime\t  burst time\t compeltion time\t turn aroundtime\t waiting time" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << " p" << arr[i].id << "\t\t" << arr[i].arivaltime << "\t\t" << temp_burst_time[arr[i].id] << "\t\t" << arr[i].compeltiontime << "\t\t\t" << arr[i].turnaroundtime << "\t\t\t" << arr[i].waitingtime << endl;
    }
}