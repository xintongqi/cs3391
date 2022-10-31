//
//  main.cpp
//  week10_69_recurring_decimals
//
//  Created by Xintong Qi on 19/3/2022.
//

#include <iostream>
#include <algorithm>

using namespace std;

int findDiff(int num, int l){
    string smallest=to_string(num);
    sort(smallest.begin(), smallest.end());
    string largest=smallest;
    reverse(largest.begin(), largest.end());
    for(int i=0;i<l-smallest.length();i++){
        largest.append("0");
    }
    int small=stoi(smallest);
    int large=stoi(largest);
    return large-small;
}

int recur(int* arr, int num){
    for (int i=0; i<20; i++) {
        if (arr[i]==num) {
            return i;
        }
    }
    return -1;
}

int main() {
    int num;
    short l;
    while (cin>>num>>l) {
        if (num==0 && l==0) {
            break;
        }
        
        int* arr=new int[20];
        for (int i=0; i<20; i++) {
            arr[i]=-1;
        }
        
        int tmp=num;
        bool notFound=true;
        int now_idx=0;
        int tmp_idx=0;
        
        while (notFound) {
            arr[now_idx]=tmp;
            tmp=findDiff(tmp,l);
            tmp_idx=recur(arr, tmp);
            now_idx++;
            if (tmp_idx!=-1) {
                notFound=false;
            }
            
            
//            for (int k=0; k<20; k++) {
//                printf("%d ", arr[k]);
//            }
            
//            printf("\n");
        }
        
        printf("%d %d %d\n", tmp_idx, tmp, now_idx-tmp_idx);
        
        delete[] arr;
    }
    
    
    return 0;
}
