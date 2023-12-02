#include <mergeStrings.h>
#include <stdlib.h>
#include <string.h>

char * mergeAlternately(char * word1,char * word2) {
    int m = strlen(word1);
    int n = strlen(word2);

    char * str = malloc(sizeof(char)*(m+n));

    int i=0,j=0,k=0;
    while(i<m && j<n) {
        str[k++] = word1[i++]; 
        str[k++] = word2[j++]; 
    }

    while(i<m) str[k++] = word1[i++];
    while(j<n) str[k++] = word2[j++];
    return str;
}