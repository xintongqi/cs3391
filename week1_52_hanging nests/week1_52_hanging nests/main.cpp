//
//  main.cpp
//  week1_52_hanging nests
//
//  Created by Xintong Qi on 5/2/2022.
//

#include<iostream>
#include<vector>
#include<map>
#include<cstdio>
using namespace std;

map<int,int> position_map;
vector<int> all_spots;
int unbalanced;
int most_unbalanced;

void updateResult(int nunb,int nres){
    if(nunb>unbalanced){
        unbalanced = nunb;
        most_unbalanced=nres;
    }
    else if(nunb==unbalanced){
        if(position_map[nres]<position_map[most_unbalanced]) most_unbalanced = nres;
    }
}

int add_bird(vector<int> v){
    if(v.size()==0){
        return 0;
    }
    if(v.size()==1){
        updateResult(0,v[0]);
        return 1;
    }
    vector<int> shorter,longer;
    for(int i=1;i<v.size();++i){
        if(v[i]<v[0]) shorter.push_back(v[i]);
        else longer.push_back(v[i]);
    }
    int d1 = add_bird(shorter);
    int d2 = add_bird(longer);
    int d3 = d1-d2;
    if(d3<0) d3=-d3;
    updateResult(d3,v[0]);
    int ret = d1>d2?d1:d2;
    return ret+1;
}


int main(){
    int test_cases;
    cin>>test_cases;
    for(int flock=1;flock<=test_cases;++flock){
        int num_of_flocks;
        cin>>num_of_flocks;
        all_spots.resize(num_of_flocks);
        position_map.clear();
        for(int i=0;i<num_of_flocks;++i){
            cin>>all_spots[i];
            position_map[all_spots[i]]=i;
        }
        unbalanced = -1;
        most_unbalanced = -1;
        add_bird(all_spots);
        printf("Flock #%d: %d\n\n",flock,most_unbalanced);
    }
    return 0;
}
