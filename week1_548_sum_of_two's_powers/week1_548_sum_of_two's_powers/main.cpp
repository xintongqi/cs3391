//
//  main.cpp
//  week1_548_sum_of_two's_powers
//
//  Created by Xintong Qi on 26/1/2022.
//

#include <iostream>
#include <cmath>

using namespace std;

int get_different_bit(long long int num1, long long int num2){ // find the higest different bits
    long long int n=num1^num2;
    
//    printf("xor result is %lld \n", n);
    
    if (n == 0)
            return 0;
         
    int r=0;
    while (n >>= 1) {
        r++;
    }
    
//    printf("highest bit is %d \n", r);
    
    return r;
}

long long int construct_num(int bit){ // construct a binary number for OR operation
    if (bit==0) {
        return 0;
    }
    
    long long int num=(long long int)pow(2, bit+1)-1;
    
//    printf("constructed num is %lld \n", num);
    return num;
}

int main()
{
    long long int num1;
    long long int num2;
    
    while(cin>>num1>>num2){

        int diff_bit = get_different_bit(num1, num2);
        long long int constructed_num = construct_num(diff_bit);
        cout<<(num2|constructed_num)<<endl;
    }
    return 0;
}
