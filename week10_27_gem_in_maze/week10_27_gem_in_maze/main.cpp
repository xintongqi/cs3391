//
//  main.cpp
//  week10_27_gems_in_maze
//
//  Created by Xintong Qi on 17/3/2022.
//

#include <iostream>
#include <set>

using namespace std;

int connect(short a, short b, short c, short input, short ceil) {
    int val=0;
    if (a==0){
        val=b*input+c;
    }else if(b==0){
        val=a*input*input+c;
    }else if(c==0){
        val=(a*input+b)*input;
    }else{
        val=a*input*input+b*input+c;
    }
    
    return val >= ceil ? val % ceil : val;
}

//bool isVisited(short* arr, short size, short value){
//    for (int i=0; i<size; i++) {
//        if(arr[i]==value){
//            return true;
//        }
//    }
//    return false;
//}

int main() {
    int test_cases;
    cin>>test_cases;
    for (int i=0; i<test_cases; i++) {
        short a,b,c;
        cin>>a>>b>>c;
        short size;
        cin>>size;
        int* maze = new int[size];
        for (int j=0; j<size; j++) {
            
            maze[j]=connect(a,b,c,j,size);
            
//            printf("room %d is connected to room %d\n", j, maze[j]);
        }
        
        short result=0;
        
        for (int j=0; j<size; j++) {
            set<short> tmp_set;
            short visited=j;
            short tmp_result=0;
            
            while (tmp_set.insert(visited).second) {
                visited=maze[visited];
                tmp_result++;
            }
            
            if (tmp_result>result) {
                result=tmp_result;
            }
            
            
        }
        
        cout<<result<<endl;
        
        delete[] maze;
    }
    
    return 0;
}

