//
//  main.cpp
//  week16_556_boolean
//
//  Created by Xintong Qi on 23/4/2022.
//

#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <vector>
#include <map>
#include <bitset>
#include <algorithm>
#include <cmath>

using namespace std;

int var_num;
map<char,int> m;

int order(char c)
{
    if (c == '!')
        return 3;
    else if (c == '&')
        return 2;
    else if (c == '+')
        return 1;
    else
        return -1;
}

string toPostfix(string s)
{
 
    stack<char> mystack;
    string result;
 
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        
        if(isspace(c)){
            continue;
        } else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')){
            result += c;
            
            if (m.find(c) == m.end()){
                m.insert(make_pair(c, var_num));
                var_num++;
            }
            
        } else if (c == '('){
            mystack.push('(');
        } else if (c == ')') {
            while (mystack.top() != '(') {
                result += mystack.top();
                mystack.pop();
            }
            mystack.pop();
        } else {
            while (!mystack.empty() && order(s[i]) <= order(mystack.top())) {
                if (c == '!' && mystack.top() == '!')
                    break;
                else {
                    result += mystack.top();
                    mystack.pop();
                }
            }
            mystack.push(c);
        }
    }
    
    while (!mystack.empty()) {
        result += mystack.top();
        mystack.pop();
    }
   
    return result;
}



bool evaluatePostfix(string postfix, unsigned long long int value)
{
    stack<bool> mystack;

    string binary = bitset<100>(value).to_string();
    string binary_trimmed=binary.substr(100-var_num, var_num);
    
    for (char c: postfix)
    {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            
            mystack.push(binary_trimmed[m[c]]-'0');
            
        } else if (c == '!'){
            
            bool x = mystack.top();
            mystack.push(!x);
            
        } else {
           
            bool x = mystack.top();
            mystack.pop();
 
            bool y = mystack.top();
            mystack.pop();
 
            if (c == '&') {
                mystack.push(y & x);
            }
            else if (c == '+') {
                mystack.push(y | x);
            }
        }
    }
    
    return mystack.top();
}

int main() {
    string original;
    while (getline(cin, original)) {
        var_num=0;
        m.clear();
        
        string postfix=toPostfix(original);
        
        bool can=false;
        
        for (unsigned long long int i=0; i<pow(2,var_num); i++) {
            if (evaluatePostfix(postfix, i)) {
                cout<<"YES"<<endl;
                can=true;
                break;
            }
        }
        
        if (!can) {
            cout<<"NO"<<endl;
        }
    }
    
    return 0;
}
