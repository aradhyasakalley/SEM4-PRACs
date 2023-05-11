#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    int n,head,i,k,seek_time=0,min,min_index,visited[n];
    printf("Enter the number of requests: ");
    scanf("%d",&n);
    printf("Enter the current head position: ");
    scanf("%d",&head);
    int requests[n];
    printf("Enter the requests: ");
    for(i=0;i<n;i++){
        scanf("%d",&requests[i]);
        visited[i] =0;
    }


    for (k=0;k<n;k++){
        min=99999;
        for(i=0;i<n;i++){
         if(!visited[i] && abs(head-requests[i]) < min){
           min = abs(head-requests[i]);
           min_index = i;
         }
      }

      seek_time+=min;
      head=requests[min_index];
      visited[min_index] =1;
    }
    
    printf("Total seek time is: %d",&seek_time);
    return 0;
    




}
