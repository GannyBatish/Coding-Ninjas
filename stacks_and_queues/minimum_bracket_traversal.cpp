#include<stack>
int countBracketReversals(string input) {
	// Write your code here
    int n = input.size();
    if(n%2!=0){
        return -1;
    }
    else{
        stack<char> s;
        for(int i=0;i<n;i++){
            if(input[i]=='{'){
                s.push('{');
            }
            else if((s.empty() || s.top()=='}')&& input[i]=='}'){
                s.push('}');
            }
            else if(s.top()=='{' && input[i]=='}'){
                s.pop();
            }
        }
        if(s.empty()){
            return 0;
        }
        else{
            int count = 0;
            while(!s.empty()){
                char c1 = s.top();
                s.pop();
                char c2 = s.top();
                s.pop();
                if(c1==c2){
                    count++;
                }
                else{
                    count+=2;
                }
            }
            return count;
        }
    }
}