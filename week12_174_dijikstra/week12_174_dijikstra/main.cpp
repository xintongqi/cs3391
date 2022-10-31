//
//  main.cpp
//  week12_174_dijikstra
//
//  Created by Xintong Qi on 30/3/2022.
//

#include <iostream>
#include <limits.h>
#include <string>
#include <vector>

using namespace std;

int minDistance(int dist[], bool visited[], int n, int* tax)
{
    long min = INT_MAX, min_index;
    
//    cout<<"dist";
//    for (int i=0; i<n; i++) {
//        cout<<dist[i]<<" ";
//    }
//    cout<<endl;

    for (int v = 0; v <n; v++){
        if (visited[v]==false && dist[v]<=min){
//            cout<<min<<" "<<dist[v]<<" "<<tax[v]<<" "<<v<<endl;
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void printPath(int backtrack[], int v)
{
       
    if (backtrack[v] == - 1){
        printf("Path: %d",v+1);
        return;
    }
   
    printPath(backtrack, backtrack[v]);
   
    printf("-->%d", v+1);
}

void dijkstra(int** graph, int src, int des, int* tax, int n)
{
    int dist[n];
    bool visited[n];
    int backtrack[n];
    
    for (int i = 0; i<n; i++)
        dist[i] = INT_MAX, visited[i] = false, backtrack[i]=-1;

    dist[src] = 0;

    for (int i = 0; i<n-1; i++) {
        int u = minDistance(dist, visited, n, tax);
        
        visited[u] = true;
        
        for (int v = 0; v <n; v++){
            if (u==src) {
                if (!visited[v] && graph[u][v] && dist[u]!=INT_MAX && dist[u]+graph[u][v]<dist[v]){
                    backtrack[v]=u;
                    dist[v] = dist[u]+graph[u][v];
                }
            }else{
                if (!visited[v] && graph[u][v] && dist[u]!=INT_MAX && dist[u]+graph[u][v]+tax[u]<dist[v]){ // go to v through u
                    backtrack[v]=u;
                    dist[v] = dist[u]+graph[u][v]+tax[u];
                }
            }
        }
        
    }
    

    
//    for (int i=0; i<n; i++) {
//        cout<<dist[i]<<" ";
//    }
//    cout<<endl;
        
    printf("From %d to %d :\n", src+1,des+1);
    printPath(backtrack, des);
    printf("\n");
    printf("Total cost : %d\n", dist[des]);
    
}

int main()
{

    int M;
    cin>>M;
    cin.ignore(256, '\n');
    
    while (M--) {
        string s="";
        while (s=="") {
            getline(cin,s);
        }
        size_t pos = 0;
        
        vector<int> tmp;
        while ((pos = s.find(" ")) != string::npos) {
            string token = s.substr(0, pos);
            tmp.push_back(stoi(token)==-1?0:stoi(token));
            s.erase(0, pos+1);
        }
        tmp.push_back(stoi(s)==-1?0:stoi(s));
        int n=(int)tmp.size();
        
        int** graph = new int*[n];
        graph[0]=&tmp[0];
        
        for (int i=1; i<n; i++) {
            graph[i]=new int[n];
            for (int j=0; j<n; j++) {
                int tmp;
                cin>>tmp;
                tmp==-1?graph[i][j]=0:graph[i][j]=tmp;
            }
        }
        
        
        
//        cout<<endl;
//        for (int i=0; i<n; i++) {
//            for (int j=0; j<n; j++) {
//                cout<<graph[i][j]<<" ";
//            }
//            cout<<endl;
//        }
//        cout<<endl;
        
        
        
        int* tax= new int[n];
        for (int i=0; i<n; i++) {
            cin>>tax[i];
        }
        
        
        
        
//        for (int i=0; i<n; i++) {
//            cout<<tax[i]<<" ";
//        }
//        cout<<endl;
        
        
        cin.ignore(256, '\n');
        
        string line;
        bool first=true;
        while (true) {
            getline(cin,line);
            
            if (line=="") {
                break;
            }
            
            int tmp_array[2];
            size_t pos=line.find(" ");
            tmp_array[0]=stoi(line.substr(0,pos));
            line.erase(0,pos);
            tmp_array[1]=stoi(line);
            
//            cout<<tmp_array[0]<<" "<<tmp_array[1]<<endl;
            if (first) {
                first=false;
            }else{
                printf("\n");
            }
            dijkstra(graph, tmp_array[0]-1, tmp_array[1]-1, tax, n);
        }
        if (M!=0) {
            cout<<endl;
        }
        for (int i=1; i<n; i++) {
            delete [] graph[i];
        }
        delete [] graph;
        delete [] tax;
    }

    return 0;
}
