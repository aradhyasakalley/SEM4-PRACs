#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void selectionSort(int arr[],int n){
    int i,j,min_index;
    for(i=0;i<n-1;i++){
        min_index = i;
        for(j=i+1;j<n;j++)
            if(arr[j] < arr[min_index])
               min_index = j;
        
        int temp;
        temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;
        
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
    selectionSort(arr1,n);
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
    selectionSort(arr,n);
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
    selectionSort(arr3,n);
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