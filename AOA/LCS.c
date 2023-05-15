#include<stdio.h>
#include<string.h>
#define MAX 100
int max(int a,int b){
    return ((a>b) ? a : b);
}
int LCS(char *x,char *y,int m,int n){
    if(m == 0 || n == 0)
       return 0;
    else if (x[m-1] == y[n-1])
       return 1 + LCS(x,y,m-1,n-1);
    else 
       return max(LCS(x,y,m-1,n),LCS(x,y,m,n-1));
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