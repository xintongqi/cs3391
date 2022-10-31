//
//  main.cpp
//  week12_202_max_sum_rectangle
//
//  Created by Xintong Qi on 30/3/2022.
//

#include <iostream>
#include <climits>
#include <cstring>
using namespace std;

int kadane1d(int* temp, int N)
{
    int sum = 0, result = INT_MIN;
    bool isEnd=false;

    for (int i = 0; i < N; ++i)
    {
        sum += temp[i];
        if (sum < 0)
        {
            sum = 0;
        } else if (sum > result)
        {
            result = sum;
            isEnd=true;
        }
    }

    if (isEnd)
        return result;
    
    result = temp[0];
    
    for (int i = 1; i < N; i++)
        if (temp[i] > result)
            result = temp[i];
  
    return result;
}

int kadane2d(short** matrix, int N)
{
    int result = INT_MIN;

    int left, right, i;
    int temp[N], sum;

    for (left = 0; left < N; ++left) {
        memset(temp, 0, sizeof(temp));
        for (right = left; right < N; ++right) {

            for (i = 0; i < N; ++i)
                temp[i] += matrix[i][right];

            sum = kadane1d(temp, N);

            if (sum > result)
                result = sum;
        }
    }
    return result;
}

int main()
{
    int N;
    cin>>N;
    
    short** matrix = new short*[N];
    for (int i=0; i<N; i++) {
        matrix[i]=new short[N];
    }
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin>>matrix[i][j];
        }
    }
    
    cout<<kadane2d(matrix, N)<<endl;
    
    for (int i=0; i<N; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
