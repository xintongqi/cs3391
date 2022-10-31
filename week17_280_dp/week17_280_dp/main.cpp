//
//  main.cpp
//  week17_280_dp
//
//  Created by Xintong Qi on 25/4/2022.
//

#include <climits>
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        
        int* a = new int[n];
        int* left = new int[n];
        int* right = new int[n];
        int* dp = new int [n];
        
        for (int i=0; i<n; i++) {
            scanf("%d", &a[i]);
            left[i]=0;
            right[i]=0;
            dp[i]=0;
        }
        
        int result = 0;
        left[0] = a[0];
        
        for (int i=1; i<n; i++) {
            left[i] = max(left[i-1]+a[i], a[i]);
        }
        
        dp[n-1] = right[n-1] = a[n-1];
        
        for (int i=n-2; i>=0; i--){
            right[i] = max(right[i+1]+a[i], a[i]);
            dp[i] = max(dp[i+1], right[i]);
        }
        
        result = -INT_MAX;
        
        for (int i=0; i<n-1; i++) {
            result = max(result, left[i]+dp[i+1]);
        }
        
        printf("%d\n", result);
        
        delete [] a;
        delete [] left;
        delete [] right;
        delete [] dp;
    }
    return 0;
}


//    int test_cases;
//    scanf("%d",&test_cases);
//    while(test_cases--){
//        int digit_num;
//        scanf("%d",&digit_num);
//
//        int* digits = new int[50010];
//
//        int** index = new int*[50010];
//        int** dp = new int*[50010];
//        for (int i=0; i<50010; i++) {
//            index[i]=new int[3];
//            dp[i]=new int[3];
//        }
//
//        for(int i=1; i<=digit_num; i++){
//            scanf("%d",&digits[i]);
//        }
//
//        for(int i=0; i<digit_num; i++){
//            for(int j=1; j<3; j++){
//                index[i][j]=-INT_MAX;
//                dp[i][j]=-INT_MAX;
//            }
//        }
//
//        index[1][1]=dp[1][1]=digits[1];
//
//        for(int i=2;i<=digit_num;i++){
//            for(int j=1;j<3;j++){
//                index[i][j]=max(index[i-1][j]+digits[i], dp[i-1][j-1]+digits[i]);
//                dp[i][j]=max(index[i][j], dp[i-1][j]);
//            }
//        }
//
//        printf("%d\n",dp[digit_num][2]);
//
//        delete [] digits;
//        for (int i=0; i<50010; i++) {
//            delete [] index[i];
//            delete [] dp[i];
//        }
//        delete [] index;
//        delete [] dp;
//    }
//    return 0;

