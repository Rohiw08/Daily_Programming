#include<iostream>
#include<algorithm>
using namespace std;

void merge(long long arr1[], long long arr2[], int n, int m) { 
    int i = n - 1, j = 0;
    while(i >= 0 && j < m){
        if(arr1[i] > arr2[j]) swap(arr1[i--], arr2[j++]);
        else break;
    }
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
}

void printArray(long long a[], unsigned size){
    for(int i = 0; i < size; i++){
        cout<<a[i]<<" ";
    }
}

int main(){
    // question input
    const unsigned n = 4, m = 4;
    long long arr1[n] = {1, 3, 5, 7};
    long long arr2[m] = {2, 4, 6, 8};

    // solution
    merge(arr1, arr2, n, m);

    // print solution
    printArray(arr1, n);
    cout<<endl;
    printArray(arr2, m);

    return 0;
}
