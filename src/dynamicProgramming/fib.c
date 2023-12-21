#include <stdio.h>
#include <fib.h>

int fib(int n) {
    if(n<=2) return 1;
    return fib(n-1)+fib(n-2);
}

int fibMemo(int n,int *arr) {
    if(arr[n]!=-1) return arr[n];
    if(n<=2) return 1;
    arr[n] = fibMemo(n-1,arr) + fibMemo(n-2,arr);
    return arr[n];
}
int fibUltHelper(int a,int b,int c) {
    if(c==2) return b;
    return fibUltHelper(b,a+b,c-1);
}
int fibUlt(int n) {
    if(n<=2) return 1;
    return fibUltHelper(1,1,n);
}



int fibDP(int n) {
    int arr[n+1];
    arr[1]=1;
    arr[2]=1;

    for(int i=3;i<=n;i++) arr[i]=arr[i-1]+arr[i-2];
    return arr[n];
}

int fibDPOpt(int n) {
    int a = 1,b=1,c;
    for(int i=3;i<=n;i++) {
        c= a+b;
        a=b;
        b=c;
    }
    return b;
}

