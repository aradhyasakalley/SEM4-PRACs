#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = (low - 1);
    
    for(int j=low; j<=high-1; j++){
        if(arr[j] < pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return (i+1);
}

void quickSort(int arr[], int low, int high){
    if(low < high){
        int pi = partition(arr, low, high);
        
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

int main(){
    int n,i,arr[10000];
    clock_t start,end;
    double time_taken;
    
    printf("Enter the number of elements in the array : ");
    scanf("%d",&n);
    
    //for best case 
    for(i=0;i<n;i++){
        arr[i] = i+1;
    }
    start = clock();
    quickSort(arr,0,n-1);
    end = clock();
    time_taken = ((double)(end - start))/CLOCKS_PER_SEC;
    printf("The best case time is %f seconds\n",time_taken);


    //for worst case 
    for(i=0;i<n;i++){
        arr[i] = n-i;
    }
    start = clock();
    quickSort(arr,0,n-1);
    end = clock();
    time_taken = ((double)(end - start))/CLOCKS_PER_SEC;
    printf("The worst case time is %f seconds\n",time_taken);


    //for average case 
    for(i=0;i<n;i++){
        arr[i] = rand()%10000;
    }
    start = clock();
    quickSort(arr,0,n-1);
    end = clock();
    time_taken = ((double)(end - start))/CLOCKS_PER_SEC;
    printf("The average case time is %f seconds",time_taken);
}
