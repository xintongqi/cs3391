//
//  main.cpp
//  week13_439_dp_max_num_from_string
//
//  Created by Xintong Qi on 3/4/2022.
//

#include <iostream>
#include <climits>
#include <string>
#include <cstring>

using namespace std;

char s[100005];
long long max_value[205];

long long solve(int length){
    if (max_value[length] != -1)
        return max_value[length];
    
    long long &result = max_value[length];
    
    for (int i = 1; i<11; i++){
        
        long long tmp = 0;
        for (int j = length-i+1; j <= length; j++)
            tmp = tmp*10 + s[j]-'0';
        if(tmp>INT_MAX){
            tmp=-1;
        }
        result = max(result, solve(length - i) +tmp);
    }
        
    return result;
}

int main(){
    int N;
    cin>>N;
    while(N--){
        scanf("%s", s + 1);
        s[0] = '0';
//        cout<<s<<endl;
        
        memset(max_value, -1, sizeof(max_value));
        
        cout<<solve(strlen(s) - 1)<<endl;;
    }
    return 0;
}
