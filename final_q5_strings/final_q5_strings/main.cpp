//
//  main.cpp
//  final_q5_strings
//
//  Created by Xintong Qi on 29/4/2022.
//

#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin>>n;
    
    string* strings=new string[n];
//    int* types=new int[n];
    for (int i=0; i<n; i++) {
        cin>>strings[i];
//        types[i]=-1;
    }
    
    
    int s=(int)strings[0].size();
    
    long long int result;
    int sort_num=0, magic_num=0;
//    int ctr=0;
    
    for (int i=0; i<n-1; i++) {
        for (int j=i+1; j<n; j++) { // choose two strings
            if (strings[i]==strings[j]) {
                continue;
            }
            
            int* count1=new int[26];
            int* count2=new int[26];
            bool array_empty=true;
            bool unmatched=false;
            
            for (int k=0; k<26; k++) {
                count1[k]=count2[k]=0;
            }
            
            
            bool sort1=true;
            bool sort2=true;
            for (int k=0; k<s; k++) {
                
                if (unmatched) {
                    break;
                }
                
                char c1=strings[i].at(k);
                char c2=strings[j].at(k);
                
                if (k==s-1 && c1!=c2) {
                    count1[c1-'a']++;
                    count2[c2-'a']++;
                    
                    for (int m=0; m<26; m++) {
                        if (count1[m]!=count2[m]) {
                            unmatched=true;
                            break;
                        }else{
                            count1[m]=count2[m]=0;
                        }
                    }
                    array_empty=true;
                    if (!unmatched) {
                        if (!sort1) {
                            sort_num++;
                        }
                        if (!sort2) {
                            sort_num++;
                        }
                        
                        sort1=true;
                        sort2=true;
                    }
                    
                    break;
                }
                
                if (c1==c2) {
                    if (array_empty) {
                        continue;
                    }else{
//                        cout<<strings[i]<<endl;;
//                        for (int m=0; m<26; m++) {
//                            cout<<count1[m]<<" ";
//                        }
//                        cout<<endl;
//                        cout<<strings[j]<<endl;
//                        for (int m=0; m<26; m++) {
//                            cout<<count2[m]<<" ";
//                        }
//                        cout<<endl;
                        
                        for (int m=0; m<26; m++) {
                            if (count1[m]!=count2[m]) {
                                unmatched=true;
                                break;
                            }else{
                                count1[m]=count2[m]=0;
                            }
                        }
                        array_empty=true;
                        if (!unmatched) {
                            if (!sort1) {
                                sort_num++;
                            }
                            if (!sort2) {
                                sort_num++;
                            }
                            
                            sort1=true;
                            sort2=true;
                        }
                    }
                }else{
                    array_empty=false;
                    
                    count1[c1-'a']++;
                    count2[c2-'a']++;
                    
                    if (k>0 && c1<strings[i].at(k-1)) {
                        sort1=false;
                    }
                    if (k>0 && c1<strings[j].at(k-1)) {
                        sort2=false;
                    }
                }
            }
            delete [] count1;
            delete [] count2;
            
            if (unmatched) {
                magic_num++;
            }
            
            cout<<strings[i]<<" "<<strings[j]<<" "<<magic_num<<" "<<sort_num<<endl;
        }
    }
    
    result=magic_num*1337+sort_num;
    
    cout<<result<<endl;
    
    delete [] strings;
//    delete [] types;
    return 0;
}
