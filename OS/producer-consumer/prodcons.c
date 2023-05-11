#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int mutex=1,empty=MAX,full=0,data =0,buffer[MAX];

int wait(int s){
   return --s; 
}

int signal(int s){
  return ++s;
}

void producer(){

  mutex = wait(mutex);
  full = signal(full);
  empty = wait(empty);
  data++;
  printf("Producer produces data : %d\n",data);
  buffer[full - 1] = data;
  mutex = signal(mutex);

}

void consumer(){

  mutex = wait(mutex);
  empty = signal(empty);
  full = wait(full);
  printf("Consumer consumer data : %d\n",data);
  data --;
  mutex = signal(mutex);

}

int main(){
  int i,choice,flag=0;
  printf("\n1) Produce\n2) Consume\n3) Show Buffer\n4) Exit\n");
  while(1){
    int n;
    printf("enter your choice :");
    scanf("%d",&n);

    switch(n){
      case 1 : 
        if((mutex == 1) && (empty!=0)){
          producer();
        }
        else{
          printf("Buffer is full\n");
        }
        break;
      case 2 : 
        if((mutex == 1) && (full!=0)){
          consumer();
        }
        else{
            
          printf("Buffer is empty\n");
        }
        break;
      case 3 :
        printf("Current Buffer State : ");
        for(i=0;i<full;i++){
          printf("%d",buffer[i]);
        }
        printf("\n");
        break;
      case 4 :
        flag = 1;
        printf("Program ended....");
        break;

    }
    if(flag == 1){
      break;
    }
  }
}