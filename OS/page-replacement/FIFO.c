#include<stdio.h>
#include<conio.h>

int main(){
    int i,j,num,frames,s;;
    printf("enter the number of requests: ");
    scanf("%d",&num);
    printf("enter the number of frames:");
    scanf("%d",&frames);
    int request[num];
    printf("enter the requests: ");
    for(i=0;i<num;i++){
        scanf("%d",&request[i]);
    }
    int pageFaults = 0;

    int pages = num;
    int temp[frames];
    for (i=0;i<frames;i++){
        temp[i] = -1;
    }
    for(i=0;i<num;i++){
        s=0;
        for(j = 0;j<frames;j++){
            if(request[i] == temp[j]){
                s++;
                pageFaults--;
            }
        }
        pageFaults++;

        if(pageFaults <= frames && (s==0)){
            temp[i] == request[i];
        }
        else if(s==0){
            temp[(pageFaults - 1) % frames] = request[i];
        }
    }
    
    printf("the total page faults are: %d",pageFaults);
    return 0;
}