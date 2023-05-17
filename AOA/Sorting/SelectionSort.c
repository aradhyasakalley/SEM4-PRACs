#include<stdio.h>
#include<stdlib.h>
#include<time.h>


// void selectionSort(int arr[],int n){
//     int i,j,min_index;
//     for(i=0;i<n-1;i++){
//         min_index = i;
//         for(j=i+1;j<n;j++)
//             if(arr[j] < arr[min_index])
//                min_index = j;
        
//         int temp;
//         temp = arr[min_index];
//         arr[min_index] = arr[i];
//         arr[i] = temp;
        
//     }
// }


void selectionSort(int arr[],int n){
    int i,j,min_index;
    for(i=0;i<n-1;i++){
        min_index = i;
        for(j=i+1;j<n;j++){
            if(arr[i] < arr[min_index]){
                min_index = i;
            }
        }
        int temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;
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
    selectionSort(arr,n);
    end = clock();
    time_taken = ((double)(end - start))/CLOCKS_PER_SEC;
    printf("The best case time is %f seconds\n",time_taken);


    //for worst case 
    for(i=0;i<n;i++){
        arr[i] = n-i;
    }
    start = clock();
    selectionSort(arr,n);
    end = clock();
    time_taken = ((double)(end - start))/CLOCKS_PER_SEC;
    printf("The worst case time is %f seconds\n",time_taken);


    //for average case 
    for(i=0;i<n;i++){
        arr[i] = rand()%10000;
    }
    start = clock();
    selectionSort(arr,n);
    end = clock();
    time_taken = ((double)(end - start))/CLOCKS_PER_SEC;
    printf("The average case time is %f seconds",time_taken);



    return 0;
}