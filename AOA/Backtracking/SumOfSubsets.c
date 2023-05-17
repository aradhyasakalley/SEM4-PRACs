#include<stdio.h>
#include<stdlib.h>
int sumOfSubsets(int arr[],int n,int target,int index,int sum,int subSet[]){
    if(sum == target){
        for(int i =0;i<index;i++){
            printf("%d\t",subSet[i]);
        }
        printf("\n");
        return 1;
    }

    if(index == n){
        return 0;
    }

    subSet[index] = arr[index];
    sumOfSubsets(arr,n,target,index+1,sum+arr[index],subSet);
    subSet[index] = 0;
    sumOfSubsets(arr,n,target,index+1,sum,subSet);
    
}
int main(){
    int n,target;
    printf("Enter the number of elements in the set : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array : ");
    for(int i =0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the target sum : ");
    scanf("%d",&target);
    int subSet[n];
    sumOfSubsets(arr,n,target,0,0,subSet);
    
    return 0;
}