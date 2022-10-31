//
//  main.cpp
//  week16_617_dp_candy_matching
//
//  Created by Xintong Qi on 24/4/2022.
//

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int num;

string remove_pairs(string s){
    stack<char> mystack;
    
    int i = 0;
    while (i < s.length()) {
        if (mystack.empty() || s[i] != mystack.top()) {
            mystack.push(s[i]);
            i++;
        } else {
            mystack.pop();
            i++;
            num++;
        }
    }
    
    string without_pairs = "";
    
    while (!mystack.empty()) {
        without_pairs = mystack.top()+without_pairs;
        mystack.pop();
    }
    
    return without_pairs;
}


string remove_ends(string s){
    if (s.length()<3 || s[0]!=s[s.length()-1]) {
        return s;
    }
    num++;
    return remove_ends(s.substr(1, s.size()-2));
}

int main() {
    string original;
    while (cin>>original) {
        num=0;
        
        if (original.length()<2) {
            cout<<num<<endl;
            continue;
        }
        
        string without_pairs = remove_pairs(original);
        
//        cout<<without_pairs<<" "<<num<<endl;
        
        if (without_pairs.length()<3) {
            cout<<num<<endl;
            continue;
        }
        
        string without_ends = remove_ends(without_pairs);
        
//        cout<<without_ends<<" "<<num<<endl;
        
        if (without_ends.length()<3) {
            cout<<num<<endl;
            continue;
        }
            
        num+=(without_ends.length()/2-1);
        cout<<num<<endl;
    }
    
    return 0;
}
