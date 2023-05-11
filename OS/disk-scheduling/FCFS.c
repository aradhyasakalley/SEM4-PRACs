#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
    int n,head,i,seek_time=0;
    printf("Enter the number of requests:");
    scanf("%d",&n);
    printf("Enter the current head position:");
    scanf("%d",&head);
    int requests[n];
    printf("Enter the requests:");
    for(i=0;i<n;i++){
        scanf("%d",&requests[i]);
    }
    //calculating seek time 
    for (i=0;i<n;i++){
        seek_time+=abs(head-requests[i]);
        head = requests[i];
    }
    
    printf("total seek time is: %d",seek_time);

}