#include<unordered_map>
string uniqueChar(string str) {
	// Write your code here
    unordered_map<char,int> mp;
    string res = "";
    int n = str.size();
    for(int i=0;i<n;i++){
        if(mp.count(str[i])==0){
            res+=str[i];
        }
        mp[str[i]]++;
    }
    return res;
}