#include <iostream>
using namespace std;
#include <limits.h>


int minDistance(int dis[], bool visited[], int V)
{
    int min=INT_MAX, min_index=0;

    for (int v = 0; v < V; v++)
        if (visited[v] == false && dis[v] <= min){
            min = dis[v];
            min_index = v;
        }

    return min_index;
}

int dijkstra(int** graph, int V, bool** path)
{
    int dis[V];
    bool visited[V];
    int src=0;
    
//    initialization
    for (int i = 0; i < V; i++){
        dis[i] = INT_MAX;
        visited[i] = false;
    }
    dis[src] = 0;

//    kernel
    for (int i = 0; i<V-1; i++) {
        
        int u = minDistance(dis, visited, V);
        visited[u] = true;
        for (int j = 0; j < V; j++)
            if (!visited[j] && graph[u][j] && dis[u] != INT_MAX && dis[u]+graph[u][j] < dis[j]){
                dis[j] = dis[u] + graph[u][j];
                if (j==V-1) {
                    path[u][j]=true;
                }
            }
    }
    
    for (int i=0; i<V; i++) {
        if (visited[V-1]==false) {
            return -10000;
        }
    }

    return dis[V-1];
}

int main()
{
    int V;
    while (cin>>V) {
        
        if(V==0){
            break;
        }
        
        int E;
        cin>>E;
        
        int** graph = new int*[V];
        bool** path = new bool*[V];
        for(int i = 0; i < V; i++){
            graph[i] = new int[V];
            path[i]=new bool[V];
            for (int j=0; j<V; j++) {
                path[i][j]=false;
            }
        }
        
        for (int i=0; i<E; i++) {
            int src, des, weight;
            cin>>src>>des>>weight;
            
            graph[src-1][des-1]=weight;
            graph[des-1][src-1]=weight;
        }
        
        int friend_time=dijkstra(graph, V, path);
        
//        remote edges that are travelled
        for(int i = 0; i < V; i++){
            for (int j=0; j<V; j++) {
                if (path[i][j]) {
                    graph[i][j]=0;
                    graph[j][i]=0;
                }
            }
        }
        
        int my_time=dijkstra(graph, V, path);
        
        if (my_time<0) {
            cout<<"Back to jail"<<endl;
        }else{
            cout<<friend_time+my_time<<endl;
        }
        
        for(int i = 0; i < V; i++) {
            delete[] graph[i];
            delete[] path[i];
        }
        delete[] graph;
        delete[] path;
    }

    return 0;
}


