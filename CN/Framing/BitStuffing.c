#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int n;
    printf("Enter the frame length : ");
    scanf("%d",&n);
    int frame[20],stuffedFrame[40],i=0,j=0,k,count=1;
    printf("Enter the input frame : ");
    for(i=0;i<n;i++){
        scanf("%d",&frame[i]);
    }
    i = 0;
    while(i<n){
        if(frame[i] == 1){
            stuffedFrame[j] = frame[i];
            for(k = i+1;frame[k] == 1 && count < 5 && k < n;k++){
                j++;
                stuffedFrame[j] = frame[k];
                count ++;
                if(count == 5){
                    j++;
                    stuffedFrame[j] = 0;
                }
                i = k;

            }
        }
        else{
            stuffedFrame[j] = frame[i];
        }
        i++;
        j++;
    }

    printf("The stuffed array is : ");
    for(i=0;i<j;i++){ // loop should run from i=0 to i<j
        printf("%d\t",stuffedFrame[i]);
    }

    return 0;
}
