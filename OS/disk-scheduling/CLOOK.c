#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    int n,head,i,j,direction,seek_time=0;
    printf("Enter the number of requests:");
    scanf("%d",&n);
    int requests[n];
    printf("Enter the current head position:");
    scanf("%d",&head);
    
    printf("Enter the requests:");
    for(i=0;i<n;i++){
        scanf("%d",&requests[i]);
    }
    
    printf("Enter the direction of movement (1 for high and 0 for low):");
    scanf("%d",&direction);

    //C-LOOK Algorithm 
    //sort requests in ascending order
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(requests[j] > requests[j+1]){
                int temp;
                temp = requests[j];
                requests[j] = requests[j+1];
                requests[j+1] = temp;
            }
        }
    }

    //set position of head
    int index = 0;
    for(i=0;i<n;i++){
        if (head < requests[i]){
            index = i;
            break;
        }
    }

    //if movement towards high 
    if(direction == 1){
        // for index to last request 
        for(i=index;i<n;i++){
            seek_time+=abs(requests[i] - head);
            head = requests[i];
        }
        // for first request to index-1
        for(i=index-1;i>=0;i--){
            seek_time+=abs(requests[i] - head);
            head = requests[i];
        }
    }
    
    //if movement towards low 
    else{
        // for index-1 to first request 
        for(i=index-1;i>=0;i--){
            seek_time+=abs(requests[i] - head);
            head = requests[i];
        }
        // for last to index 
        for(i=n-1;i>=index;i--){
            seek_time+=abs(requests[i] - head);
            head = requests[i];
        }
    }
    printf("total seek time is : %d",seek_time);
    return 0;
}

