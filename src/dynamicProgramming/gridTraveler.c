#include <stdio.h>
#include <gridTraveler.h>
#include <stdlib.h>
int gridTraveler(int m,int n) {
    if(m==0 || n==0) return 0;
    if(m==1 || n==1) return 1;
    return gridTraveler(m-1,n) + gridTraveler(m,n-1);
}

int memoHelper(int m,int n,int**arr) {
    if(arr[m][n]!=-1) return arr[m][n];
    if(m==0 || n==0) return 0;
    if(m==1 || n==1) return 1;
    arr[m][n] = memoHelper(m-1,n,arr) + memoHelper(m,n-1,arr);
    return arr[m][n];
}

int gridTravelerMemo(int m,int n) {
    int **arr = malloc(sizeof(int*)*(m+1));

    for(int i=0;i<m+1;i++) {
        *(arr+i) =malloc(sizeof(int)*(n+1));
        for(int j=0;j<n+1;j++) arr[i][j]= -1;
    }

    return memoHelper(m,n,arr);
}

int DPhelper(int m,int n,int**arr) {
    for(int i=1;i<=m;i++) {
        for(int j=1;j<=m;j++) {
            if(i==1||j==1) arr[i][j]=1;
            else arr[i][j] = arr[i-1][j] + arr[i][j-1];
        }
    }
    return arr[m][n];
}

int gridTravelerDP(int m,int n) {
    int **arr = malloc(sizeof(int*)*(m+1));

    for(int i=0;i<m+1;i++) {
        *(arr+i) =malloc(sizeof(int)*(n+1));
        for(int j=0;j<n+1;j++) arr[i][j]= -1;
    }
    return DPhelper(m,n,arr);
}