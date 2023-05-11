#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
  int i,n,head,seek_time = 0;
  printf("enter number of requests : ");
  scanf("%d",&n);
  int request[n];
  printf("enter the requests : ");
  for(i=0;i<n;i++){
    scanf("%d",&request[i]);
  }
  printf("enter the initial head : ");
  scanf("%d",&head);

  int count = 0;

  while(count!=n){

    int min = 1000,index,d;
    for(i=0;i<n;i++){
      d = abs(request[i] - head);
      if (min > d){
        min = d;
        index = i;
      }
    }
    seek_time+=min;
    head = request[index];
    request[index] = 1000;
    count ++;

  }

  return 0;
}
