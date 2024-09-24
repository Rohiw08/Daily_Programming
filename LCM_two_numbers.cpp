#include<iostream>
using namespace std;

int LCM(int a, int b)
{
    int greater = max(a, b);
    int smallest = min(a, b);
    for (int i = greater; ; i += greater) {
        if (i % smallest  == 0)
            return i;
    }
}

int main(){
    int a = 4, b = 6;
    int ans = LCM(a, b);
    cout<<"Smallest number divisible by "<<a<<" and "<<b<<" is "<<ans;

    return 0;
}
