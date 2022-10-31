//
//  main.cpp
//  week13_247_bfs
//
//  Created by Xintong Qi on 2/4/2022.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;



struct Room
{
    int x, y, step;
    bool flag;
    Room(){};
    Room(int i, int j, bool f, int s){
        x=i;
        y=j;
        flag=f;
        step=s;
    }
};

int bfs(int R, int C, int** status, char** maze)
{
    queue<Room> q;
    Room joe;
    
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            if (maze[i][j]=='F') {
                q.push(Room(i,j,0,0));
            }else if (maze[i][j]=='J'){
                joe=Room(i,j,1,0);
            } else {
                continue;
            }
        }
    }
    
    q.push(joe);
    status[joe.x][joe.y]=0;
    
    int directions[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    
    while (!q.empty())
        {
            Room room = q.front();
            q.pop();
            
            if (room.flag&&(room.x==0||room.x==R-1||room.y==0||room.y==C-1)){
                // already at exit
                return status[room.x][room.y];
            }
                
            for (int k=0;k<4;k++)
            {
                int nx=room.x + directions[k][0];
                int ny=room.y + directions[k][1];
                
                if (nx>=0 && nx<R && ny>=0 && ny<C && maze[nx][ny]=='.' && status[nx][ny]==-1)
                {
                    status[nx][ny]=room.step+1;
                    q.push(Room(nx, ny, room.flag, status[nx][ny]));
                }
            }
        }
    
    return -1;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int R,C;
        cin>>R>>C;
        
        char** maze = new char*[1005];
        for (int i=0; i<1005; i++) {
            maze[i]=new char[1005];
        }
        
        for (int i=0; i<R; i++) {
            for (int j=0; j<C; j++) {
                cin>>maze[i][j];
            }
        }
        
        int** status = new int*[1005];
        for (int i=0; i<1005; i++) {
            status[i]=new int[1005];
        }
        
        for (int i=0; i<R; i++) {
            for (int j=0; j<C; j++) {
                status[i][j]=-1;
            }
        }
        
        int result=bfs(R, C, status, maze);
        
        if (result==-1) {
            cout<<"IMPOSSIBLE"<<endl;
        }else{
            cout<<result+1<<endl;
        }
        
        for (int i=0; i<1005; i++) {
            delete[] maze[i];
        }
        delete[] maze;
    }
    return 0;
}
