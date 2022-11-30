#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
long staircase(int n) {
  long *arr = new long[n + 1];
  arr[0] = 1;
  arr[1] = 1;
  arr[2] = 2;
  arr[3] = 4;
  for (int i = 4; i <= n; i++) {
    arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
  }
  return arr[n] %mod;
}

int main() {
  int t;
  cin>>t;
  while(t--){
    int n;
    cin >> n;
    cout << staircase(n) << endl;
  }
  
  return 0;
}