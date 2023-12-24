#include <stdbool.h>
#include <canSum.h>
#include <stdlib.h>
#include <stdio.h>

// without repeating
bool canSum(int ts,int *arr,int as) {
    if(as==1) return ts==arr[0];
    return canSum(ts-arr[as-1],arr,as-1) || canSum(ts,arr,as-1);
}

bool canSum2(int ts,int *arr,int as) {
    if(ts==0) return true;
    if(ts<0) return false;

    for(int i=0;i<as;i++) {
        if(canSum2(ts-arr[i],arr,as)) return true;
    }
    return false;
}

bool memoHelpercs(int ts,int*arr,int as,int*csa) {
    if(csa[ts]!=-1) return csa[ts];
    if(ts==0) return true;
    if(ts<0) return false;

    for(int i=0;i<as;i++) {
        csa[ts] = memoHelpercs(ts-arr[i],arr,as,csa);
        if(csa[ts]) return true;
    }
    csa[ts]=false;
    return false;
}
bool canSumMemo(int ts,int *arr,int as) {
    int *csa = malloc(sizeof(int)*ts+1);
    for(int i=0;i<=ts;i++) csa[i]=-1;

    return memoHelpercs(ts,arr,as,csa);
}