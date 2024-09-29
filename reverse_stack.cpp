#include<iostream>
#include<stack>
#include<string>
using namespace std;

void insert(stack<int> &s, int temp){
    if(s.empty()){
        s.push(temp);
        return;
    }
    int curr = s.top();
    s.pop();
    insert(s, temp);
    s.push(curr);
}

void reverseStack(stack<int> &s){
    if(s.empty()) return;
    int temp = s.top();
    s.pop();
    reverseStack(s);
    insert(s, temp);
}

void pushStack(stack<int> &s) {
    while(true) {
        cout << "Type an integer value to push (type 'c' to stop): " << endl;
        string val = "";
        cin >> val;
        if(val == "c") break;
        try {
            s.push(stoi(val));
        } catch (const invalid_argument& e) {
            cout << "Invalid input. Please enter an integer value." << endl;
        }
    }
}

int main(){
    stack<int> question;
    pushStack(question);
    reverseStack(question);
    return 0;
}
