#include<iostream>
#include<vector>
using namespace std;

int missingNumber(vector<int>& nums) {
    int n = nums.size();
    n = (n * (n + 1)) / 2;
    int sum = 0;
    for(const int &i : nums) sum += i;
    return n - sum;
}

int main(){
    vector<int> question = {0, 1, 2, 4};
    int ans = missingNumber(question);
    cout<<ans<<endl;

    return 0;
}
