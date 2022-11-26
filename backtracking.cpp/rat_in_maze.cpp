/*
	Note:
	To get all the test cases accepted, make recursive calls in following order: Top, Down, Left, Right.
	This means that if the current cell is (x, y), then order of calls should be: top cell (x-1, y), 
	down cell (x+1, y), left cell (x, y-1) and right cell (x, y+1).
*/
#include<bits/stdc++.h>
using namespace std;

int maze[19][19];
int n;

void helper(int** arr , int n,int row,int col){
    if(row==n-1 && col==n-1){
        maze[row][col] = 1;
        //print maze
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<maze[i][j]<<" ";
            }
        }
        cout<<endl;
        return;
    }

    //check for boundaries
    if(row>=n || row<0 || col>=n || col<0 || arr[row][col]==0 || maze[row][col]==1){
        return;
    }

    //go to next possible location
    maze[row][col] = 1;
    helper(arr,n,row-1,col);
    helper(arr,n,row+1,col);
    helper(arr,n,row,col-1);
    helper(arr,n,row,col+1);
    maze[row][col] = 0;

}

void rat_in_maze(int** arr,int n){
    memset(maze,0,19*19*sizeof(int));
    helper(arr,n,0,0);
}

int main() {

	// Write your code here
	cin>>n;
	int** arr = new int*[n];
    for(int i=0;i<n;i++){
        arr[i] = new int[n];
    }
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
		}
	}
	rat_in_maze(arr,n);
	return 0;
}
