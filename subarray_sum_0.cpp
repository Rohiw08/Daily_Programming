#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<vector<int>> subArraySum(vector<int> &nums){
    unordered_map<int, vector<int>> map;
    vector<vector<int>> ans;
    int prefix = 0;

    // map[0].push_back(-1);

    int n = nums.size();
    for(int i = 0; i < n; i++){
        prefix += nums[i];
        
        if(prefix == 0) 
            ans.push_back({0, i});

        if(map.find(prefix) != map.end())
            for(int inx : map[prefix])
                ans.push_back({inx + 1, i});

        map[prefix].push_back(i);
    }

    return ans;
}

void printa(auto a){
    cout<<"[";
    for(auto i : a){
        cout<<"[";
        for(auto j : i){
            cout<<" "<<j;
        }
        cout<<"]";
    }
    cout<<"]";
}

int main(){
    vector<int> question = {1, 2, -3, 3, -1, 2};
    vector<vector<int>> ans = subArraySum(question);
    printa(ans);

    return 0;
}
