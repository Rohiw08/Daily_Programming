#include<iostream>
using namespace std;

string palindrome(string &s, int i, int j){
    int n = s.size();
    while(i >= 0 && j < n && s[i] == s[j]) i--, j++;
    return s.substr(i + 1, j - i - 1);
}

string longestPalindrome(string s) {
    int n = s.size();
    string ans = "";
    
    for(int i = 0; i < n; i++) {
        // odd case
        string subString = palindrome(s, i, i);
        if(subString.size() > ans.size()) ans = subString;

        // even case
        subString = palindrome(s, i, i + 1);
        if(subString.size() > ans.size()) ans = subString;
    }
    
    return ans;
}

int main(){
    string question = "babad";
    cout<<"Longest palindromic substring is : "<<longestPalindrome(question)<<endl;
    return 0;
}
