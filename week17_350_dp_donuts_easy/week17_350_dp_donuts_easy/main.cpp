//
//  main.cpp
//  week17_350_dp_donuts_easy
//
//  Created by Xintong Qi on 25/4/2022.
//

#include <iostream>

using namespace std;

int main() {
    int test_cases;
    cin>>test_cases;
    while (test_cases--) {
        int row, column;
        cin>>row;
        string tmp;
        cin>>tmp;
        column=(int)tmp.size();
        
        char** matrix = new char*[row];
        for (int i=0; i<row; i++) {
            matrix[i]=new char[column];
        }
        
        strcpy(matrix[0], tmp.c_str());
        
        for (int i=1; i<row; i++) {
            for (int j=0; j<column; j++) {
                cin>>matrix[i][j];
            }
        }
        
        
        
        
        
        for (int i=0; i<row; i++) {
            delete [] matrix[i];
        }
        delete [] matrix;
    }
    
    return 0;
}
