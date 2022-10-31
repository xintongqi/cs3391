//
//  main.cpp
//  week12_392_string_php_trim
//
//  Created by Xintong Qi on 28/3/2022.
//

#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

string& rtrim(string& s, char* t)
{
    s.erase(s.find_last_not_of(t) + 1);
    return s;
}

string& ltrim(string& s, char* t)
{
    s.erase(0, s.find_first_not_of(t));
    return s;
}

string& trim(string& s, char* t)
{
    return ltrim(rtrim(s, t), t);
}

vector<string> split_string(string& s)
{
    vector<std::string> splitted;
    bool flag = false;
    splitted.push_back("");
    for(int i=0; i<s.size(); ++i)
    {
        if(s[i]=='\"')
        {
            flag = flag? false : true;
            continue;
        }

        if(s[i]==' ' && !flag)
            splitted.push_back("");
        else
            splitted[splitted.size()-1] += s[i];
    }
    return splitted;
}

int main() {
    int test_cases;
    cin>>test_cases;
    cin.ignore(256, '\n');
    cin.clear();
    for (int i=0; i<test_cases; i++) {
        string line;
        getline(cin,line);
        
        vector<string> tokens=split_string(line);
        
//        for(auto a: tokens){
//            cout<<a<<endl;
//        }
        
        char* pattern = new char[128];
        strcpy(pattern, tokens[1].c_str());
        
        string result=trim(tokens[0], pattern);
        cout<<"\""<<result<<"\""<<endl;
        
        delete [] pattern;
        
        
//        original.erase(remove(original.begin(), original.end(), '\"' ),original.end());
//        cout<<original<<endl;
//
//        string pattern;
//        getline(cin,pattern);
//        pattern.erase(remove(pattern.begin(), pattern.end(), '\"'), pattern.end());
//        cout<<pattern<<endl;
//
//        char* pat = new char[128];
//        strcpy(pat, pattern.c_str());
//        cout<<pat<<endl;
//
//        string result=trim(original, pat);
//        cout<<"\""<<result<<"\""<<endl;
        
//        delete [] pat;
    }
    return 0;
}
