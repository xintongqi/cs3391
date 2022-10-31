//
//  main.cpp
//  week11_386_rewrite_math_calculation
//
//  Created by Xintong Qi on 23/3/2022.
//

#include <iostream>
#include <vector>

using namespace std;

int fast_mod(int input, int ceil) {
    return input >= ceil ? input % ceil : input;
}

int modular_exponential(int num_a, int num_k, int num_n)
{
    int result = 1;
    num_a = num_a % num_n;
  
    if (num_a == 0) return 0;
 
    while (num_k > 0)
    {
        if (num_k & 1)
            result = (result*num_a) % num_n;
        num_k = num_k>>1;
        num_a = (num_a*num_a) % num_n;
    }
    return result;
}

int main(){
    
    int a , k , n , result;
     while(scanf("%d%d%d" , &a , &k , &n)!=EOF ){

         if (n&(n-1)) { // n is NOT a power of 2
             result=modular_exponential(a, k, n);
         }else{ // n is a power of 2
             a=a&(n-1);
             result=1;
             
             while (k--) {
                 result*=a;
                 result=result&(n-1);
             }
         }
         printf("%d\n" , result);
     }
     return 0;
    
    
    
    
    
    
    
    
    
    
    
    
    
//     int a , k , n , result;
//     while(scanf("%d%d%d" , &a , &k , &n)!=EOF){
////         a = foo(a,n), result = 1, foo(a,k);
//         result=1;
//         a=fast_mod(a, n);
//
////         printf("a=%d, k=%d, n=%d, result=%d\n", a, k, n, result);
//         vector<int> numbers;
////         while(k--){
////             result*=a,result=(n&(n-1))?(foo(result,n)):((result)&(n-1));
////             printf("when k=%d, a=%d, n=%d, result=%d\n", k, a, n, result);
////         }
//
//
//         int tmp=k;
//         bool flag=false;
//         if (n&(n-1)) {
////             that means n is not a power of two
//             while (k--) {
//                 result*=a;
//                 result=fast_mod(result, n);
//                 numbers.push_back(result);
//                 if (result==1) {
//                     break;
//                 }
//                 if(result==0){
//                     flag=true;
//                     break;
//                 }
//             }
//         }else{
////             that means n is a power of two
//             while (k--) {
//                 result*=a;
//                 result=result&(n-1);
//                 numbers.push_back(result);
//                 if (result==1) {
//                     break;
//                 }
//                 if (result==0) {
//                     flag=true;
//                     break;
//                 }
//             }
//         }
//
//         if (flag) {
//             printf("%d\n" , result);
//             continue;
//         }
//
//         int index;
//         if (numbers.size()==1) {
//             index=0;
//         }else if(numbers.size()==0){
//             numbers.push_back(1);
//             index=0;
//         }else{
//             index=fast_mod(tmp, (int)numbers.size())-1;
//         }
//
//         result=numbers.at(index);
//
//         printf("%d\n" , result);
//     }
//     return 0;
}
