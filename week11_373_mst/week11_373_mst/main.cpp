//
//  main.cpp
//  week11_373_mst
//
//  Created by Xintong Qi on 27/3/2022.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Graph
{
    int V, E;
    vector<pair<int, pair<int, int>>> edges;

    Graph(int V, int E)
    {
        this->V = V;
        this->E = E;
    }
    
    void addEdge(int u, int v, int w)
    {
        edges.push_back({w, {u, v}});
    }
    void kruskalMST();
};

struct DisjointSets
{
    int *parent, *rank;
    int n;

    DisjointSets(int n)
    {
        this->n = n;
        parent = new int[n+1];
        rank = new int[n+1];
        for (int i = 0; i <= n; i++)
        {
            rank[i] = 0;
            parent[i] = i;
        }
    }

    int find(int u)
    {
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }

    void merge(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (rank[x] > rank[y])
            parent[y] = x;
        else
            parent[x] = y;

        if (rank[x] == rank[y])
            rank[y]++;
    }
};

void Graph::kruskalMST()
{
    int result = 0;
    stable_sort(edges.begin(), edges.end());

    DisjointSets disjoint_set(V);
    
    vector<pair<int, pair<int, int>>> unused_edges;

    vector<pair<int, pair<int, int>>>::iterator it;
    for (it=edges.begin(); it!=edges.end(); it++)
    {
        int u = it->second.first;
        int v = it->second.second;

        int set_u = disjoint_set.find(u);
        int set_v = disjoint_set.find(v);

        if (set_u != set_v)
        {
            result += it->first;
            disjoint_set.merge(set_u, set_v);
        }
        else{
            unused_edges.push_back(*it);
        }
    }
    
    bool mst=true;
    int root=disjoint_set.find(0);
    for (int i=1; i<V; i++) {
        if (disjoint_set.find(i)!=root) {
            mst=false;
        }
    }
    
    if (mst) {
        cout<<"Min cost: "<<result<<endl;
        if (unused_edges.size()!=0) {
            vector<pair<int, pair<int, int>>>::iterator second_to_last_it = unused_edges.end()-1;
            for (it=unused_edges.begin(); it!=unused_edges.end(); it++) {
                int w = it->first;
                if (it!=second_to_last_it) {
                    cout<<w<<" ";
                }else{
                    cout<<w<<endl;
                }
            }
        }else{
            cout<<endl;
        }
    }else{
        char emoji [] =R"(\(^o^)/ pray to god)";
        cout<<emoji<<endl;
    }
}

int main()
{
    int n,m;
    while (cin>>n>>m) {
        if (n==0 && m==0) {
            break;
        }
        Graph graph(n,m);
        
        for (int i=0; i<m; i++) {
            int u,v,w;
            cin>>u>>v>>w;
            graph.addEdge(u, v, w);
        }
        
        graph.kruskalMST();
    }
    return 0;
}
