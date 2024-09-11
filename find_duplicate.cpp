#include<iostream>
#include<vector>
using namespace std;

int findDuplicate(vector<int>& nums) {
    int slow = nums[0], fast = nums[0];
    do{
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while(slow != fast);
        
    slow = nums[0];
    while(slow != fast){
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}

int main(){
    vector<int> question = {3, 1, 3, 4, 2};
    int ans = findDuplicate(question);
    cout<<ans<<endl;

    return 0;
}
