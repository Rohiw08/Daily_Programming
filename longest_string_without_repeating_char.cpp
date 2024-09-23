#include<iostream>
#include<vector>
using namespace std;


int lengthOfLongestSubstring(string s) {
    vector<int> seen(256, -1);
    int maxLength = 0;
    int j = 0, n = s.length();
    for(int i = 0; i < n; i++){
        int curr = seen[s[i]];
        if(curr != -1 and curr >= j) j = curr + 1;
        seen[s[i]] = i;
        maxLength = max(maxLength, i - j + 1);
    }
    return maxLength;
}

int main(){
    string question = "abcabcbb";
    int ans = lengthOfLongestSubstring(question);
    cout<<"Longest string without repeating chars has length : "<< ans <<endl;

    return 0;
}
