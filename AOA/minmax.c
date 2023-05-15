#include<stdio.h>
#include<limits.h>
int minimum(int a,int b ){
    return ((a>b) ? b : a);
}
int maximum(int a,int b ){
    return ((a>b) ? a : b);
}
int findMinMax(int arr[],int low,int high,int *min,int *max){
    if(low == high){
        *min = *max = arr[low];
    }
    else if(high == low + 1){
        if(arr[low] > arr[high]){
            *max = arr[low];
            *min = arr[high];
        }
        else{
            *max = arr[high];
            *min = arr[low];
        }
    }
    else{
        int mid = (low + high)/2;
        int min1,min2,max1,max2;
        findMinMax(arr,low,mid,&min1,&max1);
        findMinMax(arr,mid+1,high,&min2,&max2);
        *min = minimum(min1,min2);
        *max = maximum(max1,max2);
    }
}
int main(){
    int n,min,max;
    printf("Enter the number of elements in the array : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array : ");
    for(int i =0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    findMinMax(arr,0,n-1,&min,&max);
    printf("The minimum element is %d and the maximum element is %d",min,max);
    
}