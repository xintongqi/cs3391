//
//  main.cpp
//  quiz2_pair_students
//
//  Created by Xintong Qi on 8/4/2022.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    
    short N;
    while (cin>>N) {
//        vector<int> students;
//        for (int i=0; i<N; i++) {
//            int tmp;
//            cin>>tmp;
//            students.push_back(tmp);
//        }
//
//        stable_sort(students.begin(), students.end());
        int* students = new int[N];
        for (int i=0; i<N; i++) {
            cin>>students[i];
        }
//        int n = sizeof(students) / sizeof(students[0]);
        
        stable_sort(students, students+N);
        
//        for (int i=0; i<N; i++) {
//            cout<<students[i]<<" ";
//        }
//        cout<<endl;
        
        int halfN = (int)(N/2);
        
        double* groups = new double[halfN];
        
        for (int i=0; i<halfN; i++) {
            groups[i]=students[i]+students[N-1-i];
        }
        
        stable_sort(groups, groups+halfN);
        
//        for (int i=0; i<halfN; i++) {
//            cout<<groups[i]<<" ";
//        }
//        cout<<endl;
        
        cout<<groups[halfN-1]-groups[0]<<endl;
        
        delete[] students;
        delete[] groups;
    }
    
    return 0;
}
