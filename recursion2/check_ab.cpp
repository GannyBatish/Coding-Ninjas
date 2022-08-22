/*bool checkAB(char input[]) {
	// Write your code here
    if(input[0] == '\0'){
        return false;
    }
    bool small = checkAB(inp)
    if(input[0]=='a'){
        if(input[1]=='a' || input[1]=='\0'){
            return true;
        }
        else{
            if(input[1]=='b' && input[2]=='b'){
                return true;
            }
            else{
                return false;
            }
        }
    }
    else{
        if(input[0]=='b' && input[1]=='b'){
            return true;
        }
        else{
            return false;
        }
    }
    
}*/

bool solve(char input[]) {
    if(input[0]=='\0')
        return true; // Write your code here
    bool so;
    if(input[0]=='a'&&(input[1]=='\0'||input[1]=='a'))
        so=solve(input+1);
    else if(input[0]=='a'&&(input[1]=='b'&&input[2]=='b'))
        so=solve(input+1);
    else if(input[0]=='b'&&input[1]=='b'&&(input[2]=='\0'||input[2]=='a'))
        so= solve(input+2);
    else
        return false;
    return so;
}


bool checkAB(char input[]) {
    if(input[0]=='\0')
        return true; 
    else if (input[0] != 'a')
        return false;
    return solve(input);
}