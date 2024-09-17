#include<iostream>
#include<vector>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";
    
    string prefix = strs[0];
    
    for (int i = 1; i < strs.size(); i++) {
        while (strs[i].find(prefix) != 0) {
            prefix = prefix.substr(0, prefix.size() - 1);
            if (prefix.empty()) return "";
        }
    }
    
    return prefix;
}


int main(){
    vector<string> question = {"flower","flow","flight"};
    cout<<"longest common prefix is : "<<longestCommonPrefix(question)<<endl;
    return 0;
}
