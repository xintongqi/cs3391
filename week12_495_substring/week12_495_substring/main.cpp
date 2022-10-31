//
//  main.cpp
//  week12_495_substring
//
//  Created by Xintong Qi on 28/3/2022.
//

#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

int main(){
    int test_cases;
    cin>>test_cases;
    for (int i=0; i<test_cases; i++) {
        char str[1000001];
        cin>>str;
        int num_of_checks;
        cin>>num_of_checks;
        for (int j=0; j<num_of_checks; j++) {
            char check[1000001];
            cin>>check;
            char* occur=strstr(str, check);
            if (occur!=NULL) {
                cout<<"y"<<endl;
            }else{
                cout<<"n"<<endl;
            }
        }
    }
    return 0;

}
