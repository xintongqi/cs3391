//
//  main.cpp
//  week16_378_monster_synthesis
//
//  Created by Xintong Qi on 16/4/2022.
//

#include <iostream>
#include <climits>
#include <vector>
#include <set>

using namespace std;

struct Monster{
    short level;
    int cost;
    Monster(){};
    Monster(int c, short l){
        level=l;
        cost=c;
    }
};

int minDistance(int dist[], bool visited[], int n)
{
    int min = INT_MAX, min_index;
 
    for (int v = 0; v < n; v++){
        if (!visited[v] && dist[v]<=min){
            min = dist[v];
            min_index = v;
        }
    }
    
    return min_index;
}

int dijkstra(int** graph, int n, Monster* monsters, int src)
{
    int dist[n];
    bool visited[n];
    
    for (int i = 0; i < n; i++){
        dist[i] = INT_MAX;
        visited[i] = false;
    }
    dist[src] = monsters[src].cost;
 
    for (int i=0; i<n-1; i++) {
        int u = minDistance(dist, visited, n);
        visited[u] = true;
        for (int v=0; v<n; v++){

            if (!u) {
                if (!visited[v] && graph[u][v] && dist[u]!=50000 && dist[u]+graph[u][v]+monsters[v].cost<dist[v]){
                    dist[v] = dist[u]+graph[u][v]+monsters[v].cost;
                }
            }else{
                if (!visited[v] && graph[u][v] && dist[u]!=50000 && dist[u]+graph[u][v]+monsters[u].cost+monsters[v].cost<dist[v]){ // go to v through u
                    dist[v] = dist[u]+graph[u][v]+monsters[u].cost+monsters[v].cost;
                }
            }
        }
    }
    
    dist[0]+=monsters[0].cost;
    
    for (int i=0; i<n; i++) {
        cout<<dist[i]<<" ";
    }
    cout<<endl;
    
    int result=50000;
    for (int i=0; i<n; i++) {
        if (dist[i] && result>dist[i]) {
            result=dist[i];
        }
    }
    return result;
    
}

int main() {
    int max_diff, monster_num;
    while (cin>>max_diff>>monster_num) {
        int** matrix=new int*[monster_num];
        for (int i=0; i<monster_num; i++) {
            matrix[i]=new int[monster_num];
        }

        Monster* monsters=new Monster[monster_num];

        for (int i=0; i<monster_num; i++) {
            for (int j=0; j<monster_num; j++) {
                matrix[i][j]=0;
            }
        }

        for (int i=0; i<monster_num; i++) {
            int level, rule_num, cost;
            cin>>cost>>level>>rule_num;
            monsters[i]=Monster(cost,level);
            for (int j=0; j<rule_num; j++) {
                int from, addon;
                cin>>from>>addon;
                if (i && (level-monsters[0].level>max_diff || monsters[0].level-level>max_diff)) {
                    continue;
                }else{
                    matrix[i][from-1]=addon;
//                    matrix[from-1][i]=addon;
                }
            }
        }
        
        // find conflict pairs
        vector<set<int> > conflicts;
        bool hasConflicts=false;
        for (int i=0; i<monster_num; i++) {
            set<int> tmp;
            for (int j=0; j<monster_num; j++) {
                if (monsters[i].level-monsters[j].level>max_diff || monsters[j].level-monsters[i].level>max_diff) {
                    tmp.insert(j);
                    hasConflicts=true;
                }
            }
            conflicts.push_back(tmp);
        }
        
        // TODO: printing only
//        int counter=0;
//        for (auto& r:conflicts) {
//            cout<<"conflicts"<<counter<<":";
//            for (auto& c:r){
//                cout<<c<<" ";
//            }
//            counter++;
//            cout<<endl;
//        }
        
        for (int i=monster_num-1; i>0; i--) {
            
        }
        
        for (int i=0; i<monster_num; i++) {
            delete [] matrix[i];
        }
        delete [] matrix;
        delete [] monsters;
    }

    return 0;
}




//        int result=INT_MAX;
//        if (hasConflicts) {
//            int ctr=0;
//            for(auto& row:conflicts){
//                if (!row.empty()) {
//                    int** graph=new int*[monster_num];
//                    for (int i=0; i<monster_num; i++) {
//                        graph[i]=new int[monster_num];
//                    }
//
//                    for (int i=0; i<monster_num; i++) {
//                        if (row.count(i)) {
//                            for (int j=0; j<monster_num; j++) {
//                                graph[i][j]=0;
//                            }
//                        }else{
//                            for (int j=0; j<monster_num; j++) {
//                                if (row.count(j)) {
//                                    graph[i][j]=0;
//                                }else{
//                                    graph[i][j]=matrix[i][j];
//                                }
//                            }
//                        }
//                    }
//
//                    for (int i=0; i<monster_num; i++) {
//                        for (int j=0; j<monster_num; j++) {
//                            cout<<graph[i][j]<<" ";
//                        }
//                        cout<<endl;
//                    }
//
//                    int local=dijkstra(graph, monster_num, monsters);
//
//                    if (local<result) {
//                        result=local;
//                    }
//
//                    for (int i=0; i<monster_num; i++) {
//                        delete [] graph[i];
//                    }
//                    delete [] graph;
//                }
//                ctr++;
//            }
//        } else{
//            result=dijkstra(matrix, monster_num, monsters);
//        }
        
//        cout<<result<<endl;
