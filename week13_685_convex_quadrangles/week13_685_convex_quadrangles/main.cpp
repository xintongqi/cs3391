//
//  main.cpp
//  week13_685_convex_quadrangles
//
//  Created by Xintong Qi on 3/4/2022.
//

#include <iostream>
#include <vector>

using namespace std;

struct Point{
    int x,y;
    Point(int a, int b){
        x=a;
        y=b;
    }
};

int orientation(Point p, Point q, Point r)
{
    int result = (q.y-p.y) * (r.x-q.x) - (q.x-p.x) * (r.y-q.y);
    return (result > 0)? 1: 2;
}

bool intersects(Point p1, Point q1, Point p2, Point q2)
{
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);
 
    if (o1 != o2 && o3 != o4)
        return true;
 
    return false;
}
 

int main() {
    int test_cases;
    cin>>test_cases;
    while (test_cases--) {
        int n;
        cin>>n;
        vector<Point> points;
        for (int i=0; i<n; i++) {
            int a,b;
            cin>>a>>b;
            points.push_back(Point(a,b));
        }
        
        int result=0;
        
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                Point p1=points[i];
                Point q1=points[j];
                
                for (int a=j+1; a<n; a++) {
                    for (int b=a+1; b<n; b++) {
                        
                        Point p2=points[a];
                        Point q2=points[b];
                        
                        if (intersects(p1, q1, p2, q2) || intersects(p1, p2, q1, q2) || intersects(p1, q2, p2, q1)) {
                            result++;
                        }
                    }
                }
            }
        }
        
        cout<<result<<endl;
        
    }
    return 0;
}
