#include<iostream>
#include<vector>
using namespace std;

void sortColors(vector<int>& nums) {
    vector<int> map(3, 0);
    for(int i : nums) map[i]++;
    int j = 0;
    for(int i = 0; i <= 2; i++){
        int count = map[i];
        while(count--) nums[j++] = i;
    }
}

int main(){
    vector<int> question = {0, 1, 2, 1, 0, 2, 1, 0};
    sortColors(question);
    return 0;
}
