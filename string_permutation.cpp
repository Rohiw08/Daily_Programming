#include <iostream>
#include <vector>
#include <string>

using namespace std;

void permute(string s, int left, int right, vector<string> &result) {
    if (left == right) {
        result.push_back(s);
        return;
    }

    for (int i = left; i <= right; i++) {
        swap(s[left], s[i]);
        permute(s, left + 1, right, result);
        swap(s[left], s[i]);
    }
}

vector<string> findPermutations(string s) {
    vector<string> result;
    permute(s, 0, s.length() - 1, result);
    return result;
}

void printa(auto a){
    cout<<"[";
    for(auto str : a)
        cout<<str<<",";
    cout<<"]";
}

int main() {
    string question = "abc";
    vector<string> ans = findPermutations(question);
    printa(ans);
    
    return 0;
}
