//
//  main.cpp
//  week13_227_2ddp_no_path_printing
//
//  Created by Xintong Qi on 2/4/2022.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cstring>

using namespace std;

struct Price{
    int amount;
    double cost;
    
    Price(int a, double c){
        amount=a;
        cost=c;
    }
    
    bool operator<(const Price& p) const
    {
        return (amount<p.amount) || (amount==p.amount && cost<=p.cost);
    }
};

void dp(double* results, vector<Price>& prices){
    
    for (int i=1; i<110; i++) {
        double result=numeric_limits<double>::max();
        for (int j=0; j<prices.size(); j++) {
            int amount=prices[j].amount;
            if (i>=amount) {
                if (result>results[i-amount]+prices[j].cost) {
                    result=results[i-amount]+prices[j].cost;
                }
            }else{
                break;
            }
        }
        results[i]=result;
    }
}

int main() {
    
    double cost1;
    int test_cases=0;
    while (cin>>cost1) {
        test_cases++;
        
        vector<Price> prices;
        prices.push_back(Price(1,cost1));
        
        short num_price_pairs;
        cin>>num_price_pairs;
        while (num_price_pairs--) {
            double c;
            int a;
            cin>>a>>c;
            prices.push_back(Price(a,c));
        }
        stable_sort(prices.begin(), prices.end());
        
//        for(auto& p: prices){
//            printf("amount %d cost %.2f\n", p.amount, p.cost);
//        }
        
        double* results=new double[110];
        memset(results,0, 110);
        
        dp(results, prices);
        
//        for (int i=0; i<110; i++) {
//            cout<<results[i]<<" ";
//        }
//        cout<<endl;
        
        cin.ignore(256, '\n');
        string s;
        getline(cin, s);
        size_t pos=0;
        string test;
        int amount;
        printf("Case %d:\n",test_cases);
        while ((pos = s.find(" ")) != string::npos) {
            test=s.substr(0,pos);
            amount=stoi(test);
            printf("Buy %d for $%.2f\n",amount, results[amount]);
            s.erase(0,pos+1);
        }
        if (s!="") {
            amount=stoi(s);
            printf("Buy %d for $%.2f\n", amount, results[amount]);
        }
        
        delete [] results;
    }
    
    return 0;
}


/*
 
 1 20
 5 4.95
 10 9.91
 15 14.8
 20 18.5
 25 22.5
 30 27.95
 35 32
 40 36.3
 45 40.56
 50 45.1
 55 48.7
 60 54.2
 65 57.99
 70 62.79
 75 65.4
 80 70.29
 85 74.99
 90 79.99
 95 84.6
 100 89.3
 
 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98 99 100
 
 **/
