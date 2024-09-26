#include<iostream>
#include<vector>
using namespace std;

void SieveOfEratosthenes(int n, vector<bool>& prime, vector<bool>& primesquare, vector<int>& a) { 
    for (int i = 2; i <= n; i++) 
        prime[i] = true;

    for (int i = 0; i <= (n * n); i++) 
        primesquare[i] = false;

    prime[1] = false;

    for (int p = 2; p * p <= n; p++) { 
        if (prime[p]) { 
            for (int i = p * p; i <= n; i += p) 
                prime[i] = false; 
        }
    } 

    int j = 0; 
    for (int p = 2; p <= n; p++) { 
        if (prime[p]) { 
            a.push_back(p);
            if (p * p <= n * n) {
                primesquare[p * p] = true; 
            }
            j++; 
        } 
    } 
} 

int countDivisors(int n) { 
    if (n == 1) return 1;

    vector<bool> prime(n + 1);
    vector<bool> primesquare(n * n + 1);
    vector<int> a;

    SieveOfEratosthenes(n, prime, primesquare, a); 

    int ans = 1;
    for (size_t i = 0; i < a.size(); i++) { 

        if (a[i] * a[i] * a[i] > n) break; 
 
        int cnt = 1;
        while (n % a[i] == 0) { 
            n = n / a[i]; 
            cnt++; 
        } 
        ans = ans * cnt; 
    }

    if (prime[n]) 
        ans = ans * 2; 
    else if (primesquare[n]) 
        ans = ans * 3; 
    else if (n != 1) 
        ans = ans * 4; 

    return ans;
} 

int main() { 
    int question = 12;
    cout<<"Total distinct divisors of " <<question<< " are : "<<countDivisors(question)<<endl; 
    return 0; 
}
