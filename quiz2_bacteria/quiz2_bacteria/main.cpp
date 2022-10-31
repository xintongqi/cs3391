//
//  main.cpp
//  quiz2_bacteria
//
//  Created by Xintong Qi on 8/4/2022.
//

#include <iostream>
#include <map>
#include <stack>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

class node {
public:
    int x, y;
    int march;
 
    node(int i, int j)
    {
        x = i;
        y = j;
        march = 0;
    }
};

bool cmp(pair<char, int>& a,
         pair<char, int>& b)
{
    if (a.second!=b.second) {
        return a.second>b.second;
    }
    return a.first<b.first;
}

void sortMap(map<char, int>& M, int test_case)
{
    vector<pair<char, int>> result;
    for (auto& it : M) {
        result.push_back(it);
    }
    sort(result.begin(), result.end(), cmp);
    
    printf("Plate #%d\n", test_case);
    for(auto& it:result ){
            printf("%c: %d\n", it.first, it.second);
    }
}

int main() {
    int N;
    cin>>N;
    
    for (int test_case=1; test_case<=N; test_case++) {
        int height, width;
        cin>>height>>width;
        
        char** matrix=new char*[height];
        for (int i=0; i<height; i++) {
            matrix[i]=new char[width];
        }
        
        bool** visited=new bool*[height];
        for (int i=0; i<height; i++) {
            visited[i]=new bool[width];
        }
        
        for (int i=0; i<height; i++) {
            for (int j=0; j<width; j++) {
                cin>>matrix[i][j];
                visited[i][j]=false;
            }
        }
    
        map<char, int> result;
        bool notEnd=true;
        int i=0, j=0;
        
        while(notEnd){
            notEnd=false;
            
            stack<node> s;
            node now(i, j);
            s.push(now);
            
            char current=matrix[i][j];
            
            while (!s.empty()) {
                now = s.top();
                int d = now.march;
                i = now.x, j = now.y;
         
                now.march++;
                s.pop();
                s.push(now);
         
                if (d==0) {
                    if (i-1>=0 && matrix[i-1][j]==current && !visited[i-1][j]) {
                        node temp1(i-1, j);
                        visited[i-1][j] = true;
                        s.push(temp1);
                    }
                }else if (d==1) {
                    if (j-1>=0 && matrix[i][j-1]==current && !visited[i][j-1]) {
                        node temp1(i, j-1);
                        visited[i][j-1] = true;
                        s.push(temp1);
                    }
                }else if (d==2) {
                    if (i+1<width && matrix[i+1][j]==current && !visited[i+1][j]) {
                        node temp1(i+1, j);
                        visited[i+1][j] = true;
                        s.push(temp1);
                    }
                }else if (d==3) {
                    if (j+1<width && matrix[i][j+1]==current && !visited[i][j+1]) {
                        node temp1(i, j + 1);
                        visited[i][j+1] = true;
                        s.push(temp1);
                    }
                } else {
//                    visited[now.x][now.y] = false;
                    s.pop();
                }

            }
            
            result[current]++;
            
            for (int x=0; x<height; x++) { // visit any unvisited spot
                for (int y=0; y<width; y++) {
                    if (!visited[x][y]) {
                        i=x;
                        j=y;
                        notEnd=true;
                        break;
                    }
                }
                if (notEnd) {
                    break;
                }
            }
            
//            for (int i=0; i<height; i++) {
//                for (int j=0; j<width; j++) {
//                    cout<<matrix[i][j];
//                }
//                cout<<endl;
//            }
//            cout<<endl;
//
//            for (int i=0; i<height; i++) {
//                for (int j=0; j<width; j++) {
//                    cout<<visited[i][j];
//                }
//                cout<<endl;
//            }
//            cout<<endl;
        }
        
        sortMap(result, test_case);
        
        for (int i=0; i<height; i++) {
            delete matrix[i];
        }
        delete[] matrix;
        
        for (int i=0; i<height; i++) {
            delete visited[i];
        }
        delete[] visited;
    }
    
    return 0;
}
