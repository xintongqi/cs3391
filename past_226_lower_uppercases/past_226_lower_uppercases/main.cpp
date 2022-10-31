//
//  main.cpp
//  past_226_lower_uppercases
//
//  Created by Xintong Qi on 28/4/2022.
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s;
    while (getline(cin, s)) {
        string result;
        for (int i=0; i<s.size(); i++) {
            char c=s.at(i);
            if (c<='z' && c>='a') { //lowercase
                c=c-'a'+'A';
            } else if (c<='Z' && c>='A') { //uppercase
                c=c-'A'+'a';
            }
            result+=c;
        }
        
        reverse(result.begin(), result.end());
        cout<<result<<endl;
    }
    return 0;
}
