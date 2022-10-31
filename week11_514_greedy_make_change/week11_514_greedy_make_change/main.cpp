//
//  main.cpp
//  week11_514_greedy_make_change
//
//  Created by Xintong Qi on 23/3/2022.
//

#include <iostream>

using namespace std;

int main() {
    int x,y;
    while (cin>>x>>y) {

        while(true){
            
            // Bert
            if (x>=2) {
                if (y<2) {
                    cout<<"Kengood"<<endl;
                    break;
                }else{
                    x-=2;
                    y-=2;
                }
            }else if(x==1){
                if (y<12) {
                    cout<<"Kengood"<<endl;
                    break;
                }else{
                    x-=1;
                    y-=12;
                }
            }else{
                if (y<22) {
                    cout<<"Kengood"<<endl;
                    break;
                }else{
                    y-=22;
                }
            }
//            printf("After Bert x=%d y=%d\n", x,y);
            
            // Kengood
            if (y>=22) {
                y-=22;
            }else if (y>=12) {
                if (x<1) {
                    cout<<"Bert"<<endl;
                    break;
                }else{
                    y-=12;
                    x-=1;
                }
            }else if (y>=2){
                if (x<2) {
                    cout<<"Bert"<<endl;
                    break;
                }else{
                    y-=2;
                    x-=2;
                }
            }else{
                cout<<"Bert"<<endl;
                break;
            }
            
//            printf("After Kengood x=%d y=%d\n", x,y);
        }
    }
    return 0;
}
