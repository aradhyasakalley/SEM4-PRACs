#include<stdio.h>
#include<string.h>
#define MAX 100

int max(int a,int b){
    return ((a>b) ? a : b);
}


int LCS(char *x,char *y,int m,int n){
    int L[m+1][n+1];
    for(int i = 0;i<=m;i++){
        for(int j =0;j<=n;j++){
            if (i == 0 || i == 0){
                L[i][j] = 0;
            }
            else if(x[i-1] == y[j-1]){
                L[i][j] = 1 + L[i-1][j-1];
            }
            else{
                L[i][j] = max(L[i-1][j],L[i][j-1]);
            }
        }
    }

    int index = L[m][n];
    char lcs[index+1];
    lcs[index] = '\0';
    int i =m,j=n;
    while(i>0 && j>0){
        if(x[i-1] == y[j-1]){
            lcs[index-1] = x[i-1];
            i--;
            j--;
            index--;
        }
        else if(L[i-1][j] > L[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }
    printf("The LCS is : %s\n",lcs);
    return L[m][n];
}
int main(){
    char x[MAX],y[MAX];
    printf("enter the first string : ");
    scanf("%s",&x);
    printf("enter the second string : ");
    scanf("%s",&y);
    int m = strlen(x);
    int n = strlen(y);

    int length = LCS(x,y,m,n);
    printf("the lenght of LCS is : %d",length);
    
    return 0;
}