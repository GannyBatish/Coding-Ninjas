#include <iostream>
#include<stack>
#include<queue>
using namespace std;

void reverseQueue(queue<int> &input) {
	// Write your code here
    stack<int> tmp;
    while(!input.empty()){
        tmp.push(input.front());
        input.pop();
    }
    while(!tmp.empty()){
        input.push(tmp.top());
        tmp.pop();
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        queue<int> q;
        int size;
        cin >> size;

        for (int i = 0, val; i < size; i++) {
            cin >> val;
            q.push(val);
        }

        reverseQueue(q);
        while (!q.empty()) {
            cout << q.front() << " ";
            q.pop();
        }

        cout << "\n";
    }
}