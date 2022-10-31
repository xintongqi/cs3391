//
//  main.cpp
//  week1_278_average
//
//  Created by Xintong Qi on 23/1/2022.
//

#include <iostream>
#include <vector>
#include <numeric>
#include <iomanip>

using namespace std;

int main(int argc, const char * argv[]) {
    int test_cases;
    cin>>test_cases;
    
    for (int i=0; i<test_cases; i++) {
        int people;
        cin>>people;
        
        int person;
        vector<int> all_grades;
        for (int j=0; j<people; j++) {
            cin>>person;
            all_grades.push_back(person);
        }
        
        auto sum = accumulate(all_grades.begin(), all_grades.end(), 0.0);
        auto avg = sum / all_grades.size();
        int greater_than_average=0;
        
        for (int j : all_grades) {
            if(j>avg){
                greater_than_average++;
            }
        }
        
        float ratio=100*(float)greater_than_average/(float)people;
        cout << fixed;
        cout.precision(3);
        cout<<ratio<<"%"<<endl;
    }
}
