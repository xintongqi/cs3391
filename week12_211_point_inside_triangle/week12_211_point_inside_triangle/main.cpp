//
//  main.cpp
//  week12_211_point_inside_triangle
//
//  Created by Xintong Qi on 30/3/2022.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point{
    int x,y;
    Point(){};
    Point(int x, int y):x(x),y(y){};

    bool operator < (const Point& point)const{
        if (x<point.x) {
            return true;
        }else if(x==point.x && y<point.y){
            return true;
        }
        return false;
    }

    Point operator - (Point point){
        return Point(x-point.x, y-point.y);
    }
};

int helperFunc(Point p1, Point p2){
    return p1.x*p2.y-p1.y*p2.x;
}

int grahamScan(Point* convex_hull, vector<Point>& points){
    int ctr1=0;
    for (int i=0; i<points.size(); i++) {
        while (ctr1>1 && helperFunc(convex_hull[ctr1-1]-convex_hull[ctr1-2], points[i]-convex_hull[ctr1-2])<=0) {
            ctr1--;
        }
        convex_hull[ctr1++]=points[i];
    }
    int ctr2=ctr1;
    for (int i=(int)points.size()-2; i>=0; i--) {
        while (ctr1>ctr2 && helperFunc(convex_hull[ctr1-1]-convex_hull[ctr1-2], points[i]-convex_hull[ctr1-2])<=0) {
            ctr1--;
        }
        convex_hull[ctr1++]=points[i];
    }

    return ctr1;
}

int main() {
    int p;
    while (cin>>p) {
        vector<Point> points;
        for (int i=0; i<p; i++) {
            int x,y;
            cin>>x>>y;
            points.push_back(Point(x,y));
        }
        stable_sort(points.begin(), points.end());
        Point* convex_hull= new Point[100001];
        int amount = grahamScan(convex_hull, points);
        
        
//        for (int i=0; i<p; i++) {
//            cout<<convex_hull[i].x <<" " << convex_hull[i].y <<" " <<endl;;
//        }
        
        int r;
        cin>>r;
        bool isOutside;
        for (int i=0; i<r; i++) {
            isOutside=false;
            int x,y;
            cin>>x>>y;
            for (int j=0; j<amount-1; j++) {
//                printf("first %d %d\n", (convex_hull[j+1]-convex_hull[j]).x, (convex_hull[j+1]-convex_hull[j]).y);
//                printf("second %d %d\n", (Point(x,y)-convex_hull[j]).x, (Point(x,y)-convex_hull[j]).y);
//                printf("whole %d\n", helperFunc(convex_hull[j+1]-convex_hull[j], Point(x,y)-convex_hull[j]));
                if (helperFunc(convex_hull[j+1]-convex_hull[j], Point(x,y)-convex_hull[j])<0) {
                    isOutside=true;
                    break;
                }
            }
            
            if (isOutside) {
                cout<<"outside"<<endl;
            }else{
                cout<<"inside"<<endl;
            }
        }

        delete[] convex_hull;
    }
    return 0;
}
