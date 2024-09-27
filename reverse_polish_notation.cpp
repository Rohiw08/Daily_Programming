#include<iostream>
#include<stack>
#include<functional>
#include<unordered_map> // Added this
#include<sstream> // Added this
#include<string>
using namespace std;

int evalRPN(const string &s) {
    unordered_map<string, function<int(int, int)>> operations;
    operations["+"] = [](int a, int b) { return a + b; };
    operations["-"] = [](int a, int b) { return a - b; };
    operations["*"] = [](int a, int b) { return a * b; };
    operations["/"] = [](int a, int b) { return a / b; };

    stack<int> stk;

    stringstream ss(s);
    string exp;
    while (ss >> exp) {
        if (isdigit(exp[exp.length() - 1])) {
            int num = stoi(exp);
            stk.push(num);
        } else {
            int num1 = stk.top();
            stk.pop();
            int num2 = stk.top();
            stk.pop();
            int ans = operations[exp](num2, num1);
            stk.push(ans);
        }
    }
    return stk.top();
}

int main() {
    string expression = "2 1 + 3 *";
    
    int result = evalRPN(expression);
    cout << "Result: " << result << endl;

    return 0;
}
