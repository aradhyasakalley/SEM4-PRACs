#include<stdio.h>

int main(){
    int i,n;
    printf("enter number of processes : ");
    scanf("%d",&n);
    int AT[n],BT[n],WT[n],TT[n],total=0,burst=0;
    float avgWT,avgTT,compl_time=0;

    printf("enter the arrival times and burst times for all processes : \n");
    for(i=0;i<n;i++){
        scanf("%d %d",&AT[i],&BT[i]);
    }

    //calculation of waiting time
    for(i=0;i<n;i++){
        if(i==0){
            WT[i] = AT[i];
        }else{
            WT[i] = burst-AT[i];
        }
        burst+=BT[i];
        total+=WT[i];
    }
    avgWT=(float)total/n;

    //calculation of turnaround time
    total=0;
    compl_time=0;
    for(i=0;i<n;i++){
       compl_time+=BT[i];
       TT[i] = compl_time - AT[i];
       total+=TT[i]; 
    }
    avgTT=(float)total/n;
    
    printf("average waiting time is %.2f and average turnaround time is %.2f",avgWT,avgTT);
    return 0;
}
