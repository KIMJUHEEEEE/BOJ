#include<iostream>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	int arr[100] = { 0, };
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int ans = 0;
	for (int i = 0; i <= n - 3; i++)
	{
	
		for (int j = i + 1; j <= n - 2; j++)
		{
			for (int z = j+1; z <= n - 1; z++)
			{	
				int sum = arr[i] + arr[j] + arr[z];
				if (sum <=m && sum > ans)
					ans = sum;
			}
		}
	}
	cout << ans;
}