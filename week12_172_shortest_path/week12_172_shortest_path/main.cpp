//
//  main.cpp
//  week12_172_shortest_path
//
//  Created by Xintong Qi on 28/3/2022.
//

#include <iostream>
#include <limits.h>
#include <vector>
#include <set>
#include <map>

using namespace std;

//int minDistance(int** dist, bool visited[], int n, short status)
//{
//    int min = INT_MAX, min_index;
//
//    for (int i = 0; i < n; i++){
//        if (!visited[i] && dist[i][!status] <= min){
//            min = dist[i][!status];
//            min_index = i;
//        }
//    }
//
//    return min_index;
//}


int dijkstra(vector<vector<pair<int, int>>>& graph, int n)
{
    set<pair<int, pair<int, int>>> unvisisited; // unvisited nodes: <des, <weight, 0>>
    map<int,map<int, int>> dis; // distances: <des, <0, weight>>
    
    for(int i=0; i<n; i++)
        for(int j=0; j<2; j++)
            dis[i][j] = INT_MAX;

    for(auto a:graph[0]){
        dis[a.first][0] = a.second;
        unvisisited.insert(make_pair(a.first, make_pair(a.second, 0)));
    }

    while(!unvisisited.empty()){
        
        int method = unvisisited.begin()->second.second;
        int node = unvisisited.begin()->first;
        int cost = unvisisited.begin()->second.first;

        unvisisited.erase(unvisisited.begin());
        for(auto a:graph[node])
            if(cost+a.second<dis[a.first][!method]){
                unvisisited.erase(make_pair(a.first, make_pair(dis[a.first][!method], !method)));
                dis[a.first][!method]=cost+a.second;
                unvisisited.insert(make_pair(a.first, make_pair(dis[a.first][!method], !method)));
            }
    }
    
    if (dis[n-1][1]==INT_MAX) {
        return -1;
    }else{
        return dis[n-1][1];
    }
}

int main()
{

    int n,r;
    int test_cases=1;
    while (cin>>n>>r) {
//        short** method = new short*[n];
//        for (int i=0; i<n; i++) {
//            method[i] = new short[n];
//        }
//        int** graph = new int*[n];
//        for (int i=0; i<n; i++) {
//            graph[i] = new int[n];
//        }
//
//        for (int i=0; i<n; i++) {
//            for (int j=0; j<n; j++) {
//                graph[i][j]=0;
//                method[i][j]=2;
//            }
//        }
//
//        for (int i=0; i<r; i++) {
//            int src,des,weight;
//            cin>>src>>des>>weight;
//            graph[src][des]=weight;
//            graph[des][src]=weight;
//            method[src][des]=i%2;
//            method[des][src]=i%2;
//        }
        vector<vector<pair <int, int>>> graph(n);
        for (int i=0; i<r; i++) {
            int src,des,weight;
            cin>>src>>des>>weight;
            graph[src].push_back(make_pair(des, weight));
            graph[des].push_back(make_pair(src, weight));
        }
        
        printf("Set #%d\n", test_cases);

        int result = dijkstra(graph, n);
        if (result==-1) {
            printf("?\n");
        }else{
            printf("%d\n",result);
        }
        
        test_cases++;
        
//
//        for (int i=0; i<n; i++) {
//            delete[] method[i];
//        }
//        delete[] method;
//
//        for (int i=0; i<n; i++) {
//            delete[] graph[i];
//        }
//        delete[] graph;
    }
   
    return 0;
}

//struct Edge {
//    int src, dest, weight, type;
//};
//
//struct Graph {
//    int V, E;
//    struct Edge* edge;
//};
//
//struct Graph* createGraph(int V, int E)
//{
//    struct Graph* graph = new Graph;
//    graph->V = V;
//    graph->E = E;
//    graph->edge = new Edge[E];
//    return graph;
//}
//
//
//int BellmanFord(struct Graph* graph, int src)
//{
//    int V = graph->V;
//    int E = graph->E;
//    int dist[V];
//
//    for (int i = 0; i < V; i++)
//        dist[i] = INT_MAX;
//    dist[src] = 0;
//
//    int previous_type=-1;
//    for (int i = 1; i <= V - 1; i++) {
//        for (int j = 0; j < E; j++) {
//            int u = graph->edge[j].src;
//            int v = graph->edge[j].dest;
//            int weight = graph->edge[j].weight;
//            int type = graph->edge[j].type;
//            if (dist[u] != INT_MAX && dist[u] + weight < dist[v] && type!=previous_type){
//                dist[v] = dist[u] + weight;
//                previous_type=type;
//            }
//        }
//    }
//
//    for (int i = 0; i < E; i++) {
//        int u = graph->edge[i].src;
//        int v = graph->edge[i].dest;
//        int weight = graph->edge[i].weight;
//        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
//            return -1;
//        }
//    }
//
//    return dist[V-1];
//}
//
//int main()
//{
//    int n,r;
//    int test_cases=1;
//    while (cin>>n>>r) {
//        struct Graph* graph = createGraph(n, r);
//
//        for (int i=0; i<r; i++) {
//            int src, des, weight;
//            cin>>src>>des>>weight;
//            graph->edge[i].src = src;
//            graph->edge[i].dest = des;
//            graph->edge[i].weight = weight;
//            graph->edge[i].type = i%2;
//        }
//        printf("Set #%d\n", test_cases);
//        int result=BellmanFord(graph, 0);
//        printf("%d\n", BellmanFord(graph, 0));
//    }
//
//
//
//
//    return 0;
//}
