//
//  main.cpp
//  week2_354_checksum
//
//  Created by Xintong Qi on 23/1/2022.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int doubleDigit(int digit){
    int result=0;
    digit*=2;
    if (digit>=10) {
        result=digit/10+digit%10;
    }else{
        result=digit;
    }
    return result;
}

int getSegmentChecksum(string s){
    int checkSum=s.at(1)-'0'+s.at(3)-'0';
    checkSum+=doubleDigit(s.at(0)-'0');
    checkSum+=doubleDigit(s.at(2)-'0');
    return checkSum;
}

int main(int argc, const char * argv[]) {
    int test_cases;
    cin>>test_cases;
    
    for (int i=0; i<test_cases; i++) {
        // get the input
        vector<string> segments;
        for (int j=0; j<4; j++) {
            string segment;
            cin>>segment;
            segments.push_back(segment);
        }
        
        // get the checksum of each segment
        int checksum=0;
        for (string s : segments) {
            checksum+=getSegmentChecksum(s);
        }
        
        // print the output
        if (checksum%10==0) {
            cout<<"Valid"<<endl;
        }else{
            cout<<"Invalid"<<endl;
        }
    }
}
