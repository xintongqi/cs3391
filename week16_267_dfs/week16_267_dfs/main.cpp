//
//  main.cpp
//  week16_267_dfs
//
//  Created by Xintong Qi on 16/4/2022.
//

#include <iostream>

using namespace std;

int directions[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int local;
int matrix[220][220];
int visited[220][220];

void dfs(int x, int y, int M, int N){
    local++;
    
//    for (int i=0; i<N; i++) {
//        for (int j=0; j<M; j++) {
//            cout<<matrix[i][j]<<" ";
//        }
//        cout<<endl;
//    }
//    cout<<endl;
    
    for(int i=0; i<4; i++) {
        int newx=x+directions[i][0];
        int newy=y+directions[i][1];
        
        if(newx<0 || newx>N-1 || newy<0 || newy>M-1)
            continue;
        if(matrix[newx][newy]==1 && visited[newx][newy]==0) {
            visited[newx][newy]=1;
            
            dfs(newx, newy, M, N);
        }
    }
}

int main() {
    
    int N,M,K;
    while(cin>>N>>M>>K){
//        int** matrix = new int*[220];
//        int** visited = new int*[220];
//        for (int i=0; i<220; i++) {
//            matrix[i]=new int[220];
//            visited[i]=new int[220];
//        }
//
        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                matrix[i][j]=0;
                visited[i][j]=0;
            }
        }
        
        for(int i=0; i<K; i++) {
            int x,y;
            cin>>x>>y;
            matrix[x-1][y-1]=1;
        }
        
//        for (int i=0; i<N; i++) {
//            for (int j=0; j<M; j++) {
//                cout<<matrix[i][j]<<" ";
//            }
//            cout<<endl;
//        }
//        cout<<endl;
        
        int global=0;
        local=0;
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                if(matrix[i][j]==1 && visited[i][j]==0) {
                    visited[i][j]=1;
                    dfs(i, j, M, N);
                    
                    if (global<local) {
                        global=local;
                    }
                    
                    visited[i][j]=0;
                    local=0;
                }
            }
        }
        cout<<global<<endl;
        
//        for (int i=0; i<220; i++) {
//            delete[] matrix[i];
//            delete[] visited[i];
//        }
//        delete[] matrix;
//        delete[] visited;
    }
    
    return 0;
}
