//
//  main.cpp
//  week12_145_mst
//
//  Created by Xintong Qi on 27/3/2022.
//

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

struct Point{
    int X;
    int Y;
};

struct Edge {
    int a_index;
    int b_index;
    double Len;
};

bool comparator(const Edge &A, const Edge &B) {
    return A.Len < B.Len;
}

int Find_Root(int x, int* indexes)
{
    if (x == indexes[x])
        return x;
    return indexes[x] = Find_Root(indexes[x], indexes);
}

bool Union(const Edge &E, vector<double> &LenOfEdge, int* indexes)
{
    int a = Find_Root(E.a_index, indexes);
    int b = Find_Root(E.b_index, indexes);
    if (a != b) {
        indexes[a] = b;
        LenOfEdge.push_back(E.Len);
        return true;
    }
    return false;
}

double find_distance(Point point1, Point point2){
    double result = sqrt(pow((point1.X-point2.X),2)+pow((point1.Y-point2.Y),2));
    return result;
}

int main()
{
    int test_cases;
    cin>>test_cases;
    for (int i=0; i<test_cases; i++) {
        int S,P;
        cin>>S>>P;
        Point* locations = new Point[501];
        int* indexes = new int[501];
        for (int j=0; j<P; j++) {
            cin>>locations[j].X>>locations[j].Y;
            indexes[j]=j;
        }

        int num_of_edges=0;
        Edge* edges = new Edge[501*501];
        for (int j=0; j<P; j++) {
            for (int k=j+1; k<P; k++) {
                edges[num_of_edges]={j,k,find_distance(locations[j],locations[k])};
                num_of_edges++;
            }
        }
        
//        for (int j=0; j<num_of_edges; j++) {
//            printf("%.2f\n", edges[j].Len);
//        }

        stable_sort(edges, edges+num_of_edges, comparator);
        
//        for (int j=0; j<num_of_edges; j++) {
//            printf("%.2f\n", edges[j].Len);
//        }

        vector<double> cost;
        for (int j=0, k=0; k!=P-1; j++) {
            if (Union(edges[j], cost, indexes)) {
                k++;
            }
        }

        printf("%.2f\n", cost[P-S-1]);

        delete[] locations;
        delete[] indexes;
        delete[] edges;
     }
}
