#include <arrayStringsAreEqual.h>

bool arrayStringsAreEqual(char** word1, int word1Size, char** word2, int word2Size) {
    int i=0,j=0;

    char a,b;
    while(i<word1Size && j<word2Size) {  
        while((a=*word1[i])!='\0' && (b=*word2[j])!='\0') {
            if(a!=b) return false;
            word1[i]++;
            word2[j]++;
        }
        if(a=='\0')i++;
        if(b=='\0')j++;
    }
    
    return a=='\0' && b=='\0';
}