//
//  main.cpp
//  final_q1_stick_length
//
//  Created by Xintong Qi on 29/4/2022.
//

#include <iostream>

using namespace std;

int main() {
    int test_cases;
    cin>>test_cases;
    while (test_cases--) {
        int one_num, two_num;
        cin>>one_num>>two_num;
        
        int result;
        if (one_num) {
            result=two_num*2+one_num+1;
        }else{
            result=1;
        }
        
        cout<<result<<endl;
    }
    
    return 0;
}
