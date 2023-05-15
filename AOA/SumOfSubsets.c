#include<stdio.h>
#include<stdlib.h>
int sumOfSubset(int arr[],int n, int target,int index,int sum,int subSet[]){
    if(sum == target){
        for(int i =0;i<index;i++){
            printf("%d\t",subSet[i]);
        }
        printf("\n");
        return 1;
    }
    if(index == n)
      return 0;

    subSet[index] = arr[index];
    sumOfSubset(arr,n,target,index+1,sum+arr[index],subSet);
    subSet[index] = 0; 
    sumOfSubset(arr,n,target,index+1,sum,subSet);
}
int main(){
    int n,target;
    printf("Enter the number of elements in the set : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements in the set : ");
    for(int i =0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the target sum : ");
    scanf("%d",&target);
    int subSet[n];

    sumOfSubset(arr,n,target,0,0,subSet);
    int found = sumOfSubset(arr, n, target, 0, 0, subSet);
    if (!found) {
        printf("No subset found that adds up to the target sum.\n");
    }

}