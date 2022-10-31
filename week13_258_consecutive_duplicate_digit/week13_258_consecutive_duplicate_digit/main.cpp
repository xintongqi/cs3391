//
//  main.cpp
//  week13_258_consecutive_duplicate_digit
//
//  Created by Xintong Qi on 1/4/2022.
//

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>

using namespace std;

bool hasDuplicate(string s){
    bool hasDuplicate=false;
    char tmp='x';
    
    for (char& c: s) {
        if (tmp==c) {
            hasDuplicate=true;
        }
        tmp=c;
    }
    return hasDuplicate;
}

string findSmallest(string s){
    char tmp='x';
    string result="";
    size_t pos=0;
    
    // before the duplicate, unchanged
    for (char& c: s) {
        if (tmp==c) {
            tmp=c;
            break;
        }
        tmp=c;
        result+=c;
        pos++;
    }
    
    // duplicate=>duplicate+1
    if (tmp-'0'==9) {
        int index=s.length()-static_cast<int>(pos)-1;
        char *end;
        long long unsigned int value=strtoull(s.c_str(),&end,10)+(long long unsigned int)pow(10, index);
        result=findSmallest(to_string(value));
    }else if (isdigit(tmp)){
        tmp++;
        result+=tmp;
        
        // append 0,1,0,1...until length
        s.erase(0,pos+1);
        for (int i=0; i<s.length(); i++) {
            if (i%2) { // i is even
                result+="1";
            }else{ // i is odd
                result+="0";
            }
        }
    }else{ // no duplicate in string
        return result;
    }
    
    return result;
}

int main() {
    string s;
    while (cin>>s) {
        if (hasDuplicate(s)) {
            cout<<findSmallest(s)<<endl;
            continue;
        }else{
            char *end;
            unsigned long long int value = strtoull(s.c_str(),&end,10);
            value++;
            s=to_string(value);
            if (!hasDuplicate(s)) {
                cout<<value<<endl;
                continue;
            }else{
                cout<<findSmallest(s)<<endl;
                continue;
            }
        }
    }
    return 0;
}
