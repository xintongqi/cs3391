//
//  main.cpp
//  week1_12_inversions
//
//  Created by Xintong Qi on 22/1/2022.
//

#include <iostream>
#include <map>
using namespace std;

int merge(int arr[], int temp[], int left, int mid, int right) {
   int i, j, k;
   int count = 0;
   i = left;
   j = mid;
   k = left;
   while ((i <= mid - 1) && (j <= right)) {
      if (arr[i] <= arr[j]){
      temp[k++] = arr[i++];
      } else {
         temp[k++] = arr[j++];
         count += (mid - i);
      }
   }
   while (i <= mid - 1)
      temp[k++] = arr[i++];
   while (j <= right)
      temp[k++] = arr[j++];
   for (i=left; i <= right; i++)
      arr[i] = temp[i];
   return count;
}

int mergeSort(int arr[], int temp[], int left, int right){
   int mid, count = 0;
   if (right > left) {
      mid = (right + left)/2;
      count = mergeSort(arr, temp, left, mid);
      count += mergeSort(arr, temp, mid+1, right);
      count += merge(arr, temp, left, mid+1, right);
   }
   return count;
}

int count_inversions(int* arr, int n){
    int *temp = new int[n];
    return mergeSort(arr, temp, 0, n-1);
}

int main(){
    
    int test_cases;
    cin>>test_cases;
    for(int j = 0; j < test_cases; j++)
    {
        int str_length;
        cin>>str_length;

        // create the out_of_order array for counting inversions
        string *yoda = new string[str_length];
        for (int i = 0; i < str_length; i++)
        {
            string token;
            cin>>token;
            yoda[i]=token;
        }
        
        // construct a map for lookup based on the original string
        map<string,int> original;
        for (int i = 0; i < str_length; i++)
        {
            string token;
            cin>>token;
            original.insert(make_pair(token, i));
        }
        
        // construct the int list
        int *input = new int[str_length];
        for (int i = 0; i < str_length; i++)
        {
            input[i]=original.at(yoda[i]);
        }
        
        // count inversions
        int result = count_inversions(input, str_length);
        cout<<result<<endl;
        delete[] yoda;
    }
    

    return 0;
}
