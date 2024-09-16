#include<iostream>
using namespace std;

string reverseWords(string s) {
    string temp = "";
    string ans = "";
    int i=0, n = s.size();
    
    while(s[i] == ' ') i++;

    while(i < n) {
        if(s[i] == ' ') {
            if(!temp.empty()) {
                temp+=ans;
                ans=(" " + temp);
                temp = "";
            }
            while(s[i]==' ') i++;   
        }
        else temp+=s[i], i++;
    }
    
    if(!temp.empty() && temp!=" ") {
        temp+=ans;
        ans=temp;
    }
    
    if(ans[0]==' ') ans.erase(0,1);
    return ans;
}

int main(){
    string question = "the sky is blue";
    cout<<"Reversed string : "<<reverseWords(question);

    return 0;
}
