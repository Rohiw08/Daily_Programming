#include<iostream>
#include<stack>
#include<string>
using namespace std;

void insert(stack<int> &s, int temp) {
    if(s.empty() || s.top() >= temp) {
        s.push(temp);
        return;
    }

    int curr = s.top();
    s.pop();
    insert(s, temp);
    s.push(curr);
}

void sort(stack<int> &s) {
    if(s.size() == 1 || s.empty()) 
        return;

    int temp = s.top();
    s.pop();
    sort(s);
    insert(s, temp);
}

void print_stack(stack<int> s) {
    cout << "[";
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << "]" << endl;
}

void push_stack(stack<int> &s) {
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

int main() {
    stack<int> question;
    push_stack(question);
    sort(question);
    print_stack(question);
    
    return 0;
}
