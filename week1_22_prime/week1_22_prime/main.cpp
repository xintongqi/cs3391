//
//  main.cpp
//  week1_22_prime
//
//  Created by Xintong Qi on 22/1/2022.
//

#include <iostream>
#include <list>
#include <queue>
#include <cstring>

using namespace std;

class graph {
    int V;
    list<int>* l;
public:
    graph(int V)
    {
        this->V = V;
        l = new list<int>[V];
    }
    void addedge(int V1, int V2)
    {
        l[V1].push_back(V2);
        l[V2].push_back(V1);
    }
    int bfs(int in1, int in2);
};

bool isPrime(int number){

    if(number < 2) return false;
    if(number == 2) return true;
    if(number % 2 == 0) return false;
    for(int i=3; (i*i)<=number; i+=2){
        if(number % i == 0 ) return false;
    }
    return true;
}

void findAllPrimes(vector<int>& v)
{
    for (int i=1000; i<9999; i++) {
        if (isPrime(i)) {
            v.push_back(i);
        }
    }
}

bool oneDigitDifferent(int num1, int num2)
{
    string s1 = to_string(num1);
    string s2 = to_string(num2);
    int c = 0;
    if (s1[0] != s2[0])
        c++;
    if (s1[1] != s2[1])
        c++;
    if (s1[2] != s2[2])
        c++;
    if (s1[3] != s2[3])
        c++;
    return (c == 1);
}

void constructGraph(vector<int>& all_primes, graph& g){
//  construct all known paths for four digits numbers
    for (int i = 0; i < all_primes.size(); i++)
        for (int j = i + 1; j < all_primes.size(); j++)
            if (oneDigitDifferent(all_primes[i], all_primes[j]))
                g.addedge(i, j);
}

int findPath(int num1, int num2, vector<int>& all_primes, graph& g)
{
//  find path between start and end
    int node1, node2;
    for (int j = 0; j < all_primes.size(); j++){
        if (all_primes[j] == num1)
            node1 = j;
        if (all_primes[j] == num2)
            node2 = j;
    }

    return g.bfs(node1, node2);
}

int graph::bfs(int node1, int node2)
{
    int visited[V];
    memset(visited, 0, sizeof(visited));
    
    queue<int> q;
    visited[node1] = 1;
    q.push(node1);
    
    list<int>::iterator i;
    while (!q.empty()) {
        int p = q.front();
        q.pop();
        for (i = l[p].begin(); i != l[p].end(); i++) {
            if (!visited[*i]) {
                visited[*i] = visited[p] + 1;
                q.push(*i);
            }
            if (*i == node2) {
                int result = visited[*i] - 1;
                return result;
            }
        }
    }
    
    return -1;
}


int main()
{
    int test_cases;
    cin>>test_cases;
    
//  find all primes within range
    vector<int> all_primes;
    findAllPrimes(all_primes);
//  construct the graph
    graph g((int)all_primes.size());
    constructGraph(all_primes, g);
    
    for (int i=0; i<test_cases; i++) {
        int start, end;
        cin>>start>>end;

//      get shortest path using bfs
        int result = findPath(start, end, all_primes, g);

        if(result==-1){
            cout<<"Impossible"<<endl;
        }else{
            cout<<result<<endl;
        }
    }
    
//    int result1 = findPath(1033, 8179, all_primes, g);
//    int result2 = findPath(1373, 8017, all_primes, g);
//    int result3 = findPath(1033, 1033, all_primes, g);
//    int result4 = findPath(1231, 1237, all_primes, g);
//    printf("%d %d %d %d", result1, result2, result3, result4);
    
    return 0;
}
