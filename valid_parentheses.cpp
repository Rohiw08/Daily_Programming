#include<iostream>
#include<stack>
using namespace std;

bool validopening(char ch){
    return (ch == '(' || ch == '{' || ch == '[');
}
bool validclosing(char top , char ch){
    return (
    (top == '(' && ch ==')') || 
    (top == '{' && ch =='}') || 
    (top == '[' && ch ==']')
    );
}

bool isValid(string s) {
    stack<char> stk;
    for(const char &curr : s){
        if(validopening(curr)) 
            stk.push(curr);
        else{
            if(!stk.empty() && validclosing(stk.top(), curr)) 
                stk.pop();
            else 
                return false;
        }
    }
    return stk.empty();
}


int main(){
    string question = "[{()}]";
    cout<<question + " are "<< (isValid(question) ? "valid" : "invalid" ) <<" parentheses"<<endl;

    return 0;
}
