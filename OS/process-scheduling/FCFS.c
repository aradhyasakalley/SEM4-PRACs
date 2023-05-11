// turn aroundtime = completion - arrival
// waiting time = turnaround - burst

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    int n, i, j;
    float avgWaitTime = 0, avgTurnaroundTime = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int burstTime[n], arrivalTime[n], waitTime[n], turnaroundTime[n];
    printf("Enter the burst time and arrival time of each process:\n");
    for(i = 0; i < n; i++) {
        printf("Process %d:\n", i+1);
        printf("Burst time: ");
        scanf("%d", &burstTime[i]);
        printf("Arrival time: ");
        scanf("%d", &arrivalTime[i]);
    }

    //FCFS Algorithm 

    for(i=0;i<n;i++){
        if (i==0)
            waitTime[i]=0;
        else{
            waitTime[i]=0;
            for(j=0;j<i;j++){
                waitTime[i]+=burstTime[j];
            }
            waitTime[i]-=arrivalTime[i];
        }
        turnaroundTime[i] = burstTime[i] + waitTime[i];
        avgWaitTime+=waitTime[i];
        avgTurnaroundTime+=turnaroundTime[i];
        
    }
    printf("\nProcess\tBT\t\tAT\tWT\t\tTT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i+1, burstTime[i], arrivalTime[i], waitTime[i], turnaroundTime[i]);
    }
    avgWaitTime /= n;
    avgTurnaroundTime /= n;
    printf("\nAverage waiting time: %.2f\n", avgWaitTime);
    printf("Average turnaround time: %.2f\n", avgTurnaroundTime);

    return 0;
}