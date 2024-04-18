//!correct one

#include<iostream>
using namespace std;

void calculateTimes(int n,int processes[],int burst_time[],int arrival_time[], int completion_time[], int turnaround_time[], int waiting_time[] ){

   completion_time[0]=arrival_time[0]+burst_time[0];

   //!  calculating completion time of each process 

   for(int i=1;i<n;i++){  

    if(arrival_time[i]>completion_time[i-1]){

        completion_time[i]=arrival_time[i]+burst_time[i];
    }
    else{
        completion_time[i]=burst_time[i]+completion_time[i-1];
    }
   }

   for(int i=0;i<n;i++){

    turnaround_time[i]=completion_time[i]-arrival_time[i];

    waiting_time[i]=turnaround_time[i]-burst_time[i];
   }
   


}


int main(){
    int n;
    cout<<"Enter the number of processes:- ";
    cin>>n;
    int processes[n];
    int arrival_time[n];
    int burst_time[n];
    int completion_time[n];
    int turnaround_time[n];
    int waiting_time[n];

    for(int i=0;i<n;i++){
        cout<<"\nEnter the details of process "<<i+1<<":\n";
        cout<<"Arrival time : ";
        cin>>arrival_time[i];
        cout<<"Burst time : ";
        cin>>burst_time[i];
        processes[i]=i+1;
    }
    
    //! sorting here on the basis of arrival time to calculate all timings.

    for(int i=0; i<n-1;i++){
      for(int j=0; j<n-1; j++){
        if(arrival_time[j]>arrival_time[j+1]){
            swap(arrival_time[j],arrival_time[j+1]);
            swap(burst_time[j],burst_time[j+1]);
            swap(processes[j],processes[j+1]);
        }
         
      }
    }
  
    calculateTimes( n, processes, burst_time, arrival_time, completion_time, turnaround_time, waiting_time);
 
    //! sorting here on the basis of process number to display properly on screen.

    for(int i=0; i<n-1;i++){
      for(int j=0; j<n-1; j++){
        if(processes[j]>processes[j+1]){
            swap(arrival_time[j],arrival_time[j+1]);
            swap(burst_time[j],burst_time[j+1]);
            swap(processes[j],processes[j+1]);
            swap(turnaround_time[j],turnaround_time[j+1]);
            swap(completion_time[j],completion_time[j+1]);
            swap(waiting_time[j],waiting_time[j+1]);

        }
         
      }
    }
  
    
    cout << "\nProcess\t Arrival Time\t Burst Time\t Completion Time\t Turnaround Time\t Waiting Time\n";
    for (int i = 0; i < n; i++) {
        cout << processes[i] << "\t\t " << arrival_time[i] << "\t\t " << burst_time[i] << "\t\t " << completion_time[i] << "\t\t\t " << turnaround_time[i] << "\t\t\t " << waiting_time[i] << "\n";
    }

}