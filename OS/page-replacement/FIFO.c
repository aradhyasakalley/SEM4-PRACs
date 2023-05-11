#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    int n,i,j,frames,pageFaults=0,s;
    printf("enter the number of requests:");
    scanf("%d",&n);
    int incomingStream[n];
    printf("enter the incoming stream of requests: ");
    for(i=0;i<n;i++){
        scanf("%d",&incomingStream[i]);
    }
    printf("enter the number of frames:");
    scanf("%d",&frames);

    int temp[frames];
    for(i=0;i<frames;i++){
        temp[i] = -1;
    }

    //FIFO ALGO

    for(i=0;i<n;i++){
        s = 0;

        for(j=0;j<frames;j++){
            if(incomingStream[i] == temp[j]){
                s++;
                pageFaults--;
            }
        }
        
        pageFaults++;
        if(pageFaults <= frames && (s == 0)){
            temp[i] = incomingStream[i]; 
        }

        else if(s == 0){
            temp[(pageFaults-1) % frames] = incomingStream[i];
        }
        printf("\n");
        printf("%d\t\t\t",incomingStream[i]);
        for(j = 0; j < frames; j++)
        {
            if(temp[j] != -1)
                printf(" %d\t\t\t", temp[j]);
            else
                printf(" - \t\t\t");
        }
        printf("\n");
        
    }

    printf("number of page faults is : %d",pageFaults);
    return 0;
}