#include <iostream>
using namespace std;
#include<algorithm>

void rotate(int *input, int d, int n)
{
    //Write your code here
    /*for(int i=0;i<d;i++){
        int tmp = input[0];
        int j=0;
        while(j<n){
            input[j] = input[j+1];
            j++;
        }
        input[j-1]=tmp;
    }*/
    reverse(input,input+n);
    reverse(input,input+n-d);
    reverse(input+n-d,input+n);
}

int main()
{
	int t;
	cin >> t;
	
	while (t--)
	{
		int size;
		cin >> size;

		int *input = new int[size];

		for (int i = 0; i < size; ++i)
		{
			cin >> input[i];
		}

		int d;
		cin >> d;

		rotate(input, d, size);

		for (int i = 0; i < size; ++i)
		{
			cout << input[i] << " ";
		}
		
		delete[] input;
		cout << endl;
	}

	return 0;
}