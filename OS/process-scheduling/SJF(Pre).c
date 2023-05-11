#include<stdio.h>
#include<conio.h>
struct process {
    int id,AT,BT,WT,TAT
};
struct  process a[10];
void swap(int *b,int *c){
    int temp;
    temp = *c;
    *c = *b;
    *b =temp;
}
int main(){
    int i,j,n,check_arrival=0,compl_time=0;
    float total_WT =0,total_TAT=0,avg_WT,avg_TAT;
    printf("enter number of processes : ");
    scanf("%d",&n);
    

    printf("enter the arrival times and burst times for all processes : ");
    for(i=0;i<n;i++){
        scanf("%d%d",&a[i].AT,&a[i].BT);
        a[i].id = i+1;
        if(i==0)
          check_arrival=a[i].AT;
        if (check_arrival!=a[i].AT)
           check_arrival=1;
    }

    //if arrived at diff times sort acc to arrival time
    if(check_arrival!=0){
        for(i=0;i<n;i++){
            for(j=0;j<n-i-1;j++){
                if(a[j].AT > a[j+1].AT){
                    swap(&a[j].id,&a[j+1].id);
                    swap(&a[j].AT,&a[j+1].AT);
                    swap(&a[j].BT,&a[j+1].BT);
                }

            }
        }
    }
    //logic for sjf pre-emptive

    if(check_arrival!=0){
        a[0].WT = a[0].AT;
        a[0].TAT = a[0].BT - a[0].AT;
        compl_time=a[0].TAT;
        for(i=1;i<n;i++){
            int min = a[i].BT;
            for(j=1+i;j<n;j++){
                if (min > a[j].BT && a[j].AT <= compl_time ){
                    min = a[j].BT;
                    swap(&a[i].id,&a[j].id);
                    swap(&a[i].AT,&a[j].AT);
                    swap(&a[i].BT,&a[j].BT);
                }
            }
            a[i].WT = compl_time - a[i].AT;
            total_WT+=a[i].WT;
            compl_time+=a[i].BT;
            a[i].TAT = compl_time - a[i].AT;
            total_TAT+=a[i].TAT;
        }
    }
    else{
        for(i=0;i<n;i++){
            int min = a[i].BT;
            for(j=1+i;j<n;j++){
                if (min > a[j].BT && a[j].AT <= compl_time ){
                    min = a[j].BT;
                    swap(&a[i].id,&a[j].id);
                    swap(&a[i].AT,&a[j].AT);
                    swap(&a[i].BT,&a[j].BT);
                }
            }
            a[i].WT = compl_time - a[i].AT;
            total_WT+=a[i].WT;
            compl_time+=a[i].BT;
            a[i].TAT = compl_time - a[i].AT;
            total_TAT+=a[i].TAT;
        }
    }

    avg_WT=total_WT/n;
    avg_TAT=total_TAT/n;
    printf("average waiting time is %.2f and average turnaround time is %.2f",avg_WT,avg_TAT);

    return 0;
}