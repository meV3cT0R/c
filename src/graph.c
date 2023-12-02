#include <graph.h>
#include <queue.h>

void initGraph(struct Graph *g) {
    for(int i=0;i<MAX;i++) {
        for(int j=0;j<MAX;j++) {
            g->adjMatrix[i][j] = 0;
        }
    }
    g->nvertices=0;
    g->directed=1;
}

void insertEdge(struct Graph *g,int x,int y) {
    g->adjMatrix[x][y]=1;
    g->nvertices+=1;
    if(!g->directed){
        g->adjMatrix[y][x]=1;
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