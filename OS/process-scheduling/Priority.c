#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    int n, i, j,temp=0;
    float avgWaitTime = 0, avgTurnaroundTime = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int burstTime[n], arrivalTime[n], waitTime[n], turnaroundTime[n],processSequence[n],completionTime[n],priority[n];
    printf("Enter the burst time, arrival time and priority of each process:\n");
    for(i = 0; i < n; i++) {
        printf("Process %d:\n", i+1);
        printf("Burst time: ");
        scanf("%d", &burstTime[i]);
        printf("Arrival time: ");
        scanf("%d", &arrivalTime[i]);
        printf("Priority: ");
        scanf("%d", &priority[i]);
        processSequence[i] = i+1;
    }

    //Priority ALGORITHM
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(priority[i] > priority[j]){
                temp = burstTime[i];
                burstTime[i] = burstTime[j];
                burstTime[j]=temp;

                temp = priority[i];
                priority[i] = arrivalTime[j];
                priority[j]=temp;

                temp = arrivalTime[i];
                arrivalTime[i] = arrivalTime[j];
                arrivalTime[j]=temp;

                temp = processSequence[i];
                processSequence[i] = processSequence[j];
                processSequence[j]=temp;
            }

        }
    }


    for(i=0;i<n;i++){
        if(i==0){
            completionTime[i] = burstTime[i];
            waitTime[i]=0;
        }
        else{
            completionTime[i] = completionTime[i-1] + burstTime[i];
            waitTime[i] = completionTime[i-1] - arrivalTime[i];
            
        }
        turnaroundTime[i] = completionTime[i] - arrivalTime[i];
        avgWaitTime+=waitTime[i];
        avgTurnaroundTime+=turnaroundTime[i];
    }
    printf("\nProcess\tBT\t\tAT\tCT\t\tWT\t\tTT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processSequence[i], burstTime[i], arrivalTime[i], completionTime[i], waitTime[i], turnaroundTime[i]);
    }
    avgWaitTime /= n;
    avgTurnaroundTime /= n;
    printf("\nAverage waiting time: %.2f\n", avgWaitTime);
    printf("Average turnaround time: %.2f\n", avgTurnaroundTime);


    return 0;
}