//
//  main.cpp
//  week16_396_max_flow
//
//  Created by Xintong Qi on 23/4/2022.
//


#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

#define MAX_EDGE 50000
#define MAX_NODE 50000

typedef struct {
    int v;
    int cap;
    int next;
}EDGE;

void add_edge(int u, int v, int cap, EDGE* edge, int* head, int &totaledge) {
    edge[totaledge].v = v;
    edge[totaledge].cap = cap;
    edge[totaledge].next = head[u];
    head[u] = totaledge;
    totaledge++;
}
bool bfs(int start, int end, EDGE* edge, int* head, int*d, int*f) {
    int u, v;
    
    for (int i=0; i<MAX_NODE; i++) {
        d[i]=-1;
    }
    
    queue<int> my_queue;
    while (!my_queue.empty())
        my_queue.pop();
    my_queue.push(start);
    
    d[start] = 0;
    while (!my_queue.empty()) {
        u = my_queue.front();
        my_queue.pop();
        for (int e = head[u]; e != -1; e = edge[e].next) {
            v = edge[e].v;
            if ((d[v] == -1) && edge[e].cap > f[e]) {
                d[v] = d[u] + 1;
                my_queue.push(v);
            }
        }
    }
    return d[end] >= 0;
}

int max_flow(int u, int T, int total, EDGE* edge, int* head, int* d, int* f) {
    if (u == T)
        return total;
    
    int v, tmp = total;
    
    for (int e = head[u]; e != -1 && total; e = edge[e].next) {
        v = edge[e].v;
        if (d[v] == d[u]+1 && edge[e].cap>f[e]) {
            int local = max_flow(v, T, min(total, edge[e].cap - f[e]), edge, head, d, f);
            f[e] += local;
            f[e^1] -= local;
            total -= local;
        }
    }
    return tmp - total;
}

int main() {
    int N, M;
    while (cin>>N>>M) {

        int totaledge=0;
        int* head = new int[MAX_EDGE];
        EDGE* edge = new EDGE[MAX_NODE];
        int* d = new int[MAX_NODE];
        int* f = new int[MAX_EDGE];
        
        
        for (int i=0; i<MAX_EDGE; i++) {
            head[i]=-1;
            f[i]=0;
        }
        
        int start = 2*N, end = 2*N + 1;
        
        int a, b, c;
        for (int i = 0; i < N; i++){
            cin>>a>>b;
            add_edge(start, i, a, edge, head, totaledge);
            add_edge(i, start, 0, edge, head, totaledge);
            add_edge(i, end, b, edge, head, totaledge);
            add_edge(end, i, 0, edge, head, totaledge);
        }
        for (int i = 1; i <= M; i++){
            cin>>a>>b>>c;
            add_edge(a-1, b-1, c, edge, head, totaledge);
            add_edge(b-1, a-1, c, edge, head, totaledge);
        }
        
        int result = 0;
        while (bfs(start, end, edge, head, d, f))
            result += max_flow(start, end, INT_MAX, edge, head, d, f);
        cout<<result<<endl;
        
        delete [] head;
        delete [] edge;
        delete [] d;
        delete [] f;
    }

    return 0;
}
