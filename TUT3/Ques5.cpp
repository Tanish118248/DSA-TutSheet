// Write a program for the evaluation of a Postfix expression
#include <iostream>
#include <stack>
#include <cctype>  
#include <cmath>   
using namespace std;
int evaluatePostfix(string expr) {
    stack<int> st;
    for (char c : expr) {
        if (c == ' ') continue;
        if (isdigit(c)) {
            st.push(c - '0');  
        }
        else {
            int op2 = st.top(); st.pop(); 
            int op1 = st.top(); st.pop();
            int result;
            switch (c) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
                case '^': result = pow(op1, op2); break;
                default: 
                    cout << "Invalid operator: " << c << endl;
                    return -1;
            }
            st.push(result);
        }
    }
    return st.top();
}
int main() {
    string postfix;  
    cout<<"Enter Postfix Expression: ";
    getline(cin, postfix);
    cout << "Postfix Expression: " << postfix << endl;
    cout << "Evaluated Result = " << evaluatePostfix(postfix) << endl;

    return 0;
}


