//
//  main.cpp
//  midterm_hanoi
//
//  Created by Xintong Qi on 25/2/2022.
//

#include <iostream>

using namespace std;

int findSteps(int n){
    if (n==1) {
        return 2;
    }
    return findSteps(n-1)*3+2;
}

int main() {
    int n;
    while (cin>>n) {
        cout<<findSteps(n)<<endl;
    }
    
    return 0;
}
