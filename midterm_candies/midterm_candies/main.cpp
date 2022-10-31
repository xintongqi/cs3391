//
//  main.cpp
//  midterm_candies
//
//  Created by Xintong Qi on 25/2/2022.
//

#include <iostream>

using namespace std;

int main() {
    
    int test_cases;
    cin>>test_cases;
    for (int i=0; i<test_cases; i++) {
        int a,b,c,x,y,z;
        cin>>x>>y>>z>>a>>b>>c;
        
//      satisfy kirito first
        if (a<x) {
            cout<<"NO"<<endl;
            continue;
        }
        a-=x;
        
//      then satisfy eugeo
        if(a+b<y){
            cout<<"NO"<<endl;
            continue;
        }
        
//      finally alice
        if(a+b-y+c<z){
            cout<<"NO"<<endl;
            continue;
        }
        
        cout<<"YES"<<endl;
    }
    
    return 0;
}
