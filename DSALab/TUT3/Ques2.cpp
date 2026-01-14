#include <iostream>
using namespace std;

class Stack{
    char arr[1000];
    int top;
    public:
        Stack(){ top = -1; }
        void push(char ch){
            if(top == 999){
                cout << "Stack Overflow! " << endl;
                return;
            }
            arr[++top] = ch;
        }
        char pop(){
            if(top == -1){
                cout<<"Stack Underflow ! "<<endl;
                return '\0';  
            }
            return arr[top--];   
        }
        bool isEmpty(){
            return top == -1;
        }
};

int main(){
    Stack s;
    string str = "DataStructure"; 
    for(char ch : str){  
        s.push(ch);
    }
    cout << "Reversed string = ";
    while(!s.isEmpty()){  
        cout << s.pop();   
    }
    cout << endl;

    return 0;
}

