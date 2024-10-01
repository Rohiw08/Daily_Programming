#include<iostream>
#include<vector>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> q(nums.size());
    unsigned l = 0, r = 0;
    unsigned idx = 0;
    unsigned k_idx = 0;
    while (idx < k - 1) {
        while (l < r && q[r - 1] < nums[idx]) {
            --r;
        }
        q[r++] = nums[idx++];
    }
    
    while (idx < nums.size()) {
        while (l < r && q[r - 1] < nums[idx]) {
            --r;
        }
        q[r++] = nums[idx];
        
        if (q[l] == nums[k_idx]) {
            ++l;
        } else {
            nums[k_idx] = q[l];
        }
        ++idx;
        ++k_idx;
    }
    
    nums.resize(k_idx);
    return std::move(nums);
}

void printa(vector<int> a){
    cout<<"[";
    for(int i : a) cout<<i<<" ";
    cout<<"]";
}

int main(){
    vector<int> question = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> ans = maxSlidingWindow(question, k);
    printa(ans);
    return 0;
}
