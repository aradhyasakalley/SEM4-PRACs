#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void insertionSort(int arr[],int n){
    int i,j,key;
    for(i=1;i<n;i++){
        key = arr[i];
        j = i-1;
        while(j >=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j + 1] = key; 
    }
}


int main(){
    int n,i,arr1[10],arr2[10],arr3[10],arr[10];
    clock_t start,end;
    double time_taken;
    
    printf("Enter the number of elements in the array : ");
    scanf("%d",&n);
    
    //for best case 
    for(i=0;i<n;i++){
        arr1[i] = i+1;
    }
    start = clock();
    insertionSort(arr1,n);
    end = clock();
    printf("The used array is : ");
    for(i=0;i<n;i++){
        printf("%d",arr1[i]);
    }
    printf("\n");
    time_taken = ((double)(end - start))/CLOCKS_PER_SEC;
    printf("The best case time is %f seconds\n",time_taken);

    //for worst case 
    for(i=0;i<n;i++){
        arr2[i] = n-i;
    }
    start = clock();
    insertionSort(arr,n);
    end = clock();
    printf("The used array is : ");
    for(i=0;i<n;i++){
        printf("%d",arr2[i]);
    }
    printf("\n");
    time_taken = ((double)(end - start))/CLOCKS_PER_SEC;
    printf("The worst case time is %f seconds\n",time_taken);


    //for average case 
    for(i=0;i<n;i++){
        arr3[i] = rand()%10;
    }
    start = clock();
    insertionSort(arr3,n);
    end = clock();
    printf("The used array is : ");
    for(i=0;i<n;i++){
        printf("%d",arr3[i]);
    }
    printf("\n");
    time_taken = ((double)(end - start))/CLOCKS_PER_SEC;
    printf("The average case time is %f seconds",time_taken);



    return 0;
}