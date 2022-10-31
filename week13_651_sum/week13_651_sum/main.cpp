//
//  main.cpp
//  week13_651_sum
//
//  Created by Xintong Qi on 3/4/2022.
//

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    
    int T;
    cin>>T;
    while (T--) {
        int N;
        cin>>N;
        long long allA[1010],allB[1010];
        for (int i=0; i<N; i++) {
            cin>>allA[i];
        }
        for (int i=0; i<N; i++) {
            cin>>allB[i];
        }
        
        long long sumA = 0, sumB = 0;
        for (int i=0; i<N; i++) {
            sumA+=allA[i];
            sumB+=allB[i];
        }
        
        long long result = 0;
        for (int i=0; i<N; i++) {
            long long countA=0, countB=0;
            for (int j=0; j<N; j++) {
                if(allA[i]*allB[j]>allA[j]*allB[i] || (allA[i]*allB[j]==allA[j]*allB[i] && allA[i]*allA[j]+allB[i]*allB[j] > 0)){
                    countA += allA[j];
                    countB += allB[j];
                }
            }
            result = max(result, countA*countA + countB*countB);
            countA = sumA-countA;
            countB = sumB-countB;
            result = max(result, countA*countA + countB*countB);
        }
        
        cout<<result<<endl;
    }
    return 0;
}
