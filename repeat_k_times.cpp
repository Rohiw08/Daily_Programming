#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int firstElementKTime(vector<int> elements, int k){

    unordered_map<int, int> map;
    for(const int &element : elements) 
        map[element]++;

    for(const int &element : elements) 
        if(map[element] == k) 
            return element;

    return -1;

}

int main(){
    vector<int> question = {6, 6, 6, 6, 7, 7, 8, 8, 8};
    int k = 3;
    cout<<"First Element to occur "<<k<<" times is : "<<firstElementKTime(question, k);
    return 0;
}
