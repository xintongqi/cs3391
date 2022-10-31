//
//  main.cpp
//  final_q2_max_diff
//
//  Created by Xintong Qi on 29/4/2022.
//

#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int result;

//int solve(int* arr, int n, int left, int right){
//    int mid = (right+left)/2;
//    int low=solve(arr, n, left, mid);
//    int high=solve(arr, n, mid+1, right);
//    if (high-low>result) {
//        result=high-low;
//    }
//    return result;
//}

int main() {
    int month_num;
    while (cin>>month_num) {
        int* months = new int[month_num];
        for (int i=0; i<month_num; i++) {
            cin>>months[i];
        }
        
        result=-INT_MAX;
        
        for (int i=0; i<month_num-1; i++) {
            long int high=0;
            for (int j=i+1; j<month_num; j++) {
                if (months[j]<months[i]) {
                    continue;
                }
                if (months[j]>high) {
                    high=months[j];
                }
            }
            
            if (high-months[i]>result) {
                result=high-months[i];
            }
        }
        
        if (result>=0) {
            cout<<result<<endl;
        }else{
            cout<<"QUIT"<<endl;
        }
        
        delete [] months;
    }
    
    return 0;
}





//void merge(int* arr, int* temp, int left, int mid, int right) {
//   int i, j, k;
//   i = left;
//   j = mid;
//   k = left;
//
//    int left_high=-INT_MAX, left_low=INT_MAX, right_high=-INT_MAX, right_low=INT_MAX;
//    int left_diff, right_diff, left_right_diff;
//    while (i<mid) {
//        if (arr[i]>left_high) {
//            left_high=arr[i];
//        }else if (arr[i]<left_low){
//            left_low=arr[i];
//        }
//        i++;
//    }
//
//    left_diff=left_high-left_low;
//
//    while (j<=right) {
//        if (arr[j]>right_high) {
//            right_high=arr[j];
//        }else if (arr[j]<right_low){
//            right_low=arr[j];
//        }
//        j++;
//    }
//
//    right_diff=right_high-right_low;
//
//    left_right_diff=right_high-left_low;
//
////    int result=max(left_diff, right_diff, left_right_diff);
//
//
//    if (left_diff>right_diff && left_diff>left_right_diff) {
//        high=left_high;
//        low=left_low;
//    } else if(right_diff>left_diff && right_diff>left_right_diff){
//        high=right_high;
//        low=right_low;
//    } else{
//        high=right_high;
//        low=left_low;
//    }
//
//}
//
//void mergeSort(int* arr, int* temp, int left, int right){
//   int mid;
//   if (right > left) {
//       mid = (right+left)/2;
//       mergeSort(arr, temp, left, mid);
//       mergeSort(arr, temp, mid+1, right);
//       merge(arr, temp, left, mid+1, right);
//   }
//}
