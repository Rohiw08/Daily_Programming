#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> leaders(vector<int> &arr) {
    int n = arr.size();
    vector<int> ans = {arr[n - 1]};
    for(int i = n - 2; i >= 0; i--)
        if(ans.back() <= arr[i]) 
            ans.push_back(arr[i]);
    reverse(ans.begin(), ans.end());
    return ans;
}

void printa(auto a){
    for(auto i : a) cout<<i<<" ";
}

int main(){
    vector<int> question = {16, 17, 4, 3, 5, 2};
    vector<int> ans = leaders(question);
    printa(ans);
    return 0;
}
