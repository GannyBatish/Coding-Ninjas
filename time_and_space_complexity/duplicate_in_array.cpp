#include <iostream>
using namespace std;

int findDuplicate(int *arr, int n)
{
    //Write your code here
    int sumN = ((n-1)*(n-2))/2;
    int sumArr = 0;
    for(int i=0;i<n;i++){
        sumArr+=arr[i];
    }
    return sumArr-sumN;
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

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		cout << findDuplicate(input, size) << endl;
	}

	return 0;
}