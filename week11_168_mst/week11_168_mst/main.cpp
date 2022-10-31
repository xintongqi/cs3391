//
//  main.cpp
//  week11_168_mst
//
//  Created by Xintong Qi on 27/3/2022.
//

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

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
    int kruskalMST();
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

int Graph::kruskalMST()
{
    int result = 0;
    stable_sort(edges.begin(), edges.end());

    DisjointSets disjoint_set(V);

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
    }

    return result;
}

int main()
{
    int P,R;
    while (cin>>P) {
        if (P==0) {
            break;
        }
        cin>>R;
        if (R==0) {
            cout<<0<<endl;
            continue;
        }
        Graph graph(P,R);
        
        for (int i=0; i<R; i++) {
            int u,v,w;
            cin>>u>>v>>w;
            graph.addEdge(u, v, w);
        }
        
        int result=graph.kruskalMST();
        cout<<result<<endl;
    }
    return 0;
}
