#define MAX 101
#include <stdio.h>

struct Graph {
    int adjMatrix[MAX][MAX];
    int discovered[MAX];
    int parents[MAX];    
    int directed;
    int nvertices;
};

void initGraph(struct Graph*);
void initSearch(struct Graph*);
void insertEdge(struct Graph*,int,int);
void printGraph(struct Graph*);
void bfs(struct Graph*,int);
void dfs(struct Graph*,int);