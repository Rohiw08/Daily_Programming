#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// prime factorization
vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 
37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<double, vector<string>> map;
    for(string str : strs){
        double key = 1;
        for(char ch : str) key *= primes[ch - 'a'];
        map[key].push_back(str);
    }
    vector<vector<string>> ans;
    for (auto& entry : map) {
        ans.push_back(entry.second);
    }

    return ans;
}

void printa(auto a){
    for(auto i : a){
        cout<<"[";
        for(auto j : i) cout<<j<<" ";
        cout<<"]";
    }
}

int main(){
    vector<string> question = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> ans = groupAnagrams(question);
    printa(ans);
    cout<<endl;
    
    return 0;
}
