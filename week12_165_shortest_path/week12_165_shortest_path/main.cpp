//
//  main.cpp
//  week12_165_shortest_path
//
//  Created by Xintong Qi on 28/3/2022.
//

#include <iostream>
#include <cmath>

using namespace std;

double findDistance(int x1, int x2, int y1, int y2){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main(int argc, const char * argv[]) {
    int n;
    int test_cases=1;
    while (cin>>n) {
        
        if (n==0) {
            break;
        }
        
        int x[201]={-1};
        int y[201]={-1};
        for (int i=0; i<n; i++) {
            cin>>x[i]>>y[i];
        }
        double distance[201][201];
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                distance[i][j] = distance[j][i] = findDistance(x[i], x[j], y[i], y[j]);
            }
        }
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                for (int k=0; k<n; k++) {
                    distance[j][k] = min(distance[j][k], max(distance[j][i], distance[i][k]));
                }
            }
        }
        printf ("Scenario #%d\n", test_cases);
        printf ("Frog Distance = %.3lf\n\n", distance[0][1]);
        test_cases++;
    }
    return 0;
}
