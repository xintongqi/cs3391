//
//  main.cpp
//  week12_207_dijkstra
//
//  Created by Xintong Qi on 31/3/2022.
//

#include <iostream>
#include <limits.h>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int minDistance(int dist[], bool visited[], int n)
{
    long min = INT_MAX;
    int min_index;
    
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

void printMarchPath(int backtrack[], int v, string names[])
{
       
    if (backtrack[v]==-1){
        cout<<names[v];
        return;
    }
   
    printMarchPath(backtrack, backtrack[v], names);
   
    cout<<" -> "<<names[v];
}

void printBackPath(int backtrack[], int v, string names[])
{
       
    if (backtrack[v]==-1){
        return;
    }
   
    printBackPath(backtrack, backtrack[v], names);
   
    cout<<" -> "<<names[v];
}


void dijkstra(int** graph, int src, int des, int n, string* names)
{
    
    int result=0;
    
    int march_dist[n];
    bool march_visited[n];
    int march_backtrack[n];
    
    for (int i = 0; i<n; i++)
        march_dist[i] = INT_MAX, march_visited[i] = false, march_backtrack[i]=-1;

    march_dist[src] = 0;

    for (int i = 0; i<n-1; i++) {
        int u = minDistance(march_dist, march_visited, n);
        
        march_visited[u] = true;
        
        for (int v = 0; v <n; v++){
            if (!march_visited[v] && graph[u][v] && march_dist[u]!=INT_MAX && march_dist[u]+graph[u][v]<march_dist[v]){
                march_backtrack[v]=u;
                march_dist[v] = march_dist[u]+graph[u][v];
            }
        }
    }
    
    result+=march_dist[des];
    
    int back_dist[n];
    bool back_visited[n];
    int back_backtrack[n];
    
    for (int i=0; i<n; i++) {
        back_dist[i]=INT_MAX, back_visited[i]=false, back_backtrack[i]=-1;
    }
    
    back_dist[des]=0;
    
    for (int i=0; i<n-1; i++) {
        int u=minDistance(back_dist, back_visited, n);
        back_visited[u]=true;
        
        for (int v=0; v<n; v++) {
            if (!back_visited[v] && graph[u][v] && back_dist[u]!=INT_MAX && back_dist[u]+graph[u][v]<back_dist[v]) {
                back_backtrack[v]=u;
                back_dist[v]=back_dist[u]+graph[u][v];
            }
        }
    }
    
    result+=back_dist[src];
    
    cout<<result<<endl;
    
//    for (int i=0; i<n; i++) {
//        cout<<dist[i]<<" ";
//    }
//    cout<<endl;
    
    printMarchPath(march_backtrack, des, names);
    printBackPath(back_backtrack, src, names);
}

//bool is_number(const string& s)
//{
//    string::const_iterator it = s.begin();
//    while (it != s.end() && isdigit(*it)) ++it;
//    return !s.empty() && it == s.end();
//}

int main()
{
    short N;
    while (cin>>N) {
        cin.ignore(256, '\n');
        
        // get the names
        short places=0;
        string names[201];
        unordered_map<string, int> map_for_index;
        while (N--) {
            string tmp;
            getline(cin, tmp);
            names[places]=tmp;
            map_for_index.insert(pair<string, int>(tmp,places));
            places++;
        }
        
//        for (int i=0; i<places; i++) {
//            cout<<names[i]<<endl;
//        }
        
//        unordered_map<string, int>::iterator it;
//        unordered_map<string, int>::iterator itEnd;
//        it=map_for_index.begin();
//        itEnd=map_for_index.end();
//        while (it!=itEnd) {
//            cout<<it->first<<" "<<it->second<<endl;
//            it++;
//        }
        
        int P;
        cin>>P;
        cin.ignore(256, '\n');
        // store the graph
        int** graph = new int*[places];
        for (int i=0; i<places; i++) {
            graph[i]=new int[places];
        }
        
        for (int i=0; i<places; i++) {
            for (int j=0; j<places; j++) {
                graph[i][j]=0;
            }
        }
        
        for (int i=0; i<P; i++) {
            string s;
            getline(cin, s);
            // parse the string
            size_t pos_of_comma = s.find(":");
            string first_place=s.substr(0, pos_of_comma);
            s.erase(0, pos_of_comma+1);
            
            string second_place;
            for (int j=0; j<places; j++) {
                size_t pos=s.find(names[j]);
                if (pos!=string::npos) {
                    second_place=names[j];
                    s.erase(0,pos+second_place.length()+1);
                    break;
                }
            }
            
            int first_index=map_for_index.find(first_place)->second;
            int second_index=map_for_index.find(second_place)->second;
            
            int first_value,second_value;
            size_t pos_of_space=s.find(" ");
            if (pos_of_space!=string::npos) {
                first_value=stoi(s.substr(0,pos_of_space));
                s.erase(0,pos_of_space+1);
                second_value=stoi(s);
                if(!graph[first_index][second_index] && !graph[second_index][first_index]){
                    graph[first_index][second_index]=first_value;
                    graph[second_index][first_index]=second_value;
                }
            }else{
                first_value=stoi(s);
                if (!graph[first_index][second_index]) {
                    graph[first_index][second_index]=first_value;
                }
            }
            
//            char first_digit;
//            int first_value, second_value;
//            for(char& c : s) {
//                if (!isdigit(c)) {
//                    second_place+=c;
//                }else{
//                    first_digit=c;
//                    break;
//                }
//            }
//            second_place=second_place.substr(0,second_place.length()-1);
//            int first_index=map_for_index.find(first_place)->second;
//            int second_index=map_for_index.find(second_place)->second;
//
//            size_t pos_of_num = s.find(first_digit);
//            s.erase(0,pos_of_num);
//            size_t pos_of_space=s.find(" ");
//            if (pos_of_space==string::npos) {
//                first_value=stoi(s);
//                graph[first_index][second_index]=first_value;
//            }else{
//                first_value=stoi(s.substr(0,pos_of_space));
//                s.erase(0,pos_of_space+1);
//                second_value=stoi(s);
//                graph[first_index][second_index]=first_value;
//                graph[second_index][first_index]=second_value;
//            }
        }
        
        
//        for (int i=0; i<places; i++) {
//            for (int j=0; j<places; j++) {
//                cout<<graph[i][j]<<" ";
//            }
//            cout<<endl;
//        }
        
        int office_index=map_for_index.find("office")->second;
        int hall_index=map_for_index.find("hall")->second;
        
        dijkstra(graph, office_index, hall_index, places, names);
        cout<<endl<<endl;
        
        for (int i=0; i<places; i++) {
            delete [] graph[i];
        }
        delete [] graph;
    }
}
