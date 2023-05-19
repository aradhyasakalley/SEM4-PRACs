#include<stdio.h>
#include<string.h>

int main(){
    int octet1,octet2,octet3,octet4;
    printf("enter the ip address (x.x.x.x): ");
    scanf("%d.%d.%d.%d",&octet1,&octet2,&octet3,&octet4);
    if(octet1 >= 1 && octet1 <=126){
        printf("Class of ip address : A\n");
        printf("%d\n",octet2);
        printf("subnet address :  %d.%d.%d.0\n",octet1,octet2,octet3);
    }
    else if(octet1 >= 1 && octet1 <=126){
        printf("Class of ip address : B\n");
        printf("subnet address :  %d.%d.0.0\n",octet1,octet2);
    }
    else if(octet1 >= 128 && octet1 <=191){
        printf("Class of ip address : C\n");
        printf("subnet address :  %d.%d.%d.0\n",octet1,octet2,octet3);
    }
    else if(octet1 >= 192 && octet1 <=223){
        printf("Class of ip address : D (multicast)\n");
    }
    else if(octet1 >= 224 && octet1 <=239){
        printf("Class of ip address : E (reserved for future use)\n");
    }
    else{
        printf("invalid ip address");
        
    }
    return 0;

}