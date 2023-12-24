#include <howSum.h>
#include <stdlib.h>
#include <stdbool.h>

struct Ans {
    int *arr;
    int i;
};

bool howSumHelper(int ts,int*arr,int as,struct Ans* node) {
    if(ts==0) return true;
    if(ts<0) return false;

    for(int i=0;i<as;i++) {
        if(howSumHelper(ts-arr[i],arr,as,node)){ 
            node->arr[node->i] = arr[i];
            node->i+=1;
            return true;
        }
    }
    return false;
}

int* howSum(int ts,int*arr,int as,int *rs) {
    struct Ans* node = malloc(sizeof(struct Ans));
    node->arr = malloc(sizeof(int)*1000);
    node->i=0;
    if(howSumHelper(ts,arr,as,node)){
        *rs=node->i;
        return node->arr;
    }
    free(node);
    return NULL;
}