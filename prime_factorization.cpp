#include<iostream>
#include<vector>
using namespace std;

vector<int> primeFactors(int n){
    vector<int> factors;

    // chehck 2
    while(n % 2 == 0) {
        factors.push_back(2);
        n /= 2;
    }

    // check odd nums
    for(int i = 3; i * i <= n; i += 2){
        while(n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }

    // num is prime num
    if(n > 2) factors.push_back(n);

    return factors;
}

void printa(auto a){
    cout<<"[";
    for(auto i : a) cout<<i<<" ";
    cout<<"]";
}

int main() {
    int question = 81;
    vector<int> ans = primeFactors(question);
    printa(ans);

    return 0;
}
