#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int countSubstringsWithKDistinct(string s, int k) {
    int n = s.size();
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        unordered_map<char, int> freq;
        int distinctCount = 0;

        for (int j = i; j < n; j++) {
            if (freq[s[j]] == 0) distinctCount++;
            freq[s[j]]++;
            if (distinctCount == k) count++;
            if (distinctCount > k) break;
        }
    }
    
    return count;
}

int main() {
    string question = "pqpqs";
    int k = 2;
    int ans = countSubstringsWithKDistinct(question, k);
    cout << "Number of substring are : " << ans << endl;
    return 0;
}
