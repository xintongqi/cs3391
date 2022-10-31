//
//  main.cpp
//  fun_63_substitute_words_in_string
//
//  Created by Xintong Qi on 28/4/2022.
//

#include <iostream>
#include <string>

using namespace std;

int replaceAll(string& str, const string& from, const string& to) {
    int result=0;
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
        result++;
    }
    return result;
}

int main() {
    int n;
    cin>>n;
    cin.ignore(256, '\n');
    int ctr=0;
    while (n--) {
        ctr++;
        string sentense;
        getline(cin, sentense);
        int result=replaceAll(sentense, "France", "Bacon");
        printf("Sentence #%d: %d\n", ctr, result);
    }
    
    return 0;
}
