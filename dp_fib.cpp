#include<iostream>
using namespace std;

int memo[1000] = {0};

int fib(int n) {
    if(n <= 1) return n;
    if(memo[n] != 0) return memo[n];
    memo[n] = fib(n - 2) + fib(n - 1);
    return memo[n];
}

int main(){
    int question = 30;
    cout<<fib(question)<<endl;
    return 0;
}
