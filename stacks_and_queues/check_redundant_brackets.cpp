bool checkRedundantBrackets(string expression) {
	// Write your code here
    int n = expression.size();
    for(int i=0;i<n;i++){
        if(expression[i]=='('){
            if(expression[i+1]=='('||expression[i+1]==')'||expression[i+2]==')'){
                return true;
            }
        }
    }
    return false;
}