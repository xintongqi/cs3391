//
//  main.cpp
//  week10_215_set_theory
//
//  Created by Xintong Qi on 20/3/2022.
//

#include <iostream>

using namespace std;

struct Point{
    int x,y;
};

struct Line{
    Point a,b;
};
Line lines[13];

//bool intersect(Line l1, Line l2){
//    int s1_x, s1_y, s2_x, s2_y;
//    s1_x = l1.b.x - l1.a.x;     s1_y = l1.b.y - l1.a.y;
//    s2_x = l2.b.x - l2.a.x;     s2_y = l2.b.y - l2.a.y;
//
//    int tmp1=-s2_x * s1_y + s1_x * s2_y;
//    int tmp2=-s2_x * s1_y + s1_x * s2_y;
//    if (tmp1==0 || tmp2==0) {
//        return false; // colinear or parallel
//    }
//
//    float s, t;
//    s = (-s1_y * (l1.a.x - l2.a.x) + s1_x * (l1.a.y - l2.a.y)) / tmp1;
//    t = ( s2_x * (l1.a.y - l2.a.y) - s2_y * (l1.a.x - l2.a.x)) / tmp2;
//
//    if (s >= 0 && s <= 1 && t >= 0 && t <= 1)
//    {
//        return true;
//    }
//
//    return false;
//}

//bool util(Point A, Point B, Point C){
//    return (C.y-A.y) * (B.x-A.x) > (B.y-A.y) * (C.x-A.x);
//}
//
//bool intersect(Line l1, Line l2, int j, int k){
//    if((j==3&&k==4) || (j==5&&k==6)){
//        cout<<l1.a.x<<" "<<l1.a.y;
//        cout<<l1.b.x<<" "<<l1.b.y<<endl;
//        cout<<l2.a.x<<" "<<l2.a.y;
//        cout<<l2.b.x<<" "<<l2.b.y<<endl;
//        bool b1= util(l1.a,l2.a,l2.b);
//        bool b2= util(l1.b,l2.a,l2.b);
//        bool b3= util(l1.a,l1.b,l2.a);
//        bool b4= util(l1.a,l1.b,l2.b);
//        cout<<b1<<" "<<b2<<" "<<b3<<" "<<b4<<endl;
//    }
//
//    return (util(l1.a,l2.a,l2.b) != util(l1.b,l2.a,l2.b))
//    && (util(l1.a,l1.b,l2.a) != util(l1.a,l1.b,l2.b));
//}

bool touch(Point p, Point q, Point r)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
       return true;
 
    return false;
}

int ccr(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
 
    if (val == 0)
        return 0;
 
    return (val > 0)? 1: 2;
}

bool intersect(Point p1, Point q1, Point p2, Point q2)
{
    int o1 = ccr(p1, q1, p2);
    int o2 = ccr(p1, q1, q2);
    int o3 = ccr(p2, q2, p1);
    int o4 = ccr(p2, q2, q1);

    if (o1 != o2 && o3 != o4)
        return true;
 
    if (o1 == 0 && touch(p1, p2, q1)) return true;
 
    if (o2 == 0 && touch(p1, q2, q1)) return true;
 
    if (o3 == 0 && touch(p2, p1, q2)) return true;
 
    if (o4 == 0 && touch(p2, q1, q2)) return true;
 
    return false;
}

int main() {
    int test_cases;
    cin>>test_cases;
    for (int i=0; i<test_cases; i++) {
        int sticks;
        cin>>sticks;
        
        for (int j=0; j<sticks; j++) {
            cin>>lines[j].a.x>>lines[j].a.y>>lines[j].b.x>>lines[j].b.y;
        }
        
        bool **all_sticks = new bool*[13];
        for(int j=0; j<13; j++) {
            all_sticks[j] = new bool[13];
        }
        
        for (int j=0; j<sticks; j++) {
            for (int k=j; k<sticks; k++) {
                if (j==k || intersect(lines[j].a,lines[j].b,lines[k].a,lines[k].b)) {
                    all_sticks[j][k]=true;
                    all_sticks[k][j]=true;
                }else{
                    all_sticks[j][k]=false;
                    all_sticks[k][j]=false;
                }
            }
        }
        
//        for (int j=0; j<sticks; j++) {
//            for (int k=0; k<sticks; k++) {
//                cout<<all_sticks[j][k]<<" ";
//            }
//            cout<<endl;
//        }
//
//        cout<<endl;
        
        for (int j=0; j<sticks; j++) {
            for (int k=0; k<sticks; k++) {
                for (int l=0; l<sticks; l++) {
                    if (k!=l && all_sticks[k][j] && all_sticks[j][l] && !all_sticks[k][l]) {
                        all_sticks[k][l]=true;
                    }
                }
            }
        }
        
//        for (int j=0; j<sticks; j++) {
//            for (int k=0; k<sticks; k++) {
//                cout<<all_sticks[j][k]<<" ";
//            }
//            cout<<endl;
//        }
        
        int line1,line2;
//        string s;
        while (cin>>line1>>line2) {
            if (line1==0 && line2==0) {
                break;
            }

            if (all_sticks[line1-1][line2-1]) {
                cout<<"CONNECTED"<<endl;
//                s+="CONNECTED\n";
            }else{
                cout<<"NOT CONNECTED"<<endl;
//                s+="NOT CONNECTED\n";
            }
        }
        if (i!=test_cases-1) {
            cout<<endl;
        }
        
//        int line1,line2;
//        while (cin>>line1>>line2 ){
//            if (line1==0 && line2==0) {
//                break;
//            }
//            puts(all_sticks[line1-1][line2-1] ? "CONNECTED\n" : "NOT CONNECTED\n");
//        }
//
//        putchar('\n');
        
        for(int j=0; j<13; j++) {
            delete[] all_sticks[j];
        }
        delete[] all_sticks;
    }
    return 0;
}
