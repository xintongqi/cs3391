//
//  main.cpp
//  week6_14_euclid_equation
//
//  Created by Xintong Qi on 25/2/2022.
//

#include <iostream>

using namespace std;

int solve(int a, int b, int& x, int& y)
{
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    else {
        int g = solve(b, a % b, x, y);
        int x1 = x, y1 = y;
        x = y1;
        y = x1 - (a / b) * y1;
        return g;
    }
}

int main(void)
{
    int a, b;

    while (cin>>a>>b) {
        int x, y;
        int d=solve(a, b, x, y);
        
        cout<<x<<" "<<y<<" "<<d<<endl;
    }
    return 0;
}
