//
//  main.cpp
//  week10_228_nth_digit_of_numbers
//
//  Created by Xintong Qi on 20/3/2022.
//

#include <iostream>

using namespace std;

int main() {
    int n;
    int test_cases=0;
    while (cin>>n) {
        test_cases++;
        if (n<10) {
            printf("Case %d : %d\n", test_cases, n);
        }else if(n<190){
            double value=(double)(n-10)/2;
            string value_str=to_string((int)value+10);
            int index=(int)(value*2)%2;
            printf("Case %d : %c\n", test_cases, value_str.at(index));
        }else if(n<2890){
            double value=(double)(n-190)/3;
            string value_str=to_string((int)value+100);
            int index=(int)(value*3)%3;
            printf("Case %d : %c\n", test_cases, value_str.at(index));
        }else if(n<38890){
            double value=(double)(n-2890)/4;
            string value_str=to_string((int)value+1000);
            int index=(int)(value*4)%4;
            printf("Case %d : %c\n", test_cases, value_str.at(index));
        }else if(n<488890){
            double value=(double)(n-38890)/5;
            string value_str=to_string((int)value+10000);
            int index=(int)(value*5)%5;
            printf("Case %d : %c\n", test_cases, value_str.at(index));
        }else if(n<5888890){
            double value=(double)(n-488890)/6;
            string value_str=to_string((int)value+100000);
            int index=(int)(value*6)%6;
            printf("Case %d : %c\n", test_cases, value_str.at(index));
        }else if(n<68888890){
            double value=(double)(n-5888890)/7;
            string value_str=to_string((int)value+1000000);
            int index=(int)(value*7)%7;
            printf("Case %d : %c\n", test_cases, value_str.at(index));
        }else{
            double value=(double)(n-68888890)/8;
            string value_str=to_string((int)value+10000000);
            int index=(int)(value*8)%8;
            printf("Case %d : %c\n", test_cases, value_str.at(index));
        }
    }
    
    return 0;
}
