//
//  main.cpp
//  week14_629_longest_repeated_nonoverlapping_substring
//
//  Created by Xintong Qi on 4/4/2022.
//

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main() {
    string str;
    while (cin>>str) {
        int str_len = (int)str.length();
        int** dp_table = new int*[str_len+1];
        for (int i=0; i<str_len+1; i++) {
            dp_table[i]=new int[str_len+1];
        }
        
        for (int i=0; i<str_len+1; i++) {
            for (int j=0; j<str_len+1; j++) {
                dp_table[i][j]=0;
            }
        }
     
        string result;
        int res_len=0;
        int end_index=0;
        
        for (int i=1; i<=str_len; i++)
        {
            for (int j=i+1; j<=str_len; j++)
            {
                if (str[i-1]==str[j-1] && dp_table[i-1][j-1]<(j-i)){
                    dp_table[i][j] = dp_table[i-1][j-1]+1;
                    if (dp_table[i][j] > res_len)
                    {
                        res_len = dp_table[i][j];
                        end_index = max(i, end_index);
                    } else if (dp_table[i][j]==res_len){
                        bool endOfCompare=false;
                        int digit=0;
                        while (!endOfCompare && digit<res_len) {
                            if(str[end_index-res_len+digit]>str[max(i,end_index)-res_len+digit]) {
                                endOfCompare=true;
                                end_index = max(i, end_index);
                            }
                            digit++;
                        }
                    }
                }else{
                    dp_table[i][j] = 0;
                }
            }
        }
        
        if (res_len>0){
            for (int i=end_index-res_len; i<end_index; i++){
                result.push_back(str[i]);
            }
            cout<<result<<endl;
        }else{
            cout<<"No LRS is found."<<endl;
        }
        
        for (int i=0; i<str_len+1; i++) {
            delete[] dp_table[i];
        }
        delete[] dp_table;
    }
    
    return 0;
}
