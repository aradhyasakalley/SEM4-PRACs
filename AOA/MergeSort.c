#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void merge(int arr[], int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // create temp arrays
    int L[n1], R[n2];
    for(i=0;i<n1;i++){
        L[i] = arr[l+i];
    }
    for(j=0;j<n2;j++){
        R[j] = arr[m+1+j];
    }

    i=0;
    j=0;
    k=l;

    while(i<n1 && j<n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i<n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r){
    if(l >= r){
        return;
    }
    int m = l + (r-l)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);
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
    mergeSort(arr,0,n-1);
    end = clock();
    time_taken = ((double)(end - start))/CLOCKS_PER_SEC;
    printf("The best case time is %f seconds\n",time_taken);


    //for worst case 
    for(i=0;i<n;i++){
        arr[i] = n-i;
    }
    start = clock();
    mergeSort(arr,0,n-1);
    end = clock();
    time_taken = ((double)(end - start))/CLOCKS_PER_SEC;
    printf("The worst case time is %f seconds\n",time_taken);


    //for average case 
    for(i=0;i<n;i++){
        arr[i] = rand()%10000;
    }
    start = clock();
    mergeSort(arr,0,n-1);
    end = clock();
    time_taken = ((double)(end - start))/CLOCKS_PER_SEC;
    printf("The average case time is %f seconds",time_taken);
}
