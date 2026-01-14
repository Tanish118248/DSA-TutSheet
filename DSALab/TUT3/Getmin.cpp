#include <iostream>
#include <stack>
using namespace std;

class SpecialStack {
private:
    stack<int> st;
    int minEle;
    
public:
    SpecialStack() {
        minEle = -1;
    }
    void push(int x) {
        if (st.empty()) {
            minEle = x;
            st.push(x);
        }
        else if (x < minEle) {
            st.push(2 * x - minEle);
            minEle = x;
        }
        else {
            st.push(x);
        }
    }
    void pop() {
        if (st.empty()) return;
        
        int top = st.top();
        st.pop();
        
        if (top < minEle) {
            minEle = 2 * minEle - top;
        }
    }
    
    int peek() {
        if (st.empty()) return -1;

        int top = st.top();
        return (minEle > top) ? minEle : top;
    }
    
    int getMin() {
        if (st.empty()) return -1;
        return minEle;
    }
};

int main() {
    SpecialStack st;
    
    st.push(2);
    st.push(3);
    cout << st.peek() << " ";
    st.pop();
    cout << st.getMin() << " ";
    st.push(1);
    cout << st.getMin() << " ";
}
