#include <iostream>
#include <string>
#include<stack>
using namespace std;

bool isBalanced(string expression) 
{
    // Write your code here
    int n = expression.size();
    stack<char> s;
    for(int i=0;i<n;i++){
        if(expression[i]=='('){
            s.push('(');
        }else if(expression[i]==')'){
            if(s.empty()){
                return false;
            }
            else if(s.top()=='('){
                s.pop();
            }
        }
    }
    return s.size()==0;
}

int main() 
{
    string input;
    cin >> input;
    cout << ((isBalanced(input)) ? "true" : "false");
}