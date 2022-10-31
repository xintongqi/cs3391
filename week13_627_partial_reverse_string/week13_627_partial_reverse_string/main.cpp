//
//  main.cpp
//  week13_627_partial_reverse_string
//
//  Created by Xintong Qi on 1/4/2022.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <fstream>

using namespace std;

struct Input{
    string s;
    bool paired;
    
    Input(string str, bool sta){
        s=str;
        paired=sta;
    }
};

int main() {
    int N;
    while (cin>>N) {
        cin.ignore(256, '\n');
        vector<Input> strings;
        while (N--) {
            string s;
            cin>>s;
            strings.push_back(Input(s, false));
        }
        
//        ifstream myfile;
//        myfile.open("/Users/xintongqi/Codes/cs3391/week13_627_partial_reverse_string/week13_627_partial_reverse_string/input.txt");
//        string line;
//        while (getline(myfile,line)){
//            cout<<line<<endl;
//            strings.push_back(Input(line, false));
//        }
//        myfile.close();
        
        int result=0;
        
        
        
        for (auto outer=strings.begin(); outer!=strings.end(); ++outer) {
            
            if (outer->paired) { // already matched with a previous string
                result++;
                continue;
            }
            
            for (auto inner=std::next(outer); inner!=strings.end(); ++inner) {
                
                if (outer->s.size()!=inner->s.size()) { // not the same size, cannot pair
                    continue;
                }
                
                if (outer->s.size()==1) {
                    if (outer->s==inner->s) { // both length of 1
                        outer->paired=true;
                        inner->paired=true;
                        result++;
                        break;
                    }
                } else{
                    // both length >= 2
                    bool match=true;
                    string inner_copy=inner->s;
                    for (int i=0; i<outer->s.size()-1; i+=2) {
                        string tmp=outer->s.substr(i,2);
                        size_t pos=inner_copy.find(tmp);
                        if (pos!=string::npos && pos%2==0) {
                            inner_copy.erase(pos,pos+2);
                            continue;
                        }else{
                            reverse(tmp.begin(), tmp.end());
                            pos=inner_copy.find(tmp);
                            if (pos!=string::npos && pos%2==0) {
                                inner_copy.erase(pos,pos+2);
                                continue;
                            } else{
                                match=false;
                                break; // one segment missing, cannot match
                            }
                        }
                        
                    }
                    
                    if (match) {
                        outer->paired=true;
                        inner->paired=true;
                        result++;
                        break;
                    }
                }
                
                
            }
        }
        
        cout<<strings.size()-result<<endl;
    }
    return 0;
}
