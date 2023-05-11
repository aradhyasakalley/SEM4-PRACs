#include<stdio.h>
#include<stdlib.h>

int mutex = 1;
int empty = 10;
int full = 0;
int x = 0;

void producer(){
    --mutex;
    ++full;
    --empty;
    ++x;
    printf("Producer produces item %d\n",x);
    ++mutex;
}

void consumer(){
    --mutex;
    ++empty;
    --full;
    
    printf("Consumer consumer item %d\n",x);
    --x;
    ++mutex;
}

int main(){
    int i,choice;
    printf("\nPress 1 for Producer"
		"\nPress 2 for Consumer"
		"\nPress 3 for Exit\n");
    while(1){
      printf("enter a choice:");
      scanf("%d",&choice);
        switch(choice){
        case 1 : 
          if ((mutex == 1) && (empty!=0)){
            producer();
          }
          else{
            printf("Buffer is full\n");
          }
          break;
        case 2 : 
          if ((mutex == 1) && (full!=0)){
            consumer();
          }
          else{
            printf("Buffer is empty\n");
          }
          break;
        case 3 :
          exit(0);
          break;
          
    }
    }
    
    return 0;
}