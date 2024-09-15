#include<iostream>
#include<vector>
using namespace std;

int trap(vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int leftMax = 0, rightMax = 0;
    int maxWater = 0;
    while(left < right){
        if(height[left] < height[right]){
            if(leftMax <= height[left]){
                leftMax = height[left];
            }else{
                maxWater += leftMax - height[left];
            }
            left++;
        }
        else{
            if(rightMax <= height[right]){
                rightMax = height[right];
            }else{
                maxWater += rightMax - height[right];
            }
            right--;
        }
    }
    return maxWater;
}

int main(){
    vector<int> question = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout<<"Maximum water : "<<trap(question);
    
    return 0;
}
