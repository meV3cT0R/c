#include <graph.h>
#include <queue.h>
#include <limits.h>

void initGraph(struct Graph *g) {
    for(int i=0;i<MAX;i++) {
        for(int j=0;j<MAX;j++) {
            g->adjMatrix[i][j] = 0;
        }
    }
    g->nvertices=0;
    g->directed=0;
    g->weighted=0;
}

void insertEdge(struct Graph *g,int x,int y,int weight) { 
    if(!g->weighted) weight=1;
    g->adjMatrix[x][y]=weight;
    g->nvertices+=1;
    if(!g->directed){
        g->adjMatrix[y][x]=weight;
        g->nvertices+=1;
    }
}

void printGraph(struct Graph *g) {
    for(int i=0;i<=g->nvertices;i++) {
        printf("%d : ",i);
        for(int j=0;j<MAX;j++) {
            if(g->adjMatrix[i][j]==1)
                printf("%d ",j);
        }
        printf("\n");
    }
}

void initSearch(struct Graph *g) {
    for(int i=0;i<MAX;i++) {
        g->discovered[i]=0;
        g->parents[i]=-1;
        g->distance[i]=INT_MAX;
    }
}

void bfs(struct Graph *g,int start) {
    struct Queue queue;
    dequeue(&queue);
    initSearch(g);
    enqueue(&queue,start);
    g->discovered[start] = 1;

    while(!isEmptyQ(&queue)) {
        int v = dequeue(&queue);
        printf("%d ",v);
        for(int i=0;i<MAX;i++) {
            if(g->adjMatrix[v][i]==1) {
                if(!g->discovered[i]) {
                    enqueue(&queue,i);
                    g->discovered[i]=1;
                    g->parents[i] = v;
                }
            }
        }
    }
    printf("\n");
}
void dfs_helper(struct Graph*g,int start) {
    g->discovered[start] = 1;
    printf("%d ",start);
    for(int i=0;i<MAX;i++) {
        if(g->adjMatrix[start][i]==1) {
            if((g->discovered[i])==0) {
                g->parents[i] = start;
                dfs_helper(g,i);
            }
        }
    }
}
void dfs(struct Graph*g,int start) {
    initSearch(g);
    dfs_helper(g,start);
}

int primMST(struct Graph *g,int start) {
    initSearch(g);
    g->distance[start] =0;
    int v=start;
    int weight=0;

    int prev = v;
    while(!g->discovered[v]) {
        g->discovered[v]=1;
        if(start!=v) weight+=g->adjMatrix[prev][v];
        
        for(int i=0;i<MAX;i++) {
            if(g->distance[i] > g->adjMatrix[v][i] && !g->discovered[i]) {
                g->distance[i] = g->adjMatrix[v][i];
            }
        }

        int dist = INT_MAX;

        prev = v;
        for(int i=0;i<MAX;i++) {
            if(!g->discovered[i] && g->distance[i] <dist) {
                dist = g->distance[i];
                v = i;
            }
        }
    }
    return weight;
}
