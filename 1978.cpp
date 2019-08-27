#include<iostream>
using namespace std;
int arr[1001];
void map()
{
	for (int i = 2; i <= 1000; i++)
	{
		arr[i] = i;
	}
	for (int i = 2; i <= 1000; i++)
	{
		for (int j = 2; j <= 1000; j++)
		{
			if (arr[j] != i && arr[j] % i == 0)
				arr[j] = 0;
		}
	}
}
int main() {
	int n = 0;
	cin >> n;
	int ans = 0;
	map();
	for (int i = 0; i < n; i++)
	{
		int a = 0;
		cin >> a;
		if (arr[a] != 0)
			ans++;
	}
	cout << ans;
}