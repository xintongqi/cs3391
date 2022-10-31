//
//  main.cpp
//  week10_65_mack_zack
//
//  Created by Xintong Qi on 19/3/2022.
//

#include <iostream>
#include <math.h>
//#include <iomanip>

using namespace std;

int main() {
    double pi=3.141592653589793;
//    cout<<setprecision (19)<< pi<<endl;
    
//    double x=2147483646.5;
//    cout<<round(x)<<endl;
//    cout<<setprecision(0)<<round(x)<<endl;
//    cout<<to_string((int)round(x))<<endl;
    
    int test_cases;
    cin>>test_cases;
    
    for (int i=0; i<test_cases; i++) {
        short l,r1,r2,lap1,lap2;
        cin>>l>>r1>>r2>>lap1>>lap2;
        
        int straight=(lap2-lap1)*2*l;
        int tmp=r2*lap2-r1*lap1;
        double circle=2*pi*tmp;
        double dis=straight+circle;
        if(dis<0){
            printf("Track #%d: Drats!\n",i+1);
        }else{
            cout<<"Track #" << i+1 << ": I've run "<< to_string((int)round(dis)) <<" more meters than Mack!!!"<<endl;
        }
    }
    return 0;
}
