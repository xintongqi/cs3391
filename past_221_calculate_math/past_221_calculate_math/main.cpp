//
//  main.cpp
//  past_221_calculate_math
//
//  Created by Xintong Qi on 28/4/2022.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <cmath>

using namespace std;

//int myPow(int x, unsigned int p)
//{
//  if (p == 0) return 1;
//  if (p == 1) return x;
//  
//  int tmp = myPow(x, p/2);
//  if (p%2 == 0) return tmp * tmp;
//  else return x * tmp * tmp;
//}

int main() {
    
    
    long long int a, b;
    char oper;
    while (cin>>a>>oper>>b) {
        if (oper=='+') {
            cout<<a+b<<endl;
        } else if (oper=='-'){
            cout<<a-b<<endl;
        }
    }
    
    
//    string str;
//    while (getline(cin, str)) {
//        int result;
//        stack<char> mystack;
//        int a,b;
//        bool plus;
//        for (int i=0; i<str.length(); i++) {
//            char c=str.at(i);
//            if (c=='+') {
//                int ctr=0;
//                int value=0;
//                while (!mystack.empty()) {
//                    int power=myPow(10, ctr);
//                    int digit=mystack.top()-'0';
//                    value+=digit*power;
//                    mystack.pop();
//                    ctr++;
//                }
//                a=value;
//                plus=true;
//            }else if (c=='-'){
//                int ctr=0;
//                int value=0;
//                while (!mystack.empty()) {
//                    int power=myPow(10, ctr);
//                    int digit=mystack.top()-'0';
//                    value+=digit*power;
//                    mystack.pop();
//                    ctr++;
//                }
//                a=value;
//                plus=false;
//            }else if (c<='9' && c>='0'){
//                mystack.push(c);
//            }else{
//                continue;
//            }
//        }
//
//        int ctr=0;
//        int value=0;
//        while (!mystack.empty()) {
//            int power=myPow(10, ctr);
//            int digit=mystack.top()-'0';
//            value+=digit*power;
//            mystack.pop();
//            ctr++;
//        }
//        b=value;
//
//        if (plus) {
//            cout<<a+b<<endl;
//        }else{
//            cout<<a-b<<endl;
//        }
        
//        string::iterator end_pos = remove(str.begin(), str.end(), ' ');
//        str.erase(end_pos, str.end());
//        str.erase(std::remove(str.begin(), str.end(), '\n'), str.end());
//        int a,b;
//        size_t pos = 0;
//        if ((pos=str.find("+")) != std::string::npos) {
//            string a_str;
//            a_str = str.substr(0, pos);
//            a=stoi(a_str);
//            str.erase(0, pos+1);
//            b=stoi(str);
//            result=a+b;
//        }else{
//            pos=str.find("-");
//            string a_str;
//            a_str = str.substr(0, pos);
//            a=stoi(a_str);
//            str.erase(0, pos+1);
//            b=stoi(str);
//            result=a-b;
//        }
//        cout<<result<<endl;
//    }
    
    return 0;
}
